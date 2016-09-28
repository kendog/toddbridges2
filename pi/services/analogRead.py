#!/usr/bin/python

import serial
ser = serial.Serial('/dev/ttyUSB0', 9600)

import time
 
read = ser.readline()
time.sleep(5)
read = ser.readline()
ser.write('1000')
ser.close()

#print read

line = read.strip(" \t\n\r")
items = line.split("&")


import json
 
myList={}

for item in items:
	tmp = item.split("=")
	if tmp[0] == "A0":
		myList["A0"] = tmp[1]
	elif tmp[0] == "A1":
		myList["A1"] = tmp[1]
	elif tmp[0] == "A2":
		myList["A2"] = tmp[1]
	elif tmp[0] == "A3":
		myList["A3"] = tmp[1]
	elif tmp[0] == "A4":
		myList["A4"] = tmp[1]
	elif tmp[0] == "A5":
		myList["A5"] = tmp[1]
	else:
		item = ""

data = json.dumps(myList)
print data

import requests
url = 'http://localhost/api/api.php?request=analog'

response = requests.post(url, data=data)
print response.content
