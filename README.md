# Feeder

![Feeder](https://i.imgur.com/StnJ8UC.jpg)

### Integrantes
[Lucas Marques de Araujo - 16.01203-8](https://github.com/lucasmaarques "GitHub Lucas Marques")

[Arthur Segura Ortiz Novello - 14.03329-0](https://github.com/arthurnovello "GitHub Arthur Novello")

[Luca Ezellner Miraglia - 16.01977-6](https://github.com/lucaezellner "GitHub Luca Ezellner")

### Descrição do projeto
 Automação de um feeder de animais com sensores responsáveis pela análise e reposição automática de água.

### Módulos Utilizados
    - MBED;
    - Sensor de umidade;
    - Sensor LDR;
    - Bomba d'água;
    - Bluetooth;
    - RTC;
    - Sensor de presença;
    - LED;

### Funcionamento

 O *Sensor de Umidade* controla o nivel da água e aciona a *Bomba* de acordo com a necessidade. Um *Sensor de Presença* controla o acendimento dos *LEDs* caso o *Sensor LDR* não capte luminosidade no ambiente. Por fim o **FEEDER** envia notificações sempre que um celular for conectado pelo *Bluetooth* com informações de acionamento da *Bomba* ou dos *LEDs*, além do envio, o programa gera um arquivo de log, que fica armazenado no microcontrolador.

### Imagens

![mBED](https://i.imgur.com/ajw2pKA.jpg)
![Vasilha](https://i.imgur.com/z8Jr8VN.jpg)
![Reservatorio](https://i.imgur.com/yl50S51.jpg)
![FEEDER aceso](https://i.imgur.com/zaWGhNH.jpg)
