#include "spi.h"
#include <bcm2835.h>
#include "tftdriver.h"
#include "tftdraw.h"
#include "ascii.h"
#include <iostream>

int main() {
  if (!bcm2835_init())
    return 1;

  SpiOpenPort(0);

std::cout << "TFT init" << std::endl;
  SPI_TFT_Reset();
std::cout << "clear" << std::endl;
  clear_screen(Color::Red);

std::cout << "draw text1" << std::endl;
  char txt[] = "HOLA";
  draw_text(txt, 4, 0, 0);
std::cout << "draw text2" << std::endl;
  char txt2[] = "QUE TAL";
  draw_text(txt2, 7, 0, 8);

  //Return SPI pins to default inputs state
  SpiClosePort(0);
  bcm2835_close();
}
