#include<stdio.h>
#include<stdlib.h>
#include<time.h>

char board[3][3];
const char PLAYER = 'X';
const char COMPUTER = 'O';

void printWinner(char);

void reset_board(){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            board[i][j] = ' ';
        }
    }
}

void print_board(){
    printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
}

int checkFreeSpaces(){
    int freeSpaces = 9;

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(board[i][j] != ' '){
                freeSpaces--;
            }
        }
    }
    return freeSpaces;
}

void playerMove(){
    int x, y;

    do
    {
        printf("Enter row number (1 - 3): ");
        scanf("%d", &x);
        x--;
        printf("Enter column number (1 - 3): ");
        scanf("%d", &y);
        y--;
        
        if(board[x][y] != ' '){
            printf("Invalid move!\n");
        } else{
            board[x][y] = PLAYER;
            break;
        }
    } while (board[x][y != ' ']);
    
}

char checkWinner(){
    char winner;

    /*Check rows*/
    for(int i = 0; i < 3; i++){
        if(board[i][0] == board[i][1] && board[i][0] == board[i][2]){
            winner = board[i][0];
            return winner;
        }
    }

    /*Check columns*/
    for(int i = 0; i < 3; i++){
        if(board[0][i] == board[1][i] && board[0][i] == board[2][i]){
            winner = board[0][i];
            return winner;
        }
    }

    /*check diagonals*/
    if(board[0][0] == board[1][1] && board[0][0] == board[2][2]){
        winner = board[0][0];
        return winner;
    }

    if(board[0][2] == board[1][1] && board[0][2] == board[2][0]){
        winner = board[0][2];
        return winner;
    }
    
    return ' ';
}

void computerMove(){
   
    srand(time(0));
    int x, y;

    if(checkFreeSpaces() != 0){
        do
        {
            x = rand() % 3;
            y = rand() % 3;
        } while (board[x][y] != 0);
        
        board[x][y] = COMPUTER;
    } else{
        printWinner(' ');
    }
}

void printWinner(char winner){
    if(winner == PLAYER){
        printf("You win!");
    } else if (winner == COMPUTER)
    {
        printf("You lose!");
    } else{
        printf("It's a draw.");
    }
    
}

int main(){

    char winner = ' ';

    reset_board();

    while(winner == ' ' && checkFreeSpaces() != 0 ){
        print_board();

        playerMove();
        winner = checkWinner();
        if(winner != ' ' || checkFreeSpaces() == 0){
            break;
        }
        
        computerMove();
        winner = checkWinner();
        if(winner != ' ' || checkFreeSpaces() == 0){
            break;
        }
    }

    print_board();
    printWinner(winner);
    



    return 0;
}

