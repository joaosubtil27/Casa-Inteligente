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
- 1x Módulo ESP8266
- 1x Sensor MQ-2 (sensor de inflamáveis)
- 1x Sensor PIR (sensor de presença)
- 2x Protoboard's
- 3x LED's
- 3x Resistores (330Ω)
- 11x Jumpers
### Hardware - Montagem
 A montagem do dispositivo envolve os seguintes componentes:
- ESP8266: Responsável pela conexão Wi-Fi e envio de notificações.
- Sensor MQ-2: Detecta gases inflamáveis e fumaça.
- Sensor PIR: Detecta a presença de movimentos no ambiente.
- LEDs (3x):
  - LED 1: Alerta de presença.
  - LED 2: Alerta de gás inflamável detectado.
  - LED 3: Indica se o modo férias está ativado.
- Resistores (3x): 330Ω para os LEDs.
- Protoboard e Jumpers: Para as conexões entre os componentes.

Conexões principais:

1. O ESP8266 se conecta ao MQ-2 (pino analógico) e ao PIR (pino digital).
2. LEDs são conectados aos pinos digitais do ESP8266.
3. Jumpers para interligar os componentes à protoboard.
Após a montagem, o dispositivo monitora gases inflamáveis, detecta presença e envia notificações via Wi-Fi para o aplicativo móvel. O LED 3 indica quando o modo férias está ativado.
### Software - Programação
### Conexão - Notificação via Wi-Fi
