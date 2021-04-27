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
    printf("Here is a blank rubiks cube: \n");
    init_rubiks(rubiks);
    display_rubiks(rubiks);
    
    printf("Please fill the cube with the following letters: R for RED, B for BLUE, G for GREEN, Y for YELLOW, O for ORANGE or W for WHITE: \n");
    fill_face(rubiks);
    printf("Here is your custom rubiks cube: \n");
    display_rubiks(rubiks);
    free_rubiks(rubiks);
}

