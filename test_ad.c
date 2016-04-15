#include <iostream>
#include "ad_driver.h"
#include <bcm2835.h>
#include <time.h>
#include <unistd.h>

int main() {

  bcm2835_init();
  AD::init();
  uint16_t x, y;
  while(1) {
    
    x = AD::readX();
    y = AD::readY();
    std::cout << std::hex << x;
    std::cout << " " << std::hex << y << std::endl;
    usleep(500000);
  }
  bcm2835_close();

}
