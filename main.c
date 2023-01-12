
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "minesweeper.h"
#include "history.h"
#include "clock.h"

#define FLUSH fflush(stdin)

void difficulty( void );
void easy( history * ptr_h, history * ptr_front ); //add
void beginner( history * ptr_h, history * ptr_front );
void intermediate( history * ptr_h, history * ptr_front );
void expert( history * ptr_h, history * ptr_front );
void custom( history * ptr_h, history * ptr_front );
void guess( history * ptr_h, history * ptr_front );
void time_limit( history * ptr_front );
void boom( history * ptr_front );
void win( history * ptr_front );
void play_again( void );
void game_over( void );

int main()
{
    printf("\t\tWelcome to Minesweeper\n");
    difficulty();
    return 0;
}

void difficulty( void )                                     //Function for choosing the difficulty level
{
    DIFF diff = 0;
    cnt = 0;
    while( (diff != BEGINNER) && (diff != INTERMEDIATE) && (diff != EXPERT) && (diff != CUSTOM))        
    {
        printf("\t\tChoose a difficulty level(1-3) or 4 for a custom game: ");   
        scanf("%d", &diff);
        FLUSH;
        if( (diff != BEGINNER) && (diff != INTERMEDIATE) && (diff != EXPERT) && (diff != CUSTOM))
        {
            printf("\t\tPlease enter either 1, 2, 3 or 4\n");
        }
    }
    history * ptr_h = (history*)malloc(sizeof(history));
    ptr_h->count = cnt;
    ptr_h->ptr = NULL;
    history * ptr_front = ptr_h;
    switch(diff)                                            //If, else if and else statements that each go to the respective difficulty
    {
        case BEGINNER:
        beginner(ptr_h, ptr_front);

        case INTERMEDIATE:
        intermediate(ptr_h, ptr_front);

        case EXPERT: 
        expert(ptr_h, ptr_front);

        case CUSTOM:
        custom(ptr_h, ptr_front);
    }
}

void easy( history * ptr_h, history * ptr_front )  //add                                //Gives the minefield the 'easy' grid and mines
{
    M = EASY_M;
    N = EASY_N;
    total_mines = EASY_TOTAL_MINES;
    printf("\t\tPlease input the time(seconds) that you want to limit: ");
    scanf("%f", &time_limitation);
    minefield_generator();
    start = clock();
    guess(ptr_h, ptr_front);
}

void beginner( history * ptr_h, history * ptr_front )                                       //Gives the minefield the 'beginner' grid and mines
{
    M = BEGINNER_M;
    N = BEGINNER_N;
    total_mines = BEGINNER_TOTAL_MINES;
    printf("\t\tPlease input the time(seconds) that you want to limit: ");
    scanf("%f", &time_limitation);
    minefield_generator();
    start = clock();
    guess(ptr_h, ptr_front);
}

void intermediate( history * ptr_h, history * ptr_front )                                   //Gives the minefield the 'intermediate' grid and mines
{
    M = INTERMEDIATE_M;
    N = INTERMEDIATE_N;
    total_mines = INTERMEDIATE_TOTAL_MINES;
    printf("\t\tPlease input the time(seconds) that you want to limit: ");
    scanf("%f", &time_limitation);
    minefield_generator();
    start = clock();
    guess(ptr_h, ptr_front);
}

void expert( history * ptr_h, history * ptr_front )                                         //Gives the minefield the 'expert' grid size and mines
{
    M = EXPERT_M;
    N = EXPERT_N;
    total_mines = EXPERT_TOTAL_MINES;
    printf("\t\tPlease input the time(seconds) that you want to limit: ");
    scanf("%f", &time_limitation);
    minefield_generator();
    start = clock();
    guess(ptr_h, ptr_front);
}

void custom( history * ptr_h, history * ptr_front )
{
    M = 0;
    N = 0;
    total_mines = 0;
    printf("\t\tPlease enter the size of the dimensions you want\n");
    printf("\t\tFirst value(col): ");
    scanf("%d", &M);
    printf("\t\tSecond value(row): ");
    scanf("%d", &N);
    printf("\t\tNumber of mines you want to assign to the board: ");
    scanf("%d", &total_mines);
    printf("\t\tPlease input the time(seconds) that you want to limit: ");
    scanf("%f", &time_limitation);
    minefield_generator();
    start = clock();
    guess(ptr_h, ptr_front);
}

void guess( history * ptr_h, history * ptr_front )
{
    int q = 0, i=0, j=0, match=0;
    print_minefield();
    while( j < N )                                          // While loop for testing whether or not the user has cleared the minefield
    {
        while( i < M )
        {
            if(minefield[i][j] == blank_minefield[i][j])
            {
                match++;
            }
            i++;
        }
        i = 0;
        j++;
    }
    if( match == (( M * N ) - total_mines))                 // If the user has cleared the minefield, the win() function is run
    {
        finish = clock();
        win(ptr_front);
    }
    finish_limit = clock();
    if(((finish_limit-start)/(double)(CLOCKS_PER_SEC)) > time_limitation)
    {
        finish = clock();
        time_limit(ptr_front);
    }
    printf("\nEnter the x(col) value, then a space, then the y(row) value: ");
    scanf("%d %d", &x, &y);                                 // Reading in the coordinates for the guess
    FLUSH;
    if( (x >= M) || (x < 0) || (y < 0) || (y >= N) )
    {
        printf("\nPlease enter a value inside the grid\n");
        guess(ptr_h, ptr_front);
    }
    if( minefield[x][y] == '*' )                            // Runs the boom() function if the user selects a mine
    {
        finish = clock();
        ptr_h->ptr = (history*)malloc(sizeof(history));
        ptr_h = ptr_h->ptr;
        ptr_h->count = cnt++;
        ptr_h->col = x;
        ptr_h->row = y;
        ptr_h->ptr = NULL;
        boom(ptr_front);
    }
    if( blank_minefield[x][y] != '-' )
    {
        printf("\nPlease enter a value that has not already been entered\n");
        guess(ptr_h, ptr_front);
    }
    else                                                // Checks if the adjacent spaces are blank, then changes the values in the blank_minefield array.
    {                                                   // Because they are changed, they will now print out in the print_minefield function.
        blank_minefield[x][y] = minefield[x][y];
        ptr_h->ptr = (history*)malloc(sizeof(history));
        ptr_h = ptr_h->ptr;
        ptr_h->count = cnt++;
        ptr_h->col = x;
        ptr_h->row = y;
        ptr_h->ptr = NULL;
        if( minefield[x][y] == 0 )
        {
            if( minefield[x-1][y-1] == 0 )
            {
                blank_minefield[x-1][y] = minefield[x-1][y];
            }
            if( minefield[x-1][y] == 0 )
            {
                blank_minefield[x-1][y] = minefield[x-1][y];
            }
            if( minefield[x][y-1] == 0 )
            {
                blank_minefield[x][y-1] = minefield[x][y-1];
            }
            if( minefield[x-1][y+1] == 0 )
            {
                blank_minefield[x-1][y+1] = minefield[x-1][y+1];
            }
            if( minefield[x+1][y-1] == 0 )
            {
                blank_minefield[x+1][y-1] = minefield[x+1][y-1];
            }
            if( minefield[x+1][y] == 0 )
            {
                blank_minefield[x+1][y] = minefield[x+1][y];
            }
            if( minefield[x][y+1] == 0 )
            {
                blank_minefield[x][y+1] = minefield[x][y+1];
            }
            if( minefield[x+1][y+1] == 0 )
            {
                blank_minefield[x+1][y+1] = minefield[x+1][y+1];
            }
        }
        guess(ptr_h, ptr_front);
    }
}

void time_limit( history * ptr_front )                                       // Runs the print_final_minefield function, then the play_again function                    
{
    printf("\n");
    print_final_minefield();
    show_history(ptr_front);
    printf("\n\t\tYou exceed the time(%f seconds) of this game.", time_limitation);
    printf("\n\t\tYou spent %f seconds.", (finish-start)/(double)(CLOCKS_PER_SEC));
    play_again();
}

void boom( history * ptr_front )                                       // Runs the print_final_minefield function, then the play_again function                    
{
    print_final_minefield();
    show_history(ptr_front);
    printf("\n\t\tYou spent %f seconds.", (finish-start)/(double)(CLOCKS_PER_SEC));
    printf("\n\t\tYou hit a mine at %d,%d\n\t\tYOU LOSE!!!!", x, y);
    play_again();
}

void win( history * ptr_front )                                        // Runs the play_again function
{
    show_history(ptr_front);
    printf("\n\t\tYou spent %f seconds.", (finish-start)/(double)(CLOCKS_PER_SEC));
    printf("\n\n\n\t\t\tYOU WIN!!!!!\n\n\n");
    play_again();
}

void play_again( void )                                 // Gives the user the option to play again
{
    char option;
    printf("\n\t\tWould you like to play again(Y/N)?: ");
    scanf("%c", &option);
    FLUSH;
    if((option == 'Y') || (option == 'y'))        // Restarts the program from after the welcome message
    {
        difficulty();
    }
    else if( (option == 'N') || (option == 'n'))
    {
        game_over();
    }
    else
    {
        printf("Please enter either Y or N");
        play_again();
    }
}

void game_over( void )                                  // Ends the program
{
    printf("\n\n\t\tGame Over");
    exit(1);
}