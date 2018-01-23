#include "mbed.h"
#include "rtos.h"


DigitalOut led0(LED0);
DigitalOut led1(LED1);
DigitalOut led2(LED2);
DigitalOut led3(LED3);
DigitalOut led4(LED4);
DigitalOut led5(LED5);
DigitalOut led6(LED6);

Serial pc(UART1_TX, UART1_RX);

bool gpio_check = FALSE;

void gpio_led_toggle(void) {

    if(!gpio_check)
    {
    	gpio_check = TRUE;
        pc.printf("LED's ON\n");

    	led0 = 1;
    	led1 = 1;
    	led2 = 1;
    	led3 = 1;
    	led4 = 1;
    	led5 = 1;
    	led6 = 1;
    }
    else
    {
    	gpio_check = FALSE;
        pc.printf("LED's OFF\n\n");

    	led0 = 0;
    	led1 = 0;
    	led2 = 0;
    	led3 = 0;
    	led4 = 0;
    	led5 = 0;
    	led6 = 0;
    }
}

void test_thread_1(void const *args) {

	while(true){
		gpio_led_toggle();
		Thread::wait(10);
	}
}


int main() {
    Thread t1(osPriorityHigh);

    pc.printf("GPIO DEMO STARTS ...\r\n");

    t1.start(callback(test_thread_1, (void *)"LED's Thread"));

    while(1);

}

