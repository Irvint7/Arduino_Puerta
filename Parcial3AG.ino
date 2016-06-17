
#include <Servo.h>
Servo myservo; 
int contador = 0;  //Variable para guardar la cuenta de pulsaciones
int contador2=0;
int estadoAnteriorBoton2 = 0;
int estadoAnteriorBoton = 0; //Declaramos e inicializamos la variable
int valorBoton = 0; //Declaramos e inicializamos la variable
int valorBoton2 =0;
int rojo=0;
int PIR = 2; //pin donde esta la salida del sensor.
int val = 0;
//------------------------------------
//Funcion principal
//------------------------------------
void setup() // Se ejecuta cada vez que el Arduino se inicia
{
  Serial.begin(9600);   //Inicia comunicación serie
  pinMode(11,INPUT);    
  pinMode(12,INPUT);
  pinMode(9,OUTPUT);  
  pinMode(10,OUTPUT);
  myservo.attach(8); 
  myservo.write(0);
  pinMode(PIR,INPUT);
  
}

//------------------------------------
//Funcion ciclica
//------------------------------------
void loop() // Esta funcion se mantiene ejecutando
{           //  cuando este alimentado el Arduino

valorBoton=digitalRead(11);
valorBoton2=digitalRead(12);
val = digitalRead(PIR);
int valor ;

if (val == HIGH) {

digitalWrite(10,HIGH);
delay(100);
digitalWrite(10,LOW);
delay(100);
}


if(rojo==0){
digitalWrite(10,HIGH);
myservo.write(0);
}
if(valorBoton!=estadoAnteriorBoton){ //Si hay un cambio de estado, entramos en el if

  if(valorBoton==1){
    contador++; //Aumentamos en una unidad la cuenta
    Serial.println("pulsador 1: ");
    Serial.println(contador); //Imprime el valor por consola
  
  }
}

if(valorBoton2!=estadoAnteriorBoton2){

if(valorBoton2==1){
    contador2++; //Aumentamos en una unidad la cuenta
    Serial.println("Pulsador 2");
    Serial.println(contador2); //Imprime el valor por consola
  
  }
}


if(contador  == 3){
  if(contador2 == 2){
  digitalWrite(9, HIGH);
  digitalWrite(10, LOW);
  contador = 0;
  contador2 = 0;
  rojo = 1;
  myservo.write(180);
  valor=myservo.read();
  Serial.println(valor);
  }
}

if(contador == 4){
  if(contador2 == 3){
  digitalWrite(10,HIGH);
  digitalWrite(9, LOW);
  contador = 0;
  contador2 = 0;
  myservo.write(0);
  rojo=0;
  }
}

if(contador>4 || contador2>3){ //borrar si se excede el numero de pulsos 
contador=0;
contador2=0;
}
estadoAnteriorBoton=valorBoton; //guardamos el estado actual del pulsador para la siguiente iteración
estadoAnteriorBoton2=valorBoton2;
}
