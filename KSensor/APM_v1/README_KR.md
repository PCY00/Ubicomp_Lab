# APM_v1
## 언어 선택

[English](README.md) | [한국어](README_KR.md)

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





