from socket import timeout
import cv2
from cv2 import circle
import numpy
import serial
import time
from threading import Thread, Event
from scipy.interpolate import interp1d

event = Event()

def getdata(rawdata):
    while True:
        with serial.Serial('COM5', 9600) as ser:
            
            rawdata[0] = float(ser.readline().strip(b'\r\n').decode("utf-8"))

            #print(rawdata)
        if event.is_set():
            break
        
rawdata = [0]
t = Thread(target=getdata, args= (rawdata, ))
t.start()
cv2.namedWindow("preview")
vc = cv2.VideoCapture(0, cv2.CAP_DSHOW)
strength = 0.4

if vc.isOpened(): # try to get the first frame
    rval, frame = vc.read()
else:
    rval = False


while rval:
    
    ret, frame = vc.read()
    overlay = frame.copy()

    cv2.circle(frame,(310,250),50,(0,0,255),-1)
    final = cv2.addWeighted(overlay, 1-strength , frame, strength, 0)
    cv2.imshow("preview", final)
    rval, frame = vc.read()
    key = cv2.waitKey(20)   
    print(rawdata[0])
    interpoliert = interp1d([0,5],[0,1])
    strength = float(interpoliert(rawdata[0]))
    if key == 27: # exit on ESC
        event.set()
        break

t.join()
vc.release()
cv2.destroyWindow("preview")

