#!/usr/bin/python

import serial
import time


ser = serial.Serial('/dev/ttyUSB0', 9600)
time.sleep(2)
ser.write('0')