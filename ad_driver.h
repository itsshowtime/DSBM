#ifndef AD_DRIVER_H
#define AD_DRIVER_H

#include <bcm2835.h>

namespace AD {
  const uint8_t CLK_Pin = RPI_V2_GPIO_P1_29;
  const uint8_t CS_Pin = RPI_V2_GPIO_P1_33;
  const uint8_t MISO_Pin = RPI_V2_GPIO_P1_31;
  const uint8_t MOSI_Pin = RPI_V2_GPIO_P1_32;
  const uint8_t xpos_Pin = RPI_V2_GPIO_P1_35;
  const uint8_t xneg_Pin = RPI_V2_GPIO_P1_36;
  const uint8_t ypos_Pin = RPI_V2_GPIO_P1_37;
  const uint8_t yneg_Pin = RPI_V2_GPIO_P1_38;

  void init();
  uint16_t readX();
  uint16_t readY();
}

#endif // AD_DRIVER_H
