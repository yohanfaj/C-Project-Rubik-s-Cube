#ifndef RUBIKS_H_
#define RUBIKS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "conio.h"
#define FACE 6
#define SIZE 3

    
/* ENUM VARIABLES */

typedef enum T_SIDE
{
    FRONT=1,
    BACK=2,
    UP=3,
    DOWN=4,
    RIGHT=5,
    LEFT=6,
}T_SIDE;


typedef enum T_COLOR
{
    RED_CASE=10,
    BLUE_CASE=20,
    GREEN_CASE=30,
    WHITE_CASE=40,
    YELLOW_CASE=50,
    ORANGE_CASE=60,
    LG_CASE=70,
}T_COLOR;


/* ENUM TYPE FUNCTIONS */

T_COLOR select_color();
T_SIDE side_to_index();
const char* index_to_side(int i);


/* CUBE REPRESENTATION FUNCTIONS */
void create_rubiks(char ****rubiks);
void init_rubiks(char ***rubiks);
void display_rubiks(char ***rubiks);
void blank_rubiks();
void fill_rubiks();
void scramble_rubiks();
void free_rubiks(char ***rubiks);


/* MOVEMENT FUNCTIONS */
void FRONT_clockwise();
void BACK_clockwise();
void UP_cloxkwise();
void DOWN_clockwise();
void RIGHT_clockwise();
void LEFT_clockwise();

void FRONT_anticlockwise();
void BACK_anticlockwise();
void UP_anticlockwise();
void DOWN_anticlockwise();
void RIGHT_anticlockwise();
void LEFT_anticlockwise();

void horizontal_rotation();
void vertical_rotation();
int move_rubiks();

#endif