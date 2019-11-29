#include "tga.h"


void create_tga_blank (const char* filename, int width, int height)
{
    Picture* pic = (Picture*)malloc(sizeof(Picture));
    pic->width = width;
    pic->height = height;
    pic->size = width*height;

    pic->head = (Header*)malloc(sizeof(Header));
    pic->head->idlength = 0;
    pic->head->colourmaptype = 0;
    pic->head->datatypecode = 2;
    pic->head->colourmaporigin = 0;
    pic->head->colourmaplength = 0;
    pic->head->colourmapdepth = 0;
    pic->head->x_origin = 0;
    pic->head->y_origin = 0;
    pic->head->width = pic->width;
    pic->head->height = pic->height;
    pic->head->bitsperpixel = 24;
    pic->head->imagedescriptor = 0;

    pic->RGBdata = (Pixel*)malloc(sizeof(Pixel) * pic->size);
    for (int i = 0; i < pic->size; i++)
    {
        pic->RGBdata[i].b = 127;
        pic->RGBdata[i].g = 0;
        pic->RGBdata[i].r = 255;
    }



    FILE* blanktga = fopen(filename, "wb");
    if(blanktga == NULL) return;
    fwrite(&pic->head->idlength, sizeof(pic->head->idlength),1,blanktga);
    fwrite(&pic->head->colourmaptype, sizeof(pic->head->colourmaptype),1,blanktga);
    fwrite(&pic->head->datatypecode, sizeof(pic->head->datatypecode),1,blanktga);
    fwrite(&pic->head->colourmaporigin, sizeof(pic->head->colourmaporigin),1,blanktga);
    fwrite(&pic->head->colourmaplength, sizeof(pic->head->colourmaplength),1,blanktga);
    fwrite(&pic->head->colourmapdepth, sizeof(pic->head->colourmapdepth),1,blanktga);
    fwrite(&pic->head->x_origin, sizeof(pic->head->x_origin),1,blanktga);
    fwrite(&pic->head->y_origin, sizeof(pic->head->y_origin),1,blanktga);
    fwrite(&pic->head->width, sizeof(pic->head->width),1,blanktga);
    fwrite(&pic->head->height, sizeof(pic->head->height),1,blanktga);
    fwrite(&pic->head->bitsperpixel, sizeof(pic->head->bitsperpixel),1,blanktga);
    fwrite(&pic->head->imagedescriptor, sizeof(pic->head->imagedescriptor),1,blanktga);


    
    for (int i = 0; i < pic->size; i++) fwrite(&pic->RGBdata[i], sizeof(Pixel), 1 , blanktga);


    fclose(blanktga);
    free(pic->head);
    free(pic);
}

