int Enviados[] = {0,0}; //Hacemos un arreglo para los datos a enviar
int led13 = 13; //Declaramos el pin del LED
char entrada; //Declaramos una variables para los datos de entrada
 
//El tiempo que se demora en enviar un nuevo dato a la aplicacion
unsigned long TiempoAhora = 0; //Variable para determinar el tiempo transcurrido

void setup() {
  pinMode(led13, OUTPUT); //Declaramos el pin del LED como salida
  Serial.begin(9600);   //Declaramos el puerto Serie

}

void loop() {
 
if (Serial.available()>0){ //Si hay datos enviados por la aplicacion
    entrada=Serial.read(); //Leemos los datos recibidos
    

    if(entrada=='A') {  //Si el dato recibido es A, se enciende el led
      digitalWrite(led13, HIGH);
      Enviados[0] = 1;  //Modificamos en el la posicion 1 del arreglo el estado del led con 0 o 1
    }
    
    if(entrada=='B') {  //Si el dato recibido es B, se apaga el led
      digitalWrite(led13, LOW);
      Enviados[0] = 0;  //Modificamos en el la posicion 0 del arreglo el estado del led con 0 o 1
      
    }
  }

     }
