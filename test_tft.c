#include <bcm2835.h>
#include "tftdriver.h"
#include <iostream>
#include "tftdraw.h"

int main() {

  bcm2835_init();
  bcm2835_spi_begin();
  bcm2835_spi_setBitOrder(BCM2835_SPI_BIT_ORDER_MSBFIRST);      // The default
  bcm2835_spi_setDataMode(BCM2835_SPI_MODE0);                   // The default
  bcm2835_spi_setClockDivider(BCM2835_SPI_CLOCK_DIVIDER_8); // The default
  bcm2835_spi_chipSelect(BCM2835_SPI_CS_NONE);                      // The default
  bcm2835_spi_setChipSelectPolarity(BCM2835_SPI_CS0, LOW);      // the default
  bcm2835_gpio_fsel(CS_Pin, BCM2835_GPIO_FSEL_OUTP);
  bcm2835_gpio_write(CS_Pin, LOW);
  SPI_TFT_Reset();
      
  clear_screen(Color::Green);
  draw_char('A',0,8);
  char txt[] = "A B C D E F G H I J K";  
  draw_text(&txt[0],sizeof(txt)-1,0,64);
  char txt2[] = "L M N O P Q R S T U V W X Y Z";
  draw_text(&txt2[0],sizeof(txt2)-1,0,32);

  bcm2835_spi_end();
  bcm2835_close();
  return 0;
}
