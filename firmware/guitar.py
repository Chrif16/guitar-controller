import socket
import pyautogui
import time

HOST='0.0.0.0'
PORT=5005

server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server_socket.bind((HOST,PORT))
server_socket.listen(1)
conn, addr = server_socket.accept()
buffer =""

while True:
     try:
         data=conn.recv(1024).decode('itf-8')
         if not data:
               conn , addr = server_socket.accept()
               continue
         buffer += data
         while"\n" in buffer:
             line,buffer = buffer.split("\n",1)
             x = line.strip()
             if x=="pin0":
                pyautogui.press('a')
                time.sleep(0.3)  
             elif x=="pin1":
                pyautogui.press('z')
                time.sleep(0.3)  
             elif x=="pin2":
                pyautogui.press('e')
                time.sleep(0.3)  
             elif x=="pin3":
                pyautogui.press('r')
                time.sleep(0.3)
     except Exception as e:
         conn , addr = server_socket.accept()
 