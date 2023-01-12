#include <stdio.h>
#include "minesweeper.h"

void print_minefield(void)                                  // This function prints the minefield
{
    int i = 0, j = 0, z = 0;
    while( z < M )                                          // This while loop prints out the line of co-ordinates along the x axis of the minefield
    {
        if( z == 0 )
        {
            printf("\t");
        }
        printf("|%d|\t", z);
        z++;
    }
    printf("\n\n");

    while( j < N )                                          // Loop that prints out each character in the minefield                         
    {   
        printf("|%d|\t", j);
        while( i < M)
        {
            if( blank_minefield[i][j] == '-')
            {
                printf("|%c|\t", blank_minefield[i][j]);

            }
            else if( minefield[i][j] == 0 )                 // This changes any spaces with values of zero to the character 'B'
            {
                blank_minefield[i][j] = 0;                
                printf("|B|\t");
            }
            else
            {
                printf("|%d|\t", blank_minefield[i][j]);

            }
            i++;
        }
        printf("\n");
        i = 0;
        j++;
    }
}

void print_final_minefield( void )                      // Prints the minefield, showing where all of the mines are placed
{
    int i = 0, j = 0, z = 0;
    while( z < M )
    {
        if( z == 0 )
        {
            printf("\t");
        }
        printf("|%d|\t", z);
        z++;
    }
    printf("\n\n");

    while( j < N )
    {   
        printf("|%d|\t", j);
        while( i < M)
        {
            printf("|%c|\t", final_minefield[i][j]);
            i++;
        }
        printf("\n");
        i = 0;
        j++;
    }
}
