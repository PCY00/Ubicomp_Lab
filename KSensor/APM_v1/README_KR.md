# APM_v1
## 언어 선택

[English](README.md) | [한국어](README_KR.md)

<br><br>

## 개요

- 대기 오염 수집 장치는 저가형 미세먼지 센서를 이용하여 고가의 미세먼지 측정 장비와 비슷한 성능을 내고자 저가형 센서 기반으로 제작된 장비
- 기상 및 대기 오염 물질과 고농도 미세먼지의 계절별 상관 분석 연구 결과를 바탕으로, 미세먼지, 온습도, 아황산가스, 일산화탄소, 이산화질소, 풍향, 풍속 센서가 설치
- 장치는 환경부의 대기 오염 측정 및 운영지침에 따라 1.5미터 이상의 높이에 센서들을 위치
- 상부에는 측정을 위한 저가형 미세먼지 측정 센서와 환경 센서(온습도, 아황산가스, 일산화탄소, 이산화질소, 풍향, 풍속, 오존)가 설치
- 미세먼지 센서는 상하 및 360도 회전이 가능한 형태로 설계되었으며, 사용자의 명령에 따라 센서의 위치를 조절가능


<br><br>

### 모델링 및 설치 사진
<div align="center">
  
  | 모델링 | 설치 |
  |:---:|:---:|
  | <img src="https://github.com/user-attachments/assets/16247e7f-1541-47be-a514-2af5a8bb7449" width="420px" height="300px"> | <img src="https://github.com/user-attachments/assets/54e6a5d6-ec62-4971-b192-cef102818fc4" width="420px" height="300px"> |
</div>

<br><br>

### APM_v1 Mqtt 구동 영상

```
https://youtube.com/shorts/-vXDwXWd0H0?feature=share
```

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

### 배선도
<div align="center">
  
  | 센서 배선 | 모터 배선 |
  |:---:|:---:|
  | <img src="https://github.com/user-attachments/assets/b9ae9f78-adc2-4b7d-a810-ac639ee7c0d8" width="420px" height="300px"> | <img src="https://github.com/user-attachments/assets/166d0f0b-ee65-4d67-88f7-16cb4cec47f2" width="420px" height="300px"> |
</div>

<br>

#### 센서 배선도

<div align="center">
  <table>
    <tr>
      <td>
        <table>
          <tr>
            <th>**Arduino Mega 2560 1**</th>
            <th>**PM1, PM2, PM3**</th>
          </tr>
          <tr>
            <td>5V</td>
            <td>VCC</td>
          </tr>
          <tr>
            <td>GND</td>
            <td>GND</td>
          </tr>
          <tr>
            <td>D19</td>
            <td>PM1_Tx</td>
          </tr>
          <tr>
            <td>D17</td>
            <td>PM2_Tx</td>
          </tr>
          <tr>
            <td>D15</td>
            <td>PM3_Dx</td>
          </tr>
          <tr>
            <td></td>
            <td><strong>DHT22</strong></td>
          </tr>
          <tr>
            <td>5V</td>
            <td>VCC</td>
          </tr>
          <tr>
            <td>GND</td>
            <td>GND</td>
          </tr>
          <tr>
            <td>D6</td>
            <td>OUT</td>
          </tr>
          <tr>
            <td></td>
            <td><strong>Ozone</strong></td>
          </tr>
          <tr>
            <td>5V</td>
            <td>VCC</td>
          </tr>
          <tr>
            <td>GND</td>
            <td>GND</td>
          </tr>
          <tr>
            <td>D20</td>
            <td>SDA</td>
          </tr>
          <tr>
            <td>D21</td>
            <td>SCL</td>
          </tr>
        </table>
      </td>
      <td>
        <table>
          <tr>
            <th>**Arduino Mega 2560 2**</th>
            <th>**CO, NO2, SO2**</th>
          </tr>
          <tr>
            <td>5V</td>
            <td>VCC</td>
          </tr>
          <tr>
            <td>GND</td>
            <td>GND</td>
          </tr>
          <tr>
            <td>D19</td>
            <td>CO_Tx</td>
          </tr>
          <tr>
            <td>D18</td>
            <td>CO_Rx</td>
          </tr>
          <tr>
            <td>D17</td>
            <td>NO2_Tx</td>
          </tr>
          <tr>
            <td>D16</td>
            <td>NO2_Rx</td>
          </tr>
          <tr>
            <td>D15</td>
            <td>SO2_Tx</td>
          </tr>
          <tr>
            <td>D14</td>
            <td>SO2_Rx</td>
          </tr>
          <tr>
            <td></td>
            <td><strong>Wind Direction</strong></td>
          </tr>
          <tr>
            <td>5V</td>
            <td>VCC</td>
          </tr>
          <tr>
            <td>GND</td>
            <td>GND</td>
          </tr>
          <tr>
            <td>A0</td>
            <td>OUT</td>
          </tr>
          <tr>
            <td></td>
            <td><strong>Wind Speed</strong></td>
          </tr>
          <tr>
            <td>Power Supply 24V</td>
            <td>VCC</td>
          </tr>
          <tr>
            <td>Power Supply GND</td>
            <td>GND</td>
          </tr>
          <tr>
            <td>A1</td>
            <td>OUT</td>
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
| `pm?_x`                  | PM 센서의 X축 위치 (? : PM 센서 ID에 따라, X :  1, 2, 3 중 하나) |
| `pm1_x`                  | PM1 센서의 X축 위치 (1: 상단, 2: 중간, 3: 하단) |
| `pm2_x`                  | PM2 센서의 X축 위치 (1: 상단, 2: 중간, 3: 하단) |
| `pm3_x`                  | PM3 센서의 X축 위치 (1: 상단, 2: 중간, 3: 하단) |






