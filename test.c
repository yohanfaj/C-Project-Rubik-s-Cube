#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "rubiks.c"
#define FACE 6
#define SIZE 3

void main(void)
{
    int i,j,k, op;
    int op_move_cube, op_clock, op_side, type;
    int init=0;
    int solved=0, cont=1, step;
    char ***rubiks = create_rubiks();
    init_rubiks(rubiks);
    display_rubiks(rubiks);
    scramble_rubiks(rubiks);
    display_rubiks(rubiks);
    
    perfect_cross(rubiks);
    display_rubiks(rubiks);
    first_crown(rubiks);
    display_rubiks(rubiks);
    second_crown(rubiks);
    display_rubiks(rubiks);
    last_crown(rubiks);
    display_rubiks(rubiks);
    
    /*
    UP_anticlockwise(rubiks);
    display_rubiks(rubiks);
    */
    free_rubiks(rubiks);
}