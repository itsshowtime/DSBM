#ifndef ASCII_H
#define ASCII_H

// ASCII characters are defined as a 8x8 logic matrix
// Values are separated into upper and lower path of the characters because of errors with uint128_t
// Each character starts at its upper left corner

typedef struct {
  uint64_t high, low;
} ascii;

const ascii ascii_map[] = {
  {0x00000000,0x00000000}, // SPACE
  {0x18181818,0x18001800}, // !
  {0x6C6C6C00,0x00000000}, // "
  {0x6C6CFE6C,0xFE6C6C00}, // #
  {0x187EC07C,0x06FC1800}, // $
  {0x00C6CC18,0x3066C600}, // %
  {0x386C3876,0xDCCC7600}, // &
  {0x30306000,0x00000000}, // '
  {0x0C183030,0x30180C00}, // (
  {0x30180C0C,0x0C183000}, // )
  {0x00663CFF,0x3C660000}, // *
  {0x0018187E,0x18180000}, // +
  {0x00000000,0x00181830}, // ,
  {0x0000007E,0x00000000}, // -
  {0x00000000,0x00181800}, // .
  {0x060C1830,0x60C08000}, // /
  {0x7CCED7F6,0xE6C67C00}, // 0
  {0x18381818,0x18187E00}, // 1
  {0x7CC6067C,0xC0C0FE00}, // 2
  {0xFC06063C,0x0606FC00}, // 3
  {0x0CCCCCCC,0xF70C0C00}, // 4
  {0xF7C0FC06,0x06C67C00}, // 5
  {0x7CC0C0FC,0xC6C67C00}, // 6
  {0xFE06060C,0x18303000}, // 7
  {0x7CC6C67C,0xC6C67C00}, // 8
  {0x7CC6C67E,0x06067C00}, // 9
  {0x00181800,0x00181800}, // :
  {0x00181800,0x00181830}, // ;
  {0x0C183060,0x30180C00}, // <
  {0x00007E00,0x7E000000}, // =
  {0x30180C06,0x0C183000}, // >
  {0x3C660C18,0x18001800}, // ?
  {0x7CC6DEDE,0xDEC07E00}, // @
  {0x386CC6C6,0xFEC6C600}, // A
  {0xFCC6C6FC,0xC6C6FC00}, // B
  {0x7CC6C0C0,0xC0C67C00}, // C
  {0xF8CCC6C6,0xC6CCF800}, // D
  {0xFEC0C0F8,0xC0C0FE00}, // E
  {0xFEC0C0F8,0xC0C0C000}, // F
  {0x7CC6C0C0,0xCEC67C00}, // G
  {0xC6C6C6FE,0xC6C6C600}, // H
  {0x7E181818,0x18187E00}, // I
  {0x06060606,0x06C67C00}, // J
  {0xC6CCD8F0,0xD8CCC600}, // K
  {0xC0C0C0C0,0xC0C0FE00}, // L
  {0xC6EEFEFE,0xD6C6C600}, // M
  {0xC6E6F6DE,0xCEC6C600}, // N
  {0x7CC6C6C6,0xC6C67C00}, // O
  {0xFCC6C6FC,0xC0C0C000}, // P
  {0x7CC6C6C6,0xD6DE7C06}, // Q
  {0xFCC6C6FC,0xD8CCC600}, // R
  {0x7CC6C07C,0x06C67C00}, // S
  {0xFF181818,0x18181800}, // T
  {0xC6C6C6C6,0xC6C6FE00}, // U
  {0xC6C6C6C6,0xC6763800}, // V
  {0xC6C6C6C6,0xD6FE6C00}, // W
  {0xC6C66C38,0x6CC6C600}, // X
  {0xC6C6C67C,0x1830E000}, // Y
  {0xFE060C18,0x3060FE00}, // Z
  {0x9E9090FE,0x1212F200}, // [ ... quizas no
  {0xC0603018,0x0C060300}, // \ .como mola C
  {0x3C0C0C0C,0x0C0C3C00}, // ]
  {0x183C6600,0x00000000}, // ^
  {0x00000000,0x0000FF00}, // _ // a lo mejor hay que cambiar FF por FC
  {0x18180C00,0x00000000}, // `
  {0x00003C06,0x3E663E00}, // a
  {0x60607C66,0x66667C00}, // b
  {0x00003C60,0x60603C00}, // c
  {0x06063E66,0x66663E00}, // d
  {0x00003C66,0x7E603C00}, // e
  {0x1C307C30,0x30303000}, // f
  {0x00003E66,0x663E063C}, // g
  {0x60607C66,0x66666600}, // h
  {0x18001818,0x18180C00}, // i
  {0x0C000C0C,0x0C0C0C78}, // j
  {0x6060666C,0x786C6600}, // k 
  {0x18181818,0x18180C00}, // l
  {0x0000ECFE,0xD6C6C600}, // m
  {0x00007C66,0x66666600}, // n
  {0x00003C66,0x66663C00}, // o
  {0x00007C66,0x667C6060}, // p
  {0x00003E66,0x663E0606}, // q
  {0x00007C66,0x60606000}, // r
  {0x00003C60,0x3C067C00}, // s
  {0x30307C30,0x30301C00}, // t
  {0x00006666,0x66663E00}, // u
  {0x00006666,0x663C1800}, // v
  {0x0000C6C6,0xD6FE6C00}, // w
  {0x0000C66C,0x386CC600}, // x
  {0x00006666,0x663C1830}, // y
  {0x00007E0C,0x18307E00}, // z
  {0x0C181830,0x18180C00}, // {
  {0x18181818,0x18181888}, // |
  {0x3018180C,0x18183000}, // }
  {0x076DC000,0x00000000}, // ~

  // No Faltan simbolos
};

#endif // ASCII_H
