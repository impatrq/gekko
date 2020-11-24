//bluetooth hc-05
int led13 = 13; // usamos un pin de salida al LED
int pin7 = 7;
int state = 0;   // Variable lectrura dato serial

void setup() {
    pinMode(led13, OUTPUT);   //Declara pin de Salida
    pinMode(pin7, INPUT);
    digitalWrite(led13, LOW); //Normalmente Apagado
    Serial.begin(9600);
}
 
void loop()
{
 if(Serial.available() > 0)
        {
             state = Serial.read();
        } 
        
  if (digitalRead(7)== 1)
  {
    state == 1;
    digitalWrite(13, HIGH);
    Serial.println("Señal GPS Activada");
  }
  else
  {
    state == 0;
    digitalWrite(13, LOW);
    Serial.println("Sin señal");
  }
         
            
}
