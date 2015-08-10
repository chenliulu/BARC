#include "stdio.h"
#include "firmata.h"
#include "stdbool.h"
#include "clock.h"

#define PI 3.14159265359
#define DIAMETER 7.239

int main()
{
    t_firmata     *firmata;
    firmata = firmata_new("/dev/ttyACM99"); //init Firmata
    while(!firmata->isReady) //Wait until device is up
        firmata_pull(firmata);
    
    firmata_pinMode(firmata, 12, MODE_INPUT); //set pin 3 (led on most arduino) to out
    
    float buffer[10];
    
    int i;
    
    for (i=0;i<10;i++)
    {
        buffer[i]=0;
    }
    
    long int stime=clock();
    
    firmata_pull(firmata);
    int value1=firmata->pins[12].value == HIGH;
    
    for (i=0;i<10;i++)
    {
        firmata_pull(firmata);
        printf("pin 12 value = %d\n", (firmata->pins[12].value == HIGH));
    }
}
