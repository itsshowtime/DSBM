#include <bcm2835.h>
#include <iostream>

int main() {
  bcm2835_init();
  bcm2835_spi_begin();

  uint8_t write = 0x3F;
  uint8_t read = bcm2835_spi_transfer(write);
  printf("Sent to SPI: 0x%02X. Read back from SPI: 0x%02X.\n", write, read);

  bcm2835_spi_end();
  bcm2835_close();
  return 0;
}
