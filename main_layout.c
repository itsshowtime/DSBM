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

  rect fingerTouch(10,10,180,180);
  rect pcIcon(10,210,20,20);
  Who w = Who();
//  char* pctxt;
//  std::strcpy(pctxt, w.ip.c_str());
  rect sensor(220,200,100,10);
  char sensortxt[] = "SENSOR";
  rect motor(220,80,100,10);
  char motortxt[] = "MOTOR";

  Screen::clear(Color::White);
  Screen::draw_rect(fingerTouch, Color::Black); // Touch panel
  Screen::draw_rect(pcIcon, Color::Magenta);
  Screen::draw_rect(sensor, Color::Black);
  Screen::draw_rect(motor, Color::Black);
  Screen::draw_text(w.ip.c_str(), w.ip.size(), 40, 222);
  Screen::draw_text(sensortxt, sizeof(sensortxt)-1, 220, 220);
  Screen::draw_text(motortxt, sizeof(motortxt)-1, 220, 100);

  bcm2835_spi_end();
  bcm2835_close();
  return 0;
}
