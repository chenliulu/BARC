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

FILE* rvalue;
char value[] = "0";
char svalue[] = "1";
chdir("/sys/class/gpio/gpio199");
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
    int cmp = strcmp(svalue, value);
    if (cmp != 0)
    {
	float etime = clock();
	printf("%f\n",(etime-stime)/CLOCKS_PER_SEC);
	stime = etime;
	//printf("difference detected\n");
        strcpy(svalue, value);
    }
}


return 0;

}