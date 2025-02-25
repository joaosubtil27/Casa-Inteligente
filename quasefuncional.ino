
#define BLYNK_TEMPLATE_ID "TMPL2oBTUo08S"
#define BLYNK_TEMPLATE_NAME "pic1"
#define BLYNK_AUTH_TOKEN "sc-rMH4-5lgXbUn8vyISntzmLS3vUUI1"
#define BLYNK_PRINT Serial
#define D1 5 // LED 
#define D2 4 // led PIR 
#define D5 14 // LED ferias
#define D6 12 //sensor PIR 
#define tempo 55
#define variacao 40
int soma = 0;
int base;
int ferias;
int sensor_fumaca = 0;
 int sensor_presenca = 0;

int leiturapir;

#include<ESP8266WiFi.h>
#include<BlynkSimpleEsp8266.h>
#include<Blynk.h>

BlynkTimer timer;


//http://arduino.esp8266.com/stable/package_esp8266com_index.json

//char ssid[] = "S20 FE de Leonardo";
//char senha[] = "yzhv4568";

//char ssid[] = "Redmi Note 13";
//char senha[] = "lucao123";

//char ssid[] = "João Arthur";
//char senha[] = "12345678";

char ssid[] = "LUCIANA";
char senha[] = "MM832311";

//char ssid[] = "PIC2-2.4G";
//char senha[] = "engcomp@ufes";

void enviarInfo(){

  Blynk.virtualWrite(V3, sensor_fumaca);

  if( sensor_presenca>0)  Blynk.virtualWrite(V0, HIGH);
  else Blynk.virtualWrite(V0, LOW);

  Blynk.run();
  
}


BLYNK_CONNECTED(){
  Blynk.syncVirtual(V2);

}

BLYNK_WRITE(V2){

  ferias = param.asInt();
  digitalWrite(D5,ferias);
}

void setup(){
  Serial.begin(9600);
  delay(500);
  pinMode(D5, OUTPUT);
  pinMode(D1, OUTPUT);
  pinMode(A0, INPUT);
  pinMode(D6, INPUT);
  pinMode(D2, OUTPUT);
 
  Blynk.begin(BLYNK_AUTH_TOKEN,ssid,senha,"blynk.cloud",80);
  timer.setInterval(100L, enviarInfo);
  
  base = calculaBase();
  
}

void loop(){
  
 

  timer.run();
  detecta();
  PIR();

}

int calculaBase(){

  for(int i=0;i<tempo;i++){
    digitalWrite(D1, HIGH);
    delay(50);
    soma+= analogRead(A0);
    digitalWrite(D1, LOW);
    delay(50);
  }

  return soma/tempo;
}

void detecta(){

  sensor_fumaca = analogRead(A0);
 
  if((sensor_fumaca-base)>=variacao){
    digitalWrite(D1, HIGH);
  }else{ 
    digitalWrite(D1, LOW);
  }

  Serial.println(sensor_fumaca);

}

void PIR() {
  if(ferias){
    int leitura_atual = digitalRead(D6);
    digitalWrite(D2, leitura_atual);

  }

}

