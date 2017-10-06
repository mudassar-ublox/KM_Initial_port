#include "mbed.h"

DigitalOut led1(LED1);
//Serial pc(SERIAL_TX, SERIAL_RX);

int gA=1;
int gB;
const int C = 10;

static void myHeap_Address()
{
	//pc.printf("address gA: %d\n", &gA);
	//pc.printf("address gB: %d\n", &gB);
	//pc.printf("address constant C: %d\n", &C);
}

// main() runs in its own thread in the OS
int main() {
    while (true) {
		int a =10;		
        led1 = !led1;
        wait(0.5);
		myHeap_Address();
		//pc.printf("Stack address: %d\n", &a);
		//pc.printf("This is ")
    }
}

