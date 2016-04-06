#include "rect.h"

rect::rect(uint16_t left, uint16_t bottom, uint16_t width, uint16_t height) :
left(left), bottom(bottom), width(width), height(height) {}

bool rect::contains(uint16_t x, uint16_t y) {
  return
      (x > left && x < left + width) &&
      (y > bottom && y < bottom + height);
}
