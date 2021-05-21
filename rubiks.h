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
char index_to_color(int i);
enum T_SIDE side_to_index(const char* side);
const char* index_to_side(int i);


/* CUBE REPRESENTATION FUNCTIONS */
char*** create_rubiks();
void init_rubiks(char ***rubiks);
void display_rubiks(char ***rubiks);
void blank_rubiks(char *** rubiks);
void scramble_rubiks(char ***rubiks);
void free_rubiks(char ***rubiks);

int get_cpt_color(char ***rubiks);
int check_comb_centers(char ***rubiks);
int check_comb_corners(char ***rubiks);
void fill_all_faces(char *** rubiks);


/* MOVEMENT FUNCTIONS */
void FRONT_clockwise(char ***rubiks, int type);
void BACK_clockwise(char ***rubiks, int type);
void UP_clockwise(char ***rubiks, int type);
void DOWN_clockwise(char ***rubiks, int type);
void RIGHT_clockwise(char ***rubiks, int type);
void LEFT_clockwise(char ***rubiks, int type);

void FRONT_anticlockwise(char ***rubiks, int type);
void BACK_anticlockwise(char ***rubiks, int type);
void UP_anticlockwise(char ***rubiks, int type);
void DOWN_anticlockwise(char ***rubiks, int type);
void RIGHT_anticlockwise(char ***rubiks, int type);
void LEFT_anticlockwise(char ***rubiks, int type);

void horizontal_rotation();
void vertical_rotation();
int move_rubiks();

/* TEXT COLOR */
void text_color(int color);

#endif