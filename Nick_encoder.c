#include "stdio.h"
#include "firmata.h"
#include "stdbool.h"
#include "time.h"

#define PI 3.14159265359
#define DIAMETER 7.239
#define CUTOFF 0.5
#define FAST

float speed;

void main()
{
    t_firmata     *firmata;
    firmata = firmata_new("/dev/ttyACM99"); //init Firmata
    while(!firmata->isReady) //Wait until device is up
        firmata_pull(firmata);
    
    firmata_pinMode(firmata, 12, MODE_INPUT); //set pin 3 (led on most arduino) to out
    
    float buffer[10];
    
    long int i=0;
    
    for (i=0;i<10;i++)
    {
        buffer[i]=0;
    }
    
    long int stime=clock();
    
    firmata_pull(firmata);
    bool value1=firmata->pins[12].value == HIGH;
    
    speed=0.0;
    
    while (i<9)
    {
        firmata_pull(firmata);
        if((firmata->pins[12].value == HIGH)^(value1))
        {
            buffer[i+1]=clock()-stime;
            speed = PI*DIAMETER/(4.0*(buffer[i+1]-buffer[i]))*CLOCKS_PER_SEC;
        }
    }
    
    int j=0;
    long int etime=0;
    
    while (1)
    {
        firmata_pull(firmata);
        if((firmata->pins[12].value == HIGH)^(value1))
        {
            ++i;
            etime=clock();
            if( float(1.0*(etime-stime)/CLOCKS_PER_SEC>0.05)
               {
                   speed = PI*DIAMETER/(4.0*(etime-buffer[j==0? 9:j-1]))*CLOCKS_PER_SEC;
                   buffer[j]=etime;
                   j=j==9? 0:j+1;
               }
               else if ( float(1.0*(etime-stime)/CLOCKS_PER_SEC>0.01))
               {
                   speed = 1.25*PI*DIAMETER/(etime-buffer[j>4? j-5:j+5])*CLOCKS_PER_SEC;
                   buffer[j]=etime;
                   j=j==9? 0:j+1;
               }
               else
               {
                   speed = 2.5*PI*DIAMETER/(etime-buffer[j])*CLOCKS_PER_SEC;
                   buffer[j]=etime;
                   j=j==9? 0:j+1;
               }
        
               if (float(1.0*(clock()-buffer[j==0? 9:j-1])/CLOCKS_PER_SEC)>CUTOFF)
        }
               
    }
}
