#include <stdio.h>
#include <stdlib.h>
#include "tga.h"
#include "tga.c"

int main(int argc, char **argv)
{
    create_tga_blank("image.tga", 500, 500);
    return 0;
} 