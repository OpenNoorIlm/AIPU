import serial
import socket
import threading
import time

SERIAL_PORT = '/dev/ttyUSB0'
BAUD = 115200
TCP_PORT = 3335

ser = serial.Serial(SERIAL_PORT, BAUD, timeout=0.1)

# Flush any startup garbage from ESP32
time.sleep(2)
ser.reset_input_buffer()
ser.reset_output_buffer()
print("Serial port ready")

def handle_client(conn):
    print("Client connected")
    ser.reset_input_buffer()
    try:
        while True:
            data = conn.recv(1024)
            if not data:
                break
            for byte in data:
                c = chr(byte)
                if c == 'R':
                    ser.write(b'R')
                    ser.flush()
                    resp = b''
                    timeout = 0
                    while not resp and timeout < 100:
                        resp = ser.read(1)
                        timeout += 1
                    if resp:
                        conn.send(resp)
                    else:
                        conn.send(b'0')
                elif c in ('B', 'b', 'Q', 'q'):
                    pass
                elif '0' <= c <= '7':
                    ser.write(bytes([byte]))
                    ser.flush()
    except Exception as e:
        print(f"Error: {e}")
    finally:
        conn.close()
        print("Client disconnected")

server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
server.bind(('localhost', TCP_PORT))
server.listen(1)
print(f"Listening on port {TCP_PORT}...")

while True:
    conn, addr = server.accept()
    t = threading.Thread(target=handle_client, args=(conn,))
    t.daemon = True
    t.start()
