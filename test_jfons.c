#include <bcm2835.h>
#include "tftdriver.h"
#include "tftdraw.h"
#include "color.h"
#include "rect.h"
#include "whoread.h"
#include <stdlib.h>
#include <cstring>

///////////////////////
// TEST DRAW LIBRARY //
///////////////////////

int main() {

  bcm2835_init();
  TFT::SPI_Reset();

  uint16_t colors[] = {Color::Blue, Color::Red, Color::Green};
  int count = 0;
  uint16_t step = 2;
  while (true) {
    for (uint16_t k = 0; k < step; ++k) {
      for (uint16_t l = 0; l < step; ++l) {
        for (uint16_t i = 0; i < 320; i += step) {
          for (uint16_t j = 0; j < 240; j += step) {
              TFT::draw_pixel(j+l, i+k, Color::Red);
          }
        }
      }
    }
    ++count;
  }

  bcm2835_spi_end();
  bcm2835_close();
  return 0;
}
