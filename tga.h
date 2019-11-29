#include <inttypes.h>
#ifndef TGA_HEADERS
#define TGA_HEADERS

typedef struct __attribute__((__packed__))
/*if program doesn't compile, just get rid of the attrib, it's for gcc compilers*/
{
   uint8_t  idlength;
   uint8_t  colourmaptype;
   uint8_t  datatypecode;
   uint16_t colourmaporigin;
   uint16_t colourmaplength;
   uint8_t  colourmapdepth;
   uint16_t x_origin;
   uint16_t y_origin;
   uint16_t width;
   uint16_t height;
   uint8_t  bitsperpixel;
   uint8_t  imagedescriptor;

} Header;

typedef struct
{
    uint8_t b,g,r;

} Pixel;

typedef struct
{
    int width;
    int height;
    int size;
    Header* head;
    Pixel* RGBdata;

} Picture;

void create_tga_blank (const char* filename, int width, int height);
#endif