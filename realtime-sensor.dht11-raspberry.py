import cayenne.client
import time
import Adafruit_DHT
sensor= Adafruit_DHT.DHT11
gpio_pin=26

# Cayenne authentication info. This should be obtained from the Cayenne Dashboard.
MQTT_USERNAME  = "62e61850-0c91-11eb-8779-7d56e82df461"
MQTT_PASSWORD  = "bc31107f237d4aee0739e05a620ca6c13120f681"
MQTT_CLIENT_ID = "6734a850-0d49-11eb-8779-7d56e82df461"

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
    humitat, temp = Adafruit_DHT.read_retry(sensor, gpio_pin)
    time.sleep(2)
    client.loop()
    client.virtualWrite(0,temp)
    client.virtualWrite(1,humitat)

  except KeyboardInterrupt:
    break
sys.exit()