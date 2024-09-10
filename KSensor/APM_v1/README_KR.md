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

### 배선도

| Device                | Pin               | Arduino Mega 2560 1 | Pin  | Arduino Mega 2560 2 | Pin |
|-----------------------|-------------------|---------------------|------|---------------------|------|
| **PM1**                | 5V                | VCC                 |      |                     |      |
|                       | GND               | GND                 |      |                     |      |
|                       | D19               | PM1_Tx              |      |                     |      |
| **PM2**                | 5V                | VCC                 |      |                     |      |
|                       | GND               | GND                 |      |                     |      |
|                       | D17               | PM2_Tx              |      |                     |      |
| **PM3**                | 5V                | VCC                 |      |                     |      |
|                       | GND               | GND                 |      |                     |      |
|                       | D15               | PM3_Dx              |      |                     |      |
| **DHT22**              | 5V                | VCC                 |      |                     |      |
|                       | GND               | GND                 |      |                     |      |
|                       | D6                | OUT                 |      |                     |      |
| **SEN0321 (Ozone)**    | 5V                | VCC                 |      |                     |      |
|                       | GND               | GND                 |      |                     |      |
|                       | D20               | SDA                 |      |                     |      |
|                       | D21               | SCL                 |      |                     |      |
| **CO**                 | 5V                |                     |      | VCC                 |      |
|                       | GND               |                     |      | GND                 |      |
|                       | D19               |                     |      | CO_Tx               |      |
|                       | D18               |                     |      | CO_Rx               |      |
| **NO2**                | 5V                |                     |      | VCC                 |      |
|                       | GND               |                     |      | GND                 |      |
|                       | D17               |                     |      | NO2_Tx              |      |
|                       | D16               |                     |      | NO2_Rx              |      |
| **SO2**                | 5V                |                     |      | VCC                 |      |
|                       | GND               |                     |      | GND                 |      |
|                       | D15               |                     |      | SO2_Tx              |      |
|                       | D14               |                     |      | SO2_Rx              |      |
| **Wind Direction**     | 5V                |                     |      | VCC                 |      |
|                       | GND               |                     |      | GND                 |      |
|                       | A0                |                     |      | OUT                 |      |
| **Wind Speed**         | 파워서플라이 (24V) |                     |      | VCC                 |      |
|                       | 파워서플라이 (GND) |                     |      | GND                 |      |
|                       | A1                |                     |      | OUT                 |      |


