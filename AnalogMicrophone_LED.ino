/*
Name: Modul KY-037 Big Microphone

Pin anschluss: (Links Mic. || Rechts ESP8266)
A0  -> A0
GND -> GND
+   -> 3V3
D0  -> D4

code by Nico.N
*/
int sensorPin = A0;  // denn input A0 als "sensorPin festlegen"
int ledPin = D4;     // Denn LED Pin festlegen der aufleuchten soll
int sensorValue = 0; // die variable die vom sennsor kommt

void setup ()
{
  pinMode (ledPin, OUTPUT);   //ledPin (denn vorher festgelegten D pin auswählen als Output
  Serial.begin (115200);      //die Baud rate im Seriellen Monitor
}

void loop ()
{
  sensorValue = analogRead (sensorPin);    //wenn die Sensor Value unter 484,
  if (sensorValue < 484)                   //(die Value muss jeh nach Mic. sehr wahrscheinlich angepaast werden.)
  {
    digitalWrite (ledPin, HIGH);           //Dann soll die LED aus bleiben (HIGH weil es am chip verkehrt herum ist)
    //delay (sensorValue);                                                                                              //(wenn man einen delay haben möchte in ms was in denn Monitor reinkamm auskommentieren)
    Serial.println (sensorValue, DEC);     //(die Value in denn Serieln Monitor schreiben... zum anpassen)
    delay(5);
  }
  else                                     //wenn nicht unter 484,
  {
    digitalWrite (ledPin, LOW);            //dann die LED einschalten und
    //delay (sensorValue);
    Serial.println (sensorValue, DEC);
    delay(600);                            //einen delay von 600ms damit die LED länger anbleibt und nicht nur 1ms
  }
}

