#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void welcome() {
  printf("\nɯҽɬ𝓬σ𝓶ҽ 𝜏σ\n");
  printf("〸讠⼕ 〸闩⼕ 〸ㄖ🝗\n\n");
}
void rulesBoard() {
    welcome(); 
  
    printf("\t\t\t 1 1 █ 1 2 █ 1 3 \n");
    printf("\t\t\t     █     █    \n");

    printf("\t\t\t▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬\n");
    printf("\t\t\t 2 1 █ 2 2 █ 2 3 \n");
    printf("\t\t\t     █     █    \n");

    printf("\t\t\t▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬\n");
    printf("\t\t\t 3 1 █ 3 2 █ 3 3 \n");
    printf("\t\t\t     █     █    \n\n");
}
void displayBoard(char board[][3]) {
      printf("\t\t\t  %c █ %c  █ %c  \n", board[0][0],
                             board[0][1], board[0][2]);
      printf("\t\t\t    █    █    \n");

    printf("\t\t\t▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬\n");
    printf("\t\t\t  %c █ %c  █ %c  \n", board[1][0],
                             board[1][1], board[1][2]);
        printf("\t\t\t    █    █    \n");

    printf("\t\t\t▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬\n");
    printf("\t\t\t  %c █ %c  █ %c  \n", board[2][0],
                             board[2][1], board[2][2]);
    printf("\t\t\t    █    █    \n\n");
  }


void playerXMove(int *rowChoose, int *columnChoose, char board[][3], int rowsX[], int columnsX[], int diagonalsX[], int *numMoves) {
    printf("You are X. Player 1's turn >>\n");
  
      do {
        printf("Enter row and column # # >>\n");
        scanf("%d %d", rowChoose, columnChoose);
        system("clear");
        
          if (board[*rowChoose-1][*columnChoose-1] == 'X' || board[*rowChoose-1][*columnChoose-1] == '0' || *rowChoose<1||*rowChoose>3||*columnChoose<1||*columnChoose>3) {
            displayBoard(board);
            printf("Sorry. That is an invalid spot.\n\n");
            printf("You are X. Player 1's turn >>\n");
          } //failsafe for user to input valid / not taken spot
        
      } while (board[*rowChoose-1][*columnChoose-1]== 'X' || board[*rowChoose-1][*columnChoose-1] == '0' || *rowChoose<1||*rowChoose>3||*columnChoose<1||*columnChoose>3); 
  
    //add x to chosen spot on board
    board[*rowChoose-1][*columnChoose-1] = 'X';
    system("clear");

    //increment row and column
    rowsX[*rowChoose-1]++; 
    columnsX[*columnChoose-1]++;

      //increment diagonal if applicable
      if (*rowChoose==*columnChoose || *rowChoose+2 == *columnChoose || *columnChoose+2 == *rowChoose) {
    
          //two potential diagonals for middle spot
          if (*rowChoose == 2 && *columnChoose ==2) {
              diagonalsX[0]++;
              diagonalsX[1]++;
          }
          else if (*rowChoose != *columnChoose) {
              diagonalsX[1]++;
          }
          else {
            diagonalsX[0]++;
          }
      }
        (*numMoves)++;
        displayBoard(board);
} 

void player0Move(int *rowChoose, int *columnChoose, char board[][3], int rows0[], int columns0[], int diagonals0[], int *numMoves) {

  //same as playerXMove except with 0 
  printf("You are 0. Player 2's turn >>\n");
  
    do {
      printf("Enter row and column # # >>\n");
      scanf("%d %d", rowChoose, columnChoose);
      system("clear");
      
        if (board[*rowChoose-1][*columnChoose-1]== 'X' || board[*rowChoose-1][*columnChoose-1] == '0' || *rowChoose<1||*rowChoose>3||*columnChoose<1||*columnChoose>3) {
          displayBoard(board);
          printf("Sorry, that is an invalid spot.\n\n");
          printf("You are 0. Player 2's turn >>\n");
        }
      
    } while (board[*rowChoose-1][*columnChoose-1]== 'X' || board[*rowChoose-1][*columnChoose-1] == '0' || *rowChoose<1||*rowChoose>3||*columnChoose<1||*columnChoose>3); 
  
      board[*rowChoose-1][*columnChoose-1] = '0';
      system("clear");
      rows0[*rowChoose-1]++; //increment row and column
      columns0[*columnChoose-1]++;
      
    //increment diagonal if applicable
        if (*rowChoose==*columnChoose || *rowChoose+2 == *columnChoose || *columnChoose+2 == *rowChoose) {
          if (*rowChoose == 2 && *columnChoose ==2) {
            diagonals0[1]++;
            diagonals0[0]++;
          }
          else if (*rowChoose != *columnChoose) {
            diagonals0[1]++;
          }
          else {
            diagonals0[0]++;
          }
      }
      displayBoard(board);
      (*numMoves)++;
}

void ticTacToe(char board[][3], int *rowChoose, int *columnChoose, int rowsX[], int columnsX[], int diagonalsX[], int rows0[], int columns0[], int diagonals0[], int *numMoves) {
  
  rulesBoard();
  
  printf("Press enter to continue");
  getchar();
  system("clear");
  
  displayBoard(board);

  do { //continue until 1 - player x wins 2 - player 0 wins 3 -  all board is filled up (tie)
    
    playerXMove(rowChoose, columnChoose, board, rowsX, columnsX, diagonalsX, numMoves);
  
      if (*numMoves == 9) {
              printf("\nNobody wins.");
              break; 
      }
      
      if (rowsX[0]==3||rowsX[1]==3||rowsX[2]==3||columnsX[0]==3||columnsX[1]==3||columnsX[2]==3||diagonalsX[0]==3||diagonalsX[1]==3) {
            printf("\nƤɬαყҽɾ ⵋ ɯιɳട");
            break;
      }
     player0Move(rowChoose, columnChoose, board, rows0, columns0, diagonals0, numMoves);
    
      if (rows0[0]==3 || rows0[1]==3 || rows0[2]==3 || columns0[0]==3||columns0[1]==3||columns0[2]==3||diagonals0[0]==3||diagonals0[1]==3) {
          printf("\nƤɬαყҽɾ 0 ɯιɳട");
      }
    
  } while (rows0[0]!=3&&rows0[1]!=3&&rows0[2]!=3&& columns0[0]!=3&&columns0[1]!=3&&columns0[2]!=3&&diagonals0[0]!=3&&diagonals0[1]!=3); 
  
}

int main(void) {
   char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
  int rowChoose, columnChoose, numMoves=0; 
  int rowsX[3] = {0}, columnsX[3] = {0}, diagonalsX[2] = {0};
  int rows0[3] = {0}, columns0[3] = {0}, diagonals0[2] = {0};
  int round=0; 
  
  ticTacToe(board, &rowChoose, &columnChoose, rowsX, columnsX, diagonalsX, rows0, columns0, diagonals0, &numMoves);
}

