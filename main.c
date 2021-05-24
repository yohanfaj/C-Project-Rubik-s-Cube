/* 
BARBIER Adrien - FAJERMAN Yohan - L1 INT 1
C PROJECT - The Rubik's Cube - main.c
The file contains the main algorithm, including the User Interface, which performs our program.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "rubiks.c"
#define FACE 6
#define SIZE 3

void main(void)
{
    int i,j,k, op;
    int op_move_cube, op_clock, op_side, type;
    int init=0;
    int solved=0, cont=1, step;
    char ***rubiks = create_rubiks();
    
    printf("\nWelcome to the RUBIK'S CUBE SIMULATOR ! \n");

    do
    {
        do
        {
            printf("\nHere are your options: ");
            printf("\n1: BLANK -- 2: INITIALIZE -- 3: SCRAMBLE -- 4: FILL\n");
            printf("5: MOVE CUBE -- 6: MOVE SIDE -- 7: SOLVE -- 0: QUIT\n");
            printf("Action: ");
            scanf("%d", &op);
        } while (op < 0 || op > 7);
        printf("\n");

        switch (op)
        {
            case 1:
                printf("Here is your blank rubiks cube: \n");
                blank_rubiks(rubiks);
                display_rubiks(rubiks);
                break;
            
            case 2: 
                printf("Here is a normal rubiks cube: \n");
                init_rubiks(rubiks);
                init=1;
                display_rubiks(rubiks);
                break;

            case 3:
                if (init==1)
                {
                    scramble_rubiks(rubiks);
                    printf("Here is your scrambled cube: \n");
                    display_rubiks(rubiks);
                }
                else
                    printf("\nPlease INITIALIZE the Cube before performing any movement !\n");
                break;

            case 4:
                if (init==1)
                {
                    printf("PAY ATTENTION !!! there are several conditions to follow in order to fill the cube correctly: \n");
                    printf("\t 1) The center cell of the cube must always be of the same color:\n");
                    printf("\t\t UP=WHITE, LEFT=ORANGE, FRONT=GREEN,\n");
                    printf("\t\t RIGHT=RED, BACK=BLUE, DOWN=YELLOW.\n");
                    printf("\t 2) Two cells adjacent to the center cell must be of different colors.\n");
                    printf("\t 3) Two adjacent corners must be of different colors.\n");
                    printf("\n Also, please fill the cube with the following CAPITAL letters:\n");
                    printf("\t R for RED, B for BLUE, G for GREEN,"); 
                    printf("\t Y for YELLOW, O for ORANGE or W for WHITE.");

                    printf("\n\n Now, you have the choice between three filling methods:\n");
                    printf("\t 1) filling entirely a blank cube,\n");
                    printf("\t 2) filling an entire specific face,\n");
                    printf("\t 3) filling an specific cell.\n");
                    fill_menu(rubiks);
                }
                else
                    printf("\nPlease INITIALIZE the Cube before performing any movement !\n");
                break;
            
            case 5:
                if (init==1)
                {
                    do
                    {
                        printf("\nHORIZONTAL, HALF HORIZONTAL or VERTICAL Rotation ? Press 1, 2 or 3: ");
                        scanf("%d", &op_move_cube);
                    } while (op_move_cube < 1 || op_move_cube > 3);
                    printf("\n");

                    switch (op_move_cube)
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
                    display_rubiks(rubiks);
                }
                else
                    printf("\nPlease INITIALIZE the Cube before performing any movement !\n");
                break;

            case 6:
                if (init==1)
                {
                    do
                    {
                         do
                        {
                            printf("\nCLOCKWISE or ANTICLOCKWISE rotation ? Press 1 or 2: ");
                            scanf("%d", &op_clock);
                        } while (op_clock < 1 || op_clock > 2);
                        printf("\n");

                        do
                        {
                            printf("\nHow many rotations ? 1 for a quarter turn, 2 for a half turn, or 3 for three quarter turns: ");
                            scanf("%d", &type);
                        } while (type < 1 || type > 3);
                        printf("\n");

                        printf("1: UP -- 2: LEFT -- 3: FRONT\n");
                        printf("4: RIGHT -- 5: BACK -- 6: DOWN\n");
                        do
                        {
                            printf("Enter the side on which you want to apply the rotation: ");
                            scanf("%d", &op_side);
                        } while (op_side < 1 || op_side > 6);
                        printf("\n");

                        switch (op_clock)
                        {
                        case 1:
                            move_side_clockwise(rubiks, op_side, type);
                            break;
                        case 2:
                            move_side_anticlockwise(rubiks, op_side, type);
                            break;
                        default:
                            break;
                        }
                        display_rubiks(rubiks);

                        do
                        {
                            printf("Continue to perform some rotations? or do something else? Press 1 or 2: ");
                            scanf("%d", &cont);
                        } while (cont < 1 || cont > 2);
                        if (cont == 2)
                            break;
                    } while (cont == 1);
                }
                else
                    printf("\nPlease INITIALIZE the Cube before performing any movement !\n");
                break;

            case 7:
                if (init==1)
                {
                    do
                    {
                        do
                        {
                            printf("\nWhich step ?");
                            printf("\n1: PERFECT CROSS -- 2: 1st CROWN -- 3: 2nd CROWN: ");
                            scanf("%d", &step);
                        } while (step < 1 || step > 3);
                        printf("\n");
                        
                        solving_process(rubiks, step);
                        display_rubiks(rubiks);
                        do
                        {
                            printf("Continue to solve? or try it by yourself? press 1 or 2: ");
                            scanf("%d", &cont);
                        } while (cont < 1 || cont > 2);
                        if (cont == 2)
                            break;
                    } while (cont == 1 || solved == 0);
                }
                else
                    printf("\nPlease INITIALIZE the Cube before solving it !\n");
                break;

            case 0:
                printf("Thank you for using the simulator. Have a nice day !");
                break;
            default:
                printf("Wrong Choice, please try again. \n");
                break;
        }
    } while (op != 0);


    free_rubiks(rubiks);
}

