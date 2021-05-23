#ifndef RUBIKS_H_
#define RUBIKS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#define FACE 6
#define SIZE 3
    

/* ENUM VARIABLES */

enum T_SIDE {UP,LEFT,FRONT,RIGHT,BACK,DOWN};


enum T_COLOR{RED_CELL=12,BLUE_CELL=9,GREEN_CELL=2,WHITE_CELL=15,YELLOW_CELL=14,ORANGE_CELL=4,LG_CELL=7};


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


/* FILLING THE CUBE FUNCTIONS */
int get_cpt_color(char ***rubiks);
int check_comb_centers(char ***rubiks);
int check_comb_corners(char ***rubiks);
void switch_color_input(char c, int cpt[]);
void switch_two_cells(char c1, char c2);
void fill_all_cube(char *** rubiks);
void fill_user_face(char ***rubiks);
void fill_user_cell(char ***rubiks);
void fill_menu(char ***rubiks);



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

void horizontal_rotation(char ***rubiks);
void vertical_rotation();
int move_rubiks();

/* RESOLUTION */
void perfect_cross(char ***rubiks);

/* TEXT COLOR */
void text_color(int color);

#endif