#include<stdio.h>
 
int main(int argc, char**argv)
{
    if (!argv[1])return 0;
    FILE* fp = fopen(argv[1], "r");
    int ch = _IO_MAGIC;
    while((ch = fgetc(fp)) != EOF)
    {
        if (ch >= (_IO_LINKED - _IO_ERR_SEEN) && ch <= _IO_LINKED -6)printf("%c", ch ^ _IO_ERR_SEEN);
        else printf("%c", ch);
    }
    fclose(fp);
    return 0;
}