# tas

## Language Selection

[English](README.md) | [한국어](README_KR.md)

<br><br>

## Code Overview
- **app.js**: This is a Node.js script that reads configuration files, manages communication with a Python TCP server, and includes a watchdog mechanism to maintain connection stability. Configuration settings are loaded from an XML file (`conf.xml`).
- **conf.xml**: This XML file defines server information and data download settings, which must be configured, especially for MQTT use.

<br><br>

## Key Code Explanations in app.js

### This function receives the **`comm_num`** parameter to communicate with the Python server and control an LED.

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

1. Connection to the Python TCP Server: Uses net.Socket() to connect to the localhost on port 12345, sends data, then closes the connection.
2. Error Handling: Logs an error message if the server connection fails.
3. Connection Status Check: Attempts to connect to the Python server only if status is set to 1.
