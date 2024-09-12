# V1 code

## 사용된 HardWare
- Arduino DUE
- 모터 : NEX-16002 DC Motor (Coreless Motor)
- 모터 드라이버 : L298N
- 바퀴 : 메카넘휠
 
<br><br>

## 코드 설명

### Control_4WD
- 모터 드라이버 2개로 바퀴 4개를 전부 구동 시킴

### Directional_Mobility
- 각각의 바퀴를 각각의 모터 드라이버 연결해서 구동

### boost_mode_4WD
- 부스터 모드를 넣어 속도를 조절할 수 있음

### standing_tornado
- 제자리에서 돌 수 있는 모드

### test_encoder
- 모빌리티의 정확한 위치 피드백을 위해 시도한 엔코더 피드백
