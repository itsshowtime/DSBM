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
  TFT::SPI_Reset();

  char txt[] = "abcdefghijklmnopqrtstuvwxyz";

  Screen::clear(Color::Black);
  Screen::draw_rect(rect(0, 0, Screen::getWidth(), 24), Color::White);
  Screen::draw_text(txt, sizeof(txt)-1, 8, 8);

  bcm2835_spi_end();
  bcm2835_close();
  return 0;
}
