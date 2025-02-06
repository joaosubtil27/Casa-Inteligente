
#define BLYNK_TEMPLATE_ID "TMPL2oBTUo08S"
#define BLYNK_TEMPLATE_NAME "pic1"
#define BLYNK_AUTH_TOKEN "sc-rMH4-5lgXbUn8vyISntzmLS3vUUI1"
#define BLYNK_PRINT Serial
#define D0 16
#define D2 4



#include<ESP8266WiFi.h>
#include<BlynkSimpleEsp8266.h>
#include<Blynk.h>


//char ssid[] = "S20 FE de Leonardo";
//char senha[] = "yzhv4568";

char ssid[] = "Redmi Note 13";
char senha[] = "lucao123";

//char ssid[] = "João Arthur";
//char senha[] = "12345678";

//char ssid[] = "PIC2-2.4G";
//char senha[] = "engcomp@ufes";
int x =0;


BLYNK_WRITE(V0){
  
  int onoff  = param.asInt();
  digitalWrite(D0,onoff);
}

void setup(){
  Serial.begin(9600);
  pinMode(D0,OUTPUT);
  pinMode(D2,INPUT);
  Blynk.begin(BLYNK_AUTH_TOKEN,ssid,senha,"blynk.cloud",80);


}

void loop(){
Blynk.run();

 x = digitalRead(D2);
 //Serial.print(x);
 if(x==1){
  digitalWrite(D0,HIGH);

 }
 else if(x==0){
   digitalWrite(D0,LOW);
 }
   Serial.println(x);
 // Serial.println(onoff);


delay(100);
}