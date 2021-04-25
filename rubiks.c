#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
        break;
    case 2:
        return "BACK";
        break;
    case 3:
        return "UP";
        break;
    case 4:
        return "DOWN";
        break;
    case 5:
        return "RIGHT";
        break;
    case 6:
        return "LEFT";
        break;
    default:
        break;
    }
}



/* CUBE REPRESENTATION FUNCTIONS */

void create_rubiks(char ****rubiks)
{
    int i,j;
    *rubiks = (char ***) malloc(FACE * sizeof(char));
    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < SIZE; j++)
        {
            *rubiks[i][j] = (char*) malloc(SIZE * sizeof(char));
        }
    }
}


void init_rubiks(char ***rubiks)
{
    int i,j,k;
    for (i = 1; i <= FACE; i++)
    {
        *rubiks[i] = index_to_side(i); // warning: assignment discards 'const' qualifier from pointer target type [-Wdiscarded-qualifiers]
        if (side_to_index() == 1)
        {
            for (j = 0; j < SIZE; j++)
            {
                for (k = 0; i < SIZE; i++)
                {
                    *rubiks[j][k] = 'W';
                }
            }
            
        }
        
        else if (side_to_index() == 2)
        {
            for (j = 0; j < SIZE; j++)
            {
                for (k = 0; k < SIZE; k++)
                {
                    *rubiks[j][k] = 'Y';
                }
            }   
        }
        
        else if (side_to_index() == 3)
        {
            for (j = 0; j < SIZE; j++)
            {
                for (k = 0; k < SIZE; k++)
                {
                    *rubiks[j][k] = 'B';
                } 
            }
            
        }
        
        else if (side_to_index() == 4)
        {
            for (j = 0; j < SIZE; j++)
            {
                for (k = 0; k < SIZE; k++)
                {
                    *rubiks[j][k] = 'G';
                }
            }
            
        }
        
        else if (side_to_index() == 5)
        {
            for (j = 0; j < SIZE; j++)
            {
                for (k = 0; k < SIZE; k++)
                {
                    *rubiks[j][k] = 'R';
                }
            }
            
        }
        
        else if (side_to_index() == 6)
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
}


void display_rubiks(char ***rubiks)
{
    int i,j,k;

    for (i = 1; i <= FACE; i++)
    {
        printf("Face: %s\n", index_to_side(i));
        for (j = 0; i < SIZE; j++)
        {
            for (k = 0; k < SIZE; k++)
            {
                printf("%c ", rubiks[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
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
