#include "stdio.h"
#include "firmata.h"

int             main()
{
  t_firmata     *firmata;
  float val;


  firmata = firmata_new("/dev/ttyACM99"); //init Firmata
  while(!firmata->isReady) //Wait until device is up
    firmata_pull(firmata);
  firmata_pinMode(firmata, 14, MODE_ANALOG); //set pin 3 (led on most arduino) to out
  while (1)
    {
	firmata_pull(firmata);
	val = firmata->pins[14].value / 1024.f;
	printf("pin 14 value = %f\n", val);
    }
}
