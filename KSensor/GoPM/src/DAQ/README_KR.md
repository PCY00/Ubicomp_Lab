# DAQ

## 언어 선택

[English](README.md) | [한국어](README_KR.md)

<br><br>

## 코드 설명

- 해당 코드는 젯슨나노 기준 1분마다 데이터를 수집하여 모비우스 서버에 값을 올리는 일을함
- 또한 MQTT를 사용하여 사용자 명령을 실시간으로 받아 FAN속도를 제어할 수 있게끔 설계되었음

<br><br>

## 주요 코드 상세 설명

```
apm2_url = 'http://114.71.220.59:2021/Mobius/gw/data'
data_send_url = 'http://114.71.220.59:2021/Mobius/gw/motor'
rpm_url = "http://114.71.220.59:2021/Mobius/gw/RPMData"
FanSpeed_url = "http://114.71.220.59:2021/Mobius/gw/FanSpeed"
```

- apm2_url : 레퍼런스 장비의 데이터와 GoPM, 즉 모듈들이 측정한 값을 모아 데이터를 올리는 컨테이너
- data_send_url : 사용자가 각각의 모듈들의 팬 속도를 제어할 때 명령이 올라가는 컨테이너 ( MQTT Broker )
- rpm_url : 레퍼런스 장비의 측정 값이 올라가는 컨테이너 ( 레퍼런스, 즉 우리한테는 정답지 )
- FanSpeed_url : 사용자가 모듈들을 제어하고 실제로 그 모듈들이 조절한 속도로 도달했는지에 대한 피드백을 받는 컨테이너

<br>

```


```
