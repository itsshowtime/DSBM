#include <bcm2835.h>
#include "tftdriver.h"
#include "tftdraw.h"
#include "ascii.h"
#include <iostream>

int main() {
  if (!bcm2835_init())
    return 1;

std::cout << "begin" << std::endl;
  //Setup SPI pins
  if (! bcm2835_spi_begin())
    return 1;
std::cout << "polarity1" << std::endl;
  //Set CS pins polarity to low
  bcm2835_spi_setChipSelectPolarity(BCM2835_SPI_CS0, HIGH);
std::cout << "polarity2" << std::endl;
//  bcm2835_spi_setChipSelectPolarity(BCM2835_SPI_CS1, 0);
std::cout << "clock divider" << std::endl;
  //Set SPI clock speed
  //	BCM2835_SPI_CLOCK_DIVIDER_65536 = 0,       ///< 65536 = 262.144us = 3.814697260kHz (total H+L clock period)
  //	BCM2835_SPI_CLOCK_DIVIDER_32768 = 32768,   ///< 32768 = 131.072us = 7.629394531kHz
  //	BCM2835_SPI_CLOCK_DIVIDER_16384 = 16384,   ///< 16384 = 65.536us = 15.25878906kHz
  //	BCM2835_SPI_CLOCK_DIVIDER_8192  = 8192,    ///< 8192 = 32.768us = 30/51757813kHz
  //	BCM2835_SPI_CLOCK_DIVIDER_4096  = 4096,    ///< 4096 = 16.384us = 61.03515625kHz
  //	BCM2835_SPI_CLOCK_DIVIDER_2048  = 2048,    ///< 2048 = 8.192us = 122.0703125kHz
  //	BCM2835_SPI_CLOCK_DIVIDER_1024  = 1024,    ///< 1024 = 4.096us = 244.140625kHz
  //	BCM2835_SPI_CLOCK_DIVIDER_512   = 512,     ///< 512 = 2.048us = 488.28125kHz
  //	BCM2835_SPI_CLOCK_DIVIDER_256   = 256,     ///< 256 = 1.024us = 976.5625MHz
  //	BCM2835_SPI_CLOCK_DIVIDER_128   = 128,     ///< 128 = 512ns = = 1.953125MHz
  //	BCM2835_SPI_CLOCK_DIVIDER_64    = 64,      ///< 64 = 256ns = 3.90625MHz
  //	BCM2835_SPI_CLOCK_DIVIDER_32    = 32,      ///< 32 = 128ns = 7.8125MHz
  //	BCM2835_SPI_CLOCK_DIVIDER_16    = 16,      ///< 16 = 64ns = 15.625MHz
  //	BCM2835_SPI_CLOCK_DIVIDER_8     = 8,       ///< 8 = 32ns = 31.25MHz
  //	BCM2835_SPI_CLOCK_DIVIDER_4     = 4,       ///< 4 = 16ns = 62.5MHz
  //	BCM2835_SPI_CLOCK_DIVIDER_2     = 2,       ///< 2 = 8ns = 125MHz, fastest you can get
  //	BCM2835_SPI_CLOCK_DIVIDER_1     = 1,       ///< 1 = 262.144us = 3.814697260kHz, same as 0/65536
  bcm2835_spi_setClockDivider(BCM2835_SPI_CLOCK_DIVIDER_65536);
std::cout << "data mode" << std::endl;
  //Set SPI data mode
  //	BCM2835_SPI_MODE0 = 0,  // CPOL = 0, CPHA = 0, Clock idle low, data is clocked in on rising edge, output data (change) on falling edge
  //	BCM2835_SPI_MODE1 = 1,  // CPOL = 0, CPHA = 1, Clock idle low, data is clocked in on falling edge, output data (change) on rising edge
  //	BCM2835_SPI_MODE2 = 2,  // CPOL = 1, CPHA = 0, Clock idle high, data is clocked in on falling edge, output data (change) on rising edge
  //	BCM2835_SPI_MODE3 = 3,  // CPOL = 1, CPHA = 1, Clock idle high, data is clocked in on rising, edge output data (change) on falling edge
  bcm2835_spi_setDataMode(BCM2835_SPI_MODE3);		//(SPI_MODE_# | SPI_CS_HIGH)=Chip Select active high, (SPI_MODE_# | SPI_NO_CS)=1 device per bus no Chip Select
std::cout << "chip select" << std::endl;
  //Set with CS pin to use for next transfers
  bcm2835_spi_chipSelect(BCM2835_SPI_CS0);

std::cout << "TFT init" << std::endl;
  SPI_TFT_Reset();
std::cout << "clear" << std::endl;
  clear_screen(Color::Red);

std::cout << "draw text1" << std::endl;
  char txt[] = "HOLA";
  draw_text(txt, 4, 0, 0);
std::cout << "draw text2" << std::endl;
  char txt2[] = "QUE TAL";
  draw_text(txt2, 7, 0, 8);

  //Return SPI pins to default inputs state
  bcm2835_spi_end();
  bcm2835_close();
}
