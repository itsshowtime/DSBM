#include "tftdraw.h"

uint8_t Screen::orientation = HORIZONTAL;

uint8_t Screen::getOrientation() { return orientation; }
uint16_t Screen::getWidth() { return orientation == VERTICAL? TFT::Size_X : TFT::Size_Y; }
uint16_t Screen::getHeight() { return orientation == VERTICAL? TFT::Size_Y : TFT::Size_X; }

void Screen::draw_pixel(uint16_t x, uint16_t y, uint16_t color) {
  if (orientation == VERTICAL)
    TFT::draw_pixel(x, y, color);
  else
    TFT::draw_pixel(y, x, color);
}

void Screen::draw_rect(rect r, uint16_t color) {
  for (uint16_t y = r.bottom; y < r.bottom + r.height; ++y)
    for (uint16_t x = r.left; x < r.left + r.width; ++x)
      draw_pixel(x, y, color);
}

void Screen::clear(uint16_t color) {
  rect screen = {0, 0, getWidth(), getHeight()};
  draw_rect(screen, color);
}

void Screen::draw_char(char c, uint16_t x, uint16_t y) {
  draw_char(c, x, y, Color::Black);
}

void Screen::draw_char(char c, uint16_t x, uint16_t y, uint16_t color) {
  ascii character = ascii_map[c-32]; // El mapa empieza en el caracter 32 (SPACE)
  uint64_t mask = 0x80000000;
  uint8_t counter = 0;
  while (mask > 0) {
    uint16_t xposh = x + counter%8;
    uint16_t yposh = y - counter/8;

    if (character.high & mask)
      draw_pixel(xposh , yposh , color);

    uint16_t xposl = x + counter%8;
    uint16_t yposl = y-4 - counter/8;

    if (character.low & mask)
      draw_pixel(xposl , yposl , color);

    mask = mask >> 1;
    ++counter;
  }
}

void Screen::draw_text(const char *txt, uint8_t size, uint16_t x, uint16_t y) {
  for (uint8_t i = 0; i < size; ++i)
    draw_char(txt[i], x+8*i, y);
}

void Screen::draw_image(uint16_t **I, uint16_t width, uint16_t height, uint16_t x, uint16_t y) {
  for (uint16_t i = 0; i < height; ++i)
    for (uint16_t j = 0; j < width; ++j)
      draw_pixel(x + j, y + i, I[i][j]);
}
