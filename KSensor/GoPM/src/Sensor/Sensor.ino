#include <PMS.h>

String con_data = "0,0,0";

const int pwmPins[] = {8, 9, 10};    // 팬의 PWM 핀들
const int tachPins[] = {2, 3, 21};   // 팬의 TACH 핀들
const int fanCount = 3;              // 팬의 수

volatile int tachCounters[fanCount] = {0, 0, 0};
unsigned long previousMillis = 0;
const long interval = 1000;  // 1초마다 RPM 계산

int targetRPMs[fanCount] = {900, 900, 900}; // 목표 RPM
int currentPWMs[fanCount] = {30, 30, 30}; // 현재 PWM 값
bool targetReached[fanCount] = {true, true, true}; // 목표 RPM 도달 여부 추적

const int minPWM = 30; // 최소 PWM 값

PMS pms1(Serial1);
PMS::DATA data1;

PMS pms2(Serial2);
PMS::DATA data2;

PMS pms3(Serial3);
PMS::DATA data3;

bool startReceived = false;

uint16_t d1, d2, d3;

void setup() {
  for (int i = 0; i < fanCount; i++) {
    pinMode(tachPins[i], INPUT_PULLUP);  // TACH 핀을 입력으로 설정
    pinMode(pwmPins[i], OUTPUT);         // PWM 핀을 출력으로 설정
    analogWrite(pwmPins[i], 30);          // 초기 PWM 값을 0으로 설정
  }

  attachInterrupt(digitalPinToInterrupt(tachPins[0]), tachCounterISR0, FALLING);
  attachInterrupt(digitalPinToInterrupt(tachPins[1]), tachCounterISR1, FALLING);
  attachInterrupt(digitalPinToInterrupt(tachPins[2]), tachCounterISR2, FALLING);
  
  Serial.begin(9600);
  Serial1.begin(9600);
  Serial2.begin(9600);
  Serial3.begin(9600);

  delay(100);

  pms1.passiveMode();
  pms2.passiveMode();
  pms3.passiveMode();
  //Serial.println("Enter target RPMs for each fan in the format '2000 3000 1500' or 'M1_P1_2000':");
}

void loop() {
  if (Serial.available() > 0) {
    String input = Serial.readStringUntil('\n');
    input.trim();  // 공백 제거

    // 새로운 입력 형식 M1_P 처리
    if (input.startsWith("M1_P")) {
      int fanIndex = input.substring(4, 5).toInt() - 1;  // 팬 인덱스 (0부터 시작)
      int fanSpeed = input.substring(6).toInt();  // 입력된 RPM 값
      if (fanIndex >= 0 && fanIndex < fanCount) {
        targetRPMs[fanIndex] = fanSpeed;
        targetReached[fanIndex] = false; // 새로운 목표 RPM이 설정되면 도달 플래그 초기화
      }
    } else if(input == "start") {
      startReceived = true;
    }
  }

  if (startReceived == true) {
    pms1.requestRead();
    pms2.requestRead();
    pms3.requestRead();
    
    if(pms1.readUntil(data1)){
      d1 = data1.PM_AE_UG_2_5;
    }

    if(pms2.readUntil(data2)){
      d2 = data2.PM_AE_UG_2_5;
    }
    
    if(pms3.readUntil(data3)){
      d3 = data3.PM_AE_UG_2_5;
    }

    for (int i = 0; i < fanCount; i++) {
      Serial.print(targetRPMs[i]);
      Serial.print(",");
    }
    Serial.print(d1);
    Serial.print(",");
    Serial.print(d2);
    Serial.print(",");
    Serial.print(d3);
    Serial.println();

    startReceived = false;
  }

  // 1초 간격으로 RPM 계산 및 PWM 조정
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    for (int i = 0; i < fanCount; i++) {
      int realRPM = (tachCounters[i] * 60) / 2;
      tachCounters[i] = 0; // tachCounter 초기화

      // 목표 RPM에 맞게 PWM 조정
      int error = targetRPMs[i] - realRPM;
      int pwmStep = 0;

      // 오차가 30 이상일 때만 PWM을 조정
      if (abs(error) > 1000) {
        pwmStep = 20;
      } else if (abs(error) > 450) {
        pwmStep = 10;
      } else if (abs(error) > 200) {
        pwmStep = 5;
      } else if (abs(error) > 30) {
        pwmStep = 1;
      }

      // 오차에 따라 PWM 값을 증가 또는 감소
      if (pwmStep > 0) {
        currentPWMs[i] += (error > 0) ? pwmStep : -pwmStep;
        currentPWMs[i] = constrain(currentPWMs[i], minPWM, 255);  // PWM 값이 최소값과 255 범위 내에 있도록 제한
        analogWrite(pwmPins[i], currentPWMs[i]);
      }

      // 목표 RPM에 도달했는지 확인 (첫 번째로 도달한 경우만 finish 출력)
      if (abs(error) <= 30 && !targetReached[i]) {  // 오차가 ±30 이내일 때
        Serial.print("M1_P");
        Serial.print(i+1);
        Serial.print("_");
        Serial.print(realRPM);
        Serial.println();
        targetReached[i] = true; // 플래그 설정하여 이후 출력 방지
      }

      // 시리얼 모니터에 현재 상태 출력 (주석 처리된 부분)
      //Serial.print("Fan ");
      //Serial.print(i + 1);
      //Serial.print(" | Target RPM: ");
      //Serial.print(targetRPMs[i]);
      //Serial.print(" | Real RPM: ");
      //Serial.print(realRPM);
      //Serial.print(" | PWM: ");
      //Serial.println(currentPWMs[i]);
    }
  }
}

// ISR 정의
void tachCounterISR0() {
  tachCounters[0]++;
}

void tachCounterISR1() {
  tachCounters[1]++;
}

void tachCounterISR2() {
  tachCounters[2]++;
}
