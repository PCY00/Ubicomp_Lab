# GoPM

## 언어 선택

[English](README.md) | [한국어](README_KR.md)

<br><br>

## 간략 설명
- 각각 팬 3개를 제어하여 3개의 미세먼지 센서의 공기 유입량을 조절하는 기구임
- 여기서 주로 다루는 건 코드 해석 및 하드웨어적으로 어떻게 구성되어있는지를 서술함

<br><br>

## 파일 구조

```
GoPM/
├── src/
│   ├── DAQ/
│   │   └── DAQ.py
│   │
│   ├── Mobius_server_mqtt/
│   │   ├── thyme/
│   │   │   └──  conf.js
│   │   └── tas/
│   │       ├── app.js
│   │       └── conf.xml
│   │   
│   ├── Sensor/
│   │   └── Sensor.ino
│  
├── HW/
│    └── README.md  


```

<br><br>

## 파일 설명

- src : 소스 코드들의 설명과 소스 코드들이 담긴 디렉토리
- HW : 제품의 하드웨어적인 구성도가 저장된 디렉토리
