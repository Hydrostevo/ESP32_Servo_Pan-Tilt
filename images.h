#define Skull_width 37
#define Skull_height 60

#define WIFI_width 14
#define WIFI_height 8

#define Skull_neg_width 37
#define Skull_neg_height 60

const unsigned char WIFI_bits[] PROGMEM = {
  0xF0, 0x03, 0x04, 0x08, 0xF2, 0x13, 0x09, 0x24, 0xE4, 0x09, 0x10, 0x02, 
  0xC0, 0x00, 0xC0, 0x00,
  };

  
static unsigned char Skull_bits[] PROGMEM = {
   0x00, 0x40, 0x3f, 0x00, 0x00, 0x00, 0x78, 0x80, 0x07, 0x00, 0x00, 0x01,
   0x00, 0x10, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x80,
   0x00, 0x10, 0x00, 0x00, 0x00, 0x01, 0x08, 0x00, 0x00, 0x00, 0x02, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00,
   0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x01, 0x00, 0x00, 0x00, 0x10, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x10, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x10, 0x01, 0x00, 0x00, 0x00, 0x08, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x08, 0x01, 0x00, 0x00, 0x00, 0x10, 0x01, 0x00, 0x00,
   0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x08, 0x0a, 0x00, 0x00, 0x00, 0x09,
   0x16, 0x00, 0x11, 0x00, 0x0e, 0xce, 0x03, 0x0a, 0x79, 0x06, 0xec, 0x17,
   0x04, 0xfd, 0x06, 0xe8, 0x3d, 0x80, 0xfb, 0x02, 0xe8, 0x3c, 0x80, 0xf9,
   0x00, 0xe0, 0x7f, 0xc0, 0xff, 0x00, 0xc0, 0xff, 0xf1, 0x7f, 0x02, 0x80,
   0xff, 0xf0, 0x3f, 0x00, 0x00, 0x7f, 0xa0, 0x1f, 0x00, 0x04, 0x1e, 0x00,
   0x1f, 0x00, 0x80, 0x03, 0x00, 0x0c, 0x00, 0x02, 0x04, 0x0a, 0x10, 0x08,
   0x00, 0x00, 0x0a, 0x00, 0x00, 0x02, 0x00, 0x1b, 0x00, 0x08, 0x04, 0x00,
   0x1f, 0x00, 0x04, 0x08, 0x00, 0x13, 0x10, 0x02, 0xf0, 0x07, 0x08, 0xfc,
   0x01, 0xc0, 0x07, 0x00, 0x7c, 0x00, 0xc0, 0x02, 0x00, 0x68, 0x00, 0xc0,
   0x00, 0x00, 0x48, 0x00, 0x00, 0x0a, 0x05, 0x22, 0x00, 0x40, 0x60, 0xd5,
   0x42, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x40, 0x04, 0x00, 0x04, 0x00,
   0x00, 0x1c, 0x00, 0x07, 0x00, 0x00, 0xf0, 0xf5, 0x01, 0x00, 0x40, 0xc0,
   0x7f, 0x40, 0x00, 0x00, 0x08, 0x3f, 0x02, 0x00, 0x00, 0x00, 0x00, 0x01,
   0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x02, 0x14, 0x08, 0x00, 0x00,
   0x04, 0x00, 0x02, 0x00, 0x00, 0x08, 0x00, 0x02, 0x00, 0x00, 0x10, 0x00,
   0x01, 0x00, 0x00, 0x20, 0x80, 0x00, 0x00, 0x00, 0x00, 0x2b, 0x00, 0x00 }; 

// Negative skull
static unsigned char Skull_neg_bits[] PROGMEM = {
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x37, 0x00, 0x00, 0x00, 0xe8,
   0xff, 0x09, 0x00, 0x00, 0xff, 0xff, 0x1f, 0x00, 0xc0, 0xff, 0xff, 0x7f,
   0x00, 0xe0, 0xff, 0xff, 0xff, 0x00, 0xf0, 0xff, 0xff, 0xff, 0x01, 0xf8,
   0xff, 0xff, 0xff, 0x03, 0xf8, 0xff, 0xff, 0xff, 0x03, 0xfc, 0xff, 0xff,
   0xff, 0x07, 0xfc, 0xff, 0xff, 0xff, 0x07, 0xfc, 0xff, 0xff, 0xff, 0x0f,
   0xfe, 0xff, 0xff, 0xff, 0x07, 0xfe, 0xff, 0xff, 0xff, 0x0f, 0xfc, 0xff,
   0xff, 0xff, 0x17, 0xfd, 0xff, 0xff, 0xff, 0x07, 0xfe, 0xff, 0xff, 0xff,
   0x0f, 0xfc, 0xff, 0xff, 0xff, 0x07, 0xfc, 0xff, 0xff, 0xff, 0x17, 0xed,
   0xff, 0xff, 0xff, 0x06, 0xfc, 0xff, 0xff, 0xff, 0x17, 0xfd, 0xff, 0xff,
   0xff, 0x07, 0xec, 0xff, 0xff, 0xfe, 0x16, 0xe0, 0xbf, 0xce, 0xff, 0x01,
   0x70, 0xf7, 0xe4, 0xdd, 0x00, 0x20, 0xec, 0xf5, 0x85, 0x01, 0x10, 0xa0,
   0x3b, 0x02, 0x01, 0x10, 0xc0, 0x7b, 0x00, 0x01, 0x10, 0x02, 0x5f, 0x04,
   0x01, 0x10, 0x00, 0x1f, 0x00, 0x01, 0x10, 0x00, 0x0e, 0x00, 0x01, 0x38,
   0x00, 0x0e, 0x80, 0x01, 0x70, 0x00, 0x1f, 0xc0, 0x03, 0xf8, 0xc0, 0x7f,
   0xe0, 0x03, 0x78, 0xf0, 0xf7, 0xc1, 0x03, 0xfc, 0xfd, 0xf5, 0xeb, 0x07,
   0xfc, 0xff, 0xf5, 0xff, 0x07, 0xf8, 0xff, 0xe0, 0xff, 0x03, 0xe8, 0xff,
   0xe0, 0x7f, 0x03, 0xa0, 0x7a, 0xc4, 0xcb, 0x00, 0x00, 0xf0, 0xe4, 0x01,
   0x00, 0x00, 0xf8, 0xff, 0x03, 0x00, 0x00, 0xf8, 0xff, 0x03, 0x00, 0x00,
   0xfd, 0xff, 0x07, 0x00, 0x00, 0xa1, 0xaa, 0x18, 0x00, 0x80, 0x0f, 0x00,
   0x3a, 0x00, 0x80, 0xfb, 0xbb, 0x3b, 0x00, 0x80, 0xf3, 0xff, 0x3b, 0x00,
   0x80, 0xc3, 0x7f, 0x78, 0x00, 0x80, 0x0b, 0x00, 0x3a, 0x00, 0x80, 0x17,
   0x00, 0x3d, 0x00, 0x00, 0x67, 0xc0, 0x1d, 0x00, 0x00, 0xee, 0xff, 0x0e,
   0x00, 0x00, 0x9c, 0x3f, 0x0f, 0x00, 0x00, 0x7c, 0xc0, 0x03, 0x00, 0x00,
   0xf8, 0xff, 0x03, 0x00, 0x00, 0xe0, 0xff, 0x00, 0x00, 0x00, 0xc0, 0xff,
   0x00, 0x00, 0x00, 0x80, 0x35, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
