#include "stdio.h"
#include "firmata.h"
#include "stdbool.h"


int             main()
{
  t_firmata     *firmata;
  


  firmata = firmata_new("/dev/ttyACM99"); //init Firmata
  while(!firmata->isReady) //Wait until device is up
    firmata_pull(firmata);
  firmata_pinMode(firmata, 12, MODE_INPUT); //set pin 3 (led on most arduino) to out
  while (1)
    {
	firmata_pull(firmata);
	printf("pin 12 value = %d\n", (firmata->pins[12].value == HIGH));
    }
}
