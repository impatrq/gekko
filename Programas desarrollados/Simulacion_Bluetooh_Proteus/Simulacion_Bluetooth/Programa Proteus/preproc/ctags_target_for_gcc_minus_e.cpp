# 1 "C:\\Users\\Juani\\Desktop\\Simulacion_Bluetooh_Proteus\\Simulacion_Bluetooth\\Simulacion_Bluetooth.ino"
//bluetooth hc-05
int ledPin = 13; // usamos un pin de salida al LED
int state = 0; // Variable lectrura dato serial

void setup() {
    pinMode(ledPin, 0x1); //Declara pin de Salida
    digitalWrite(ledPin, 0x0); //Normalmente Apagado
    Serial.begin(9600);
}

void loop() {

        if(Serial.available() > 0){
             state = Serial.read();
        }


       if (state == 'I') {

           digitalWrite(ledPin, 0x1);
           state = 0;
       }

       if (state == 'O')
       {
           digitalWrite(ledPin, 0x0);
           state = 0;
       }

}
