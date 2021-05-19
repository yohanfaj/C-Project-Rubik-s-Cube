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
        return RED_CASE;
        break;
    case 'B':
        return BLUE_CASE;
        break;
    case 'G':
        return GREEN_CASE;
        break;
    case 'W':
        return WHITE_CASE;
        break;
    case 'Y':
        return YELLOW_CASE;
        break;
    case 'O':
        return ORANGE_CASE;
        break;
    case '-':
        return LG_CASE;
        break;
    default:
        return LG_CASE;
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
 


void fill_face(char ***rubiks)
{
    int i,j,k;
    for (i = 0; i < FACE; i++)
    {
        printf("Face: %s\n", index_to_side(i));
        for (j = 0; j < SIZE; j++)
        {
            for (k = 0; k < SIZE; k++)
            {
                printf("Line %d - Case %d: ", j, k);
                scanf(" %c", &(rubiks[i][j][k]));
            }
            printf("\n");
        }
        printf("\n");
    }
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


/* MOVEMENT FUNCTIONS */

void FRONT_clockwise(char ***rubiks, int type)
{
    int cpt,i,j,k;
    for (cpt = 0; cpt < type; cpt++)
    {
        rubiks[side_to_index("UP")][2][0] = rubiks[side_to_index("RIGHT")][0][0];
        rubiks[side_to_index("UP")][2][1] = rubiks[side_to_index("RIGHT")][1][0];
        rubiks[side_to_index("UP")][2][2] = rubiks[side_to_index("RIGHT")][2][0];

        rubiks[side_to_index("RIGHT")][0][0] = rubiks[side_to_index("DOWN")][0][0];
        rubiks[side_to_index("RIGHT")][1][0] = rubiks[side_to_index("DOWN")][0][1];
        rubiks[side_to_index("RIGHT")][2][0] = rubiks[side_to_index("DOWN")][0][2];

        rubiks[side_to_index("DOWN")][0][0] = rubiks[side_to_index("LEFT")][0][2];
        rubiks[side_to_index("DOWN")][0][1] = rubiks[side_to_index("LEFT")][1][2];
        rubiks[side_to_index("DOWN")][0][2] = rubiks[side_to_index("LEFT")][2][2];

        rubiks[side_to_index("LEFT")][0][2] = rubiks[side_to_index("UP")][2][0];
        rubiks[side_to_index("LEFT")][1][2] = rubiks[side_to_index("UP")][2][0];
        rubiks[side_to_index("LEFT")][2][2] = rubiks[side_to_index("UP")][2][0];
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


void text_color(int color) {
    static int BACKGROUND;
    HANDLE h = GetStdHandle ( STD_OUTPUT_HANDLE );
    CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
    GetConsoleScreenBufferInfo(h, &csbiInfo);
    SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), color + (BACKGROUND << 4));
}