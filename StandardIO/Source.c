//Standard IO with Command Line Inputs

//Refer to Example02 in Week 6 on ProfessorSteveH GitHub account
//Link: https://github.com/ProfessorSteveH/PROG71985F22/blob/main/week06/00Tues/example02/Source.c#L31


#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <stdlib.h> // exit() prototype

int main(int argc, char* argv[])
{
    int ch;         // place to store each character as read
    FILE* fp;       // "file pointer"
    unsigned long count = 0;

    if (argc != 2)          // ** I set command line parameters in project properties.
    {
        printf("Usage: %s filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if ((fp = fopen(argv[1], "r")) == NULL)
    {
        printf("Can't open %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while ((ch = getc(fp)) != EOF)
    {
        putc(ch, stdout);  // same as putchar(ch);
        count++;
    }

    fclose(fp);
    printf("\nFile %s has %lu characters\n", argv[1], count);

    return 0;
}