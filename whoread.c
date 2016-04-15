#include "whoread.h"

Who::Who() { update(); }

void Who::update() {
  ifstream file("who.txt");
  if (file.is_open()) {
    getline(file, ip);

    // parse
    size_t left = ip.find("(");
    ip.erase(ip.begin(), ip.begin()+left+1);
    ip.erase(ip.end()-1);
  }

  file.close();
}
