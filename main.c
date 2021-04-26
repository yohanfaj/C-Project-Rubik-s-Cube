#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "conio.h"
#include "rubiks.c"
#define FACE 6
#define SIZE 3


void main(void)
{
    int i,j,k;
    char ***rubiks = create_rubiks();
    printf("Here is the rubiks cube: \n");
    init_rubiks(rubiks);
    display_rubiks(rubiks);
    free_rubiks(rubiks);
}

