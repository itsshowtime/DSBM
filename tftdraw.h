#ifndef TFTDRAW_H
#define TFTDRAW_H

#include "tftdriver.h"
#include "ascii.h"
#include <iostream>

uint16_t Size_X = 320;
uint16_t Size_Y = 240;

enum Color : uint16_t {
  White = 0xFFFF,
  Black = 0x0000,
  Red   = 0xF800,
  Green = 0x07E0,
  Blue  = 0x001F
};

struct rect {
  uint16_t left, top;
  uint16_t width, height;
};

void draw_pixel(uint16_t x, uint16_t y, uint16_t color) {
  // Sets a Pixel X,Y to a Color

  Write_SPI_TFT_Reg(0x03,(x>>0));
  Write_SPI_TFT_Reg(0x02,(x>>8));
  Write_SPI_TFT_Reg(0x07,(y>>0));
  Write_SPI_TFT_Reg(0x06,(y>>8));
  Write_SPI_TFT_Cmd(0x22);
  Write_SPI_TFT_Dat(color);
}

void draw_rect(rect r, uint16_t color) {
  for (uint16_t y = r.top; y < r.top + r.height; ++y)
    for (uint16_t x = r.left; x < r.left + r.width; ++x)
      draw_pixel(x, y, color);
}

void clear_screen(uint16_t color) {
  rect screen = {0, 0, Size_X, Size_Y};
  draw_rect(screen, color);
}

void draw_image(uint16_t **I, uint16_t width, uint16_t height, uint16_t x, uint16_t y) {
  for (uint16_t i = 0; i < height; ++i)
    for (uint16_t j = 0; j < width; ++j)
      draw_pixel(x + j, y + i, I[i][j]);
}

void draw_char(char c, uint16_t x, uint16_t y) {
  ascii character = ascii_map[c-32]; // El mapa empieza en el caracter 32 (SPACE)
  uint64_t mask = 0x80000000;
  uint8_t counter = 0;
  while (mask > 0) {
    uint16_t xpos = x + counter%8;
    uint16_t ypos = y + counter/8;
    if (character.high & mask)
      draw_pixel(xpos , ypos , Color::Black);

    mask = mask >> 1;
    ++counter;
  }
  mask = 0x80000000;
  while (mask > 0) {
    uint16_t xpos = x + counter%8;
    uint16_t ypos = y+4 + counter/8;

    if (character.low & mask)
      draw_pixel(xpos , ypos , Color::Black);

    mask = mask >> 1;
    ++counter;
  }
}

void draw_text(char txt[], uint8_t size, uint16_t x, uint16_t y) {
  for (uint8_t i = 0; i < size; ++i)
    draw_char(txt[i], x+8, y);
}

#endif // TFTDRAW_H
