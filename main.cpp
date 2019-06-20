#include "mbed.h"

DigitalOut myled(p12); //FITA DE LED.
DigitalOut mybomb(p14); //BOMBA DE ÁGUA.
DigitalIn mymovimento(p15);//SENSOR DE MOVIMENTO
AnalogIn myumidade(p20);//SENSOR DE UMIDADE.
AnalogIn myluz(p16);//SENSOR DE LUZ
Serial device(p9,p10); //PINOS BLUETOOTH: P9 = TX, P10 = RX.
//DS1307 mytime(p28,p27); //PINOS RTC: P28 = SDA, P27 = SCL.
LocalFileSystem local("local");

//FUNÇÃO QUE RETORNA A PORCENTAGEM DO NIVEL DO RESERVATORIO
double nivelReservatorio(void){
double nivel = myumidade.read();
return nivel;
}

//FUNÇÃO QUE RETORNA A PORCENTAGEM DA LUZ AMBIENTE. 
double getStatusLuzAmbiente(void){
    double luminosidade = myluz.read();
    return luminosidade;
    }
    
    
//FUNÇÃO QUE RETORNA A SITUAÇÃO DO MOVIMENTO. TRUE OR FALSE
bool getStatusMovimento(void){
    return mymovimento;
    }

//FUNÇÃO QUE ACENDE O LED
void ligaDesligaLED(void){
     int statusAnterior = myled;
     if(getStatusMovimento() && (getStatusLuzAmbiente()>0.5)){
        myled = 1; // ACENDE A FITA DE LED
        if((statusAnterior != myled)){
        FILE *fp = fopen("/local/out.txt", "a");
        time_t seconds = time(NULL);
        char buffer[32];
        strftime(buffer, 32, "%X %x\n", localtime(&seconds));
        fprintf(fp, "Luz ACESA - %s\n\r ",buffer);
        fclose(fp);
        if ((device.writable())&& (statusAnterior != myled)){
        time_t seconds = time(NULL);
        char buffer[32];
        strftime(buffer, 32, "%X %x\n", localtime(&seconds));
        device.printf("Luz ACESA - %s\n\r ",buffer);
        }  }
        }else{
        myled = 0; // APAGA A FITA DE LED 
        if((statusAnterior != myled)){
        FILE *fp = fopen("/local/out.txt", "a");
        time_t seconds = time(NULL);
        char buffer[32];
        strftime(buffer, 32, "%X %x\n", localtime(&seconds));
        fprintf(fp, "Luz APAGADA - %s\n\r ",buffer);
        fclose(fp);
         if ((device.writable())&& (statusAnterior != myled)){
         time_t seconds = time(NULL);
        char buffer[32];
        strftime(buffer, 32, "%X %x\n", localtime(&seconds));
        device.printf("Luz APAGADA - %s\n\r ",buffer);
        }  }
        };
}

//FUNÇÃO RESPONSÁVEL PELO CONTROLE DA BOMBA
void ligaDesligaBOMBA(void){
    int estadoAnterior = mybomb;
    if(nivelReservatorio()<0.7){
        //DESLIGA A BOMBA
        mybomb = 0;
        if((estadoAnterior != mybomb)){
        FILE *fp = fopen("/local/out.txt", "a");
        time_t seconds = time(NULL);
        char buffer[32];
        strftime(buffer, 32, "%X %x\n", localtime(&seconds));
        fprintf(fp, "Bomba DESLIGADA - %s\n\r ",buffer);
        fclose(fp);
             if ((device.writable()) && (estadoAnterior != mybomb)){
 device.printf("Bomba DESLIGADA - %s\n\r ",buffer);
        }  }
        }else{
        mybomb = 1;
       
        if((estadoAnterior != mybomb)){
        FILE *fp = fopen("/local/out.txt", "a"); 
        time_t seconds = time(NULL);
        char buffer[32];
        strftime(buffer, 32, "%X %x\n", localtime(&seconds));
        fprintf(fp, "Bomba LIGADA - %s\n\r ",buffer);
        fclose(fp);
         if ((device.writable()) && (estadoAnterior != mybomb)){
        time_t seconds = time(NULL);
        char buffer[32];
        strftime(buffer, 32, "%X %x\n", localtime(&seconds));
            device.printf("Bomba LIGADA - %s\n\r ",buffer);
}}
 wait(4); //TEMPO ATÉ ENCHER O RESERVATÓRIO

            };
    }

int main() { 
    //set_time(1559751152);  // Set RTC time
    while(1) { 
    ligaDesligaLED();
    ligaDesligaBOMBA();
   
}}

