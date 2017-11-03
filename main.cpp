#include "mbed.h"
#include "rtos.h"


typedef struct {
    float    voltage;
    float    current;
    uint32_t counter;
} message_t;


DigitalOut led1(LED1);

Semaphore sem(2);
Queue<message_t, 16> queue;

int gA=1;
int gB;
const int C = 10;

static void myHeap_Address()
{
	//pc.printf("address gA: %d\n", &gA);
 	//pc.printf("address gB: %d\n", &gB);
 	//pc.printf("address constant C: %d\n", &C);
}

void Th_print_1(void) {
	message_t *message;
	int32_t value=0;

	value = sem.wait();
    printf("\nSemaphore wait: %d\n\r",value);

	message->voltage = 3;
	message->current = 2;
	message->counter = 1;

	queue.put(message);

   sem.release();
}

void Th_print_2(void) {
	message_t *message_res;
	osEvent evt;
	int32_t value=0;

	value = sem.wait();
    printf("\nSemaphore wait: %d\n\r",value);

    evt = queue.get();

    if (evt.status == osEventMessage) {
        message_res = (message_t*)evt.value.p;

        printf("\nVoltage: %.2f V\n\r"   , message_res->voltage);
        printf("Current: %.2f A\n\r"     , message_res->current);
        printf("Number of cycles: %u\n\r", message_res->counter);
    }

    sem.release();
}

void test_thread_1(void const *args) {

	while(true){
		Th_print_1();
		Thread::wait(100);
	}
}

void test_thread_2(void const *args) {

	while(true){
		Th_print_2();
		Thread::wait(100);
	}
}


int main (void) {
    Thread t1(osPriorityHigh);
    Thread t2(osPriorityHigh);

    t1.start(callback(test_thread_1, (void *)"Th 1"));
    t2.start(callback(test_thread_2, (void *)"Th 2"));


    while (true) {
    	myHeap_Address();
    }
}

