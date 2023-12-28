#include <stdio.h>
#include <string.h>
#define BOARD_HEIGHT 9
#define BOARD_WIDTH 17
int board [BOARD_HEIGHT][BOARD_WIDTH];
int player_num = 1;
int spaceOpen[9];
/*
TODO: Win Conditions
*/
void initDisplay(){
    for (int row = 0; row < BOARD_HEIGHT; row++){
        for (int col = 0; col < BOARD_WIDTH; col++){
            if (col == 5 || col == 11){
                board[row][col] = -1;
            }
            else if (row == 2 || row == 5){
                board[row][col] = -2;
            }
        }
    }
}

void switchPlayer(){
    if (player_num == 1) {player_num = 2;}
    else {player_num = 1;}
}
void markBoard(char coord, int player_num){
    int spaceIndex = coord - '0'-1;
    switch (coord)
    {
    case '1':
        board[1][2] = player_num;
        spaceOpen[spaceIndex] = player_num;
        break;
    case '2':
        board[1][8] = player_num;
        spaceOpen[spaceIndex] = player_num;
        break;
    case '3':
        board[1][14] = player_num;
        spaceOpen[spaceIndex] = player_num;
        break;
    case '4':
        board[4][2] = player_num;
        spaceOpen[spaceIndex] = player_num;
        break;
    case '5':
        board[4][8] = player_num;
        spaceOpen[spaceIndex] = player_num;
        break;
    case '6':
        board[4][14] = player_num;
        spaceOpen[spaceIndex] = player_num;
        break;
    case '7':
        board[7][2] = player_num;
        spaceOpen[spaceIndex] = player_num;
        break;
    case '8':
        board[7][8] = player_num;
        spaceOpen[spaceIndex] = player_num;
        break;
    case '9':
        board[7][14] = player_num;
        spaceOpen[spaceIndex] = player_num;
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
                printf("X");
                break;
            case 2:
                printf("O");
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
    memset(board, 0, BOARD_HEIGHT*BOARD_WIDTH*sizeof(int)); // set board to all 0 values
    memset(spaceOpen, 0, 9*sizeof(int));
    initDisplay(); // initalize display of board
    printf("Welcome to tic tac toe!\n");
    while (1){
        drawBoard(); // Draw the game board
        printf("Player %d, it's your turn! \nWhere do you want to play?", player_num);
        char input;
        int ch;
        do{
            scanf(" %c",&input); // read in character from user
            while ((ch = getchar()) != '\n' && ch != EOF);
            if (input < 49 || input > 57){
                printf("Please enter a number 1-9:");
            }
            else if (spaceOpen[input-'0'-1] > 0){
                printf("Someone has already played here! Please enter an open tile:");
            }
        } while ((input < 49 || input > 57) || spaceOpen[input-'0'-1] > 0);
        markBoard(input, player_num); // Mark an X or O on the board 
        switchPlayer(); // Switch to other player
    }
}