/*Os 3 primeiros defines são referentes ao template do dispositivo(device) configurado no Blynk,
o site disponibiliza ele para apenas copiar e colar no codigo*/

#define BLYNK_TEMPLATE_ID ""
#define BLYNK_TEMPLATE_NAME ""
#define BLYNK_AUTH_TOKEN ""
#define BLYNK_PRINT Serial

//portas utilizadas no ESP8266
#define D1 5 // LED
#define D2 4 // led PIR
#define D5 14 // LED blynk
#define D6 12 //sensor PIR

/*"tempo" eh o tanto de vezes que o sensor de fumaca MQ2 vai fazer
medicoes para calcular uma base e "variacao" eh o tanto que a medicao
precisa se elevar para enviar a notificacao para o celular.
Podem ser modificados para regular a sensibilidade sensor de fumaca*/
#define tempo 70
#define variacao 30

//variaveis globais utilizadas ao longo do codigo 
int soma = 0;
int base;
int ferias;

//bibliotecas - na arduinoIDE so eh necessario baixar o pacote blynk.h
#include<ESP8266WiFi.h>
#include<BlynkSimpleEsp8266.h>
#include<Blynk.h>

//timer que vai chamar uma funcao de callback a cada uma quantidade de tempo definida no setup
BlynkTimer timer;

//link para ser configurado onde a arduinoIDE ira proucurar a biblioteca referente a placa ESP8266
//http://arduino.esp8266.com/stable/package_esp8266com_index.json

//Nome da rede e senha do roteador wifi utilizado
char ssid[] = "";
char senha[] = "";


/*funcao que eh chamada quando o dispositivo se conecta na nuvem do blynk.
Basicamente, chama a funcao de "BLYNK_WRITE" do pino especificado "V2" para 
sincronizar o pino com o ultimo valor registrado na nuvem*/
BLYNK_CONNECTED(){
Blynk.syncVirtual(V2);

}
/*funcao que eh chamada quando o switch virtual no aplicativo do blynk sofre alguma mudanca
de valor(ou quando a BLYNK_CONNECTED eh chamada), ativando ou desativando o modo ferias*/
BLYNK_WRITE(V2){

ferias  = param.asInt();
digitalWrite(D5,ferias);
}

//atualiza o valor da medicao do sensor de fumaca no aplicativo do blynk
void enviaInfos(){

  int sensor_fumaca = analogRead(A0);
  Blynk.virtualWrite(V0, sensor_fumaca);

}


void setup(){
Serial.begin(9600);
pinMode(D5, OUTPUT);
pinMode(D1, OUTPUT);
pinMode(A0, INPUT);
pinMode(D6,INPUT);
pinMode(D2, OUTPUT);

//faz a conexao com o wifi e com a nuvem do blynk
Blynk.begin(BLYNK_AUTH_TOKEN,ssid,senha);
//configura o intervalo, em milisegundos, em que a funcao de callback eh chamada
timer.setInterval(2000L, enviaInfos);

//faz a medicao do valor de base do sensor de fumaca
base = calculaBase();
Serial.println(base);

}
/*Blynk.run atualiza os valores do ESP com a nuvem
Timer.run faz o timer configurado funcionar
*/
void loop(){


Blynk.run();
timer.run();
detecta();
PIR();

delay(50);
}
/*calcula a media das medicoes do nivel de fumaca em um determinado intervalo de tempo
para ter um parametro de comparacao de fumaca em diferentes ambientes e evitar falsos positivos
*/
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

/*verifica a diferenca entre o nivel de fumaca atual e a base e
ativa a notificacao "fumacadetectada" configurada no Blynk
*/
void detecta(){

int sensor_fumaca = analogRead(A0);

if((sensor_fumaca-base)>=variacao){
digitalWrite(D1, HIGH);
 Blynk.logEvent("fumacadetectada");
}else{ 
digitalWrite(D1, LOW);
}


}
/*le o valor do sensor de presenca e envia a notificacao "sensorpresenca"
configurada no Blynk, mas so funciona caso o modo ferias esteja ativado 
*/
void  PIR(){
  if(ferias){
    int sensor_presenca = digitalRead(D6);

    if (sensor_presenca == 1) {
      digitalWrite(D2 , HIGH);
      
      Blynk.logEvent("sensorpresenca");

    } 
    else if (sensor_presenca == 0) {
      digitalWrite(D2, LOW);
    }
  }
    
}
