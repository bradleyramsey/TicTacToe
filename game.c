#include <stdio.h>
#include <string.h>
#define BOARD_HEIGHT 10
#define BOARD_WIDTH 15
int board [BOARD_HEIGHT][BOARD_WIDTH];
int player_num = 1;
void initDisplay(){
    for (int row = 0; row < BOARD_HEIGHT; row++){
        for (int col = 0; col < BOARD_WIDTH; col++){
            if (col == 5 || col == 10){
                board[row][col] = -1;
            }
            else if (row == 3 || row == 6){
                board[row][col] = -2;
            }
        }
    }
}

void markBoard(char coord, int player_num){
    
}

void drawBoard(){
    for (int row = 0; row < BOARD_HEIGHT; row++){
        for (int col = 0; col < BOARD_WIDTH; col++){
            switch (board[row][col])
            {
            case -1:
                printf("|");
                break;
            case -2:
                printf("_");
                break;
            case 1:
                printf("/");
                break;
            case 2:
                printf("\\");
                break;
            default:
                printf(" ");
                break;
            }
        }
        printf("\n");
    }
}
int main(void){
    memset(board, 0, BOARD_HEIGHT*BOARD_WIDTH*sizeof(int));
    initDisplay();
    printf("Welcome to tic tac toe!");
    drawBoard();
    while (1){
        printf("Player %d, it's your turn! \n Where do you want to play?");
        char input;
        do{
            scanf(" %c",&input);
            getchar();
            if (input < 49 || input > 57){
                printf("Please enter a number 1-9:");
            }
        } while (input < 49 || input > 57);
        markBoard(input, player_num);
    }
}