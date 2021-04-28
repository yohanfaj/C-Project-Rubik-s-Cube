#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "conio.h"
#include "rubiks.h"
#define FACE 6
#define SIZE 3

/* ENUM TYPE FUNCTIONS */

T_COLOR select_color()
{
    T_COLOR color_case;
    switch(color_case)
    {
    case RED_CASE:
        return 'R';
        break;
    case BLUE_CASE:
        return 'B';
        break;
    case GREEN_CASE:
        return 'G';
        break;
    case WHITE_CASE:
        return 'W';
        break;
    case YELLOW_CASE:
        return 'Y';
        break;
    case ORANGE_CASE:
        return 'O';
        break;
    case LG_CASE:
        return '-';
        break;
    default:
        break;
    }
}


T_SIDE side_to_index()
{
    T_SIDE side;
    switch(side)
    {
    case FRONT:
        return 1;
        break;
    case BACK:
        return 2;
        break;
    case UP:
        return 3;
        break;
    case DOWN:
        return 4;
        break;
    case RIGHT:
        return 5;
        break;
    case LEFT:
        return 6;
        break;
    default:
        break;
    }
}


const char* index_to_side(int i)
{
    switch(i)
    {
    case 1:
        return "FRONT";
    case 2:
        return "BACK";
    case 3:
        return "UP";
    case 4:
        return "DOWN";
    case 5:
        return "RIGHT";
    case 6:
        return "LEFT";
    default:
        break;
    }
}



/* CUBE REPRESENTATION FUNCTIONS */

char*** create_rubiks()
{
    char i,j,k;
    char ***rubiks = malloc(FACE * sizeof(char**));
    for (i = 0; i <= FACE; i++)
    {
        rubiks[i] = malloc(SIZE * sizeof(char*));
        for (j = 0; j <= SIZE; j++)
        {
            rubiks[i][j] = malloc(SIZE * sizeof(char));
        }  
    }
    return rubiks;
}



void init_rubiks(char ***rubiks)
{
    int i,j,k;
    for (i = 1; i <= FACE; i++)
    {
        /* **rubiks[i] = index_to_side(i); warning: assignment discards 'const' qualifier from pointer target type [-Wdiscarded-qualifiers ] */
        switch (i)
        {
        case 1:
            for (j = 0; j <= SIZE; j++)
            {
                for (k = 0; k <= SIZE; k++)
                {
                    *(*(*(rubiks+i)+j)+k) = 'G';
                }
            }
            break;
        case 2:
            for (j = 0; j <= SIZE; j++)
            {
                for (k = 0; k <= SIZE; k++)
                {
                    *(*(*(rubiks+i)+j)+k) = 'B';
                }
            }
            break;
        case 3:
            for (j = 0; j <= SIZE; j++)
            {
                for (k = 0; k <= SIZE; k++)
                {
                    *(*(*(rubiks+i)+j)+k) = 'W';
                } 
            }
            break;
        case 4:
            for (j = 0; j <= SIZE; j++)
            {
                for (k = 0; k <= SIZE; k++)
                {
                    *(*(*(rubiks+i)+j)+k) = 'Y';
                }
            }
            break;
        case 5: 
            for (j = 0; j <= SIZE; j++)
            {
                for (k = 0; k <= SIZE; k++)
                {
                    *(*(*(rubiks+i)+j)+k) = 'R';
                }
            }
            break;
        case 6:
            for (j = 0; j <= SIZE; j++)
            {
                for (k = 0; k <= SIZE; k++)
                {
                    *(*(*(rubiks+i)+j)+k) = 'O';
                }
            }  
            break;
        default:
            break;
        } 
    }
}
 /*       if (i == 1)
        {
            for (j = 0; j < SIZE; j++)
            {
                for (k = 0; i < SIZE; i++)
                {
                    *rubiks[j][k] = 'W';
                }
            }
            
        }
        
        else if (i == 2)
        {
            for (j = 0; j < SIZE; j++)
            {
                for (k = 0; k < SIZE; k++)
                {
                    *rubiks[j][k] = 'Y';
                }
            }   
        }
        
        else if (i == 3)
        {
            for (j = 0; j < SIZE; j++)
            {
                for (k = 0; k < SIZE; k++)
                {
                    *rubiks[j][k] = 'B';
                } 
            }
            
        }
        
        else if (i == 4)
        {
            for (j = 0; j < SIZE; j++)
            {
                for (k = 0; k < SIZE; k++)
                {
                    *rubiks[j][k] = 'G';
                }
            }
            
        }
        
        else if (i == 5)
        {
            for (j = 0; j < SIZE; j++)
            {
                for (k = 0; k < SIZE; k++)
                {
                    *rubiks[j][k] = 'R';
                }
            }
            
        }
        
        else if (i == 6)
        {
            for (j = 0; j < SIZE; j++)
            {
                for (k = 0; k < SIZE; k++)
                {
                    *rubiks[j][k] = 'O';
                }
            }  
        }
    }  
}*/



void fill_face(char ***rubiks)
{
    int i,j,k;
    for (i = 1; i <= FACE; i++)
    {
        printf("Face: %s\n", index_to_side(i));
        for (j = 0; j < SIZE; j++)
        {
            for (k = 0; k < SIZE; k++)
            {
                printf("Line %d - Case %d: ", j+1, k+1);
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
            text_color(15);
            printf("%c ", rubiks[3][j][k]);
        }
        printf("\n");
    }
    printf("\n");
    for(j=0;j<SIZE;j++){
        for(k=0;k<SIZE;k++){
            text_color(12);
            printf("%c ", rubiks[6][j][k]);
        }
        printf("  ");
        for(k=0;k<SIZE;k++){
            text_color(2);
            printf("%c ", rubiks[1][j][k]);
        }
        printf("  ");
        for(k=0;k<SIZE;k++){
            text_color(4);
            printf("%c ", rubiks[5][j][k]);
        }
        printf("  ");
        for(k=0;k<SIZE;k++){
            text_color(9);
            printf("%c ", rubiks[2][j][k]);
        }
        printf("\n");
    }
    printf("\n");
    for(j=0;j<SIZE;j++){
        printf("        ");
        for(k=0;k<SIZE;k++){
            text_color(14);
            printf("%c ", rubiks[4][j][k]);
        }
        printf("\n");
    }
    text_color(15);
}

void blank_rubiks(char ***rubiks){
    int i,j,k;
    for(i=1;i<=FACE;i++){
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

void text_color(int color) {
    static int BACKGROUND;
    HANDLE h = GetStdHandle ( STD_OUTPUT_HANDLE );
    CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
    GetConsoleScreenBufferInfo(h, &csbiInfo);
    SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), color + (BACKGROUND << 4));
}