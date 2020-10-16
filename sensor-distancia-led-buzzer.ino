/*
 * Sensor de ultrasonidos como alarma
 * Version de codigo sin usar librerias
 * 
 * https://www.proyectoarduino.com
 *
 */
const int pinBuzzer = 9; 
const int pinEcho = 2;
const int pinTrigger = 3;
const int pinLed = 13;
const int distanciaAlarma = 50; // Valor en centimetros

int sensor(int pinTrigger, int pinEcho) 
{
  long duracionPulso, distancia;

  // Iniciamos el sensor enviando un pulso alto
  // al pin trigger por un lapso de 10uS
  digitalWrite(pinTrigger, HIGH);
  delayMicroseconds(1);

  // Prepara el sensor enviando un pulso bajo al trigger
  digitalWrite(pinTrigger, LOW);
  delayMicroseconds(5);

  // Envia el pulso de trigger por 10uS
  digitalWrite(pinTrigger, HIGH);
  delayMicroseconds(10);

  // Finaliza el pulso de trigger
  digitalWrite(pinTrigger, LOW);

  // Tomamos medida del ancho del pulso en el pin echo
  duracionPulso = pulseIn(pinEcho, HIGH);

  // La lectura del pulso esta en microsegundos
  // Obtenemos lectura de distancia en centimetros
  distancia = duracionPulso / 58;  
    
  return distancia;
} 
void setup() 
{
  // Inicia la consola
  Serial.begin(9600);

  // Configura los pines de control del sensor
  pinMode(pinEcho, INPUT);
  pinMode(pinTrigger, OUTPUT);

  // Configura el pin del led
  pinMode(pinLed, OUTPUT);
}
 
void loop() 
{
  // Iniciamos lectura de la distancia
  int distancia = sensor(pinTrigger, pinEcho);

  if (distancia <= distanciaAlarma)
  {
    digitalWrite(pinLed, HIGH);
    // Presenta los resultados
    Serial.println("¡ALARMA! Objeto muy cercano.");
    piratas_del_caribe();
    delay(1000);
    
  }
  else
  {
    digitalWrite(pinLed, LOW);
    noTone(pinBuzzer);
  }

  // Espera un segundo y vuelta a empezar
  delay(1000);
}


void piratas_del_caribe()
{
  /*tone(9,293.66,200);
  delay(200);
  #tone(9,293.66,100);
  #delay(100);
  #tone(9,293.66,200);
  #delay(200);
  #tone(9,293.66,100);
  #delay(100);
  #tone(9,293.66,200);
  #delay(200);
  #tone(9,293.66,100);
  #delay(100);
  #tone(9,293.66,100);
  #delay(100);
  #tone(9,293.66,100);
  #delay(100);
  #tone(9,293.66,100);
  #delay(100);
  #tone(9,293.66,200);
  #delay(200);
  #tone(9,293.66,100);
  #delay(100);
  #tone(9,293.66,200);
  #delay(200);
  #tone(9,293.66,100);
  #delay(100);
  #tone(9,293.66,200);
  #delay(200);
  #tone(9,293.66,100);
  #delay(100);
  #tone(9,293.66,100);
  #delay(100);
  #tone(9,293.66,100);
  #delay(100);
  #tone(9,293.66,100);
  #delay(100);
  #tone(9,293.66,200);
  #delay(200);
  #tone(9,293.66,100);
  #delay(100);
  #tone(9,293.66,200);
  #delay(200);
  #tone(9,293.66,100);
  #delay(100);
  tone(9,293.66,200);
  delay(200);
  tone(9,293.66,100);
  delay(100);*/
  tone(9,293.66,100);
  delay(100);
  tone(9,440,100);
  delay(100);
  tone(9,523.25,100);
  delay(100);
  tone(9,587.33,100);
  delay(200);
  tone(9,587.33,100);
  delay(200);
  tone(9,587.33,100);
  delay(100);
  tone(9,659.25,100);
  delay(100);
  tone(9,698.45,100);
  delay(200);
  tone(9,698.45,100);
  delay(200);
  tone(9,698.45,100);
  delay(100);
  tone(9,783.99,100);
  delay(100);
  tone(9,659.25,100);
  delay(200);
  tone(9,659.25,100);
  delay(200);
  tone(9,587.33,100);
  delay(100);
  tone(9,523.25,100);
  delay(100);
  tone(9,523.25,100);
  delay(100);
  tone(9,587.33,100);
  delay(300);
  tone(9,440,100);
  delay(100);
  tone(9,523.25,100);
  delay(100);
  tone(9,587.33,100);
  delay(200);
  tone(9,587.33,100);
  delay(200);
  tone(9,587.33,100);
  delay(100);
  tone(9,659.25,100);
  delay(100);
  tone(9,698.45,100);
  delay(200);
  tone(9,698.45,100);
  delay(200);
  tone(9,698.45,100);
  delay(100);
  tone(9,783.99,100);
  delay(100);
  tone(9,659.25,100);
  delay(200);
  tone(9,659.25,100);
  delay(200);
  tone(9,587.33,100);
  delay(100);
  tone(9,523.25,100);
  delay(100);
  tone(9,587.33,100);
  delay(400);
  tone(9,440,100);
  delay(100);
  tone(9,523.25,100);
  delay(100);
  tone(9,587.33,100);
  delay(200);
  tone(9,587.33,100);
  delay(200);
  tone(9,587.33,100);
  delay(100);
  tone(9,698.45,100);
  delay(100);
  tone(9,783.99,100);
  delay(200);
  tone(9,783.99,100);
  delay(200);
  tone(9,783.99,100);
  delay(100);
  tone(9,880,100);
  delay(100);
  tone(9,932.33,100);
  delay(200);
  tone(9,932.33,100);
  delay(200);
  tone(9,880,100);
  delay(100);
  tone(9,783.99,100);
  delay(100);
  tone(9,880,100);
  delay(100);
  tone(9,587.33,100);
  delay(300);
  tone(9,587.33,100);
  delay(100);
  tone(9,659.25,100);
  delay(100);
  tone(9,698.45,100);
  delay(200);
  tone(9,698.45,100);
  delay(200);
  tone(9,783.99,100);
  delay(200);
  tone(9,880,100);
  delay(100);
  tone(9,587.33,100);
  delay(300);
  tone(9,587.33,100);
  delay(100);
  tone(9,698.45,100);
  delay(100);
  tone(9,659.25,100);
  delay(200);
  tone(9,659.25,100);
  delay(200);
  tone(9,698.45,100);
  delay(100);
  tone(9,587.33,100);
  delay(100);
  tone(9,659.25,100);
  delay(400);
  tone(9,880,100);
  delay(100);
  tone(9,1046.50,100);
  delay(100);
  tone(9,1174.66,100);
  delay(200);
  tone(9,1174.66,100);
  delay(200);
  tone(9,1174.66,100);
  delay(100);
  tone(9,1318.51,100);
  delay(100);
  tone(9,1396.91,100);
  delay(200);
  tone(9,1396.91,100);
  delay(200);
  tone(9,1396.91,100);
  delay(100);
  tone(9,1567.98,100);
  delay(100);
  tone(9,1318.51,100);
  delay(200);
  tone(9,1318.51,100);
  delay(200);
  tone(9,1174.66,100);
  delay(100);
  tone(9,1046.50,100);
  delay(100);
  tone(9,1046.50,100);
  delay(100);
  tone(9,1174.66,100);
  delay(300);
  tone(9,880,100);
  delay(100);
  tone(9,1046.50,100);
  delay(100);
  tone(9,1174.66,100);
  delay(200);
  tone(9,1174.66,100);
  delay(200);
  tone(9,1174.66,100);
  delay(100);
  tone(9,1318.51,100);
  delay(100);
  tone(9,1396.91,100);
  delay(200);
  tone(9,1396.91,100);
  delay(200);
  tone(9,1396.91,100);
  delay(100);
  tone(9,1567.98,100);
  delay(100);
  tone(9,1318.51,100);
  delay(200);
  tone(9,1318.51,100);
  delay(200);
  tone(9,1174.66,100);
  delay(100);
  tone(9,1046.50,100);
  delay(100);
  tone(9,1174.66,100);
  delay(400);
  tone(9,880,100);
  delay(100);
  tone(9,1046.50,100);
  delay(100);
  tone(9,1174.66,100);
  delay(200);
  tone(9,1174.66,100);
  delay(200);
  tone(9,1174.66,100);
  delay(100);
  tone(9,1396.91,100);
  delay(100);
  tone(9,1567.98,100);
  delay(200);
  tone(9,1567.98,100);
  delay(200);
  tone(9,1567.98,100);
  delay(100);
  tone(9,1760,100);
  delay(100);
  tone(9,1864.66,100);
  delay(200);
  tone(9,1864.66,100);
  delay(200);
  tone(9,1760,100);
  delay(100);
  tone(9,1567.98,100);
  delay(100);
  tone(9,1760,100);
  delay(100);
  tone(9,1174.66,100);
  delay(300);
  tone(9,1174.66,100);
  delay(100);
  tone(9,1318.51,100);
  delay(100);
  tone(9,1396.91,100);
  delay(200);
  tone(9,1396.91,100);
  delay(200);
  tone(9,1567.98,100);
  delay(200);
  tone(9,1760,100);
  delay(100);
  tone(9,1174.66,100);
  delay(300);
  tone(9,1174.66,100);
  delay(100);
  tone(9,1396.91,100);
  delay(100);
  tone(9,1318.51,100);
  delay(200);
  tone(9,1318.51,100);
  delay(200);
  tone(9,1174.66,100);
  delay(100);
  tone(9,1108.73,100);
  delay(100);
  tone(9,1174.66,100);
  delay(200);
  tone(9,1174.66,100);
  delay(200);
  tone(9,1318.51,100);
  delay(200);
  tone(9,1396.91,100);
  delay(200);
  tone(9,1396.91,100);
  delay(100);
  tone(9,1396.91,100);
  delay(100);
  tone(9,1567.98,100);
  delay(200);
  tone(9,1760,300);
  delay(400);
  tone(9,1396.91,100);
  delay(100);
  tone(9,1174.66,100);
  delay(100);
  tone(9,880,300);
  delay(600);
  tone(9,1864.66,300);
  delay(400);
  tone(9,1396.91,100);
  delay(100);
  tone(9,1174.66,100);
  delay(100);
  tone(9,932.33,300);
  delay(600);
  tone(9,587.33,100);
  delay(100);
  tone(9,440,100);
  delay(200);
  tone(9,587.33,100);
  delay(300);
  tone(9,554.36,100);
  delay(400);
  tone(9,1567.98,100);
  delay(100);
  tone(9,1567.98,100);
  delay(100);
}
