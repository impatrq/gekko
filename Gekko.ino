#include "SoftwareSerial.h"                   // Para el Bluetooth.                                    
#include "DFRobotDFPlayerMini.h"              // Para la musica.
SoftwareSerial BT1(4,2);                      // RX, TX Del Bluetooth.
SoftwareSerial mySoftwareSerial(10, 11);      // Para la musica.
DFRobotDFPlayerMini myDFPlayer;               // Para la musica.
const int Trigger = 2;                        //Pin digital 2 para el Trigger del sensor.
const int Echo = 3;                           //Pin digital 3 para el Echo del sensor.
float distancia;                              // Distancia que mide el sensor.
const int pinemergencia = 4;                  // Botón pulsado emergencia.
const int pinlocacion = 5;                    // Botón pulsado locacion.
int BotonEmergencia = HIGH;                   // Variables estado de los botones.
int BotonLocacion = HIGH;                     // Variables estado de los botones.
int estado=0;                                 // Estado es 0.
//----------------------------Void Setup--------------------------------------------------------------------------

void setup() 

{
 Serial.begin(9600);                        // El serial empieza a 9600. 
 mySoftwareSerial.begin(9600);              // El serial del audio empieza a 9600.
 if (!myDFPlayer.begin(mySoftwareSerial))   // Si se prende el dfplayer.
  {  
   myDFPlayer.volume(30);                   // Pone el volumen a 30.
  }
 pinMode(pinemergencia, INPUT);            // Boton tocado como entrada.
 pinMode(pinlocacion, INPUT);             // Boton tocado como entrada.             
 pinMode(Trigger, OUTPUT);                 // Declarmos el pin 2 como salida del sensor.
 pinMode(Echo, INPUT);                     // Declaramos el 3 como entrada del sensor.
}
 
//-----------------------------------Void Loop---------------------------------------------------------

void loop()
{  
  long t;                                      //Tiempo que demora en llegar el eco.
  long d;                                     // Distancia en centimetros.                                
  digitalWrite (Trigger, HIGH);               // El prin Trig esta HIGH.                    
  digitalWrite (Trigger, LOW);                // El prin Trig esta LOW. 
  Serial.print (distancia);                   // Imprimimos la distancia en cm.
  t = pulseIn  (Echo, HIGH);                  // Obtenemos el ancho del pulso.
  d = t/59;                                   // Escalamos el tiempo a una distancia en cm.

if (distancia>=200 && distancia<250)         // Si la distancia es mayor a 200 y menor a 250:
{
  Serial.print("Distancia: ");
  Serial.print(d);     
  myDFPlayer.play(1);                        // Reproduce el primer aviso de Obstaculo.
}
if (distancia>=150 && distancia<199)         // Si la distancia es mayor a 150 y menor a 199:
delay(2600);
{
  myDFPlayer.play(2);                        // Reproduce el segundo aviso.   
  delay(2300);      
}
if (distancia >=100 && distancia<149)        // Si la distancia es mayor a 100 y menor a 149:
{
  myDFPlayer.play(3);                        // Reproduce el Tercer aviso.
  delay(2600);
}
if (distancia>=50 && distancia<99)           // Si la distancia es mayor a 50 y menor a 99:
{
  myDFPlayer.play(4);                        // Reproduce el Cuarto aviso.
  delay(2300);
}
if (distancia>=0 && distancia<49)            // Si la distancia es mayor a 0 y menor a 49:
{
  myDFPlayer.play(5);                        // Reproduce el quinto aviso.
  delay(2300);
}
if (distancia>251)                           // Si la distancia es mayor a 251:
{
  myDFPlayer.pause();                        // Pausa el audio.
}
return distancia;

//----------------------------------Aca termina lo del sensor ultrasonico-------------------------------------------

  BotonEmergencia = digitalRead(pinemergencia); // Lee estado del boton de emergencia.
  if(Serial.available()>0)                      // Si hay un serial disponible, entonces...
   {
    estado=Serial.read();                       // Lee el estado del puerto serial.
   }
  BotonLocacion = digitalRead(pinlocacion);     // Lee estado del boton de locacion.
  if(Serial.available()>0)                      // Si hay un serial disponible, entonces...
   {
    estado=Serial.read();                       // Lee el estado del puerto serial.
   }
  if (BotonEmergencia == LOW)                   // SE OPRIMIO EL BOTON DE EMERGENCIA?:
  {
   BT1.println("1");                            // Se manda un 1 a la Aplicacion.
  }
  if (BotonLocacion == LOW)                     // SE OPRIMIO EL BOTON DE LOCACION?:                    
 {
  BT1.println("0");                             // Se manda un 1 a la Aplicacion.
 }
}
