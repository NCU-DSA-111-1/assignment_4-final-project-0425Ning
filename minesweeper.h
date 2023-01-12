
#define INITIAL_VALUE 30
#define EASY_M 5
#define EASY_N 5
#define EASY_TOTAL_MINES 2
#define BEGINNER_M 9
#define BEGINNER_N 9
#define BEGINNER_TOTAL_MINES 10
#define INTERMEDIATE_M 16
#define INTERMEDIATE_N 16
#define INTERMEDIATE_TOTAL_MINES 40
#define EXPERT_M 16
#define EXPERT_N 30
#define EXPERT_TOTAL_MINES 99

typedef enum {
    BEGINNER = 1,
    INTERMEDIATE = 2,
    EXPERT = 3,
    CUSTOM = 4,
} DIFF;

int x, y;
int M, N;
int diff;
int total_mines;
int mines;
int minefield[INITIAL_VALUE][INITIAL_VALUE];                                      //This 2-D array contains all of the mines, numbers and blank spaces
int blank_minefield[INITIAL_VALUE][INITIAL_VALUE];                                //This contains the minefield full of '|-|' characters
int final_minefield[INITIAL_VALUE][INITIAL_VALUE];

void minefield_generator( void );
void print_minefield( void );
void print_final_minefield( void );
