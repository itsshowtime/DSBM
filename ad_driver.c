#include "ad_driver.h"

void AD::init() {
  bcm2835_gpio_fsel(CS_Pin, BCM2835_GPIO_FSEL_OUTP);
  bcm2835_gpio_write(CS_Pin, HIGH);
  bcm2835_gpio_fsel(CLK_Pin, BCM2835_GPIO_FSEL_OUTP);
  bcm2835_gpio_write(CLK_Pin, LOW);
  bcm2835_gpio_fsel(MISO_Pin, BCM2835_GPIO_FSEL_INPT);
  bcm2835_gpio_fsel(MOSI_Pin, BCM2835_GPIO_FSEL_OUTP);

  bcm2835_gpio_fsel(xpos_Pin, BCM2835_GPIO_FSEL_INPT);
  bcm2835_gpio_fsel(xneg_Pin, BCM2835_GPIO_FSEL_INPT);
  bcm2835_gpio_fsel(ypos_Pin, BCM2835_GPIO_FSEL_INPT);
  bcm2835_gpio_fsel(yneg_Pin, BCM2835_GPIO_FSEL_INPT);
}

uint16_t AD::readX() {
  bcm2835_gpio_fsel(xpos_Pin, BCM2835_GPIO_FSEL_OUTP);
  bcm2835_gpio_fsel(xneg_Pin, BCM2835_GPIO_FSEL_OUTP);
  bcm2835_gpio_fsel(ypos_Pin, BCM2835_GPIO_FSEL_INPT);
  bcm2835_gpio_fsel(yneg_Pin, BCM2835_GPIO_FSEL_INPT);

  bcm2835_gpio_write(xneg_Pin, HIGH);
  bcm2835_gpio_write(xpos_Pin, LOW);

  // Start transaction
  bcm2835_gpio_write(CS_Pin, LOW);
  bcm2835_gpio_write(MOSI_Pin, HIGH);

  bcm2835_gpio_write(CLK_Pin, HIGH);
  bcm2835_gpio_write(CLK_Pin, LOW);
  bcm2835_gpio_write(CLK_Pin, HIGH);
  bcm2835_gpio_write(CLK_Pin, LOW);

  // Chanel = 0 0 0
  bcm2835_gpio_write(MOSI_Pin, LOW);
  bcm2835_gpio_write(CLK_Pin, HIGH);  // chanel[2]
  bcm2835_gpio_write(CLK_Pin, LOW);
  bcm2835_gpio_write(CLK_Pin, HIGH);  // chanel[1]
  bcm2835_gpio_write(CLK_Pin, LOW);
  bcm2835_gpio_write(CLK_Pin, HIGH);  // chanel[0]
  bcm2835_gpio_write(CLK_Pin, LOW);
  bcm2835_gpio_write(CLK_Pin, HIGH);  // Send Trash
  bcm2835_gpio_write(CLK_Pin, LOW);
  bcm2835_gpio_write(CLK_Pin, HIGH);  // Recieve Trash
  bcm2835_gpio_write(CLK_Pin, LOW);

  // Read data
  uint16_t data = 0x00;
  for (int i = 11; i >= 0; --i) {
    bcm2835_gpio_write(CLK_Pin, HIGH);  // Recieve B[i]
    bcm2835_gpio_write(CLK_Pin, LOW);
    uint8_t read = bcm2835_gpio_lev(MISO_Pin);
    data = data<<1 | read&0x1;
  }

  bcm2835_gpio_write(CS_Pin, HIGH);
  bcm2835_gpio_fsel(xpos_Pin, BCM2835_GPIO_FSEL_INPT);
  bcm2835_gpio_fsel(xneg_Pin, BCM2835_GPIO_FSEL_INPT);
  bcm2835_gpio_fsel(ypos_Pin, BCM2835_GPIO_FSEL_INPT);
  bcm2835_gpio_fsel(yneg_Pin, BCM2835_GPIO_FSEL_INPT);

  return data;
}

uint16_t AD::readY() {
  bcm2835_gpio_fsel(xpos_Pin, BCM2835_GPIO_FSEL_INPT);
  bcm2835_gpio_fsel(xneg_Pin, BCM2835_GPIO_FSEL_INPT);
  bcm2835_gpio_fsel(ypos_Pin, BCM2835_GPIO_FSEL_OUTP);
  bcm2835_gpio_fsel(yneg_Pin, BCM2835_GPIO_FSEL_OUTP);

  bcm2835_gpio_write(yneg_Pin, LOW);
  bcm2835_gpio_write(ypos_Pin, HIGH);

  // Start transaction
  bcm2835_gpio_write(CS_Pin, LOW);
  bcm2835_gpio_write(MOSI_Pin, HIGH);

  bcm2835_gpio_write(CLK_Pin, HIGH);
  bcm2835_gpio_write(CLK_Pin, LOW);
  bcm2835_gpio_write(CLK_Pin, HIGH);
  bcm2835_gpio_write(CLK_Pin, LOW);

  // Chanel = 0 0 0
  bcm2835_gpio_write(MOSI_Pin, LOW);
  bcm2835_gpio_write(CLK_Pin, HIGH);  // chanel[2]
  bcm2835_gpio_write(CLK_Pin, LOW);
  bcm2835_gpio_write(CLK_Pin, HIGH);  // chanel[1]
  bcm2835_gpio_write(CLK_Pin, LOW);
  bcm2835_gpio_write(MOSI_Pin, HIGH);
  bcm2835_gpio_write(CLK_Pin, HIGH);  // chanel[0]
  bcm2835_gpio_write(CLK_Pin, LOW);
  bcm2835_gpio_write(CLK_Pin, HIGH);  // Send Trash
  bcm2835_gpio_write(CLK_Pin, LOW);
  bcm2835_gpio_write(CLK_Pin, HIGH);  // Recieve Trash
  bcm2835_gpio_write(CLK_Pin, LOW);

  // Read data
  uint16_t data = 0x00;
  for (int i = 11; i >= 0; --i) {
    bcm2835_gpio_write(CLK_Pin, HIGH);  // Recieve B[i]
    bcm2835_gpio_write(CLK_Pin, LOW);
    uint8_t read = bcm2835_gpio_lev(MISO_Pin);
    data = data<<1 | read&0x1;
  }

  bcm2835_gpio_write(CS_Pin, HIGH);
  bcm2835_gpio_fsel(xpos_Pin, BCM2835_GPIO_FSEL_INPT);
  bcm2835_gpio_fsel(xneg_Pin, BCM2835_GPIO_FSEL_INPT);
  bcm2835_gpio_fsel(ypos_Pin, BCM2835_GPIO_FSEL_INPT);
  bcm2835_gpio_fsel(yneg_Pin, BCM2835_GPIO_FSEL_INPT);

  return data;
}
