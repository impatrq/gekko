#include <Arduino.h>
#line 1 "C:\\Users\\Juani\\Desktop\\Simulacion_Bluetooh_Proteus\\Simulacion_Bluetooth\\Simulacion_Bluetooth.ino"
//bluetooth hc-05
int ledPin = 13; // usamos un pin de salida al LED
int state = 0;   // Variable lectrura dato serial

#line 5 "C:\\Users\\Juani\\Desktop\\Simulacion_Bluetooh_Proteus\\Simulacion_Bluetooth\\Simulacion_Bluetooth.ino"
void setup();
#line 11 "C:\\Users\\Juani\\Desktop\\Simulacion_Bluetooh_Proteus\\Simulacion_Bluetooth\\Simulacion_Bluetooth.ino"
void loop();
#line 5 "C:\\Users\\Juani\\Desktop\\Simulacion_Bluetooh_Proteus\\Simulacion_Bluetooth\\Simulacion_Bluetooth.ino"
void setup() {
    pinMode(ledPin, OUTPUT);   //Declara pin de Salida
    digitalWrite(ledPin, LOW); //Normalmente Apagado
    Serial.begin(9600);
}
 
void loop() {
 
        if(Serial.available() > 0){
             state = Serial.read();
        } 
       
      
       if (state == 'I') {
       
           digitalWrite(ledPin, HIGH);
           state = 0;
       }
      
       if (state == 'O')
       {
           digitalWrite(ledPin, LOW);
           state = 0;
       }

}

