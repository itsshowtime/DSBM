#ifndef ASCII_H
#define ASCII_H

typedef unsigned __int128 ascii;
ascii ascii_map[] = {
  0x0000000000000000, // SPACE
  0x1818181818001800, // !
  0x6C6C6C0000000000, // "
  0x6C6CFE6CFE6C6C00, // #
  0x187EC07C06FC1800, // $
  0x00C6CC183066C600, // %
  0x386C3876DCCC7600, // &
  0x3030600000000000, // '
  0x0C18303030180C00, // (
  0x30180C0C0C183000, // )
  0x00663CFF3C660000, // *
  0x0018187E18180000, // +
  0x0000000000181830, // ,
  0x0000007E00000000, // -
  0x0000000000181800, // .
  0x060C183060C08000, // /
  0x7CCED7F6E6C67C00, // 0
  0x1838181818187E00, // 1
  0x7CC6067CC0C0FE00, // 2
  0xFC06063C0606FC00, // 3
  0x0CCCCCCCF70C0C00, // 4
  0xF7C0FC0606C67C00, // 5
  0x7CC0C0FCC6C67C00, // 6
  0xFE06060C18303000, // 7
  0x7CC6C67CC6C67C00, // 8
  0x7CC6C67E06067C00, // 9
  0x0018180000181800, // :
  0x0018180000181830, // ;
  0x0C18306030180C00, // <
  0x00007E007E000000, // =
  0x30180C060C183000, // >
  0x3C660C1818001800, // ?
  0x7CC6DEDEDEC07E00, // @
  0x386CC6C6FEC6C600, // A
  0xFCC6C6FCC6C6FC00, // B
  0x7CC6C0C0C0C67C00, // C
  0xF8CCC6C6C6CCF800, // D
  0xFEC0C0F8C0C0FE00, // E
  0xFEC0C0F8C0C0C000, // F
  0x7CC6C0C0CEC67C00, // G
  0xC6C6C6FEC6C6C600, // H
  0x7E18181818187E00, // I
  0x0606060606C67C00, // J
  0xC6CCD8F0D8CCC600, // K
  0xC0C0C0C0C0C0FE00, // L
  0xC6EEFEFED6C6C600, // M
  0xC6E6F6DECEC6C600, // N
  0x7CC6C6C6C6C67C00, // O
  0xFCC6C6FCC0C0C000, // P
  0x7CC6C6C6D6DE7C06, // Q
  0xFCC6C6FCD1CCC600, // R
  0x7CC6C07C06C67C00, // S
  0xFF18181818181800, // T
  0xC6C6C6C6C6C6FE00, // U
  0xC6C6C6C6C6763100, // V
  0xC6C6C6C6D6FE6C00, // W
  0xC6C66C386CC6C600, // X
  0xC6C6C67C1830E000, // Y
  0xFE060C183060FE00  // Z
  // Faltan simbolos
};

#endif // ASCII_H