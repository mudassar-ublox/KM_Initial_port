#include "mbed.h"
#include "rtos.h"
#include <string>
#include <string.h>


DigitalOut led1(LED1);


typedef struct {
    char team[20];
    char project[10];
    int  members;
} ublox_t;

int gA=1;
int gB;
const int C = 10;

static void myHeap_Address()
{
	//pc.printf("address gA: %d\n", &gA);
 	//pc.printf("address gB: %d\n", &gB);
 	//pc.printf("address constant C: %d\n", &C);
}


int main (void) {

	ublox_t obj;

	char *var = "Stk_Tools";
	int cmp = 0, len = 0;

	len = strlen(var);
	printf("Length: %d\n", len);


	strcpy(obj.team, (const char *)"Tools");
	cmp = strcmp(obj.team,"Tools");
	if(cmp == 0)
	{
		printf("String Copied Successfully\n");
	}

	strcpy(obj.project, (const char *)"KMA");
	cmp = strcmp(obj.project,"KMA");
	if(cmp == 0)
	{
		printf("String Copied Successfully\n");
	}

	obj.members = 4;

	len = sizeof(obj);
	printf("Obj Size: %d\n", len);

	strcat(obj.project," ON FPGA");

	memcpy(obj.team,var,strlen(var)-1);

	memset(obj.project,2,3);

	cmp = memcmp(obj.team,var,5);

	if(cmp == 0)
	{
		printf("Both strings are equal\n");
	}

    while (true) {
    	myHeap_Address();
    }
}

