#ifndef TFTDRAW_H
#define TFTDRAW_H

#include "tftdriver.h"
#include "ascii.h"
#include "color.h"
#include "rect.h"

#define VERTICAL    0
#define HORIZONTAL  1

namespace Screen {
  extern uint8_t orientation;

  // Returns orientation of screen
  uint8_t getOrientation();

  // Returns screen width and height keeping track of its orientation
  uint8_t getWidth();
  uint8_t getHeight();

  // Set all pixels of the screen to the given color
  void clear(uint16_t color);

  // Draw color at (x,y) keeping track of the screen's orientation
  void draw_pixel(uint16_t x, uint16_t y, uint16_t color);
  // Fill the area of r with color
  void draw_rect(rect r, uint16_t color);

  // Draws c at (x,y) in black
  void draw_char(char c, uint16_t x, uint16_t y);
  // Draws c at (x,y) in the given color
  void draw_char(char c, uint16_t x, uint16_t y, uint16_t color);
  // Draws the string under txt at (x,y) in black
  void draw_text(char *txt, uint8_t size, uint16_t x, uint16_t y);

  // ???
  void draw_image(uint16_t **I, uint16_t width, uint16_t height, uint16_t x, uint16_t y);
}

#endif // TFTDRAW_H
