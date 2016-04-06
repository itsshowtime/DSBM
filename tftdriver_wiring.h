#ifndef TFTDRIVER_H
#define TFTDRIVER_H

#include <wiringPi.h>
#include <unistd.h> // usleep
#include <iostream> // cout

#define CS_Pin    8 // CE0
#define Reset_Pin 17 // pin11
#define SCLK_Pin  11 // CLK
#define SDO_Pin   9 // MISO
#define SDI_Pin   10 // MOSI

void Reset_TFT(bool value) {
  if (!value)
    digitalWrite(Reset_Pin, 1);
  else
    digitalWrite(Reset_Pin, 0);
}

// SPI Level Functions

uint8_t SPI_START = 0x70;
#define SPI_RD 0x01
#define SPI_WR 0x00
uint8_t SPI_DATA = 0x72;
#define SPI_INDEX 0x00

uint8_t Write_SPI_TFT_Cmd(uint8_t reg) {
  // reg is 8 bit

  // Send Start, Write, Index
  wiringPiSPIDataRW (0, &SPI_START, 1);
  // Send the value
  return wiringPiSPIDataRW (0, &reg, 1);
}

void Write_SPI_TFT_Dat(uint16_t value) {
  // value is 16 bit

  // Send Start, Write, Data
  wiringPiSPIDataRW (0, &SPI_DATA, 1);
  // Send the value
  uint8_t high = value>>8;
  uint8_t low = value;
  wiringPiSPIDataRW (0, &high, 1);
  wiringPiSPIDataRW (0, &low, 1);
}

void Write_SPI_TFT_Reg(uint8_t reg, uint16_t value) {

  // Sets a value to a reg
  Write_SPI_TFT_Cmd(reg);
  Write_SPI_TFT_Dat(value);
}

uint8_t Read_SPI_TFT_Reg(uint8_t reg) {

  // Sets a value to a reg
  Write_SPI_TFT_Cmd(reg);
  return 0x00;
}

// TFT Level Functions
uint16_t Orig_X = 0;
uint16_t Orig_Y = 0;
uint16_t Size_X = 240;
uint16_t Size_Y = 320;

void SPI_TFT_Reset() {
  // Reset the TFT
  pinMode(Reset_Pin, OUTPUT);
  Reset_TFT(false);
  usleep(250000); // para 0.25s -> 250ms -> 250000us -> 250000000ns
  Reset_TFT(true);
  usleep(6000); // para 0.006s -> 6ms -> 6000us -> 6000000ns
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
  Write_SPI_TFT_Reg(0x40,0x0000);
  Write_SPI_TFT_Reg(0x41,0x0000);
  Write_SPI_TFT_Reg(0x42,0x0001);
  Write_SPI_TFT_Reg(0x43,0x0013);
  Write_SPI_TFT_Reg(0x44,0x0010);
  Write_SPI_TFT_Reg(0x45,0x0026);
  Write_SPI_TFT_Reg(0x46,0x0008);
  Write_SPI_TFT_Reg(0x47,0x0051);
  Write_SPI_TFT_Reg(0x48,0x0002);
  Write_SPI_TFT_Reg(0x49,0x0012);
  Write_SPI_TFT_Reg(0x4A,0x0018);
  Write_SPI_TFT_Reg(0x4B,0x0019);
  Write_SPI_TFT_Reg(0x4C,0x0014);
  Write_SPI_TFT_Reg(0x50,0x0019);
  Write_SPI_TFT_Reg(0x51,0x002F);
  Write_SPI_TFT_Reg(0x52,0x002C);
  Write_SPI_TFT_Reg(0x53,0x003E);
  Write_SPI_TFT_Reg(0x54,0x003F);
  Write_SPI_TFT_Reg(0x55,0x003F);
  Write_SPI_TFT_Reg(0x56,0x002E);
  Write_SPI_TFT_Reg(0x57,0x0077);
  Write_SPI_TFT_Reg(0x58,0x000B);
  Write_SPI_TFT_Reg(0x59,0x0006);
  Write_SPI_TFT_Reg(0x5A,0x0007);
  Write_SPI_TFT_Reg(0x5B,0x000D);
  Write_SPI_TFT_Reg(0x5C,0x001D);
  Write_SPI_TFT_Reg(0x5D,0x00CC);

  // Power + Osc
  Write_SPI_TFT_Reg(0x18,0x0036);       // OSC Control 1
  Write_SPI_TFT_Reg(0x19,0x0001);       // OSC Control 2
  Write_SPI_TFT_Reg(0x01,0x0000);       // Display Mode Control
  Write_SPI_TFT_Reg(0x1F,0x0088);       // Power Control 6
  usleep(5000); // 0.005s -> 5ms -> 5000us -> 5000000ns
  Write_SPI_TFT_Reg(0x1F,0x0080);       // Power Control 6
  usleep(5000); // 0.005s -> 5ms -> 5000us -> 5000000ns
  Write_SPI_TFT_Reg(0x1F,0x0090);       // Power Control 6
  usleep(5000); // 0.005s -> 5ms -> 5000us -> 5000000ns
  Write_SPI_TFT_Reg(0x1F,0x00D0);       // Power Control 6
  usleep(5000); // 0.005s -> 5ms -> 5000us -> 5000000ns

  // Appearance
  Write_SPI_TFT_Reg(0x17,0x0005);       // Colmod 16Bit/Pixel
  Write_SPI_TFT_Reg(0x36,0x0000);       // Panel Characteristic
  Write_SPI_TFT_Reg(0x28,0x0038);       // Display Control 3
  usleep(40000); // 0.04s -> 40ms -> 40000us -> 40000000ns
  Write_SPI_TFT_Reg(0x28,0x003C);       // Display Control 3
  usleep(2000); // 0.002s -> 2ms -> 2000us -> 2000000ns
  Write_SPI_TFT_Reg(0x16,0x0008);       // Orientation
  Write_SPI_TFT_Reg(0x03,(Orig_X>>0));  // Set Dimensions
  Write_SPI_TFT_Reg(0x02,(Orig_X>>8));
  Write_SPI_TFT_Reg(0x05,((Size_X-1)>>0));
  Write_SPI_TFT_Reg(0x04,((Size_X-1)>>8));
  Write_SPI_TFT_Reg(0x07,(Orig_Y>>0));
  Write_SPI_TFT_Reg(0x06,(Orig_Y>>8));
  Write_SPI_TFT_Reg(0x09,((Size_Y-1)>>0));
  Write_SPI_TFT_Reg(0x08,((Size_Y-1)>>8));
}

#endif // TFTDRIVER_H
