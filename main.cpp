#include "mbed.h"
#include "rtos.h"

SPI spi(SPI1_MOSI, SPI1_MISO, SPI1_CLK, SPI1_CS); // mosi, miso, sclk
DigitalOut cs(SPI1_CS);

int main() {
    int x = 0, y = 0;

    printf("Starting Master. . .\r\n");
    cs = 1;

    // Setup the spi for 8 bit data, high steady state clock,
    // second edge capture, with a 1MHz clock rate
    //spi.format(8,0);
    //spi.frequency(1000000);

    // Send 0x8f, the command to read the WHOAMI register
    //spi.write(0x8F);

    // Send a dummy byte to receive the contents of the WHOAMI register
    //int whoami = spi.write(0x00);
    //printf("WHOAMI register = 0x%X\n", whoami);

	//spi.write(0x00);

    cs = 0;
    while (1) {

        printf("Data Send = %d\r\n", x);
        y = spi.write(x);
        printf("Data Received = %d\r\n", y);

        Thread::wait(1000);
        y = 0;
        Thread::wait(1000);

        x++;

		if(x >= 255){
			x = 0;
		}
    }
}
