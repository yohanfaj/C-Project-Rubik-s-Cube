#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "conio.h"
#include "rubiks.c"
#define FACE 6
#define SIZE 3


void main(void)
{
    int ***rubiks;
    create_rubiks(&rubiks);
    init_rubiks(rubiks);
    printf("Here is the rubiks cube: \n");
    display_rubiks(rubiks);
    free_rubiks(rubiks);
}

