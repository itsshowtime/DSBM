#ifndef COLOR_H
#define COLOR_H

// RGB: 5-6-5

enum Color : uint16_t {
  White   = 0xFFFF,
  Black   = 0x0000,
  Red     = 0xF800,
  Yellow  = 0xFFE0,
  Green   = 0x07E0,
  Cyan	  = 0x07FF,
  Blue    = 0x001F,
  Magenta = 0xF81F
};

#endif // COLOR_H
