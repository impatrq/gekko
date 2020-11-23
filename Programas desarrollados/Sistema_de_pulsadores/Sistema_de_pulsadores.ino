              
int loc = 8;
int emer = 6;
int locstate = 0;
int emerstate = 0;

void setup(){
    Serial.begin(9600);                        // El serial empieza a 9600.
    pinMode(loc, INPUT);
    pinMode(emer, INPUT);
}

void loop(){
    
    digitalRead(loc);
    digitalRead(emer);

    locstate = digitalRead(loc);
    emerstate = digitalRead(emer);
    
    if(locstate == HIGH){
    Serial.print("l");
    delay(1000);
    } 

    if(emerstate == HIGH){
      Serial.print("e");
      delay(1000);
    }
}
