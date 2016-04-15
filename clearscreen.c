#include <bcm2835.h>
#include "tftdriver.h"
#include "tftdraw.h"
#include "color.h"
#include <stdlib.h>
#include <stdio.h>
#include <string>

void usage() {
  printf("A VER ESTUDIAO\n");
}

int main(int argc, char** argv) {

  if (argc > 2) {
      usage();
      exit(1);
  }

  bcm2835_init();
  bcm2835_spi_begin();
  bcm2835_spi_setBitOrder(BCM2835_SPI_BIT_ORDER_MSBFIRST);
  bcm2835_spi_setDataMode(BCM2835_SPI_MODE0);
  bcm2835_spi_setClockDivider(BCM2835_SPI_CLOCK_DIVIDER_8);
  bcm2835_spi_chipSelect(BCM2835_SPI_CS_NONE); // We need to change CS_Pin manualy because it causes problems otherwise
  bcm2835_spi_setChipSelectPolarity(BCM2835_SPI_CS0, LOW);
  bcm2835_gpio_fsel(CS_Pin, BCM2835_GPIO_FSEL_OUTP);
  bcm2835_gpio_write(CS_Pin, LOW);
  TFT::SPI_Reset();

  std::string color(argv[1]);

  if (argc == 1)
    Screen::clear(Color::Black);
  else {
    if (color == "Black")
      Screen::clear(Color::Black);
    else if (color == "Red")
      Screen::clear(Color::Red);
    else if (color == "Blue")
      Screen::clear(Color::Blue);
    else
      usage();
  }

  bcm2835_spi_end();
  bcm2835_close();
  return 0;
}
