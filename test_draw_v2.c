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

  char row0_5[]   = "     [[[[[[[[[[[[[[[[[[      [[[[[[     ";
  char row6_11[]  = "                 [[[[[[      [[[[[[     ";
  char row12_17[] = "     [[[[[[[[[[[[[[[[[[[[[[[[[[[[[[     "; 
  char row18_23[] = "     [[[[[[      [[[[[[                 ";
  char row24_29[] = "     [[[[[[      [[[[[[[[[[[[[[[[[[     ";

  Screen::clear(Color::Red);

  Screen::draw_text(row0_5, sizeof(row0_5)-1, 0, 0);
  Screen::draw_text(row0_5, sizeof(row0_5)-1, 0, 8);
  Screen::draw_text(row0_5, sizeof(row0_5)-1, 0, 16);
  Screen::draw_text(row0_5, sizeof(row0_5)-1, 0, 24);
  Screen::draw_text(row0_5, sizeof(row0_5)-1, 0, 32);
  Screen::draw_text(row0_5, sizeof(row0_5)-1, 0, 40);
  Screen::draw_text(row6_11, sizeof(row0_5)-1, 0, 48);
  Screen::draw_text(row6_11, sizeof(row0_5)-1, 0, 56);
  Screen::draw_text(row6_11, sizeof(row0_5)-1, 0, 64);
  Screen::draw_text(row6_11, sizeof(row0_5)-1, 0, 72);
  Screen::draw_text(row6_11, sizeof(row0_5)-1, 0, 80);
  Screen::draw_text(row6_11, sizeof(row0_5)-1, 0, 88);
  Screen::draw_text(row12_17, sizeof(row0_5)-1, 0, 96);
  Screen::draw_text(row12_17, sizeof(row0_5)-1, 0, 104);
  Screen::draw_text(row12_17, sizeof(row0_5)-1, 0, 112);
  Screen::draw_text(row12_17, sizeof(row0_5)-1, 0, 120);
  Screen::draw_text(row12_17, sizeof(row0_5)-1, 0, 128);
  Screen::draw_text(row12_17, sizeof(row0_5)-1, 0, 136);
  Screen::draw_text(row18_23, sizeof(row0_5)-1, 0, 144);
  Screen::draw_text(row18_23, sizeof(row0_5)-1, 0, 152);
  Screen::draw_text(row18_23, sizeof(row0_5)-1, 0, 160);
  Screen::draw_text(row18_23, sizeof(row0_5)-1, 0, 168);
  Screen::draw_text(row18_23, sizeof(row0_5)-1, 0, 176);
  Screen::draw_text(row18_23, sizeof(row0_5)-1, 0, 184);
  Screen::draw_text(row24_29, sizeof(row0_5)-1, 0, 192);
  Screen::draw_text(row24_29, sizeof(row0_5)-1, 0, 200);
  Screen::draw_text(row24_29, sizeof(row0_5)-1, 0, 208);
  Screen::draw_text(row24_29, sizeof(row0_5)-1, 0, 216);
  Screen::draw_text(row24_29, sizeof(row0_5)-1, 0, 224);
  Screen::draw_text(row24_29, sizeof(row0_5)-1, 0, 232);


  bcm2835_spi_end();
  bcm2835_close();
  return 0;
}
