#ifndef RECT_H
#define RECT_H

#include <cstdint>

class rect
{
public:
    rect(uint16_t left, uint16_t bottom, uint16_t width, uint16_t height);
    bool contains(uint16_t x, uint16_t y);

    uint16_t left, bottom;
    uint16_t width, height;
};

#endif // RECT_H
