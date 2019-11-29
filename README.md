# TGA_picture_beta_0.1
a simple program in C that so far can create a TGA image of any color, any size ;D
In main.c there's only one function, if you want to change the color of an image go to tga.c,
ther's an initialization loop that looks probably like this:

for (int i = 0; i < pic->size; i++)
    {
        pic->RGBdata[i].b = 127;  --value of blue color
        pic->RGBdata[i].g = 0;    --value of green
        pic->RGBdata[i].r = 255;  --value of red
    }

you can modify the value, it's simple enough.

There might be some problems with opening .tga files on Windows, but there's an app called TGA viewer
Since i'm operating on Ubuntu 18.4 there seems to be no problem with opening the file.

it opens it with the Ubuntu default image viewer, but there's another app, it's Eye of MATE image viewer.
there's an option to show the image without blurring the pixels, which is no tavailable for the Ubuntu default image app.

I might add some theory that stands behind TGA images later, but simply enough
you gotta make a tga file first, write a TGA header into it, which is 18 bytes long.
the rest is just the image data.


