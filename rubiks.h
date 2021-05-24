/* 
BARBIER Adrien - FAJERMAN Yohan - L1 INT 1
C PROJECT - The Rubik's Cube - rubiks.h
The file acts as a header file, containing two enum variables as well as all the functions' prototypes, which we use throughout our program.
*/

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
void vertical_rotation(char *** rubiks);
void half_horizontal_rotation(char ***rubiks);

void move_cube(char ***rubiks, int op);
void move_side_clockwise(char ***rubiks, int op, int type);
void move_side_anticlockwise(char ***rubiks, int op, int type);

/* RESOLUTION FUNCTION */
void perfect_cross(char ***rubiks);
void first_crown(char ***rubiks);
int corner_case1(char ***rubiks);
int corner_case2(char ***rubiks);
int corner_check(char ***rubiks);
void second_crown(char ***rubiks);
void left_move(char ***rubiks);
void right_move(char ***rubiks);
int left_move_check(char ***rubiks);
int right_move_check(char ***rubiks);
int bad_orientation(char ***rubiks);
int second_crown_check(char ***rubiks);
int check_corner_yellow(char ***rubiks);
int single_case_yellow(char ***rubiks);
int L_shape(char ***rubiks);
int barr(char ***rubiks);
int yellow_cross_check(char ***rubiks);
int perfect_yellow_cross(char ***rubiks);
int yellow_cross_facing_edge(char ***rubiks);
int yellow_cross_side_by_side(char ***rubiks);
void solving_process(char ***rubiks, int i);

/* TEXT COLOR FUNCTION */
void text_color(int color);

#endif