#ifndef RUBIKS_H_
#define RUBIKS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "conio.h"
#define FACE 6
#define SIZE 3
    

/* ENUM VARIABLES */

enum T_SIDE {UP,LEFT,FRONT,RIGHT,BACK,DOWN};


enum T_COLOR{RED_CASE=12,BLUE_CASE=9,GREEN_CASE=2,WHITE_CASE=15,YELLOW_CASE=14,ORANGE_CASE=4,LG_CASE=7};


/* ENUM TYPE FUNCTIONS */

enum T_COLOR select_color(char color);
enum T_SIDE side_to_index(char[] side);
const char* index_to_side(int i);


/* CUBE REPRESENTATION FUNCTIONS */
char*** create_rubiks();
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

/* TEXT COLOR */
void text_color(int color);

#endif