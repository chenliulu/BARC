import pigpio



pi = pigpio.pi()
pi.set_mode(2, pigpio.INPUT)
cb1 = pi.callback( 2, pigpio.EITHER_EDGE)
previous_count = cb1.tally()
tick_init = pi.get_current_tick()
has_print = 0
while True:
	if previous_count != cb1.tally():
		if previous_count>928*has_print:
			has_print += 1
			print(cb1.tally())
			print((pi.get_current_tick()-tick_init)/1000000.0)
		previous_count = cb1.tally()