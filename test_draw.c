#include <bcm2835.h>
#include "tftdriver.h"
#include "tftdraw.h"
#include "color.h"
#include "rect.h"

///////////////////////
// TEST DRAW LIBRARY //
///////////////////////

int main() {

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

  char txt[] = "THIS IS A SAMPLE TEXT";

  Screen::clear(Color::Black);
  Screen::draw_rect(rect(0, 0, Screen::getWidth(), 24), Color::White);
  Screen::draw_text(txt, sizeof(txt)-1, 8, 8);

  bcm2835_spi_end();
  bcm2835_close();
  return 0;
}
