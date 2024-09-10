# APM_v2

## 언어 선택

[English](README.md) | [한국어](README_KR.md)

<br><br>

## 개요

- 대기 오염 수집 장치는 저가형 미세먼지 센서를 이용하여 고가의 미세먼지 측정 장비와 비슷한 성능을 내고자 저가형 센서 기반으로 제작된 장비임
- 기상 및 대기 오염 물질과 고농도 미세먼지의 계절별 상관 분석 연구 결과를 바탕으로, 미세먼지, 온습도, 아황산가스, 일산화탄소, 이산화질소, 풍향, 풍속 센서가 설치됨
- 장치는 환경부의 대기 오염 측정 및 운영지침에 따라 1.5미터 이상의 높이에 센서들을 위치시킴
- 상부에는 측정을 위한 저가형 미세먼지 측정 센서와 환경 센서(온습도, 아황산가스, 일산화탄소, 이산화질소, 풍향, 풍속, 오존)가 설치됨
- 미세먼지 센서 내부의 팬을 제거한 후 PWM 제어 팬을 설치한 후 PWM 제어팬을 이용하여, 공기 유입량 제어가 가능한 형태로 제작됨

<br><br>


### 모델링 및 설치 사진
<div align="center">
  
  | 모델링 | 설치 |
  |:---:|:---:|
  | <img src="https://github.com/user-attachments/assets/ba80964b-d8c8-4775-a51b-e386a5ecab33" width="470px" height="350px" alt="모델링"> | <img src="https://github.com/user-attachments/assets/8cf09806-a0ee-473e-bbfc-5edc33816b9d" width="470px" height="350px" alt="설치"> |
</div>

<br><br>

### APM_v2 Mqtt(모터) 구동 영상

- 모터는 필요없다고 생각되어 현재 탈거하였음

[APM_v2 Mqtt 구동 영상 보기](https://youtu.be/hN8SpTdIn4Q?feature=shared)

<br><br>

### 디렉토리 형식

```
APM_v1/
├── Document/
│   ├── APM_1_v1.0.docx
│   └── APM_1_v1.0.pdf
│
├── src/
│   ├── DAQ/
│   │   └── DAQ.py
│   │
│   ├── Mobius_server_mqtt/
│   │   ├── HowToUsing_nCube.zip
│   │   └── nCube-Thyme-Nodejs.zip
│   │
│   ├── Motor_control/
│   │   ├── Motor_auto_control/
│   │   │   └── auto_control.py
│   │   ├── Motor_control/
│   │   │   ├── Motor_NPM_RX.ino
│   │   │   └── Motor_NPM_TX.ino
│   │   ├── Motor_library/
│   │   │   ├── m_3_1.cpp
│   │   │   └── m_3_1.h
│   │   └── README.md
│   │
│   ├── Sensor/
│       ├── CNSWW_new.ino
│       └── DDDOT.ino

```

<br><br>

| 장비명                | 사양                                                                                                                                                                                                                                                                                                                                                                     | 수량 | 비고                         |
|:------------------:|:----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------:|:---:|:--------------------------:|
| Jetson Nano B 01   | Quad-core ARM® Cortex-A57@ 1.43 GHz                                                                                                                                                                                                                                                                                                                                    | 1  |                            |
| Arduino Mega 2560  | ATmega2560                                                                                                                                                                                                                                                                                                                                                             | 4  | 미세먼지 데이터 3, 환경 데이터 1       |
| Arduino Uno        | ATmega328P                                                                                                                                                                                                                                                                                                                                                             | 1  |                            |
| PMS7003            | 광산란 방식 <br> (fan 유무 : 무)                                                                                                                                                                                                                                                                                                                                               | 9  | 미세먼지 센서                    |
| 환경 센서              | CO, NO2, SO2 each 1 (AllSensing AGSM series)<br><br>Ozone 1 (sen0321) - I2C communication<br><br>WindSpeed 1 (sen0170) - Analog communication<br><br>WindDirection 1 (WS5029) - Analog communication<br><br>Temperature and Humidity (DHT22) - Digital                                                                                                             |    | UART, I2C, Digital, Analog |
| 구동부 센서             | Fan                                                                                                                                                                                                                                                                                                                                                                    | 9  | 4선 Fan                     |
| 기타                 | 파워서플라이 1개 (방수) <br>전기박스 358 x 270 x 152 1개 <br>전기박스 500 x 400 x 160 1개 <br>프로파일 40 x 40 x 500 6개 <br>프로파일 40 x 40 x 250 16개 <br>프로파일 20 x 80 x 400 8개 <br>프로파일 20 x 40 x 400 11개 <br>프로파일 20 x 40 x 360 8개 <br>프로파일 20 x 20 x 400 8개 <br>프로파일 20 x 20 x 470 10개 <br>SSEBL420 8개 <br>4선 실드 케이블 (약 1.5M) 9개 <br>2선 실드 케이블 (1.5M) 8개 <br>3D 프린터로 나머지 재료 제작 (PLA+ 재질)  |    |                            |


<br><br>

### 배선도

<div align="center">
  
  | 센서 배선 | 모터 배선 |
  |:---:|:---:|
  | <img src="https://github.com/user-attachments/assets/b9ae9f78-adc2-4b7d-a810-ac639ee7c0d8" width="420px" height="300px" alt="센서 배선도"> | <img src="https://github.com/user-attachments/assets/166d0f0b-ee65-4d67-88f7-16cb4cec47f2" width="420px" height="300px" alt="모터 배선도"> |
</div>

<br>

#### 센서 배선도

<div align="center">
  <table>
    <tr>
      <td>
        <table>
          <tr>
            <th><strong>Arduino Mega 2560 1</strong></th>
            <th><strong>PM1, PM2, PM3</strong></th>
          </tr>
          <tr>
            <td>5V</td>
            <td><strong>VCC</strong></td>
          </tr>
          <tr>
            <td>GND</td>
            <td><strong>GND</strong></td>
          </tr>
          <tr>
            <td>D19</td>
            <td><strong>PM1_Tx</strong></td>
          </tr>
          <tr>
            <td>D17</td>
            <td><strong>PM2_Tx</strong></td>
          </tr>
          <tr>
            <td>D15</td>
            <td><strong>PM3_Dx</strong></td>
          </tr>
          <tr>
            <td></td>
            <td><strong>DHT22</strong></td>
          </tr>
          <tr>
            <td>5V</td>
            <td><strong>VCC</strong></td>
          </tr>
          <tr>
            <td>GND</td>
            <td><strong>GND</strong></td>
          </tr>
          <tr>
            <td>D6</td>
            <td><strong>OUT</strong></td>
          </tr>
          <tr>
            <td></td>
            <td><strong>Ozone</strong></td>
          </tr>
          <tr>
            <td>5V</td>
            <td><strong>VCC</strong></td>
          </tr>
          <tr>
            <td>GND</td>
            <td><strong>GND</strong></td>
          </tr>
          <tr>
            <td>D20</td>
            <td><strong>SDA</strong></td>
          </tr>
          <tr>
            <td>D21</td>
            <td><strong>SCL</strong></td>
          </tr>
        </table>
      </td>
      <td>
        <table>
          <tr>
            <th><strong>Arduino Mega 2560 2</strong></th>
            <th><strong>CO, NO2, SO2</strong></th>
          </tr>
          <tr>
            <td>5V</td>
            <td><strong>VCC</strong></td>
          </tr>
          <tr>
            <td>GND</td>
            <td><strong>GND</strong></td>
          </tr>
          <tr>
            <td>D19</td>
            <td><strong>CO_Tx</strong></td>
          </tr>
          <tr>
            <td>D18</td>
            <td><strong>CO_Rx</strong></td>
          </tr>
          <tr>
            <td>D17</td>
            <td><strong>NO2_Tx</strong></td>
          </tr>
          <tr>
            <td>D16</td>
            <td><strong>NO2_Rx</strong></td>
          </tr>
          <tr>
            <td>D15</td>
            <td><strong>SO2_Tx</strong></td>
          </tr>
          <tr>
            <td>D14</td>
            <td><strong>SO2_Rx</strong></td>
          </tr>
          <tr>
            <td></td>
            <td><strong>Wind Direction</strong></td>
          </tr>
          <tr>
            <td>5V</td>
            <td><strong>VCC</strong></td>
          </tr>
          <tr>
            <td>GND</td>
            <td><strong>GND</strong></td>
          </tr>
          <tr>
            <td>A0</td>
            <td><strong>OUT</strong></td>
          </tr>
          <tr>
            <td></td>
            <td><strong>Wind Speed</strong></td>
          </tr>
          <tr>
            <td>Power Supply 24V</td>
            <td><strong>VCC</strong></td>
          </tr>
          <tr>
            <td>Power Supply GND</td>
            <td><strong>GND</strong></td>
          </tr>
          <tr>
            <td>A1</td>
            <td><strong>OUT</strong></td>
          </tr>
        </table>
      </td>
    </tr>
  </table>
</div>


<br><br>

## 모터 파라미터 조정

### 하단
| **파라미터**             | **설명**                             |
|--------------------------|--------------------------------------|
| `bottom_?`               | 원하는 각도 입력 시 해당 각도로 회전 |

### 상단
| **파라미터**             | **설명**                             |
|--------------------------|--------------------------------------|
| `pm?_x`                  | PM 센서의 X축 위치 (? : PM 센서 ID에 따라, X : 1, 2, 3 중 하나) |
| `pm1_x`                  | PM1 센서의 X축 위치 (1: 상단, 2: 중간, 3: 하단) |
| `pm2_x`                  | PM2 센서의 X축 위치 (1: 상단, 2: 중간, 3: 하단) |
| `pm3_x`                  | PM3 센서의 X축 위치 (1: 상단, 2: 중간, 3: 하단) |

<br><br>

## Server (OneM2M)

### Mobius 플랫폼

- **현재 APM_v1 철거로 인해 서버 접속 불가능**

![server](https://github.com/user-attachments/assets/9e5f2f4d-9210-41cc-a25c-f3306b2330c8)

- [Mobius 플랫폼 접속 링크](http://114.71.220.59:2021/Mobius/Ksensor_ubicomp)
