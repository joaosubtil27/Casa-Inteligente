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
 O projeto é um sistema de monitoramento que detecta substâncias inflamáveis e presença no ambiente, enviando notificações via Wi-Fi ao usuário. Ele conta com sensores MQ-2 (gás inflamável) e PIR (presença). Contém um modo férias que permite desativar a detecção de presença do sensor PIR, evitando notificações indesejadas quando o usuário está em casa.

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

![Montagem Casa Inteligente](https://github.com/joaosubtil27/Casa-Inteligente/blob/e343903197a8cfcee064473e2650a8ebc7bfd2d4/Esquema%20PIC.PNG)
### Software - Programação
O código do projeto foi desenvolvido em C++ utilizando a IDE Arduino. Funções principais:
- Leitura dos sensores (MQ-2 e PIR)
- Controle dos LEDs de alerta
- Conexão Wi-Fi com a rede local
- Interação com o Blynk para envio de notificações
  
Para o código rodar é necessário que o usuário baixe as bibliotecas: 
- Blynk.h
- ESP8266Wi-Fi.h
- BlynkSimpleEsp8266.h

Como o Arduino IDE não espera ser conectado com o ESP é necessário mudar algumas configurações para usá-lo.

- Ir em File (Arquivos), depois em Preferences(Preferências)
- Copiar o link "http://arduino.esp8266.com/stable/package_esp8266com_index.json" em Additional boards manager URLs (URLs adicionais do gerenciador de placas)
- Ir em Tools(Ferramentas), depois em Board (Placa) e, em seguida, Boards Manager(Gerenciador de placas)
- Baixar a placa esp8266

Além disso, é necessário informar o Wi-Fi e a senha para o sistema enviar as notificações ao usuário:
- Em "char ssid[]" coloca-se o nome da rede; Ex: char ssid[] = "PIC2-2.4G";
- Já em "char senha[]" é inserido a senha do Wi-Fi; Ex char senha[] = "engcomp@ufes";

Agora todas as configurações para rodar o código estão prontas!

No código, o modo férias é uma funcionalidade que desativa a detecção do sensor PIR. Isso é útil quando o usuário está em casa, pois impede que o sistema envie notificações desnecessárias de movimento. O modo pode ser ativado ou desativado por meio do aplicativo remoto do Blynk.
### Conexão - Notificação via Wi-Fi
A comunicação do sistema ocorre via Blynk, permitindo notificações em tempo real no aplicativo móvel:
1. O ESP8266 conecta-se ao Wi-Fi utilizando as credenciais armazenadas.
2. Quando um evento é detectado (gás inflamável ou movimento), o ESP8266 aciona o Blynk.
3. O Blynk envia uma notificação push para o usuário via smartphone.

Essa abordagem facilita a interação remota e garante a segurança do ambiente monitorado.
### Demonstração do Projeto 🎥
[![Assista ao vídeo](https://img.youtube.com/vi/3e1H5Q1ze2E/maxresdefault.jpg)](https://youtu.be/3e1H5Q1ze2E)
