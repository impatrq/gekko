#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"

SoftwareSerial mySoftwareSerial(9, 10); // TX, RX. establecemos los pines TX y RX para trabajar con el DFPLAYER Mini.
DFRobotDFPlayerMini myDFPlayer; // esta es la conexión entre la librería y el programa.

int pinTrig = 2; // asignamos el pin 2 del Arduino para el Trigger del sensor ultrasónico.
int pinEcho = 3; // asignamos el pin 3 del Arduino para el Echo del sensor ultrasónico.
int led1 = 4; //led en el pin 4
float tiempo_de_espera; // declaramos la existencia de un tiempo de espera.
float distancia; // declaramos la existencia de una distancia.

void setup() {
  mySoftwareSerial.begin(9600); // establecemos el código de comunicación entre el Arduino y el DFPLAYER Mini.
  Serial.begin (9600);   // establemos la comucicacion serial.
  pinMode (pinTrig, OUTPUT); // declarmos el pin 2 como salida.
  pinMode (pinEcho, INPUT);   // declaramos el 3 como entrada.

}
void loop() {
digitalWrite (pinTrig,LOW); // ponemos en bajo el pin 2 durante 2 microsegundos.
delayMicroseconds(2);
digitalWrite (pinTrig, HIGH);// ahora ponemos en alto pin 2 durante 10 microsegundos.
delayMicroseconds (10);     // pues este el momento en que emite el sonido durante 10 segungos.
digitalWrite (pinTrig, LOW); // ahora ponemos en bajo pin 2.

tiempo_de_espera = pulseIn (pinEcho,HIGH); // pulseIn, recoge la señal del sonido que emite el pinTrig.

distancia =(tiempo_de_espera/2)/29.15; // formula para hallar la distancia.

Serial.print (distancia);    // imprimimos la distancia en cm.
Serial.println ("cm");
delay (1000);

if (distancia>=40 && distancia<75){
  myDFPlayer.play(1);  // reproduce el primer aviso.
  delay(1000);
}

if (distancia>76){
  myDFPlayer.pause();  // pausa o detiene los avisos.
  delay(1000);
}
return distancia;
}
