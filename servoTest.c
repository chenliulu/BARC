#include "servo.h"

int		main()
{
  t_firmata	*firmata;
  t_servo	*servo;

  firmata = firmata_new("/dev/ttyACM99");
  while(!firmata->isReady)
    firmata_pull(firmata);
  sleep(1);
  servo = servo_attach(firmata, 3);
  int val = 10;
  while (1)
    {
      sleep(1);
      if (val++ == 180)
	val = 10;
      servo_write(servo, val);
    }
}

