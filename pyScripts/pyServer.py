import serial
import socket
import time

TCP_IP = '127.0.0.1'
TCP_PORT = 5005
BUFFER_SIZE = 20  # Normally 1024, but we want fast response

ser = serial.Serial('COM3', 9600) 

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.bind((TCP_IP, TCP_PORT))
s.listen(1)

while True:
    conn, addr = s.accept()
    print ("Connection address: ", addr)
    data = conn.recv(BUFFER_SIZE).decode("utf-8") 
    if data != "":
      if data == "1":
        print ("Turning RED led ON!")
        ser.write(b'1')
      elif data == "2":
        print ("Turning RED led OFF!")
        ser.write(b'2')
      elif data == "3":
        print ("Turning GREEN led ON!")
        ser.write(b'3')
      elif data == "4":
        print ("Turning GREEN led OFF!")
        ser.write(b'4')
      elif data == "5":
        print ("Turning YELLOW led ON!")
        ser.write(b'5')
      elif data == "6":
        print ("Turning TELLOW led OFF!")
        ser.write(b'6')
      else:
        print ("I don't know what someone sent")
      data = ""

conn.close()
s.close()
