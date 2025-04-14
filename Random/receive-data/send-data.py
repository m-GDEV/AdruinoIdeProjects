import serial
import time
import sys

ser = serial.Serial('/dev/ttyUSB0', 115200)
ser.write(input().encode('ascii'))  # or use input()
time.sleep(0.1)
ser.close()
