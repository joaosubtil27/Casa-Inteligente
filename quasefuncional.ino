
#define BLYNK_TEMPLATE_ID "TMPL2oBTUo08S"
#define BLYNK_TEMPLATE_NAME "pic1"
#define BLYNK_AUTH_TOKEN "sc-rMH4-5lgXbUn8vyISntzmLS3vUUI1"
#define BLYNK_PRINT Serial
#define D1 5 // LED
#define D2 4 // led PIR
#define D5 14 // LED blynk
#define D6 12 //sensor PIR
//#define D5 14 //led PIR
#define tempo 55
#define variacao 40
int soma = 0;
int base;
int ferias;

#include<ESP8266WiFi.h>
#include<BlynkSimpleEsp8266.h>
#include<Blynk.h>

//http://arduino.esp8266.com/stable/package_esp8266com_index.json

//char ssid[] = "S20 FE de Leonardo";
//char senha[] = "yzhv4568";

//char ssid[] = "Redmi Note 13";
//char senha[] = "lucao123";

//char ssid[] = "João Arthur";
//char senha[] = "12345678";

//char ssid[] = "LUCIANA";
//char senha[] = "MM832311";

char ssid[] = "PIC2-2.4G";
char senha[] = "engcomp@ufes";

BLYNK_CONNECTED(){
Blynk.syncVirtual(V2);

}

BLYNK_WRITE(V2){

int onoff  = param.asInt();
ferias = onoff;
digitalWrite(D5,onoff);
}

void setup(){
Serial.begin(9600);
pinMode(D5, OUTPUT);
pinMode(D1, OUTPUT);
pinMode(A0, INPUT);
pinMode(D6,INPUT);
pinMode(D2, OUTPUT);
Blynk.begin(BLYNK_AUTH_TOKEN,ssid,senha,"blynk.cloud",80);


base = calculaBase();

  

}

void loop(){


Blynk.run();
detecta();

if(ferias)PIR();
delay(100);

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

int sensor_fumaca = analogRead(A0);

if((sensor_fumaca-base)>=variacao){
digitalWrite(D1, HIGH);
}else{ 
digitalWrite(D1, LOW);
}

Serial.println(sensor_fumaca);

}

void  PIR(){
  
    int sensor_presenca = digitalRead(D6);

    if (sensor_presenca == 1) {
      digitalWrite(D2 , HIGH);
      Blynk.virtualWrite(V1, 1);
      Blynk.logEvent("alarme");

    } 
    else if (sensor_presenca == 0) {
      digitalWrite(D2, LOW);
      Blynk.virtualWrite(V1, 0);
  }


}

