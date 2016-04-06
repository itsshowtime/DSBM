#ifndef TFTDRIVER_H
#define TFTDRIVER_H

#include <bcm2835.h>
#include <unistd.h> // usleep

#define CS_Pin    RPI_V2_GPIO_P1_24 // CE0
#define Reset_Pin RPI_V2_GPIO_P1_11 // pin11
#define SCLK_Pin  RPI_V2_GPIO_P1_23 // CLK
#define SDO_Pin   RPI_V2_GPIO_P1_21 // MISO
#define SDI_Pin   RPI_V2_GPIO_P1_19 // MOSI

#define SPI_START 0x70
#define SPI_RD 0x01
#define SPI_WR 0x00
#define SPI_DATA 0x02
#define SPI_INDEX 0x00

namespace TFT {
  extern uint16_t Orig_X;
  extern uint16_t Orig_Y;
  extern uint16_t Size_X;
  extern uint16_t Size_Y;

/////////////////////////
// TFT Level functions //
/////////////////////////

  // Sets Reset_Pin to value
  void setReset(bool value);

  // Sets CS_Pin to value
  void setCS(bool value);

/////////////////////////
// SPI Level functions //
/////////////////////////

  // Write the SPI command on reg and read from SPI bus
  uint8_t Write_SPI_Cmd(uint8_t reg);

  // Write the SPI data from value
  void Write_SPI_Dat(uint16_t value);

  // Write the SPI data from value into reg
  void Write_SPI_Reg(uint8_t reg, uint16_t value);

  // Read the SPI data from reg (does nothing)
  uint8_t Read_SPI_Reg(uint8_t reg);

  // Start sequence for SPI-TFT
  void SPI_Reset();

  // Draw the given color onto (x,y)
  // Keep in mind:
  //   TFT orientation is vertical
  //   TFT coordinates start at the bottom-left corner
  void draw_pixel(uint16_t x, uint16_t y, uint16_t color);
}

#endif // TFTDRIVER_H
