import serial
import re
import matplotlib.pyplot as plt
import datetime
import time

 
ser =serial.Serial('COM3',9600,timeout=0.5) 
regex= re.compile("[0-9]{2}\.[0-9]{2}")
ser.close()
ser.open()


while True:

    plt.title("Gràfic Humitat")
    plt.ion()
    t1=plt.text(10,110,"",fontsize=12)
    t2=plt.text(10,102,"",fontsize=12)
    xdata=[]
    ydata=[]
    axes=plt.gca()
    axes.set_xlim(1,12)
    axes.set_ylim(0,100)
    
    line, = axes.plot(xdata,ydata,'r-')
    i=0
    
    while i<13:
        data=ser.readline()
        if "Hum" in data.decode():
            i += 1
            xdata.append(i)
            ydata.append(float(regex.findall(str(data))[0]))
            line.set_xdata(xdata)
            line.set_ydata(ydata)
            currentDT=datetime.datetime.now()
            t1.set_text(str(currentDT.hour)+':'+str(currentDT.minute)+':'+str(currentDT.second))
            t2.set_text(regex.findall(str(data)[0]+" %"))
            plt.plot()
            plt.pause(1e-17)
    plt.clf()