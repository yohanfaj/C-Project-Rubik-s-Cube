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
    char ***rubiks = create_rubiks();
    
    printf("\nWelcome to the RUBIK'S CUBE SIMULATOR ! \n");

    do
    {
        do
        {
            printf("\nWhat do you want to do ? \nPress 1 to display a blank cube, 2 to initialize it, 3 to scramble it, 4 to fill it manually, 5 to move the cube or 0 to quit: ");
            scanf("%d", &op);
        } while (op < 0 || op > 6);
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
                display_rubiks(rubiks);
                break;

            case 3:
                scramble_rubiks(rubiks);
                printf("Here is your scrambled cube: \n");
                display_rubiks(rubiks);
                break;

            case 4:
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
                break;
            
            case 5:
                move_rubiks(rubiks);
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

