#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define BOARD_HEIGHT 9
#define BOARD_WIDTH 17

// GAME PARAMETERS
int board[BOARD_HEIGHT][BOARD_WIDTH]; // store board as 2d array
int player_num = 1;                   // player number
int spaceOpen[9];                     // Array to check if spaces are occupied
bool isWinner = false;                // True if there is a winner, otherwise false

// Initialize the board by drawing the grid and leaving all space empty
void initDisplay()
{
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

// Switch the player
void switchPlayer(){
  if (player_num == 1){
    player_num = 2;
  }
  else{
    player_num = 1;
  }
}

/* Mark the board with an X or O in the coordinate passed
 * Input: char coord: A char from 1-9 representing a square on the board
 *        int player_num: An int holding value 1 or 2 representing the
 *                        the corresponding player
 * Output: None, the board is updated to contain the players move
 */
void markBoard(char coord, int player_num)
{
  int spaceIndex = coord - '0' - 1;
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

// Check if their is the game board is in a winning state
bool checkWin(){
  // Return call checks all possible winning states, and returns true if one exists
  return ((board[1][2] == player_num && board[1][8] == player_num && board[1][14] == player_num) ||
          (board[4][2] == player_num && board[4][8] == player_num && board[4][14] == player_num) ||
          (board[7][2] == player_num && board[7][8] == player_num && board[7][14] == player_num) ||
          (board[1][2] == player_num && board[4][2] == player_num && board[7][2] == player_num) ||
          (board[1][8] == player_num && board[4][8] == player_num && board[7][8] == player_num) ||
          (board[1][14] == player_num && board[4][14] == player_num && board[7][14] == player_num) ||
          (board[1][2] == player_num && board[4][8] == player_num && board[7][14] == player_num) ||
          (board[1][14] == player_num && board[4][8] == player_num && board[7][2] == player_num));
}

// Prints out the current state of the game board to the terminal
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
  while (true){
    int turnCount = 0;                                          // Tracks how many turns have taken place
    memset(board, 0, BOARD_HEIGHT * BOARD_WIDTH * sizeof(int)); // set board to all 0 values
    memset(spaceOpen, 0, 9 * sizeof(int));                      // set all spaces to open ('0')
    initDisplay();                                              // initalize display of board
    printf("Welcome to tic tac toe!\n");
    while (true){
      drawBoard(); // Draw the game board
      printf("Player %d, it's your turn! \nWhere do you want to play?", player_num);
      char input;
      int ch;
      do{
        scanf(" %c", &input); // read in character from user
        while ((ch = getchar()) != '\n' && ch != EOF)
          ; // Clear out excess input from buffer
        if (input < 49 || input > 57){ // check for number 1-9
          printf("Please enter a number 1-9:");
        }
        else if (spaceOpen[input - '0' - 1] > 0){ // Check if space has already been played in
          printf("Someone has already played here! Please enter an open tile:");
        }
      } while ((input < 49 || input > 57) || spaceOpen[input - '0' - 1] > 0);
      markBoard(input, player_num); // Mark an X or O on the board
      turnCount++;                  // increment turn count
      isWinner = checkWin();        // Check if winning state is on board
      if (isWinner){ // Is there a winning state on board?
        break;
      }
      if (turnCount == 9){ // Is the board full?
        break;
      }
      switchPlayer(); // Switch to other player
      system("cls");  // Clear terminal
    }
    system("cls"); // Clear terminal
    drawBoard();   // Redraw board
    if (isWinner){
      printf("Player %d wins! Do you want to play again?(y or n):", player_num);
    }
    else{
      printf("It's a cat's game! Do you want to play again?(y or n):");
    }
    char playAgain;
    int ch;
    do{
      scanf(" %c", &playAgain); // read in character from user
      while ((ch = getchar()) != '\n' && ch != EOF); // Clear excess chars from buffer
    } while (playAgain != 'y' && playAgain != 'n');
    if (playAgain == 'n'){
      break;
    }
    system("cls");
  }
}