#include "SoftwareSerial.h"                                                     
#include "DFRobotDFPlayerMini.h"              // Incluimos la librería del DFPlayer Mini.
SoftwareSerial mySoftwareSerial(10, 11);      // Declaramos la comunación serial con el DFPlayer MINI (TX, RX)
DFRobotDFPlayerMini myDFPlayer;               
int pinTrig = 2;                              // Indicamos que el pin Trigger del HC-SR04 será conectado al pin digital 2 del Arduino.
int pinEcho = 3;                              // Indicamos que el pin Echo del HC-SR04 será conectado al pin digital 3 del Arduino.
float tiempo_de_espera;                       // Tiempo de espera del sensor.
float distancia;                              // Distancia que mide el sensor.
int loc = 8;                                  // Declaro que en el pin 8 va a estar la entrada del pulsador de localización.
int emer = 6;                                 // Declaro que en el pin  va a estar la entrada del pulsador de emergencia.
int locstate;                                 // Declaro el estado de localización.
int emerstate;                                // Declaro el estado de emergencia.

void setup() 

{
 mySoftwareSerial.begin(9600);              // El serial del audio empieza a 9600.
 if (!myDFPlayer.begin(mySoftwareSerial))   // Si se prende el dfplayer.
 myDFPlayer.volume(30);                     // Establecemos el volumen en 30.
 Serial.begin(9600);                        // El serial empieza a 9600.
 pinMode (pinTrig, OUTPUT);                 // Declarmos el pin 2 como salida del sensor.
 pinMode (pinEcho, INPUT);                  // Declaramos el 3 como entrada del sensor.
 pinMode(loc, INPUT);                       // Declaro el pin de loc como entrada.
 pinMode(emer, INPUT);                      // Declaro el pin de emer como entrada.
}

void loop()
{                                  
  digitalWrite (pinTrig, HIGH);                                   
  digitalWrite (pinTrig, LOW);                 
  tiempo_de_espera = pulseIn (pinEcho,HIGH);  // Esto es para la señal del TRIG.
  distancia =(tiempo_de_espera/2)/29.15;      // Mide la distancia.
  Serial.print (distancia);                   // Imprimimos la distancia en cm.
  Serial.println ("cm");                      // Imprimimos la distancia en cm.
  digitalRead(loc);
  digitalRead(emer);

  locstate = digitalRead(loc);                // Locstate depende del valor leído en el pin de loc.
  emerstate = digitalRead(emer);              // Emerstate depende del valor leído en el pin de emer.
  
if(locstate == HIGH){
   Serial.println("l");                       // Cuando se oprima el pulsador de localización, se imprime en el serial "l".
} 
if(emerstate == HIGH){                        // Cuando se oprima el pulsador de emergencia, se imprime en el serial "e".
   Serial.println("e");
}

if (distancia>=200 && distancia<250)         // Si la distancia es mayor o igual a 200 y menor a 250:
{
  myDFPlayer.play(1);                        // Reproduce el primer aviso.
  delay(2600);
}
if (distancia>=150 && distancia<199)         // Si la distancia es mayor o igual a 150 y menor a 199:
{
  myDFPlayer.play(2);                        // Reproduce el segundo aviso.         
  delay(2300);
}
if (distancia >=100 && distancia<149)        // Si la distancia es mayor o igual a 100 y menor a 149:
{
  myDFPlayer.play(3);                        // Reproduce el tercer aviso.
  delay(2600);
}
if (distancia>=50 && distancia<99)           // Si la distancia es mayor o igual a 50 y menor a 99:
{
  myDFPlayer.play(4);                        // Reproduce el cuarto aviso.
  delay(2300);
}
if (distancia>=0 && distancia<49)            // Si la distancia es mayor o igual a 0 y menor a 49:
{
  myDFPlayer.play(5);                        // Reproduce el quinto aviso.
  delay(2300);
}
if (distancia>251)                           // Si la distancia es mayor a 251:
{
  myDFPlayer.pause();                        // Pausa el audio.
  delay(2100);
}
return distancia;

}
