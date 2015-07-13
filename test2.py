import pigpio

pi = pigpio.pi()
pi.set_mode(3, pigpio.OUTPUT)
pi.set_PWM_dutycycle(3, 128)
pi.set_PWM_frequency(3, 1)