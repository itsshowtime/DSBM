#ifndef TFTDRIVER_H
#define TFTDRIVER_H

#include <bcm2835.h>
#include <time.h> // nanosleep

#define CS_Pin    RPI_V2_GPIO_P1_24 // CE0
#define Reset_Pin RPI_V2_GPIO_P1_11 // pin11
#define SCLK_Pin  RPI_V2_GPIO_P1_23 // CLK
#define SDO_Pin   RPI_V2_GPIO_P1_21 // MISO
#define SDI_Pin   RPI_V2_GPIO_P1_19 // MOSI

void Reset_TFT(uint8_t value) {
  bcm2835_gpio_fsel(Reset_Pin, BCM2835_GPIO_FSEL_OUTP); // Configurar pint de output
  bcm2835_gpio_write(Reset_Pin, value);
}

// SPI Level Functions

#define SPI_START 0x70
#define SPI_RD 0x01
#define SPI_WR 0x00
#define SPI_DATA 0x02
#define SPI_INDEX 0x00

uint8_t Write_SPI_TFT_Cmd(uint8_t reg) {
  // reg is 8 bit

  // Send Start, Write, Index
  bcm2835_spi_transfer(SPI_START);
  // Send the value
  return bcm2835_spi_transfer(reg);
}

void Write_SPI_TFT_Dat(uint16_t value) {
  // value is 16 bit

  // Send Start, Write, Data
  bcm2835_spi_transfer(0x72); // por que no es SPI_START? Yo pondria: SPI_START | SPI_DATA
  // Send the value
  bcm2835_spi_transfer(value>>8);
  bcm2835_spi_transfer(value);
}

void Write_SPI_TFT_Reg(uint8_t reg, uint16_t value) {

  // Sets a value to a reg
  Write_SPI_TFT_Cmd(reg);
  Write_SPI_TFT_Dat(value);
}

uint8_t Read_SPI_TFT_Reg(uint8_t reg) {

  // Sets a value to a reg
  return Write_SPI_TFT_Cmd(reg);
}

// TFT Level Functions
uint16_t Orig_X = 0;
uint16_t Orig_Y = 0;
uint16_t Size_X = 240;
uint16_t Size_Y = 320;

void SPI_TFT_Reset() {
  timespec sleep;

  // Reset the TFT
  Reset_TFT(false);
  sleep.tv_nsec = 250000000L;
  nanosleep(&sleep, NULL); // para 0.25s -> 250ms -> 250000us -> 250000000ns
  Reset_TFT(true);
  sleep.tv_nsec = 6000000L;
  nanosleep(&sleep, NULL); // para 0.006s -> 6ms -> 6000us -> 6000000ns

  uint8_t driverCode = Read_SPI_TFT_Reg(0x00); // esto no se usa

  // Start Initial Sequence
  Write_SPI_TFT_Reg(0xEA, 0x0000);    // Reset Power Control 1
  Write_SPI_TFT_Reg(0xEB, 0x0020);    // Power Control 2
  Write_SPI_TFT_Reg(0xEC, 0x000C);    // Power Control 3
  Write_SPI_TFT_Reg(0xED, 0x00C4);    // Power Control 4
  Write_SPI_TFT_Reg(0xE8, 0x0040);    // Source OPON_N
  Write_SPI_TFT_Reg(0xE9, 0x0038);    // Source OPON_I
  Write_SPI_TFT_Reg(0xF1, 0x0001);
  Write_SPI_TFT_Reg(0xF2, 0x0010);
  Write_SPI_TFT_Reg(0x27, 0x00A3);    // Display Control 2

  // Power On sequence
  Write_SPI_TFT_Reg(0x1B, 0x001B);    // Power Control 2
  Write_SPI_TFT_Reg(0x1A, 0x0001);    // Power Control 1
  Write_SPI_TFT_Reg(0x24, 0x002F);    // Vcom Control 2
  Write_SPI_TFT_Reg(0x25, 0x0057);    // Vcom Control 3
  Write_SPI_TFT_Reg(0x23, 0x008D);    // Vcom Control 1

  // Gamma settings
  Write_SPI_TFT_Reg(0x40,0x00);
  Write_SPI_TFT_Reg(0x41,0x00);
  Write_SPI_TFT_Reg(0x42,0x01);
  Write_SPI_TFT_Reg(0x43,0x13);
  Write_SPI_TFT_Reg(0x44,0x10);
  Write_SPI_TFT_Reg(0x45,0x26);
  Write_SPI_TFT_Reg(0x46,0x08);
  Write_SPI_TFT_Reg(0x47,0x51);
  Write_SPI_TFT_Reg(0x48,0x02);
  Write_SPI_TFT_Reg(0x49,0x12);
  Write_SPI_TFT_Reg(0x4A,0x18);
  Write_SPI_TFT_Reg(0x4B,0x19);
  Write_SPI_TFT_Reg(0x4C,0x14);
  Write_SPI_TFT_Reg(0x50,0x19);
  Write_SPI_TFT_Reg(0x51,0x2F);
  Write_SPI_TFT_Reg(0x52,0x2C);
  Write_SPI_TFT_Reg(0x53,0x3E);
  Write_SPI_TFT_Reg(0x54,0x3F);
  Write_SPI_TFT_Reg(0x55,0x3F);
  Write_SPI_TFT_Reg(0x56,0x2E);
  Write_SPI_TFT_Reg(0x57,0x77);
  Write_SPI_TFT_Reg(0x58,0x0B);
  Write_SPI_TFT_Reg(0x59,0x06);
  Write_SPI_TFT_Reg(0x5A,0x07);
  Write_SPI_TFT_Reg(0x5B,0x0D);
  Write_SPI_TFT_Reg(0x5C,0x1D);
  Write_SPI_TFT_Reg(0x5D,0xCC);

  // Power + Osc
  Write_SPI_TFT_Reg(0x18,0x0036);       // OSC Control 1
  Write_SPI_TFT_Reg(0x19,0x0001);       // OSC Control 2
  Write_SPI_TFT_Reg(0x01,0x0000);       // Display Mode Control
  Write_SPI_TFT_Reg(0x1F,0x0088);       // Power Control 6
  sleep.tv_nsec = 5000000L;
  nanosleep(&sleep, NULL); // 0.005s -> 5ms -> 5000us -> 5000000ns
  Write_SPI_TFT_Reg(0x1F,0x0080);       // Power Control 6
  sleep.tv_nsec = 5000000L;
  nanosleep(&sleep, NULL); // 0.005s -> 5ms -> 5000us -> 5000000ns
  Write_SPI_TFT_Reg(0x1F,0x0090);       // Power Control 6
  sleep.tv_nsec = 5000000L;
  nanosleep(&sleep, NULL); // 0.005s -> 5ms -> 5000us -> 5000000ns
  Write_SPI_TFT_Reg(0x1F,0x00D0);       // Power Control 6
  sleep.tv_nsec = 5000000L;
  nanosleep(&sleep, NULL); // 0.005s -> 5ms -> 5000us -> 5000000ns

  // Appearance
  Write_SPI_TFT_Reg(0x17,0x0005);       // Colmod 16Bit/Pixel
  Write_SPI_TFT_Reg(0x36,0x0000);       // Panel Characteristic
  Write_SPI_TFT_Reg(0x28,0x0038);       // Display Control 3
  sleep.tv_nsec = 40000000L;
  nanosleep(&sleep, NULL); // 0.04s -> 40ms -> 40000us -> 40000000ns
  Write_SPI_TFT_Reg(0x28,0x003C);       // Display Control 3
  sleep.tv_nsec = 2000000L;
  nanosleep(&sleep, NULL); // 0.002s -> 2ms -> 2000us -> 2000000ns
  Write_SPI_TFT_Reg(0x16,0x0008);       // Orientation
  Write_SPI_TFT_Reg(0x03,(Orig_X>>0));  // Set Dimensions
  Write_SPI_TFT_Reg(0x02,(Orig_X>>8));
  Write_SPI_TFT_Reg(0x05,(Size_X-1>>0));
  Write_SPI_TFT_Reg(0x04,(Size_X-1>>8));
  Write_SPI_TFT_Reg(0x07,(Orig_Y>>0));
  Write_SPI_TFT_Reg(0x06,(Orig_Y>>8));
  Write_SPI_TFT_Reg(0x09,(Size_Y-1>>0));
  Write_SPI_TFT_Reg(0x08,(Size_Y-1>>8)); // PROBAR PRIORIDAD DE OPERADORES
}

#endif // TFTDRIVER_H
