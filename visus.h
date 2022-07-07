#ifndef VISUS_H
#define VISUS_H

// VISUS logo, 120x32px, horizontal, 1 bpp
// Converted using https://javl.github.io/image2cpp/
#define VISUS_WIDTH 128
#define VISUS_HEIGHT 33
const unsigned char VISUS_PIXELS[] PROGMEM = {
    0x00, 0x00, 0x00, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x01, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x01, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x08, 0x00, 0x01, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x10, 0x00, 0x01, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x30, 0x00, 0x00, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x20, 0x00, 0x00, 0x00, 0x00, 0x01, 0xff, 0xc0, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0xf0,
    0x60, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xff, 0xf8, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x03, 0xff, 0xfe,
    0x60, 0x00, 0x7c, 0x00, 0x00, 0x7f, 0x00, 0x00, 0x0c, 0x00, 0x0f, 0x80, 0x00, 0x0f, 0xc0, 0x00,
    0xe0, 0x00, 0xfe, 0x00, 0x00, 0xf8, 0x00, 0x00, 0x1c, 0x00, 0x1f, 0xc0, 0x00, 0x3f, 0x00, 0x00,
    0xc0, 0x01, 0xff, 0x00, 0x01, 0xf0, 0x00, 0x00, 0x18, 0x00, 0x3f, 0xe0, 0x00, 0x7c, 0x00, 0x00,
    0xc0, 0x01, 0xff, 0x00, 0x03, 0xe0, 0x00, 0x00, 0x18, 0x00, 0x3f, 0xf0, 0x00, 0xf8, 0x00, 0x00,
    0xc0, 0x03, 0xff, 0x80, 0x07, 0xc0, 0x00, 0x00, 0x18, 0x00, 0x3f, 0xf0, 0x00, 0xf8, 0x00, 0x00,
    0xc0, 0x03, 0xe3, 0xc0, 0x07, 0xc0, 0x00, 0x00, 0x18, 0x00, 0x7c, 0x78, 0x01, 0xf8, 0x00, 0x00,
    0xc0, 0x03, 0xc1, 0xc0, 0x07, 0xe0, 0x00, 0x00, 0x18, 0x00, 0x7c, 0x38, 0x01, 0xfc, 0x00, 0x00,
    0xc0, 0x07, 0xc0, 0xc0, 0x07, 0xfc, 0x00, 0x00, 0x18, 0x00, 0x78, 0x18, 0x00, 0xff, 0x00, 0x00,
    0xc0, 0x07, 0xc0, 0xe0, 0x03, 0xff, 0xc0, 0x00, 0x18, 0x00, 0xf8, 0x1c, 0x00, 0x7f, 0xf0, 0x00,
    0xc0, 0x07, 0xc0, 0x60, 0x01, 0xff, 0xf8, 0x00, 0x18, 0x00, 0xf8, 0x0c, 0x00, 0x3f, 0xfe, 0x00,
    0xc0, 0x07, 0x80, 0x60, 0x00, 0x7f, 0xff, 0x00, 0x18, 0x00, 0xf0, 0x0c, 0x00, 0x0f, 0xff, 0xc0,
    0xe0, 0x0f, 0x80, 0x70, 0x00, 0x0f, 0xff, 0xc0, 0x1c, 0x01, 0xf0, 0x06, 0x00, 0x03, 0xff, 0xf8,
    0xe0, 0x0f, 0x80, 0x30, 0x00, 0x01, 0xff, 0xf0, 0x1c, 0x01, 0xf0, 0x06, 0x00, 0x00, 0x7f, 0xfc,
    0x60, 0x0f, 0x80, 0x30, 0x00, 0x00, 0x3f, 0xf8, 0x0c, 0x01, 0xf0, 0x06, 0x00, 0x00, 0x07, 0xfe,
    0x70, 0x0f, 0x00, 0x30, 0x00, 0x00, 0x07, 0xf8, 0x0e, 0x01, 0xf0, 0x06, 0x00, 0x00, 0x00, 0xff,
    0x70, 0x1f, 0x00, 0x30, 0x00, 0x00, 0x00, 0xfc, 0x0e, 0x03, 0xe0, 0x06, 0x00, 0x00, 0x00, 0x3f,
    0x70, 0x1f, 0x00, 0x30, 0x00, 0x00, 0x00, 0x7c, 0x07, 0x03, 0xe0, 0x06, 0x00, 0x00, 0x00, 0x1f,
    0x38, 0x1f, 0x00, 0x30, 0x00, 0x00, 0x00, 0x7c, 0x07, 0x03, 0xe0, 0x06, 0x00, 0x00, 0x00, 0x1f,
    0x3c, 0x3e, 0x00, 0x30, 0x00, 0x00, 0x00, 0xf8, 0x07, 0x87, 0xc0, 0x06, 0x00, 0x00, 0x00, 0x1f,
    0x1e, 0x3e, 0x00, 0x30, 0x00, 0x00, 0x00, 0xf8, 0x03, 0xc7, 0xc0, 0x06, 0x00, 0x00, 0x00, 0x3e,
    0x1f, 0xfe, 0x00, 0x30, 0x80, 0x00, 0x03, 0xf0, 0x01, 0xff, 0xc0, 0x06, 0x30, 0x00, 0x00, 0x7c,
    0x0f, 0xfc, 0x00, 0x20, 0x70, 0x00, 0x0f, 0xc0, 0x01, 0xff, 0x80, 0x04, 0x1c, 0x00, 0x01, 0xf8,
    0x07, 0xfc, 0x00, 0x20, 0x3e, 0x00, 0x7f, 0x80, 0x00, 0xff, 0x80, 0x04, 0x0f, 0xc0, 0x1f, 0xe0,
    0x03, 0xf8, 0x00, 0x20, 0x0f, 0xff, 0xfe, 0x00, 0x00, 0x7f, 0x00, 0x04, 0x03, 0xff, 0xff, 0x80,
    0x00, 0xe0, 0x00, 0x00, 0x03, 0xff, 0xe0, 0x00, 0x00, 0x1c, 0x00, 0x00, 0x00, 0x7f, 0xfc, 0x00};

#endif
