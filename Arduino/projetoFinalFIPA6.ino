//Bibliotecas
#include <LiquidCrystal.h>

//Variáveis LCD
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
String texto1, texto2;


//Variáveis menu
int estado=0;
int sensorValue;
boolean indo=false;

//Variáveis  Módulo 1
int temperatura = 0;
int ler_cooler;
int contadorImprimeTela = 0;

//Variáveis Módulo 2
int potenciometro;

//Variáveis Módulo 3
String inputString = "";
boolean stringComplete = false;
boolean ligado=false;
int convertido;

//Funçoes LCD
void imprimeLcd(LiquidCrystal lcd, String textoCima, String textoBaixo) {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(textoCima);
  lcd.setCursor(0,1);
  lcd.print(textoBaixo);
  delay(10); 
}
//Funções Diversas
int Menor(int menor1,int menor2,int x, int i)
{
  if(x == 0) return (menor2);
  if(menor1 < menor2) menor2 = menor1;
  switch (i) {
    case 0:
      Menor(analogRead(A0),menor2,x-1, i);
    break;
    case 1:
      Menor(analogRead(A1),menor2,x-1, i);
    break;
    case 2:
      Menor(analogRead(A2),menor2,x-1, i);
    break;
    case 3:
      Menor(analogRead(A3),menor2,x-1, i);
    break;
    case 4:
      Menor(analogRead(A4),menor2,x-1, i);
    break;
    case 5:
      Menor(analogRead(A5),menor2,x-1, i);
    break;
  }
}

void zeraPinos() {
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW); 
}

void setup() {
  //Inicializações Menu
  Serial.begin(9600);
  pinMode(6, INPUT);
  //Inicializações LCD
  lcd.begin(16,2);
  //Inicializações Módulo 1
  pinMode(9,OUTPUT);
  pinMode(8,OUTPUT);
  //Inicializações Módulo 2
  pinMode(10,OUTPUT);
  //Inicializações Módulo 3
  inputString.reserve(200);
}

//Módulo 1
void modulo1() {
  temperatura = analogRead(A0);
  temperatura *= 0.48828125;
  //ler_cooler = analogRead(A2);
  ler_cooler = analogRead(A2);
  texto2 = "";
  texto2+="T = ";
  texto2+=temperatura;  
  texto2+= " V = ";
  texto2+= map(ler_cooler,0,500,0,100);
  texto2+= "%";  
  if(temperatura > 29)
  {
    digitalWrite(9,HIGH);
    digitalWrite(8,LOW);
  }
  else
  {
    digitalWrite(9,LOW);
    if(temperatura <= 27)
    {
      digitalWrite(8,HIGH);
    }
    else
    {
      digitalWrite(8,LOW);
    }
  }
  texto1= "Modulo 1";
  if (contadorImprimeTela == 100){
    imprimeLcd(lcd, texto1, texto2);
    contadorImprimeTela = 0;
  }
  else {
    contadorImprimeTela++; 
  }
}

//Módulo 2
void modulo2() {
  potenciometro = analogRead(A5);
  texto1 = "Modulo 2";
  texto2 = "";
  texto2+="P = ";
  texto2+=potenciometro;
  if (potenciometro>=500) {
    digitalWrite(8, LOW);
    analogWrite(9,map(potenciometro,500,1023,0,255));
  }
  else {
    digitalWrite(9, LOW);
    analogWrite(8, map(potenciometro,0,499,0,255));
  }
  imprimeLcd(lcd, texto1, texto2);  
}

//Módulo 3
boolean testaVel(String valor) {
  if (valor=="48"||valor=="49"||valor=="50"||valor=="51"||valor=="52"||valor=="53"||valor=="54"||valor=="55"||valor=="56"||valor=="57") {
    return true;
  }
  return false;
}

int converteVel(String valor) {
  if (valor=="48") return 0; 
  if (valor=="49") return 1; 
  if (valor=="50") return 2; 
  if (valor=="51") return 3; 
  if (valor=="52") return 4; 
  if (valor=="53") return 5; 
  if (valor=="54") return 6; 
  if (valor=="55") return 7; 
  if (valor=="56") return 8; 
  if (valor=="57") return 9; 
}

void modulo3() {
  if (stringComplete) {
    if (inputString=="97") {
      if (ligado) {
        digitalWrite(8, LOW);
        ligado = false; 
      }
      else {
        digitalWrite(8, HIGH);
        ligado = true; 
      }
    }
    stringComplete = false;    
  }
  else if (testaVel(inputString)) {
    convertido = converteVel(inputString);
    analogWrite(9, map(convertido, 0,9,0,255)); 
  }
  texto1 = "Modulo 3";
  texto2 = "LED: ";
  if (ligado) texto2+="ON";
  else texto2+="OFF";
  texto2+= " V= ";
  texto2+= map(convertido, 0, 9, 0, 100);
  imprimeLcd(lcd, texto1, texto2);
}

void serialEvent() {
  while (Serial.available()) {
    String inChar = (String)Serial.read();
    inputString = inChar;    
    stringComplete = true;    
  }
}

void loop() {
  sensorValue = digitalRead(6);
  if (sensorValue==1&&!indo) {
    estado ++;
    indo = true;
    zeraPinos();
  }
  if (indo&&sensorValue==0) {
    indo= false; 
  }
  if(estado>=3) estado=0;
  switch (estado) {
    case 0:
      //Serial.print("Modulo 1");
      modulo1();
    break;
    case 1:
      //Serial.print("Modulo 2");
      modulo2();
    break;
    case 2:
      //Serial.print("Modulo 3");
      modulo3();
    break; 
  } 
}
