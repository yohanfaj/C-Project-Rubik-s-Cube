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
            printf("\nWhat do you want to do ? \nPress 1 to display a blank cube, 2 to initialize it, 3 to fill it manually, 4 to scramble it or 0 to quit: ");
            scanf("%d", &op);
        } while (op < 0 && op >3);
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
                fill_menu(rubiks);
                display_rubiks(rubiks);

            case 4:
                scramble_rubiks(rubiks);
                printf("Here is your scrambled cube: \n");
                display_rubiks(rubiks);
                break;
            
            case 5:
                init_rubiks(rubiks);
                horizontal_rotation(rubiks);
                display_rubiks(rubiks);
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

