/* 
BARBIER Adrien - FAJERMAN Yohan - L1 INT 1
C PROJECT - The Rubik's Cube - rubiks.c
The file contains all the functions' definitions we use throughout our program.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "rubiks.h"
#define FACE 6
#define SIZE 3

/* ENUM TYPE FUNCTIONS */

enum T_COLOR select_color(char color)
{
    switch(color)
    {
    case 'R':
        return RED_CELL;
        break;
    case 'B':
        return BLUE_CELL;
        break;
    case 'G':
        return GREEN_CELL;
        break;
    case 'W':
        return WHITE_CELL;
        break;
    case 'Y':
        return YELLOW_CELL;
        break;
    case 'O':
        return ORANGE_CELL;
        break;
    case '-':
        return LG_CELL;
        break;
    default:
        return LG_CELL;
        break;
    }
}

char index_to_color(int i)
{
    switch (i)
    {
    case 0:
        return 'W';
        break;
    case 1: 
        return 'O';
        break;
    case 2:
        return 'G';
        break;
    case 3:
        return 'R';
        break;
    case 4:
        return 'B';
        break;
    case 5:
        return 'Y';
        break;
    default: 
        break;
    }
}

enum T_SIDE side_to_index(const char* side)
{
    if (side == "FRONT")
        return FRONT;
    else if (side == "BACK")
        return BACK;
    else if (side == "UP")
        return UP;
    else if (side == "DOWN")
        return DOWN;
    else if (side == "RIGHT")
        return RIGHT;
    else if (side == "LEFT")
        return LEFT;
}


const char* index_to_side(int i)
{
    switch(i)
    {
    case 0:
        return "UP";
        break;
    case 1:
        return "LEFT";
        break;
    case 2:
        return "FRONT";
        break;
    case 3:
        return "RIGHT";
        break;
    case 4:
        return "BACK";
        break;
    case 5:
        return "DOWN";
        break;
    default:
        break;
    }
}



/* CUBE REPRESENTATION FUNCTIONS */

char*** create_rubiks()
{
    char i,j,k;
    char ***rubiks = malloc(FACE * sizeof(char**));
    for (i = 0; i < FACE; i++)
    {
        rubiks[i] = malloc(SIZE * sizeof(char*));
        for (j = 0; j < SIZE; j++)
        {
            rubiks[i][j] = malloc(SIZE * sizeof(char));
        }  
    }
    return rubiks;
}



void init_rubiks(char ***rubiks)
{
    int i,j,k;
    for (i = 0; i < FACE; i++)
    {
        switch (i)
        {
        case 0:
            for (j = 0; j < SIZE; j++)
            {
                for (k = 0; k < SIZE; k++)
                {
                    *(*(*(rubiks+i)+j)+k) = 'W';
                }
            }
            break;
        case 1:
            for (j = 0; j < SIZE; j++)
            {
                for (k = 0; k < SIZE; k++)
                {
                    *(*(*(rubiks+i)+j)+k) = 'O';
                }
            }
            break;
        case 2:
            for (j = 0; j < SIZE; j++)
            {
                for (k = 0; k < SIZE; k++)
                {
                    *(*(*(rubiks+i)+j)+k) = 'G';
                } 
            }
            break;
        case 3:
            for (j = 0; j < SIZE; j++)
            {
                for (k = 0; k < SIZE; k++)
                {
                    *(*(*(rubiks+i)+j)+k) = 'R';
                }
            }
            break;
        case 4: 
            for (j = 0; j < SIZE; j++)
            {
                for (k = 0; k < SIZE; k++)
                {
                    *(*(*(rubiks+i)+j)+k) = 'B';
                }
            }
            break;
        case 5:
            for (j = 0; j < SIZE; j++)
            {
                for (k = 0; k < SIZE; k++)
                {
                    *(*(*(rubiks+i)+j)+k) = 'Y';
                }
            }  
            break;
        default:
            break;
        } 
    }
}
 

void scramble_rubiks(char ***rubiks)
{
    init_rubiks(rubiks);
    int r;
    r = rand()%5;
    FRONT_clockwise(rubiks, r);
    r = rand()%5;
    BACK_clockwise(rubiks, r);
    r = rand()%5;
    UP_clockwise(rubiks, r);
    r = rand()%5;
    DOWN_clockwise(rubiks, r);
    r = rand()%5;
    RIGHT_clockwise(rubiks, r);
    r = rand()%5;
    LEFT_clockwise(rubiks, r);
    r = rand()%5;
    FRONT_anticlockwise(rubiks, r);
    r = rand()%5;
    BACK_anticlockwise(rubiks, r);
    r = rand()%5;
    UP_anticlockwise(rubiks, r);
    r = rand()%5;
    DOWN_anticlockwise(rubiks, r);
    r = rand()%5;
    RIGHT_anticlockwise(rubiks, r);
    r = rand()%5;
    LEFT_anticlockwise(rubiks, r);
}

void display_rubiks(char ***rubiks)
{
    int i,j,k;
    for(j=0;j<SIZE;j++){
        printf("        ");
        for(k=0;k<SIZE;k++){
            text_color(select_color(rubiks[0][j][k]));
            printf("%c ", rubiks[0][j][k]);
        }
        printf("\n");
    }
    printf("\n");
    for(j=0;j<SIZE;j++){
        for(k=0;k<SIZE;k++){
            text_color(select_color(rubiks[1][j][k]));
            printf("%c ", rubiks[1][j][k]);
        }
        printf("  ");
        for(k=0;k<SIZE;k++){
            text_color(select_color(rubiks[2][j][k]));
            printf("%c ", rubiks[2][j][k]);
        }
        printf("  ");
        for(k=0;k<SIZE;k++){
            text_color(select_color(rubiks[3][j][k]));
            printf("%c ", rubiks[3][j][k]);
        }
        printf("  ");
        for(k=0;k<SIZE;k++){
            text_color(select_color(rubiks[4][j][k]));
            printf("%c ", rubiks[4][j][k]);
        }
        printf("\n");
    }
    printf("\n");
    for(j=0;j<SIZE;j++){
        printf("        ");
        for(k=0;k<SIZE;k++){
            text_color(select_color(rubiks[5][j][k]));
            printf("%c ", rubiks[5][j][k]);
        }
        printf("\n");
    }
    text_color(15);
    printf("\n");
}

void blank_rubiks(char ***rubiks){
    int i,j,k;
    for(i=0;i<FACE;i++){
        for(j=0;j<SIZE;j++){
            for(k=0;k<SIZE;k++){
                *(*(*(rubiks+i)+j)+k)='-';
            }
        }
    }
}

void free_rubiks(char ***rubiks)
{
    int i,j;
    for (i = 0; i < FACE; i++)
    {
        for (j = 0; j < SIZE; j++)
        {
            free(rubiks[i][j]);
        }  
    }
    free(rubiks);
}



/* FILLING THE CUBE FUNCTIONS */

int get_cpt_color(char ***rubiks)
{
    int i,j,k;
    int cpt[10];
    for (i = 0; i < FACE; i++)
    {
        for (j = 0; j < SIZE; j++)
        {
            for (k = 0; k < SIZE; k++)
            {
                if (rubiks[i][j][k] == 'R')
                    cpt[0]++;
                else if (rubiks[i][j][k] == 'B')
                    cpt[1]++;
                else if(rubiks[i][j][k] == 'G')
                    cpt[2]++;
                else if (rubiks[i][j][k] == 'Y')
                    cpt[3]++;
                else if (rubiks[i][j][k] == 'O')
                    cpt[4]++;
                else if (rubiks[i][j][k] == 'W')
                    cpt[5]++;
            } 
        }  
    }
}


int check_comb_corners(char ***rubiks)
{
    int i,j,k, check=1;
    if (rubiks[side_to_index("LEFT")][0][1]==rubiks[side_to_index("UP")][1][0] ||
    rubiks[side_to_index("LEFT")][1][0]==rubiks[side_to_index("BACK")][1][2] ||
    rubiks[side_to_index("LEFT")][2][1]==rubiks[side_to_index("DOWN")][1][0] ||
    rubiks[side_to_index("LEFT")][1][2]==rubiks[side_to_index("FRONT")][1][0] ||
    rubiks[side_to_index("UP")][0][1]==rubiks[side_to_index("BACK")][0][1] ||
    rubiks[side_to_index("UP")][2][1]==rubiks[side_to_index("FRONT")][0][1] ||
    rubiks[side_to_index("UP")][1][2]==rubiks[side_to_index("RIGHT")][0][1] ||
    rubiks[side_to_index("FRONT")][2][1]==rubiks[side_to_index("DOWN")][0][1] ||
    rubiks[side_to_index("FRONT")][1][2]==rubiks[side_to_index("RIGHT")][1][0] ||
    rubiks[side_to_index("DOWN")][1][2]==rubiks[side_to_index("RIGHT")][2][1] ||
    rubiks[side_to_index("DOWN")][2][1]==rubiks[side_to_index("BACK")][2][1] ||
    rubiks[side_to_index("RIGHT")][1][2]==rubiks[side_to_index("BACK")][1][0] ||
    rubiks[side_to_index("UP")][2][0]==rubiks[side_to_index("LEFT")][0][2] ||
    rubiks[side_to_index("LEFT")][0][2]==rubiks[side_to_index("FRONT")][0][0] ||
    rubiks[side_to_index("FRONT")][0][0]==rubiks[side_to_index("UP")][2][0] ||
    rubiks[side_to_index("UP")][2][2]==rubiks[side_to_index("FRONT")][0][2] ||
    rubiks[side_to_index("FRONT")][0][2]==rubiks[side_to_index("RIGHT")][0][0] ||
    rubiks[side_to_index("RIGHT")][0][0]==rubiks[side_to_index("UP")][2][2] ||
    rubiks[side_to_index("UP")][0][0]==rubiks[side_to_index("LEFT")][0][0] ||
    rubiks[side_to_index("LEFT")][0][0]==rubiks[side_to_index("BACK")][0][2] ||
    rubiks[side_to_index("BACK")][0][2]==rubiks[side_to_index("UP")][0][0] ||
    rubiks[side_to_index("UP")][0][2]==rubiks[side_to_index("RIGHT")][0][2] ||
    rubiks[side_to_index("RIGHT")][0][2]==rubiks[side_to_index("BACK")][0][0] ||
    rubiks[side_to_index("BACK")][0][0]==rubiks[side_to_index("UP")][0][2] ||
    rubiks[side_to_index("DOWN")][0][0]==rubiks[side_to_index("LEFT")][2][2] ||
    rubiks[side_to_index("LEFT")][2][2]==rubiks[side_to_index("FRONT")][2][0] ||
    rubiks[side_to_index("FRONT")][2][0]==rubiks[side_to_index("DOWN")][0][0] ||
    rubiks[side_to_index("DOWN")][0][2]==rubiks[side_to_index("FRONT")][2][2] ||
    rubiks[side_to_index("FRONT")][2][2]==rubiks[side_to_index("RIGHT")][2][0] ||
    rubiks[side_to_index("RIGHT")][2][0]==rubiks[side_to_index("DWON")][0][2] ||
    rubiks[side_to_index("DOWN")][2][0]==rubiks[side_to_index("LEFT")][2][0] ||
    rubiks[side_to_index("LEFT")][2][0]==rubiks[side_to_index("BACK")][2][2] ||
    rubiks[side_to_index("BACK")][2][2]==rubiks[side_to_index("DOWN")][2][0] ||
    rubiks[side_to_index("DOWN")][2][2]==rubiks[side_to_index("RIGHT")][2][2] ||
    rubiks[side_to_index("RIGHT")][2][2]==rubiks[side_to_index("BACK")][2][0] ||
    rubiks[side_to_index("BACK")][2][0]==rubiks[side_to_index("DOWN")][2][2])
        return 0;
    return 1;
}



void switch_color_input(char c, int cpt[])
{
    int index;
    switch (c)
    {
    case 'R':
        index = 0;
        if (cpt[index]>0)
                cpt[index]--;
        else {
            c = '-';
            cpt[index]=0;
        }
        break;

    case 'B':
        index = 1;
        if (cpt[index]>0)
            cpt[index]--;
        else {
            c = '-';
            cpt[index]=0;
        }
        break;

    case 'G':
        index = 2;
        if (cpt[index]>0)
            cpt[index]--;
        else {
            c = '-';
            cpt[index]=0;
        }
        break;

    case 'Y':
        index = 3;
        if (cpt[index]>0)
            cpt[index]--;
        else {
            c = '-';
            cpt[index]=0;
        }
        break;

    case 'O':
        index = 4;
        if (cpt[index]>0)
            cpt[index]--;
        else {
            c = '-';
            cpt[index]=0;
        }
        break;

    case 'W':
        index = 5;
        if (cpt[index]>0)
            cpt[index]--;
        else {
            c = '-';
            cpt[index]=0;
        }
        break;

    default:
        c = '-';
        break;
    }
}


void switch_two_cells(char c1, char c2)
{
    char temp;
    temp=c1;
    c1=c2;
    c2=temp;
}


void fill_all_cube(char ***rubiks)
{
    int i,j,k;
    int cpt[] = {8, 8, 8, 8, 8, 8}, index;
    // {cptR, cptB, cptG, cptY, cpt0, cptW};
    blank_rubiks(rubiks);
    for (i = 0; i < FACE; i++)
    {
        printf("Face: %s\n", index_to_side(i));
        for (j = 0; j < SIZE; j++)
        {
            for (k = 0; k < SIZE; k++)
            {
                printf("Line %d - Cell %d: ", j, k);
                scanf(" %c", &(rubiks[i][j][k]));
                switch_color_input(rubiks[i][j][k], cpt);
            }
            printf("\n");
        }
        printf("\nCOLOR CELLS REMAINING: \n");
        printf("RED: %d -- BLUE: %d -- GREEN: %d\n", cpt[0], cpt[1], cpt[2]);
        printf("YELLOW: %d -- ORANGE: %d -- WHITE: %d\n\n", cpt[3], cpt[4], cpt[5]);
    }
}


void fill_user_face(char ***rubiks)
{
    int i,j;
    char face[100];
    int cpt[10];
    get_cpt_color(rubiks);
    printf("\nCOLOR CELLS REMAINING: \n");
    printf("RED: %d -- BLUE: %d -- GREEN: %d\n", cpt[0], cpt[1], cpt[2]);
    printf("YELLOW: %d -- ORANGE: %d -- WHITE: %d\n\n", cpt[3], cpt[4], cpt[5]);

    printf("Which face to fill (UPPERCASE input please) ?\n");
    gets(face);
    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < SIZE; j++)
        {
            printf("Line %d - Cell %d: ", i, j);
            scanf(" %c", &(rubiks[side_to_index(face)][i][j]));
            switch_color_input(rubiks[side_to_index(face)][i][j], cpt);
        }
    }
} 


void fill_user_cell(char ***rubiks)
{
    int i,j;
    char face[100];
    int cpt[10];
    get_cpt_color(rubiks);
    printf("\nCOLOR CELLS REMAINING: \n");
    printf("RED: %d -- BLUE: %d -- GREEN: %d\n", cpt[0], cpt[1], cpt[2]);
    printf("YELLOW: %d -- ORANGE: %d -- WHITE: %d\n\n", cpt[3], cpt[4], cpt[5]);

    printf("Which face to fill (UPPERCASE input please)?\n");
    gets(face);
    printf("Which line & column, starting from 0?\n");
    scanf("%d %d", &i, &j);

    printf("Color input: ");
    scanf(" %c", &(rubiks[side_to_index(face)][i][j]));
    switch_color_input(rubiks[side_to_index(face)][i][j], cpt);
}



void fill_menu(char ***rubiks)
{
    int i,j,k, op;
    do
    {
        printf("Please, select one of these with 1, 2 or 3: ");
        scanf("%d", &op);
    } while (op < 1 || op > 3);

    switch (op)
    {
    case 1:
        do
        {
            fill_all_cube(rubiks);
            if (check_comb_corners(rubiks) == 0)
            {
                printf("ATTENTION !!! there is a problem with the corners of your cube.");
                printf("Please take into account the conditions of filling !\n");
            }
        } while (check_comb_corners(rubiks) == 0);
        printf("Your new cube is: \n");
        display_rubiks(rubiks);
        break;
    
    case 2: 
        do
        {
            fill_user_face(rubiks);
            if (check_comb_corners(rubiks) == 0)
            {
                printf("ATTENTION !!! there is a problem with the corners of your cube."); 
                printf("Please take into account the conditions of filling !\n");
            }
        } while (check_comb_corners(rubiks) == 0);
        printf("Your new cube is: \n");
        display_rubiks(rubiks);
        break;

    case 3:
        do
        {
            fill_user_cell(rubiks);
            if (check_comb_corners(rubiks) == 0)
            {
                printf("ATTENTION !!! there is a problem with the corners of your cube."); 
                printf("Please take into account the conditions of filling !\n");
            }
        } while (check_comb_corners(rubiks) == 0);
        printf("Your new cube is: \n");
        display_rubiks(rubiks);
        break;

    default:
        printf("Wrong Choice, please try again. \n");
        break;
    }
}



/* MOVEMENT FUNCTIONS */


void FRONT_clockwise(char ***rubiks, int type)
{
    int i, cpt;
    char save1[3], save2[3];
    for(cpt=0;cpt<type;cpt++){
        for(i=0;i<2;i++){
            save1[i]=rubiks[side_to_index("FRONT")][0][i];
            save2[i]=rubiks[side_to_index("FRONT")][i][2];
        }
        for(i=0;i<2;i++){
            rubiks[side_to_index("FRONT")][0][i]=rubiks[side_to_index("FRONT")][2-i][0];
            rubiks[side_to_index("FRONT")][2-i][0]=rubiks[side_to_index("FRONT")][2][2-i];
            rubiks[side_to_index("FRONT")][2][2-i]=save2[i];
            rubiks[side_to_index("FRONT")][i][2]=save1[i];
        }
        for(i=0;i<SIZE;i++){
            save1[i]=rubiks[side_to_index("UP")][2][i];
            rubiks[side_to_index("UP")][2][i]=rubiks[side_to_index("LEFT")][2-i][2];
            rubiks[side_to_index("LEFT")][2-i][2]=rubiks[side_to_index("DOWN")][0][2-i];
            rubiks[side_to_index("DOWN")][0][2-i]=rubiks[side_to_index("RIGHT")][i][0];
            rubiks[side_to_index("RIGHT")][i][0]=save1[i];
        }
    }
}


void BACK_clockwise(char ***rubiks, int type){
    int i, cpt;
    char save1[3], save2[3];
    for(cpt=0;cpt<type;cpt++){
        for(i=0;i<2;i++){
            save1[i]=rubiks[4][0][i];
            save2[i]=rubiks[4][i][2];
        }
        for(i=0;i<2;i++){
            rubiks[4][0][i]=rubiks[4][2-i][0];
            rubiks[4][2-i][0]=rubiks[4][2][2-i];
            rubiks[4][2][2-i]=save2[i];
            rubiks[4][i][2]=save1[i];
        }
        for(i=0;i<SIZE;i++){
            save1[i]=rubiks[0][0][i];
            rubiks[0][0][i]=rubiks[3][i][2];
            rubiks[3][i][2]=rubiks[5][2][2-i];
            rubiks[5][2][2-i]=rubiks[1][2-i][0];
            rubiks[1][2-i][0]=save1[i];
        }
    }
}

void UP_clockwise(char ***rubiks, int type){
    int i, cpt;
    char save1[3], save2[3];
    for(cpt=0;cpt<type;cpt++){
        for(i=0;i<2;i++){
            save1[i]=rubiks[side_to_index("UP")][0][i];
            save2[i]=rubiks[side_to_index("UP")][i][2];
        }
        for(i=0;i<2;i++){
            rubiks[side_to_index("UP")][0][i]=rubiks[side_to_index("UP")][2-i][0];
            rubiks[side_to_index("UP")][2-i][0]=rubiks[side_to_index("UP")][2][2-i];
            rubiks[side_to_index("UP")][2][2-i]=save2[i];
            rubiks[side_to_index("UP")][i][2]=save1[i];
        }
        for(i=0;i<SIZE;i++){
            save1[i]=rubiks[side_to_index("LEFT")][0][i];
            rubiks[side_to_index("LEFT")][0][i]=rubiks[side_to_index("FRONT")][0][i];
            rubiks[side_to_index("FRONT")][0][i]=rubiks[side_to_index("RIGHT")][0][i];
            rubiks[side_to_index("RIGHT")][0][i]=rubiks[side_to_index("BACK")][0][i];
            rubiks[side_to_index("BACK")][0][i]=save1[i];
        }
    }
}

void DOWN_clockwise(char ***rubiks, int type){
    int i, cpt;
    char save1[3], save2[3];
    for(cpt=0;cpt<type;cpt++){
        for(i=0;i<2;i++){
            save1[i]=rubiks[side_to_index("DOWN")][0][i];
            save2[i]=rubiks[side_to_index("DOWN")][i][2];
        }
        for(i=0;i<2;i++){
            rubiks[side_to_index("DOWN")][0][i]=rubiks[side_to_index("DOWN")][2-i][0];
            rubiks[side_to_index("DOWN")][2-i][0]=rubiks[side_to_index("DOWN")][2][2-i];
            rubiks[side_to_index("DOWN")][2][2-i]=save2[i];
            rubiks[side_to_index("DOWN")][i][2]=save1[i];
        }
        for(i=0;i<SIZE;i++){
            save1[i]=rubiks[side_to_index("LEFT")][2][i];
            rubiks[side_to_index("LEFT")][2][i]=rubiks[side_to_index("BACK")][2][i];
            rubiks[side_to_index("BACK")][2][i]=rubiks[side_to_index("RIGHT")][2][i];
            rubiks[side_to_index("RIGHT")][2][i]=rubiks[side_to_index("FRONT")][2][i];
            rubiks[side_to_index("FRONT")][2][i]=save1[i];
        }
    }
}

void RIGHT_clockwise(char ***rubiks, int type){
    int i, cpt;
    char save1[3], save2[3];
    for(cpt=0;cpt<type;cpt++){
        for(i=0;i<2;i++){
            save1[i]=rubiks[side_to_index("RIGHT")][0][i];
            save2[i]=rubiks[side_to_index("RIGHT")][i][2];
        }
        for(i=0;i<2;i++){
            rubiks[side_to_index("RIGHT")][0][i]=rubiks[side_to_index("RIGHT")][2-i][0];
            rubiks[side_to_index("RIGHT")][2-i][0]=rubiks[side_to_index("RIGHT")][2][2-i];
            rubiks[side_to_index("RIGHT")][2][2-i]=save2[i];
            rubiks[side_to_index("RIGHT")][i][2]=save1[i];
        }
        for(i=0;i<SIZE;i++){
            save1[i]=rubiks[side_to_index("UP")][i][2];
            rubiks[side_to_index("UP")][i][2]=rubiks[side_to_index("FRONT")][i][2];
            rubiks[side_to_index("FRONT")][i][2]=rubiks[side_to_index("DOWN")][i][2];
            rubiks[side_to_index("DOWN")][i][2]=rubiks[side_to_index("BACK")][2-i][0];
            rubiks[side_to_index("BACK")][2-i][0]=save1[i];
        }
    }
}

void LEFT_clockwise(char ***rubiks, int type){
    int i, cpt;
    char save1[2], save2[2];
    for(cpt=0;cpt<type;cpt++){
        for(i=0;i<2;i++){
            save1[i]=rubiks[side_to_index("LEFT")][0][i];
            save2[i]=rubiks[side_to_index("LEFT")][i][2];
        }
        for(i=0;i<2;i++){
            rubiks[side_to_index("LEFT")][0][i]=rubiks[side_to_index("LEFT")][2-i][0];
            rubiks[side_to_index("LEFT")][2-i][0]=rubiks[side_to_index("LEFT")][2][2-i];
            rubiks[side_to_index("LEFT")][2][2-i]=save2[i];
            rubiks[side_to_index("LEFT")][i][2]=save1[i];
        }
        for(i=0;i<SIZE;i++){
            save1[i]=rubiks[side_to_index("DOWN")][i][0];
            rubiks[side_to_index("DOWN")][i][0]=rubiks[side_to_index("FRONT")][i][0];
            rubiks[side_to_index("FRONT")][i][0]=rubiks[side_to_index("UP")][i][0];
            rubiks[side_to_index("UP")][i][0]=rubiks[side_to_index("BACK")][2-i][2];
            rubiks[side_to_index("BACK")][2-i][2]=save1[i];
        }
    }
}

void FRONT_anticlockwise(char ***rubiks, int type){
    int i, cpt;
    char save1[3], save2[3];
    for(cpt=0;cpt<type;cpt++){
        for(i=0;i<2;i++){
            save1[i]=rubiks[side_to_index("FRONT")][0][i];
            save2[i]=rubiks[side_to_index("FRONT")][i][2];
        }
        for(i=0;i<2;i++){
            rubiks[side_to_index("FRONT")][i][2]=rubiks[side_to_index("FRONT")][2][2-i];
            rubiks[side_to_index("FRONT")][2][2-i]=rubiks[side_to_index("FRONT")][2-i][0];
            rubiks[side_to_index("FRONT")][2-i][0]=save1[i];
            rubiks[side_to_index("FRONT")][0][i]=save2[i];
        }
        for(i=0;i<SIZE;i++){
            save1[i]=rubiks[side_to_index("UP")][2][i];
            rubiks[side_to_index("UP")][2][i]=rubiks[side_to_index("RIGHT")][i][0];
            rubiks[side_to_index("RIGHT")][i][0]=rubiks[side_to_index("DOWN")][0][2-i];
            rubiks[side_to_index("DOWN")][0][2-i]=rubiks[side_to_index("LEFT")][2-i][2];
            rubiks[side_to_index("LEFT")][2-i][2]=save1[i];
        }
    }
}

void BACK_anticlockwise(char ***rubiks, int type){
    int i, cpt;
    char save1[3], save2[3];
    for(cpt=0;cpt<type;cpt++){
        for(i=0;i<2;i++){
            save1[i]=rubiks[side_to_index("BACK")][0][i];
            save2[i]=rubiks[side_to_index("BACK")][i][2];
        }
        for(i=0;i<2;i++){
            rubiks[side_to_index("BACK")][i][2]=rubiks[side_to_index("BACK")][2][2-i];
            rubiks[side_to_index("BACK")][2][2-i]=rubiks[side_to_index("BACK")][2-i][0];
            rubiks[side_to_index("BACK")][2-i][0]=save1[i];
            rubiks[side_to_index("BACK")][0][i]=save2[i];
        }
        for(i=0;i<SIZE;i++){
            save1[i]=rubiks[side_to_index("UP")][0][i];
            rubiks[side_to_index("UP")][0][i]=rubiks[side_to_index("LEFT")][2-i][0];
            rubiks[side_to_index("LEFT")][2-i][0]=rubiks[side_to_index("DOWN")][2][2-i];
            rubiks[side_to_index("DOWN")][2][2-i]=rubiks[side_to_index("RIGHT")][i][2];
            rubiks[side_to_index("RIGHT")][i][2]=save1[i];
        }
    }
}

void UP_anticlockwise(char ***rubiks, int type){
    int i, cpt;
    char save1[3], save2[3];
    for(cpt=0;cpt<type;cpt++){
        for(i=0;i<2;i++){
            save1[i]=rubiks[side_to_index("UP")][0][i];
            save2[i]=rubiks[side_to_index("UP")][i][2];
        }
        for(i=0;i<2;i++){
            rubiks[side_to_index("UP")][i][2]=rubiks[side_to_index("UP")][2][2-i];
            rubiks[side_to_index("UP")][2][2-i]=rubiks[side_to_index("UP")][2-i][0];
            rubiks[side_to_index("UP")][2-i][0]=save1[i];
            rubiks[side_to_index("UP")][0][i]=save2[i];
        }
        for(i=0;i<SIZE;i++){
            save1[i]=rubiks[side_to_index("BACK")][0][i];
            rubiks[side_to_index("BACK")][0][i]=rubiks[side_to_index("RIGHT")][0][i];
            rubiks[side_to_index("RIGHT")][0][i]=rubiks[side_to_index("FRONT")][0][i];
            rubiks[side_to_index("FRONT")][0][i]=rubiks[side_to_index("LEFT")][0][i];
            rubiks[side_to_index("LEFT")][0][i]=save1[i];
        }
    }
}

void DOWN_anticlockwise(char ***rubiks, int type){
    int i, cpt;
    char save1[3], save2[3];
    for(cpt=0;cpt<type;cpt++){
        for(i=0;i<2;i++){
            save1[i]=rubiks[side_to_index("DOWN")][0][i];
            save2[i]=rubiks[side_to_index("DOWN")][i][2];
        }
        for(i=0;i<2;i++){
            rubiks[side_to_index("DOWN")][i][2]=rubiks[side_to_index("DOWN")][2][2-i];
            rubiks[side_to_index("DOWN")][2][2-i]=rubiks[side_to_index("DOWN")][2-i][0];
            rubiks[side_to_index("DOWN")][2-i][0]=save1[i];
            rubiks[side_to_index("DOWN")][0][i]=save2[i];
        }
        for(i=0;i<SIZE;i++){
            save1[i]=rubiks[side_to_index("LEFT")][2][i];
            rubiks[side_to_index("LEFT")][2][i]=rubiks[side_to_index("FRONT")][2][i];
            rubiks[side_to_index("FRONT")][2][i]=rubiks[side_to_index("RIGHT")][2][i];
            rubiks[side_to_index("RIGHT")][2][i]=rubiks[side_to_index("BACK")][2][i];
            rubiks[side_to_index("BACK")][2][i]=save1[i];
        }
    }
}

void RIGHT_anticlockwise(char ***rubiks, int type){
    int i, cpt;
    char save1[3], save2[3];
    for(cpt=0;cpt<type;cpt++){
        for(i=0;i<2;i++){
            save1[i]=rubiks[side_to_index("RIGHT")][0][i];
            save2[i]=rubiks[side_to_index("RIGHT")][i][2];
        }
        for(i=0;i<2;i++){
            rubiks[side_to_index("RIGHT")][i][2]=rubiks[side_to_index("RIGHT")][2][2-i];
            rubiks[side_to_index("RIGHT")][2][2-i]=rubiks[side_to_index("RIGHT")][2-i][0];
            rubiks[side_to_index("RIGHT")][2-i][0]=save1[i];
            rubiks[side_to_index("RIGHT")][0][i]=save2[i];
        }
        for(i=0;i<SIZE;i++){
            save1[i]=rubiks[side_to_index("DOWN")][i][2];
            rubiks[side_to_index("DOWN")][i][2]=rubiks[side_to_index("FRONT")][i][2];
            rubiks[side_to_index("FRONT")][i][2]=rubiks[side_to_index("UP")][i][2];
            rubiks[side_to_index("UP")][i][2]=rubiks[side_to_index("BACK")][2-i][0];
            rubiks[side_to_index("BACK")][2-i][0]=save1[i];
        }
    }
}

void LEFT_anticlockwise(char ***rubiks, int type){
    int i, cpt;
    char save1[3], save2[3];
    for(cpt=0;cpt<type;cpt++){
        for(i=0;i<2;i++){
            save1[i]=rubiks[side_to_index("LEFT")][0][i];
            save2[i]=rubiks[side_to_index("LEFT")][i][2];
        }
        for(i=0;i<2;i++){
            rubiks[side_to_index("LEFT")][i][2]=rubiks[side_to_index("LEFT")][2][2-i];
            rubiks[side_to_index("LEFT")][2][2-i]=rubiks[side_to_index("LEFT")][2-i][0];
            rubiks[side_to_index("LEFT")][2-i][0]=save1[i];
            rubiks[side_to_index("LEFT")][0][i]=save2[i];
        }
        for(i=0;i<SIZE;i++){
            save1[i]=rubiks[side_to_index("UP")][i][0];
            rubiks[side_to_index("UP")][i][0]=rubiks[side_to_index("FRONT")][i][0];
            rubiks[side_to_index("FRONT")][i][0]=rubiks[side_to_index("DOWN")][i][0];
            rubiks[side_to_index("DOWN")][i][0]=rubiks[side_to_index("BACK")][2-i][2];
            rubiks[side_to_index("BACK")][2-i][2]=save1[i];
        }
    }
}

void horizontal_rotation(char ***rubiks){
    int save, i, j;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            save = rubiks[side_to_index("LEFT")][i][j];
            rubiks[side_to_index("LEFT")][i][j]=rubiks[side_to_index("RIGHT")][i][j];
            rubiks[side_to_index("RIGHT")][i][j]=save;
        }
    }
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            save = rubiks[side_to_index("FRONT")][i][j];
            rubiks[side_to_index("FRONT")][i][j]=rubiks[side_to_index("BACK")][i][j];
            rubiks[side_to_index("BACK")][i][j]=save;
        }
    }
    for(i=0;i<2;i++){
        save=rubiks[side_to_index("UP")][0][i];
        rubiks[side_to_index("UP")][0][i]=rubiks[side_to_index("UP")][2][2-i];
        rubiks[side_to_index("UP")][2][2-i]=save;
        save = rubiks[side_to_index("UP")][i][2];
        rubiks[side_to_index("UP")][i][2] = rubiks[side_to_index("UP")][2-i][0];
        rubiks[side_to_index("UP")][2-i][0] = save;
    }
    for(i=0;i<2;i++){
        save=rubiks[side_to_index("DOWN")][0][i];
        rubiks[side_to_index("DOWN")][0][i]=rubiks[side_to_index("DOWN")][2][2-i];
        rubiks[side_to_index("DOWN")][2][2-i]=save;
        save = rubiks[side_to_index("DOWN")][i][2];
        rubiks[side_to_index("DOWN")][i][2] = rubiks[side_to_index("DOWN")][2-i][0];
        rubiks[side_to_index("DOWN")][2-i][0] = save;
    }
}

void half_horizontal_rotation(char ***rubiks){
    char save;
    int i;
    UP_anticlockwise(rubiks, 1);
    DOWN_clockwise(rubiks, 1);
    for(i=0;i<SIZE;i++){
        save = rubiks[side_to_index("BACK")][1][i];
        rubiks[side_to_index("BACK")][1][i]=rubiks[side_to_index("RIGHT")][1][i];
        rubiks[side_to_index("RIGHT")][1][i]=rubiks[side_to_index("FRONT")][1][i];
        rubiks[side_to_index("FRONT")][1][i]=rubiks[side_to_index("LEFT")][1][i];
        rubiks[side_to_index("LEFT")][1][i]=save;
    }
}

void vertical_rotation(char ***rubiks){
    int i, save, j;
    for(i=0;i<SIZE;i++){
        for(j=0;j<SIZE;j++){
            save = rubiks[side_to_index("UP")][i][j];
            rubiks[side_to_index("UP")][i][j]=rubiks[side_to_index("DOWN")][i][j];
            rubiks[side_to_index("DOWN")][i][j]=save;
        }
    }
    for(i=0;i<SIZE;i++){
        for(j=0;j<SIZE;j++){
            save = rubiks[side_to_index("FRONT")][i][j];
            rubiks[side_to_index("FRONT")][i][j]=rubiks[side_to_index("BACK")][2-i][2-j];
            rubiks[side_to_index("BACK")][2-i][2-j]=save;
        }
    }
    for(i=0;i<2;i++){
        save=rubiks[side_to_index("LEFT")][0][i];
        rubiks[side_to_index("LEFT")][0][i]=rubiks[side_to_index("LEFT")][2][2-i];
        rubiks[side_to_index("LEFT")][2][2-i]=save;
        save = rubiks[side_to_index("LEFT")][i][2];
        rubiks[side_to_index("LEFT")][i][2] = rubiks[side_to_index("LEFT")][2-i][0];
        rubiks[side_to_index("LEFT")][2-i][0] = save;
    }
    for(i=0;i<2;i++){
        save=rubiks[side_to_index("RIGHT")][0][i];
        rubiks[side_to_index("RIGHT")][0][i]=rubiks[side_to_index("RIGHT")][2][2-i];
        rubiks[side_to_index("RIGHT")][2][2-i]=save;
        save = rubiks[side_to_index("RIGHT")][i][2];
        rubiks[side_to_index("RIGHT")][i][2] = rubiks[side_to_index("RIGHT")][2-i][0];
        rubiks[side_to_index("RIGHT")][2-i][0] = save;
    }
}


void move_cube(char ***rubiks, int op)
{
    switch (op)
    {
    case 1:
        horizontal_rotation(rubiks);
        break;
    case 2:
        half_horizontal_rotation(rubiks);
        break;
    case 3:
        vertical_rotation(rubiks);
        break;
    default:
        break;
    }
}


void move_side_clockwise(char ***rubiks, int op, int type)
{
    switch (op)
    {
    case 1:
        UP_clockwise(rubiks, type);
        break;
     case 2:
        LEFT_clockwise(rubiks, type);
        break;
    case 3:
        FRONT_clockwise(rubiks, type);
        break;
    case 4:
        RIGHT_clockwise(rubiks, type);
        break;
    case 5:
        BACK_clockwise(rubiks, type);
        break;
    case 6:
        DOWN_clockwise(rubiks, type);
        break;
    default:
        break;
    }
}


void move_side_anticlockwise(char ***rubiks, int op, int type)
{
    switch (op)
    {
    case 1:
        UP_anticlockwise(rubiks, type);
        break;
     case 2:
        LEFT_anticlockwise(rubiks, type);
        break;
    case 3:
        FRONT_anticlockwise(rubiks, type);
        break;
    case 4:
        RIGHT_anticlockwise(rubiks, type);
        break;
    case 5:
        BACK_anticlockwise(rubiks, type);
        break;
    case 6:
        DOWN_anticlockwise(rubiks, type);
        break;
    default:
        break;
    }
}



/* RESOLUTION FUNCTION */


void perfect_cross(char ***rubiks){
    /* This function checks all different cases for FRONT and RIGHT faces, then rotates the cube to perform it again*/
    int i;
    do{
        for(i=0;i<2;i++){
            if(rubiks[side_to_index("UP")][2][1]==rubiks[side_to_index("FRONT")][1][1] && rubiks[side_to_index("FRONT")][0][1]==rubiks[side_to_index("UP")][1][1]){
                FRONT_clockwise(rubiks, 1);
                UP_anticlockwise(rubiks, 1);
                RIGHT_clockwise(rubiks, 1);
                UP_clockwise(rubiks, 1);
            }
            if(rubiks[side_to_index("FRONT")][2][1]==rubiks[side_to_index("UP")][1][1] && rubiks[side_to_index("DOWN")][0][1]==rubiks[side_to_index("FRONT")][1][1]){
                FRONT_anticlockwise(rubiks, 1);
                RIGHT_anticlockwise(rubiks, 1);
                DOWN_anticlockwise(rubiks, 1);
                RIGHT_clockwise(rubiks, 1);
                FRONT_anticlockwise(rubiks, 2);
            }
            if(rubiks[side_to_index("FRONT")][1][2]==rubiks[side_to_index("UP")][1][1] && rubiks[side_to_index("RIGHT")][1][0]==rubiks[side_to_index("FRONT")][1][1]){
                RIGHT_anticlockwise(rubiks, 1);
                DOWN_anticlockwise(rubiks, 1);
                RIGHT_clockwise(rubiks, 1);
                FRONT_anticlockwise(rubiks, 2);
            }
            if(rubiks[side_to_index("FRONT")][0][1]==rubiks[side_to_index("UP")][1][1] && rubiks[side_to_index("UP")][2][1]==rubiks[side_to_index("RIGHT")][1][1]){
                FRONT_clockwise(rubiks, 1);
                RIGHT_clockwise(rubiks, 1);
            }
            if(rubiks[side_to_index("UP")][1][2]==rubiks[side_to_index("LEFT")][1][1]&&rubiks[side_to_index("RIGHT")][0][1]==rubiks[side_to_index("UP")][1][1]){
                RIGHT_anticlockwise(rubiks, 1);
                FRONT_anticlockwise(rubiks, 1);
                UP_clockwise(rubiks, 1);
            }
            if(rubiks[side_to_index("UP")][1][2]==rubiks[side_to_index("RIGHT")][1][1]&&rubiks[side_to_index("RIGHT")][0][1]==rubiks[side_to_index("UP")][1][2]){
                RIGHT_clockwise(rubiks, 1);
                UP_anticlockwise(rubiks, 1);
                BACK_clockwise(rubiks, 1);
                UP_clockwise(rubiks, 1);
            }
            if(rubiks[side_to_index("RIGHT")][2][1]==rubiks[side_to_index("UP")][1][1] && rubiks[side_to_index("DOWN")][1][2]==rubiks[side_to_index("RIGHT")][1][1]){
                RIGHT_anticlockwise(rubiks, 1);
                BACK_anticlockwise(rubiks, 1);
                DOWN_anticlockwise(rubiks, 1);
                BACK_clockwise(rubiks, 1);
                RIGHT_anticlockwise(rubiks, 2);
            }
            if(rubiks[side_to_index("RIGHT")][1][2]==rubiks[side_to_index("UP")][1][1] && rubiks[side_to_index("BACK")][1][0]==rubiks[side_to_index("RIGHT")][1][1]){
                BACK_anticlockwise(rubiks, 1);
                DOWN_anticlockwise(rubiks, 1);
                RIGHT_clockwise(rubiks, 1);
                RIGHT_anticlockwise(rubiks, 2);
            }
            if(rubiks[side_to_index("RIGHT")][0][1]==rubiks[side_to_index("UP")][1][1] && rubiks[side_to_index("UP")][1][2]==rubiks[side_to_index("BACK")][1][1]){
                RIGHT_clockwise(rubiks, 1);
                BACK_clockwise(rubiks, 1);
            }
            if(rubiks[side_to_index("UP")][0][1]==rubiks[side_to_index("FRONT")][1][1]&&rubiks[side_to_index("BACK")][0][1]==rubiks[side_to_index("UP")][1][1]){
                BACK_anticlockwise(rubiks, 1);
                RIGHT_anticlockwise(rubiks, 1);
                UP_clockwise(rubiks, 1);
            }
            horizontal_rotation(rubiks);
        }
        /* Here we check if white cases are on the DOWN face, to take them to the other faces*/
        if((rubiks[side_to_index("UP")][0][1]==rubiks[side_to_index("UP")][1][0]==rubiks[side_to_index("UP")][1][2]==rubiks[side_to_index("UP")][2][1]==rubiks[side_to_index("UP")][1][1])&&(rubiks[side_to_index("LEFT")][0][1]!=rubiks[side_to_index("LEFT")][1][1]||rubiks[side_to_index("FRONT")][0][1]!=rubiks[side_to_index("FRONT")][1][1]||rubiks[side_to_index("RIGHT")][0][1]!=rubiks[side_to_index("RIGHT")][1][1]||rubiks[side_to_index("BACK")][0][1]!=rubiks[side_to_index("BACK")][1][1])){
            UP_clockwise(rubiks, 1);
        }
        if(rubiks[side_to_index("DOWN")][0][1]==rubiks[side_to_index("UP")][1][1]){
            FRONT_clockwise(rubiks, 1);
        }
        if(rubiks[side_to_index("DOWN")][1][0]==rubiks[side_to_index("UP")][1][1]){
            LEFT_clockwise(rubiks, 1);
        }
        if(rubiks[side_to_index("DOWN")][1][2]==rubiks[side_to_index("UP")][1][1]){
            RIGHT_clockwise(rubiks, 1);
        }
        if(rubiks[side_to_index("DOWN")][2][1]==rubiks[side_to_index("UP")][1][1]){
            BACK_clockwise(rubiks, 1);
        }
    }while(rubiks[side_to_index("UP")][0][1]!=rubiks[side_to_index("UP")][1][1]||rubiks[side_to_index("UP")][1][0]!=rubiks[side_to_index("UP")][1][1]||rubiks[side_to_index("UP")][1][2]!=rubiks[side_to_index("UP")][1][1]||rubiks[side_to_index("UP")][2][1]!=rubiks[side_to_index("UP")][1][1]||rubiks[side_to_index("LEFT")][0][1]!=rubiks[side_to_index("LEFT")][1][1]||rubiks[side_to_index("FRONT")][0][1]!=rubiks[side_to_index("FRONT")][1][1]||rubiks[side_to_index("RIGHT")][0][1]!=rubiks[side_to_index("RIGHT")][1][1]||rubiks[side_to_index("BACK")][0][1]!=rubiks[side_to_index("BACK")][1][1]);
}

void first_crown(char ***rubiks){
    /* We'll check different configurations and adapt to them */
    int i, check[4]={0,0,0,0};
    do{
        for(i=0;i<4;i++){
            if(corner_check(rubiks)==1)
                check[i]=1;
            else{
                if(corner_case1(rubiks)==0)
                    DOWN_clockwise(rubiks, 1);
                else{
                    while(corner_check(rubiks)==0){
                        RIGHT_anticlockwise(rubiks, 1);
                        DOWN_anticlockwise(rubiks, 1);
                        RIGHT_clockwise(rubiks, 1);
                        RIGHT_anticlockwise(rubiks, 1);
                    }
                    check[i]=1;
                }
                if(corner_case2(rubiks)==0){
                    RIGHT_anticlockwise(rubiks, 1);
                    DOWN_clockwise(rubiks, 1);
                    RIGHT_clockwise(rubiks, 1);
                }
            }
            half_horizontal_rotation(rubiks);
        }
    }while(check[0]==0 || check[1]==0 || check[2]==0 || check[3]==0);
}

int corner_case1(char ***rubiks){
    if(rubiks[side_to_index("FRONT")][2][2]!=rubiks[side_to_index("UP")][1][1]||rubiks[side_to_index("FRONT")][2][2]!=rubiks[side_to_index("FRONT")][1][1]||rubiks[side_to_index("FRONT")][2][2]!=rubiks[side_to_index("RIGHT")][1][1]
    || rubiks[side_to_index("DOWN")][0][2]!=rubiks[side_to_index("UP")][1][1]||rubiks[side_to_index("DOWN")][0][2]!=rubiks[side_to_index("FRONT")][1][1]||rubiks[side_to_index("DOWN")][0][2]!=rubiks[side_to_index("RIGHT")][1][1]
    || rubiks[side_to_index("RIGHT")][2][0]!=rubiks[side_to_index("UP")][1][1]||rubiks[side_to_index("RIGHT")][2][0]!=rubiks[side_to_index("FRONT")][1][1]||rubiks[side_to_index("RIGHT")][2][0]!=rubiks[side_to_index("RIGHT")][1][1])
        return 0;
    return 1;
}

int corner_case2(char ***rubiks){
    if(rubiks[side_to_index("UP")][2][2]!=rubiks[side_to_index("UP")][1][1]||rubiks[side_to_index("UP")][2][2]!=rubiks[side_to_index("FRONT")][1][1]||rubiks[side_to_index("UP")][2][2]!=rubiks[side_to_index("RIGHT")][1][1]
    || rubiks[side_to_index("FRONT")][0][2]!=rubiks[side_to_index("UP")][1][1]||rubiks[side_to_index("FRONT")][0][2]!=rubiks[side_to_index("FRONT")][1][1]||rubiks[side_to_index("FRONT")][0][2]!=rubiks[side_to_index("RIGHT")][1][1]
    || rubiks[side_to_index("RIGHT")][0][0]!=rubiks[side_to_index("UP")][1][1]||rubiks[side_to_index("RIGHT")][0][0]!=rubiks[side_to_index("FRONT")][1][1]||rubiks[side_to_index("RIGHT")][0][0]!=rubiks[side_to_index("RIGHT")][1][1])
        return 0;
    return 1;
}

int corner_check(char ***rubiks){
    /* This function checks if a corner is well placed */
    if(rubiks[side_to_index("UP")][2][2]==rubiks[side_to_index("UP")][1][1]&&rubiks[side_to_index("FRONT")][0][2]==rubiks[side_to_index("FRONT")][1][1]&&rubiks[side_to_index("RIGHT")][0][0]&&rubiks[side_to_index("RIGHT")][1][1])
        return 1;
    return 0;
}

void second_crown(char ***rubiks){
    /* We check the 4 positions and adapt, depending on the case */
    int i, check[4]={0,0,0,0}, cpt, cpt2=0;
    vertical_rotation(rubiks);
    do{
        for(i=0;i<4;i++){
            if(bad_orientation(rubiks)==1){
                UP_clockwise(rubiks, 1);
                RIGHT_clockwise(rubiks, 1);
                UP_anticlockwise(rubiks, 1);
                RIGHT_anticlockwise(rubiks, 1);
                UP_anticlockwise(rubiks, 1);
                FRONT_anticlockwise(rubiks, 1);
                UP_clockwise(rubiks, 1);
                FRONT_clockwise(rubiks, 1);
                UP_clockwise(rubiks, 2);
                UP_clockwise(rubiks, 1);
                RIGHT_clockwise(rubiks, 1);
                UP_anticlockwise(rubiks, 1);
                RIGHT_anticlockwise(rubiks, 1);
                UP_anticlockwise(rubiks, 1);
                FRONT_anticlockwise(rubiks, 1);
                UP_clockwise(rubiks, 1);
                FRONT_clockwise(rubiks, 1);
            }
            else{
                cpt = 0;
                while(cpt < 4 && (right_move_check(rubiks)==0 && left_move_check(rubiks)==0)){
                    UP_clockwise(rubiks, 1);
                    cpt++;
                }
                if(left_move_check(rubiks)==1)
                    left_move(rubiks);
                if(right_move_check(rubiks)==1)
                    right_move(rubiks);
            }
            if(second_crown_check(rubiks)==1)
                check[i]=1;
            half_horizontal_rotation(rubiks);
        }
        cpt2++;
    }while(check[0]==0 || check[1]==0 || check[2]==0 || check[3]==0);
}

int left_move_check(char ***rubiks){
    /* check if left move is needed */
    if(rubiks[side_to_index("FRONT")][0][1]==rubiks[side_to_index("FRONT")][1][1]&&rubiks[side_to_index("UP")][2][1]==rubiks[side_to_index("LEFT")][1][1])
        return 1;
    return 0;
}

int right_move_check(char ***rubiks){
    /* check if right move is needed */
    if(rubiks[side_to_index("FRONT")][0][1]==rubiks[side_to_index("FRONT")][1][1]&&rubiks[side_to_index("UP")][2][1]==rubiks[side_to_index("RIGHT")][1][1])
        return 1;
    return 0;
}

void left_move(char ***rubiks){
    UP_anticlockwise(rubiks, 1);
    LEFT_anticlockwise(rubiks, 1);
    UP_clockwise(rubiks, 1);
    LEFT_clockwise(rubiks, 1);
    UP_clockwise(rubiks, 1);
    FRONT_clockwise(rubiks, 1);
    UP_anticlockwise(rubiks, 1);
    FRONT_anticlockwise(rubiks, 1);
}

void right_move(char ***rubiks){
    UP_clockwise(rubiks, 1);
    RIGHT_clockwise(rubiks, 1);
    UP_anticlockwise(rubiks, 1);
    RIGHT_anticlockwise(rubiks, 1);
    UP_anticlockwise(rubiks, 1);
    FRONT_anticlockwise(rubiks, 1);
    UP_clockwise(rubiks, 1);
    FRONT_clockwise(rubiks, 1);
}

int bad_orientation(char ***rubiks){
    /* checks if the 2 colors are at the wrong place */
    if(rubiks[side_to_index("FRONT")][1][2]==rubiks[side_to_index("RIGHT")][1][1]&&rubiks[side_to_index("RIGHT")][1][0]==rubiks[side_to_index("FRONT")][1][1])
        return 1;
    return 0;
}

int second_crown_check(char ***rubiks){
    /* checks if the piece is at the right place on the front-right faces */
    if(rubiks[side_to_index("FRONT")][1][1]==rubiks[side_to_index("FRONT")][1][2]&&rubiks[side_to_index("RIGHT")][1][1]==rubiks[side_to_index("RIGHT")][1][0])
        return 1;
    return 0;
}

void last_crown(char ***rubiks){
    /* This function is not finished yet, but still pretty advanced */
    int i, cpt = 0;
    /* first checks combinations that are not crosses, in order to create one */
    do{
        if(single_case_yellow(rubiks)==1){
            RIGHT_anticlockwise(rubiks, 1);
            UP_anticlockwise(rubiks, 1);
            FRONT_anticlockwise(rubiks, 1);
            UP_clockwise(rubiks, 1);
            FRONT_clockwise(rubiks, 1);
            RIGHT_clockwise(rubiks, 1);
            FRONT_clockwise(rubiks, 1);
            RIGHT_clockwise(rubiks, 1);
            UP_clockwise(rubiks, 1);
            RIGHT_anticlockwise(rubiks, 1);
            UP_anticlockwise(rubiks, 1);
            FRONT_anticlockwise(rubiks, 1);
        }
        else if(L_shape(rubiks)==1){
            while(rubiks[side_to_index("UP")][1][0]!=rubiks[side_to_index("UP")][1][1]||rubiks[side_to_index("UP")][0][1]!=rubiks[side_to_index("UP")][1][1])
                UP_clockwise(rubiks, 1);
            RIGHT_anticlockwise(rubiks, 1);
            UP_anticlockwise(rubiks, 1);
            FRONT_anticlockwise(rubiks, 1);
            UP_clockwise(rubiks, 1);
            FRONT_clockwise(rubiks, 1);
            RIGHT_clockwise(rubiks, 1);
        }
        else if(barr(rubiks)==1){
            while(rubiks[side_to_index("UP")][1][0]!=rubiks[side_to_index("UP")][1][1])
                UP_clockwise(rubiks, 1);
            FRONT_clockwise(rubiks, 1);
            RIGHT_clockwise(rubiks, 1);
            UP_clockwise(rubiks, 1);
            RIGHT_anticlockwise(rubiks, 1);
            UP_anticlockwise(rubiks, 1);
            FRONT_anticlockwise(rubiks, 1);
        }
    }while(yellow_cross_check(rubiks)==0);
    /* checks the different cases (not fully working) and adapt */
    if(yellow_cross_check(rubiks)==1){
        if(perfect_yellow_cross(rubiks)==0){
            if(yellow_cross_facing_edge(rubiks)==1){
                RIGHT_clockwise(rubiks, 1);
                UP_clockwise(rubiks, 2);
                RIGHT_anticlockwise(rubiks, 1);
                UP_anticlockwise(rubiks, 1);
                RIGHT_clockwise(rubiks, 1);
                UP_anticlockwise(rubiks, 1);
                RIGHT_anticlockwise(rubiks, 1);
            }
            if(yellow_cross_side_by_side(rubiks)==1){
                RIGHT_clockwise(rubiks, 1);
                UP_clockwise(rubiks, 2);
                RIGHT_anticlockwise(rubiks, 1);
                UP_anticlockwise(rubiks, 1);
                RIGHT_clockwise(rubiks, 1);
                UP_anticlockwise(rubiks, 1);
                RIGHT_anticlockwise(rubiks, 1);
                UP_anticlockwise(rubiks, 1);
            }
        }
    }
    /* checks the number of corners that are at the good place */
    for(i=0;i<4;i++){
        if(check_corner_yellow(rubiks)==1)
            cpt++;
        UP_clockwise(rubiks, 1);
    }
    if(cpt==0){
        LEFT_anticlockwise(rubiks, 1);
        UP_clockwise(rubiks, 1);
        RIGHT_clockwise(rubiks, 1);
        UP_anticlockwise(rubiks, 1);
        LEFT_clockwise(rubiks, 1);
        UP_clockwise(rubiks, 1);
        RIGHT_anticlockwise(rubiks, 1);
        UP_anticlockwise(rubiks, 1);
        cpt = 0;
        for(i=0;i<4;i++){
            if(check_corner_yellow(rubiks)==1)
                cpt++;
            UP_clockwise(rubiks, 1);
        }
    }
    if(cpt==3){
        do{
            cpt=0;
            while(check_corner_yellow(rubiks)!=1)
                UP_clockwise(rubiks, 1);
            LEFT_anticlockwise(rubiks, 1);
            UP_clockwise(rubiks, 1);
            RIGHT_clockwise(rubiks, 1);
            UP_anticlockwise(rubiks, 1);
            LEFT_clockwise(rubiks, 1);
            UP_clockwise(rubiks, 1);
            RIGHT_anticlockwise(rubiks, 1);
            UP_anticlockwise(rubiks, 1);
            for(i=0;i<4;i++){
                if(check_corner_yellow(rubiks)==1)
                    cpt++;
                UP_clockwise(rubiks, 1);
            }
        }while(cpt!=4);
    }
}

int yellow_cross_check(char ***rubiks){
    /* checks the yellow cross */
    if(rubiks[side_to_index("DOWN")][0][1]==rubiks[side_to_index("DOWN")][1][1]&&rubiks[side_to_index("DOWN")][1][0]==rubiks[side_to_index("DOWN")][1][1]&&rubiks[side_to_index("DOWN")][1][2]==rubiks[side_to_index("DOWN")][1][1]&&rubiks[side_to_index("DOWN")][2][1]==rubiks[side_to_index("DOWN")][1][1])
        return 1;
    return 0;
}

int perfect_yellow_cross(char ***rubiks){
    /* checks if the cross is perfect or not */
    while(rubiks[side_to_index("FRONT")][0][1]!=rubiks[side_to_index("FRONT")][1][1])
        UP_clockwise(rubiks, 1);
    if(rubiks[side_to_index("BACK")][0][1]==rubiks[side_to_index("BACK")][1][1]&&rubiks[side_to_index("LEFT")][0][1]==rubiks[side_to_index("LEFT")][1][1]&&rubiks[side_to_index("RIGHT")][0][1]==rubiks[side_to_index("RIGHT")][1][1]&&rubiks[side_to_index("FRONT")][0][1]==rubiks[side_to_index("FRONT")][1][1])
        return 1;
    return 0;
}

int yellow_cross_facing_edge(char ***rubiks){
    /* Should check if it is the case where 2 faces are good, edging each other */
    int i=0,j=0;
    while((rubiks[side_to_index("BACK")][0][1]!=rubiks[side_to_index("BACK")][1][1]||rubiks[side_to_index("FRONT")][0][1]!=rubiks[side_to_index("FRONT")][1][1])&&i<4){
        UP_anticlockwise(rubiks, 1);
        j++;
        if(j>3){
            j=0;
            i++;
            half_horizontal_rotation(rubiks);
        }
    }
    if(rubiks[side_to_index("BACK")][0][1]==rubiks[side_to_index("BACK")][1][1]&&rubiks[side_to_index("FRONT")][0][1]==rubiks[side_to_index("FRONT")][1][1])
        return 1;
    return 0;
}

int yellow_cross_side_by_side(char ***rubiks){
    /* checks if it is the case where 2 faces are on good and on opposite faces */
    int i=0,j=0;
    while((rubiks[side_to_index("RIGHT")][0][1]!=rubiks[side_to_index("RIGHT")][1][1]||rubiks[side_to_index("FRONT")][0][1]!=rubiks[side_to_index("FRONT")][1][1])&&i<4){
        UP_anticlockwise(rubiks, 1);
        j++;
        if(j>3){
            j=0;
            i++;
            half_horizontal_rotation(rubiks);
        }
    }
    if(rubiks[side_to_index("RIGHT")][0][1]==rubiks[side_to_index("RIGHT")][1][1]&&rubiks[side_to_index("FRONT")][0][1]==rubiks[side_to_index("FRONT")][1][1])
        return 1;
    return 0;
}

int L_shape(char ***rubiks){
    /* checks the L Shape */
    int i, check=0;
    for(i=0;i<4;i++){
        if(rubiks[side_to_index("UP")][1][0]==rubiks[side_to_index("UP")][1][1]&&rubiks[side_to_index("UP")][0][1]==rubiks[side_to_index("UP")][1][1]&&rubiks[side_to_index("UP")][1][2]!=rubiks[side_to_index("UP")][1][1]&&rubiks[side_to_index("UP")][2][1]!=rubiks[side_to_index("UP")][1][1])
            check++;
        UP_clockwise(rubiks, 1);
    }
    if(check==1)
        return 1;
    return 0;
}

int barr(char ***rubiks){
    /* Checks the barr form */
    int i, check=0;
    for(i=0;i<2;i++){
        if(rubiks[side_to_index("UP")][1][0]==rubiks[side_to_index("UP")][1][1]&&rubiks[side_to_index("UP")][1][2]==rubiks[side_to_index("UP")][1][1]&&rubiks[side_to_index("UP")][0][1]!=rubiks[side_to_index("UP")][1][1]&&rubiks[side_to_index("UP")][2][1]!=rubiks[side_to_index("UP")][1][1])
            check++;
        UP_clockwise(rubiks, 1);
    }
    if(check==1)
        while(rubiks[side_to_index("UP")][1][0]!=rubiks[side_to_index("UP")][1][1])
            UP_clockwise(rubiks, 1);
        return 1;
    return 0;
}

int single_case_yellow(char ***rubiks){
    /* Checks if there is only one single yellow case */
    int i, cpt=0;
    for(i=0;i<4;i++){
        if(rubiks[side_to_index("UP")][0][1]==rubiks[side_to_index("UP")][1][1])
            cpt++;
        UP_clockwise(rubiks, 1);
    }
    if(cpt==0)
        return 1;
    return 0;
}

int check_corner_yellow(char ***rubiks){
    /*checks if the UP - FRONT - RIGHT corner has the right colors */
    if((rubiks[side_to_index("UP")][2][2]==rubiks[side_to_index("UP")][1][1]||rubiks[side_to_index("FRONT")][0][2]==rubiks[side_to_index("UP")][1][1]||rubiks[side_to_index("RIGHT")][0][0]==rubiks[side_to_index("UP")][1][1])
|| (rubiks[side_to_index("UP")][2][2]==rubiks[side_to_index("FRONT")][1][1]||rubiks[side_to_index("FRONT")][0][2]==rubiks[side_to_index("FRONT")][1][1]||rubiks[side_to_index("RIGHT")][0][0]==rubiks[side_to_index("FRONT")][1][1])
|| (rubiks[side_to_index("UP")][2][2]==rubiks[side_to_index("RIGHT")][1][1]||rubiks[side_to_index("FRONT")][0][2]==rubiks[side_to_index("RIGHT")][1][1]||rubiks[side_to_index("RIGHT")][0][0]==rubiks[side_to_index("RIGHT")][1][1]))
        return 1;
    return 0;
}

void solving_process(char ***rubiks, int i)
{
    switch (i)
    {
    case 1:
        printf("Next step: PERFECT WHITE CROSS\n");
        perfect_cross(rubiks);
        break;
    case 2:
        printf("Next step: FIRST CROWN\n");
        first_crown(rubiks);
        break;
    case 3:
        printf("Next step: SECOND CROWN\n");
        second_crown(rubiks);
        break;
    default:
        break;
    }
}


/* TEXT COLOR FUNCTION */

void text_color(int color) {
    static int BACKGROUND;
    HANDLE h = GetStdHandle ( STD_OUTPUT_HANDLE );
    CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
    GetConsoleScreenBufferInfo(h, &csbiInfo);
    SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), color + (BACKGROUND << 4));
}