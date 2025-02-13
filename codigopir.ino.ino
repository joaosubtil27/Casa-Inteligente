
/*#define BLYNK_TEMPLATE_ID "TMPL2oBTUo08S"
#define BLYNK_TEMPLATE_NAME "pic1"
#define BLYNK_AUTH_TOKEN "sc-rMH4-5lgXbUn8vyISntzmLS3vUUI1"
#define BLYNK_PRINT Serial*/
#define D0 16 // LED
#define D2 4 // sensor PIR
#define D3 0 // sensor Fumaca

//http://arduino.esp8266.com/stable/package_esp8266com_index.json

/*#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Blynk.h>*/


//char ssid[] = "S20 FE de Leonardo";
//char senha[] = "yzhv4568";

//char ssid[] = "Redmi Note 13";
//char senha[] = "lucao123";

//char ssid[] = "João Arthur";
//char senha[] = "12345678";

/*char ssid[] = "PIC2-2.4G";
char senha[] = "engcomp@ufes";*/
//int x = 0;


/*BLYNK_WRITE(V1) {

  int onoff = param.asInt();
  digitalWrite(D0, onoff);
}*/

void setup() {
  Serial.begin(9600);
  pinMode(D0, OUTPUT);
  pinMode(A0, INPUT);
  pinMode(D2, INPUT);
  pinMode(D3, INPUT);

  //Blynk.begin(BLYNK_AUTH_TOKEN, ssid, senha, "blynk.cloud", 80);
}

void loop() {


  //Blynk.run();

  int sensor_fumaca = analogRead(A0);
  int sensor_presenca = digitalRead(D2);
  
  if (sensor_presenca == 1) {
    digitalWrite(D0, HIGH);
    //Blynk.virtualWrite(V1, 1);


    delay(900);
  } 
  else if (sensor_presenca == 0) {
    digitalWrite(D0, LOW);
    //Blynk.virtualWrite(V1, 0);
  }

  Serial.println(sensor_fumaca);
  //Serial.println(onoff);
}
