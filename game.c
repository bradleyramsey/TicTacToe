#include <stdio.h>
#include <string.h>
#define BOARD_DIM 14

int board [BOARD_DIM][BOARD_DIM];
void drawX (int board [][BOARD_DIM]){

}

void drawBoard(int board [][BOARD_DIM]){
    for (int row = 0; row < BOARD_DIM; row++){
        for (int col = 0; col < BOARD_DIM; col++){
            switch (board[row][col])
            {
            case 1:
                printf("|");
                break;
            case 2:
                printf("_");
                break;
            case 3:
                printf("/");
                break;
            case 4:
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
    memset(board, 0, BOARD_DIM*BOARD_DIM*sizeof(int));

}