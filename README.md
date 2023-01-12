# Minesweeper

## Usage
```sh
# Compile
cd D:\\文件\\大四上\\資料結構\\Minesweeper\\final_project\\src
gcc -o -o main main.c minesweeper.c printfield.c history.c 
# Run
./main
```
Enter the difficulty that you want to challenge [1/2/3/4]. <br />
Enter the time(seconds) that would limit how long you can play the game. <br />
<br />

Start to play the game! <br />
Enter the col and row number until you win or lose(including if you hit the mine or exceed the time) the game. <br />
<br />

If you win
Output: the history of the number(col & row) you enter and the total time you spent. <br />

If you lose
Output: the field of the mines, the history of the number(col & row) you enter, and the total time you spent. <br />
<br />

Enter whether you want to play the game or not [Y/N]. <br />
Y -> start a new game of minesweeper <br />
N -> exit the game <br />
<br />