#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "conio.h"
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
    case 5;
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
    FRONT_clockwise(rubiks, (rand()%5)+1);
    BACK_clockwise(rubiks, (rand()%5)+1);
    UP_clockwise(rubiks, (rand()%5)+1);
    DOWN_clockwise(rubiks, (rand()%5)+1);
    RIGHT_clockwise(rubiks, (rand()%5)+1);
    LEFT_clockwise(rubiks, (rand()%5)+1);
    FRONT_anticlockwise(rubiks, (rand()%5)+1);
    BACK_anticlockwise(rubiks, (rand()%5)+1);
    UP_anticlockwise(rubiks, (rand()%5)+1);
    DOWN_anticlockwise(rubiks, (rand()%5)+1);
    RIGHT_anticlockwise(rubiks, (rand()%5)+1);
    LEFT_anticlockwise(rubiks, (rand()%5)+1);
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
                    cpt[5]++
            } 
        }  
    }
}


int check_comb_centers(char ***rubiks)
{
    int i, check=1;
    if (rubiks[i][1][1] == rubiks[i][0][1] || rubiks[i][1][1] == rubiks[i][2][1] 
    || rubiks[i][1][1] == rubiks[i][1][0] || rubiks[i][1][1] == rubiks[i][1][2] || rubiks[i][1][1] != index_to_color(i))
        check = 0;
    return check;
}

int check_comb_corners(char ***rubiks)
{
    int i,j,k, check=1;
    if (/*condition*/)
        check=0;
    return check;
}



void switch_color_input(char c)
{
    int index;
    switch (c)
    {
    case 'R':
        index = 0;
        if (cpt[index]>=0)
                cpt[index]--;
        else {
            c = '-';
            cpt[index]=0;
        }
        break;

    case 'B':
        index = 1;
        if (cpt[index]>=0)
            cpt[index]--;
        else {
            c = '-';
            cpt[index]=0;
        }
        break;

    case 'G':
        index = 2;
        if (cpt[index]>=0)
            cpt[index]--;
        else {
            c = '-';
            cpt[index]=0;
        }
        break;

    case 'Y':
        index = 3;
        if (cpt[index]>=0)
            cpt[index]--;
        else {
            c = '-';
            cpt[index]=0;
        }
        break;

    case 'O':
        index = 4;
        if (cpt[index]>=0)
            cpt[index]--;
        else {
            c = '-';
            cpt[index]=0;
        }
        break;

    case 'W':
        index = 5;
        if (cpt[index]>=0)
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
                switch_color_input(rubiks[i][j][k]);
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
            switch_color_input(rubiks[side_to_index(face)][i][j]);
        }
    }
} 


void fill_user_cell(char ***rubiks)
{
    int i,j;
    char face[100];
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
    switch_color_input(rubiks[side_to_index(face)][i][j]);
}



void fill_menu(char ***rubiks)
{
    int i,j,k, op;
    printf("PAY ATTENTION !!! there are several conditions to follow in order to fill the cube correctly: \n
    \t 1) The center cell of the cube must always be of the same color:\n
    \t\t UP=WHITE, LEFT=ORANGE, FRONT=GREEN,\n
    \t\t RIGHT=RED, BACK=BLUE, DOWN=YELLOW.\n
    \t 2) Two cells adjacent to the center cell must be of different colors.\n
    \t 3) Two adjacent corners must be of different colors.\n
    \n Also, please fill the cube with the following CAPITAL letters:\n
    \t R for RED, B for BLUE, G for GREEN, 
    \t Y for YELLOW, O for ORANGE or W for WHITE.");

    printf("\n\n Now, you have the choice between three filling methods:\n
    \t 1) filling entirely a blank cube,\n
    \t 2) filling an entire specific face,\n
    \t 3) filling an specific cell.\n");
    do
    {
        printf("Please, select one of these with 1, 2 or 3:");
        scanf("%d", &op);
    } while (op < 1 && op > 3);

    switch (op)
    {
    case 1:
        do
        {
            fill_all_cube(rubiks);
            if (check_comb_centers(rubiks) == 0)
            {
                printf("ATTENTION !!! there is a problem with the center cells of your cube. 
                Please take into account the conditions of filling !\n");
            }
            else if (check_comb_corners(rubiks) == 0)
            {
                printf("ATTENTION !!! there is a problem with the corners of your cube. 
                Please take into account the conditions of filling !\n");
            }
        } while (check_comb_centers(rubiks) == 0 && check_comb_corners(rubiks) == 0);
        printf("Your new cube is: \n");
        display_rubiks(rubiks);
        break;
    
    case 2: 
        do
        {
            fill_user_face(rubiks);
            if (check_comb_centers(rubiks) == 0)
            {
                printf("ATTENTION !!! there is a problem with the center cells of your cube. 
                Please take into account the conditions of filling !\n");
            }
            else if (check_comb_corners(rubiks) == 0)
            {
                printf("ATTENTION !!! there is a problem with the corners of your cube. 
                Please take into account the conditions of filling !\n");
            }
        } while (check_comb_centers(rubiks) == 0 && check_comb_corners(rubiks) == 0);
        printf("Your new cube is: \n");
        display_rubiks(rubiks);
        break;

    case 3:
        do
        {
            fill_user_cell(rubiks);
            if (check_comb_centers(rubiks) == 0)
            {
                printf("ATTENTION !!! there is a problem with the center cells of your cube. 
                Please take into account the conditions of filling !\n");
            }
            else if (check_comb_corners(rubiks) == 0)
            {
                printf("ATTENTION !!! there is a problem with the corners of your cube. 
                Please take into account the conditions of filling !\n");
            }
        } while (check_comb_centers(rubiks) == 0 && check_comb_corners(rubiks) == 0);
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
        for(i=0;i<SIZE;i++){
            save1[i]=rubiks[side_to_index("FRONT")][0][i];
            save2[i]=rubiks[side_to_index("FRONT")][i][2];
        }
        for(i=0;i<SIZE;i++){
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
        for(i=0;i<SIZE;i++){
            save1[i]=rubiks[4][0][i];
            save2[i]=rubiks[4][i][2];
        }
        for(i=0;i<SIZE;i++){
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
        for(i=0;i<SIZE;i++){
            save1[i]=rubiks[side_to_index("UP")][0][i];
            save2[i]=rubiks[side_to_index("UP")][i][2];
        }
        for(i=0;i<SIZE;i++){
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
        for(i=0;i<SIZE;i++){
            save1[i]=rubiks[side_to_index("DOWN")][0][i];
            save2[i]=rubiks[side_to_index("DOWN")][i][2];
        }
        for(i=0;i<SIZE;i++){
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
        for(i=0;i<SIZE;i++){
            save1[i]=rubiks[side_to_index("RIGHT")][0][i];
            save2[i]=rubiks[side_to_index("RIGHT")][i][2];
        }
        for(i=0;i<SIZE;i++){
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
    char save1[3], save2[3];
    for(cpt=0;cpt<type;cpt++){
        for(i=0;i<SIZE;i++){
            save1[i]=rubiks[side_to_index("LEFT")][0][i];
            save2[i]=rubiks[side_to_index("LEFT")][i][2];
        }
        for(i=0;i<SIZE;i++){
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
        for(i=0;i<SIZE;i++){
            save1[i]=rubiks[side_to_index("FRONT")][0][i];
            save2[i]=rubiks[side_to_index("FRONT")][i][2];
        }
        for(i=0;i<SIZE;i++){
            rubiks[side_to_index("FRONT")][i][2]=rubiks[side_to_index("FRONT")][2][2-i];
            rubiks[side_to_index("FRONT")][2][2-i]=rubiks[side_to_index("FRONT")][0][2-i];
            rubiks[side_to_index("FRONT")][0][2-i]=save1[i];
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
        for(i=0;i<SIZE;i++){
            save1[i]=rubiks[side_to_index("BACK")][0][i];
            save2[i]=rubiks[side_to_index("BACK")][i][2];
        }
        for(i=0;i<SIZE;i++){
            rubiks[side_to_index("BACK")][i][2]=rubiks[side_to_index("BACK")][2][2-i];
            rubiks[side_to_index("BACK")][2][2-i]=rubiks[side_to_index("BACK")][0][2-i];
            rubiks[side_to_index("BACK")][0][2-i]=save1[i];
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
        for(i=0;i<SIZE;i++){
            save1[i]=rubiks[side_to_index("UP")][0][i];
            save2[i]=rubiks[side_to_index("UP")][i][2];
        }
        for(i=0;i<SIZE;i++){
            rubiks[side_to_index("UP")][i][2]=rubiks[side_to_index("UP")][2][2-i];
            rubiks[side_to_index("UP")][2][2-i]=rubiks[side_to_index("UP")][0][2-i];
            rubiks[side_to_index("UP")][0][2-i]=save1[i];
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
        for(i=0;i<SIZE;i++){
            save1[i]=rubiks[side_to_index("DOWN")][0][i];
            save2[i]=rubiks[side_to_index("DOWN")][i][2];
        }
        for(i=0;i<SIZE;i++){
            rubiks[side_to_index("DOWN")][i][2]=rubiks[side_to_index("DOWN")][2][2-i];
            rubiks[side_to_index("DOWN")][2][2-i]=rubiks[side_to_index("DOWN")][0][2-i];
            rubiks[side_to_index("DOWN")][0][2-i]=save1[i];
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
        for(i=0;i<SIZE;i++){
            save1[i]=rubiks[side_to_index("RIGHT")][0][i];
            save2[i]=rubiks[side_to_index("RIGHT")][i][2];
        }
        for(i=0;i<SIZE;i++){
            rubiks[side_to_index("RIGHT")][i][2]=rubiks[side_to_index("RIGHT")][2][2-i];
            rubiks[side_to_index("RIGHT")][2][2-i]=rubiks[side_to_index("RIGHT")][0][2-i];
            rubiks[side_to_index("RIGHT")][0][2-i]=save1[i];
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
        for(i=0;i<SIZE;i++){
            save1[i]=rubiks[side_to_index("LEFT")][0][i];
            save2[i]=rubiks[side_to_index("LEFT")][i][2];
        }
        for(i=0;i<SIZE;i++){
            rubiks[side_to_index("LEFT")][i][2]=rubiks[side_to_index("LEFT")][2][2-i];
            rubiks[side_to_index("LEFT")][2][2-i]=rubiks[side_to_index("LEFT")][0][2-i];
            rubiks[side_to_index("LEFT")][0][2-i]=save1[i];
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


void text_color(int color) {
    static int BACKGROUND;
    HANDLE h = GetStdHandle ( STD_OUTPUT_HANDLE );
    CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
    GetConsoleScreenBufferInfo(h, &csbiInfo);
    SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), color + (BACKGROUND << 4));
}