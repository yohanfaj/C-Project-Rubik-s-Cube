#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
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
        return 10;
        break;
    case BLUE_CASE:
        return 20;
        break;
    case GREEN_CASE:
        return 30;
        break;
    case WHITE_CASE:
        return 40;
        break;
    case YELLOW_CASE:
        return 50;
        break;
    case ORANGE_CASE:
        return 60;
        break;
    case LG_CASE:
        return 70;
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



/* CUBE REPRESENTATION FUNCTIONS */

void create_rubiks(int ****rubiks)
{
    int i,j;
    *rubiks = (int ***) malloc(FACE * sizeof(int));
    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < SIZE; j++)
        {
            *rubiks[i][j] = (int*) malloc(SIZE * sizeof(int));
        }
    }
}


void init_rubiks(int ***rubiks)
{
    int i,j,k;
    for (i = 1; i <= FACE; i++)
    {
        if (side_to_index() == 1)
        {
            for (j = 0; j < SIZE; j++)
            {
                for (k = 0; i < SIZE; i++)
                {
                    *rubiks[j][k] = WHITE_CASE;
                }
            }
            
        }
        
        else if (side_to_index() == 2)
        {
            for (j = 0; j < SIZE; j++)
            {
                for (k = 0; k < SIZE; k++)
                {
                    *rubiks[j][k] = YELLOW_CASE;
                }
            }   
        }
        
        else if (side_to_index() == 3)
        {
            for (j = 0; j < SIZE; j++)
            {
                for (k = 0; k < SIZE; k++)
                {
                    *rubiks[j][k] = BLUE_CASE;
                } 
            }
            
        }
        
        else if (side_to_index() == 4)
        {
            for (j = 0; j < SIZE; j++)
            {
                for (k = 0; k < SIZE; k++)
                {
                    *rubiks[j][k] = GREEN_CASE;
                }
            }
            
        }
        
        else if (side_to_index() == 5)
        {
            for (j = 0; j < SIZE; j++)
            {
                for (k = 0; k < SIZE; k++)
                {
                    *rubiks[j][k] = RED_CASE;
                }
            }
            
        }
        
        else if (side_to_index() == 6)
        {
            for (j = 0; j < SIZE; j++)
            {
                for (k = 0; k < SIZE; k++)
                {
                    *rubiks[j][k] = ORANGE_CASE;
                }
            }
            
        }
    }  
}


void display_rubiks(int ***rubiks)
{
    int i,j,k;
    for (i = 1; i <= FACE; i++)
    {
        for (j = 0; i < SIZE; j++)
        {
            for (k = 0; k < SIZE; k++)
            {
                printf("%d ", rubiks[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }
}





void free_rubiks(int ***rubiks)
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
