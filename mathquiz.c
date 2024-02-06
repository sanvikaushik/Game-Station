#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void welcome() {
  printf("ⓦⓔⓛⓒⓞⓜⓔ ⓣⓞ ⓣⓗⓔ\n\n");
    printf("█▀▄▀█ █▀▀█ ▀▀█▀▀ █░░█ 　 █▀▀█ █░░█ ░▀░ ▀▀█\n");
    printf("█░▀░█ █▄▄█ ░░█░░ █▀▀█ 　 █░░█ █░░█ ▀█▀ ▄▀░\n");
    printf("▀░░░▀ ▀░░▀ ░░▀░░ ▀░░▀ 　 ▀▀▀█ ░▀▀▀ ▀▀▀ ▀▀▀\n");
}

void menu(int *operation) {
     printf("\n*** Choose an operation ***\n\t1: +\n\t2: -\n\t3: x\n\t4: /\n");
  
  do {
      printf("#");
      scanf("%d", operation);
      system("clear");
    
      if (*operation < 1 || *operation > 4) {
        printf("Sorry, that was invalid.");
      }
    
  } while (*operation < 1 || *operation > 4); 
  
}

void level(int *gameMode) { 
  
  do {
        printf("\n1 - Easy\n2 - Hard\n>> ");
        scanf("%d", gameMode);
        system("clear");
          if (*gameMode!=1 && *gameMode!=2) {
            welcome();
            printf("\nSorry, that is invalid.");
          }
    } while(*gameMode!=1 && *gameMode!=2); 
  
}

void printLevel(int gameMode) {
  
  if (gameMode==1) {
    printf("ⓔⓐⓢⓨ ⓜⓞⓓⓔ\n");
  }
    
  else {
    printf("ⓑⓔⓐⓢⓣ ⓜⓞⓓⓔ\n");
  }
  
}

void addOrSubtract(int *numWinsQuiz, int *numLossesQuiz, int operationChoice, int gameMode) {

    int sumOrDiff = rand() % 100;
    int adder1 = rand() % 300;
    int adder2 = rand() % 260; 
    int ans; 
  
    //addition
    if (operationChoice == 1) { 
        //EASY mode
        if (gameMode==1) { 
        printf("%d + %d = x\nx is ", adder1, adder2); 
        scanf("%d", &ans);
          if (ans == adder1+adder2) {
            printf("\nCorrect");
            (*numWinsQuiz)++;
          }
          else {
            printf("\nIncorrect. Answer was %d.", adder1+adder2);
            (*numLossesQuiz)++;
          }
        }
        else {
          //HARD MODE
          printf("%d + x = %d\nx is ", adder1, sumOrDiff);
          scanf("%d", &ans);
              if (ans == sumOrDiff-adder1) {
                printf("\nCorrect");
                (*numWinsQuiz)++;
              }
              else {
                printf("\nIncorrect. Answer was %d.", sumOrDiff-adder1);
                (*numLossesQuiz)++;
              }
          }
    }
    //subtraction
    else {
      if (gameMode==1) {
        //EASY mode
        printf("%d - %d = x\nx = ", adder1, adder2);
        scanf("%d", &ans);
        if (ans == adder1-adder2) {
          printf("\nCorrect");
          (*numWinsQuiz)++;
        }
        else {
          printf("\nIncorrect. Answer was %d.", adder1-adder2);
          (*numLossesQuiz)++;
        }
      }
      else {
        //HARD mode
        printf("%d - x = %d\nx = ", adder1, sumOrDiff);
        scanf("%d", &ans);
        if (ans == adder1-sumOrDiff) {
          printf("\nCorrect");
          (*numWinsQuiz)++;
        }
        else {
          printf("\nIncorrect. Answer was %d.", adder1-sumOrDiff);
          (*numLossesQuiz)++;
        }
      }
  }
}

void multiplyOrDivide(int *numWinsQuiz, int *numLossesQuiz, int operationChoice, int gameMode) {
    int factor1 = rand() % 100;
    int factor2 = rand() % 300;
    int ans; 
      //MULTIPLICATION
      if (operationChoice == 3) {
        if (gameMode==1) {
          printf("%d * %d = x\nx = ", factor1, factor2);
          scanf("%d", &ans); 
            if (ans == factor1*factor2) {
              printf("\nCorrect!");
              (*numWinsQuiz)++; 
            }
            else {
              printf("\nIncorrect. Answer was %d.", factor1*factor2);
              (*numLossesQuiz)++;
            }
        }
        else {
          printf("%d * x = %d\nx = ", factor1, factor1*factor2);
          scanf("%d", &ans);
            if (ans == factor2) {
              printf("\nCorrect!");
              (*numWinsQuiz)++; 
            }
            else {
               printf("\nIncorrect. Answer was %d.", factor2);
              (*numLossesQuiz)++;
            }
        }
      }
      //DIVISION
      else {
        if (gameMode == 1) {
          printf("%d / %d = x\nx = ", factor1*factor2, factor1);
          scanf("%d", &ans);
            if (ans == factor2) {
              printf("\nCorrect!");
              (*numWinsQuiz)++; 
            }
            else {
              printf("\nIncorrect. Answer was %d.", factor2);
              (*numLossesQuiz)++;
            }
        }
        else {
          printf("x / %d = %d\nx = ", factor1, factor2);
          scanf("%d", &ans);
            if (ans == factor1*factor2) {
              printf("\nCorrect!");
              (*numWinsQuiz)++; 
            }
          else {
            printf("\nIncorrect. Answer was %d.", factor1*factor2);
              (*numLossesQuiz)++;
          }
        }
      }
}


void mathQuiz(int *operationChoice, int *gameMode, int *questionNum, int *numWinsQuiz, int *numLossesQuiz) {
    welcome(); 
  level(gameMode);
  
  do {
    menu(operationChoice); 
    (*questionNum)++; 
    printLevel(*gameMode);
    
    printf("Question %d/5\n", *questionNum); 
    
    if (*operationChoice == 1|| *operationChoice==2) {
      addOrSubtract(numWinsQuiz, numLossesQuiz, *operationChoice, *gameMode);
    }
      
    else {
      multiplyOrDivide(numWinsQuiz, numLossesQuiz, *operationChoice, *gameMode);
    }
    
  } while(*questionNum<5); //stop after 5 questions

  printf("\nFinal score: %d/5", *numWinsQuiz);
}

int main(void) {
  srand(time(NULL));  
  int operationChoice, questionNum=0, numWinsQuiz=0, numLossesQuiz=0, gameMode=0;

  mathQuiz(&operationChoice, &gameMode, &questionNum, &numWinsQuiz, &numLossesQuiz);

}


