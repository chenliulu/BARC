/*
 * Joe Pappas and Stephen Lu
 * 
 * encoder2.c
 *
 * Reads value of GPIO pin 199 and determines if the value has changed.
 * Prints out time between value changes
 * 
 * 7/12/15
 */



#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

int main(void) 
{
    float etime;
    FILE* rvalue;
    char value[2],svalue[2];
    svalue[1]='\0';
    value[1]='\0';
    chdir("/sys/class/gpio/gpio199");
    rvalue = fopen("value", "r");
    svalue[0] = fgetc(rvalue);
    fclose(rvalue);
    float stime = clock();
    while (1) 
    {    
        rvalue = fopen("value", "r");	
        value[0] = fgetc(rvalue);
        fclose(rvalue);
        /*
         printf("pin:%s \n", value);
         printf("stored:%s \n", svalue);
         */
        
        if (strcmp(svalue, value))
        {
            etime = clock();
            printf("%f\n",(etime-stime)/CLOCKS_PER_SEC);
            stime = etime;
            //printf("difference detected\n");
            svalue[0]=value[0];
        }
    }
    return 0;
}