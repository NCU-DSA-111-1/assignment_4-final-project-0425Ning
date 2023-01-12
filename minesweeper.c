#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "minesweeper.h"

void minefield_generator( void )                            //Function that generates the minefield
{
    int i = 0, j = 0;

    srand( time( NULL ) );                                  //Starts the random no. generator

    while( j < N )                                          //Nested loop for making the blank minefield and final minefield
    {
        while( i < M)
        {
            minefield[i][j] = '-';
            blank_minefield[i][j] = minefield[i][j];        
            final_minefield[i][j] = minefield[i][j];        
            i++;
        }
        i = 0;
        j++;
    }
    mines = 0;
    while( mines < total_mines )                            //Randomly generates the mines into the minefield
    {
        i = rand()%(M);
        j = rand()%(N);
        if( minefield[i][j] != '*')                         //If statement that checks if there is a mine already there and doesn't place a mine if there is
        {
            minefield[i][j] = '*';
            final_minefield[i][j] = minefield[i][j];
            mines++;
        }
    }
    i = 0;
    j = 0;

    while( j < N )                                          //While loop that generates the numbers for any adjacent mines
    {
        while( i < M)
        {
            if( minefield[i][j] != '*')
            {
                minefield[i][j] = 0;
            }   
            if((minefield[i-1][j-1] == '*') && (minefield[i][j] != '*'))
            {
                minefield[i][j]++;
            }
            if((minefield[i-1][j] == '*') && (minefield[i][j] != '*'))
            {
                minefield[i][j]++;
            }
            if((minefield[i][j-1] == '*') && (minefield[i][j] != '*'))
            {
                minefield[i][j]++;
            }
            if((minefield[i-1][j+1] == '*') && (minefield[i][j] != '*'))
            {
                minefield[i][j]++;
            }
            if((minefield[i+1][j-1] == '*') && (minefield[i][j] != '*'))
            {
                minefield[i][j]++;
            }
            if((minefield[i+1][j] == '*') && (minefield[i][j] != '*'))
            {
                minefield[i][j]++;
            }
            if((minefield[i][j+1] == '*') && (minefield[i][j] != '*'))
            {
                minefield[i][j]++;
            }
            if((minefield[i+1][j+1] == '*') && (minefield[i][j] != '*'))
            {
                minefield[i][j]++;
            }
            i++;
        }
        i = 0;
        j++;
    }
    i = 0;
    j = 0;
}
