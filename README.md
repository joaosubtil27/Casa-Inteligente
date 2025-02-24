######
# Casa Inteligente
#### Mostra Projeto Integrado de Computação I - 2024.2
###### Alunos: João Arthur Subtil, Leonardo Rezende e Lucas Bastos
###### Universidade Federal do Espírito Santo (UFES)


## Índice
* [Descrição](#descrição)
* [Componentes](#componentes)
* [Hardware - Montagem](#hardware---montagem)
* [Software - Programação](#software---programação)
* [Conexão - Notificação via Wi-Fi](#conexão---notificação-via-wi-fi)







### Descrição
 O projeto consiste em um dispositivo capaz de detectar a presença de substâncias inflamáveis no ambiente e, caso os níveis ultrapassem os limites preestabelecidos, o sistema notifica o usuário cadastrado por meio de uma conexão sem fio, enviando a informação para um aplicativo móvel, ajudando, dessa forma, na prevenção de incêndios. Além disso, o dispositivo possui um sensor de presença que, ao ser informado sobre a ausência do usuário, monitora possíveis movimentos no ambiente e, caso algo seja detectado, envia uma notificação ao usuário pelo mesmo aplicativo.

### Componentes
- Microcontrolador: ESP8266
- Sensores:
   - MQ-2 (detecção de gases inflamáveis)
   - PIR (detecção de presença)
- Sinalizadores:
   - 3 LEDs (alertas visuais)
- Conexões e alimentação:
   - Protoboards, jumpers e resistores (330Ω)
### Hardware - Montagem
 A montagem do dispositivo segue os seguintes passos:
1. Conectar o ESP8266 à protoboard.
2. Ligar o sensor MQ-2 ao pino analógico do ESP8266.
3. Ligar o sensor PIR a um pino digital do ESP8266.
4. Conectar os LEDs aos pinos digitais apropriados, com resistores de 330Ω.
5. Garantir a alimentação correta do circuito através do ESP8266.
### Software - Programação
O código do projeto foi desenvolvido em C++ utilizando a IDE Arduino. Funções principais:
- Leitura dos sensores (MQ-2 e PIR)
- Controle dos LEDs de alerta
- Conexão Wi-Fi com a rede local
- Interação com o Blynk para envio de notificações
### Conexão - Notificação via Wi-Fi
A comunicação do sistema ocorre via Blynk, permitindo notificações em tempo real no aplicativo móvel:
1. O ESP8266 conecta-se ao Wi-Fi utilizando as credenciais armazenadas.
2. Quando um evento é detectado (gás inflamável ou movimento), o ESP8266 aciona o Blynk.
3. O Blynk envia uma notificação push para o usuário via smartphone.

Essa abordagem facilita a interação remota e garante a segurança do ambiente monitorado.
