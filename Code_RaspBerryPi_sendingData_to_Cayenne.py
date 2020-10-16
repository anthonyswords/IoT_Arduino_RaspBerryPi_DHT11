
#---------------REMEMBER TO CREATE AND EXECUTE THIS FILE IN RASPBERRY PI (NANO)-----------------------------------
import cayenne.client
import time
import Adafruit_DHT
import sys
import serial
# Cayenne authentication info. This should be obtained from the Cayenne Dashboard.
MQTT_USERNAME  = "62e61850-0c91-11eb-8779-7d56e82dfxxx" #look in Cayanne - option Create your own device -
MQTT_PASSWORD  = "bc31107f237d4aee0739e05a620ca6c13120fxxx" #look in Cayanne - option Create your own device -
MQTT_CLIENT_ID = "6734a850-0d49-11eb-8779-7d56e82dfxxx" #look in Cayanne - option Create your own device -

# Serial from USB Arduino, other words, the data that we received from arudino (through USB Arduino) to Raspberry Pi.
ser= serial.Serial('/dev/ttyAMC0') #for further information to understand wich PORT USB communication that we establish between Arduino and Raspberry Pi: https://diyi0t.com/arduino-to-raspberry-pi-serial-communication/
regex = re.compile("[0-9]{2}\.[0-9]{2}") #regex style to read the number values from temp or humidity recieved by Arduino, in other words, find the units and decimals.

# The callback for when a message is received from Cayenne.
def on_message(message):
  print("message received: " + str(message))
  # If there is an error processing the message return an error string, otherwise return nothing.

client = cayenne.client.CayenneMQTTClient()
client.on_message = on_message
client.begin(MQTT_USERNAME, MQTT_PASSWORD, MQTT_CLIENT_ID)
# For a secure connection use port 8883 when calling client.begin:
# client.begin(MQTT_USERNAME, MQTT_PASSWORD, MQTT_CLIENT_ID, port=8883)



while True:
  try:
    data_from_arduino_reading = ser.readline() 
    if "Temperature" in data_from_arduino_reading.decode():
        catching_temperature_value = float(regex.findall(str(data))[0])
    if "Humidity" in data_from_arduino_reading.decode():
        catching_humidity_value = float(regex.findall(str(data))[0])
    time.sleep(2) #important for not get a collapse of data to Cayenne server.
    client.loop()
    client.virtualWrite(0,temp)
    client.virtualWrite(1,humitat)

  except:
    pass
sys.exit()