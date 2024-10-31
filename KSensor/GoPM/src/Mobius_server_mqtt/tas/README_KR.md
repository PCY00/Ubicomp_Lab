# tas

## 언어 선택

[English](README.md) | [한국어](README_KR.md)

<br><br>

## 코드 설명
- app.js : 이 코드는 Node.js 스크립트로, 설정 파일을 읽고 Python TCP 서버와 통신을 관리하며 연결 상태를 유지하기 위한 감시(watchdog) 메커니즘을 포함하고 있음
           설정은 XML 파일(`conf.xml`)에서 읽어옴
- conf.xml : `conf.xml`은 시스템의 부모 서버 정보와 데이터 다운로드 설정을 정의하는 XML 파일임, mqtt설정시 꼭 설정해줘야 함

<br><br>

## app.js 중요 코드만 설명

### 이 함수는 **`comm_num`** 파라미터를 받아 Python 서버와 통신하여 LED를 제어함

```
function control_led(comm_num) {
    const inputData = comm_num;

    // Indicating that the control_led function has been called
    console.log(`control_led called with data: ${inputData}`);

    if (status === 1) {
        // Connect to Python TCP server
        const client = new net.Socket();
        client.connect(12345, 'localhost', function () {
            console.log('Connected to Python server');
            client.write(inputData + '\n', () => {
                // 데이터를 보낸 후 연결 종료
                client.end();
            });
        });

        client.on('data', function (data) {
            console.log('Received: ' + data);
        });

        client.on('close', function () {
            console.log('Connection closed');
        });

        client.on('error', function (err) {
            console.error('Failed to connect to Python server:', err);
        });
    } else {
        console.log('Status is not 1, skipping Python script execution');
    }
}
```

1. **Python TCP 서버에 연결**: `net.Socket()`을 사용하여 로컬 호스트의 12345 포트에 연결하고, 데이터를 보낸 후 연결을 종료함
2. **오류 처리**: 서버 연결 실패 시 오류 메시지를 출력함
3. **연결 상태 확인**: `status`가 1일 때만 Python 서버와의 연결을 시도함
