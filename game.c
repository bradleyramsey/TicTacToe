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
    switch (coord)
    {
    case 1:
        board[1][2] = player_num;
        break;
    case 2:
        board[1][7] = player_num;
        break;
    case 3:
        board[1][12] = player_num;
        break;
    case 4:
        board[5][2] = player_num;
        break;
    case 5:
        board[5][7] = player_num;
        break;
    case 6:
        board[5][12] = player_num;
        break;
    case 7:
        board[9][2] = player_num;
        break;
    case 8:
        board[9][7] = player_num;
        break;
    case 9:
        board[9][12] = player_num;
        break;
    default:
        break;
    }
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