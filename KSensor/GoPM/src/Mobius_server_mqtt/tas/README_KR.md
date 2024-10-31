# tas

## 언어 선택

[English](README.md) | [한국어](README_KR.md)

<br><br>

## 코드 설명
- app.js : 이 코드는 Node.js 스크립트로, 설정 파일을 읽고 Python TCP 서버와 통신을 관리하며 연결 상태를 유지하기 위한 감시(watchdog) 메커니즘을 포함하고 있음
           설정은 XML 파일(`conf.xml`)에서 읽어옴
- conf.xml : `conf.xml`은 시스템의 부모 서버 정보와 데이터 다운로드 설정을 정의하는 XML 파일임, mqtt설정시 꼭 설정해줘야 함
