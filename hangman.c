#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void welcome() {
  puts("🅦🅔🅛🅒🅞🅜🅔\n🅣🅞"
"\n▒█░▒█ █▀▀█ █▀▀▄ █▀▀▀ █▀▄▀█ █▀▀█ █▀▀▄\n"
"▒█▀▀█ █▄▄█ █░░█ █░▀█ █░▀░█ █▄▄█ █░░█\n"
"▒█░▒█ ▀░░▀ ▀░░▀ ▀▀▀▀ ▀░░░▀ ▀░░▀ ▀░░▀\n"); 

  printf("\n🄿🅁🄴🅂🅂 🄴🄽🅃🄴🅁 🄸🄵 🅈🄾🅄 🄳🄰🅁🄴\n");
  getchar();
}
void updateDashes(int a, int correctIndx, char str[50], char str2[50]) {
  printf("\n");
  if (a == 1) {
    for (int x = 0; x<strlen(str2); x++) {
      if( x == correctIndx) {
           str2[correctIndx] = str[correctIndx];
        }
    }
  }
    for (int x = 0; x<strlen(str2); x++) {
      printf("%-4c", str2[x]);
    }  
}

 int guessFrequency(char str[5]) {
  
    int guessRepeat=0; 
    
    for (int i=0; i<strlen(str)-1; i++) {
      for (int j=i+1; j<strlen(str); j++) {
        if (str[i] == str[j]) {
          guessRepeat++;
        }
      }
    }
  
    if (!(guessRepeat)) {
        return 0;
    }
    else {
        return 1;
    }
}

void updateWordDisplay(int correctIndx[], char *str) {
    printf("\n");
      for (int x=0; x<strlen(str); x++) {

        for (int j=0; j<sizeof(correctIndx); j++) {
          if (x == correctIndx[j]) {
            printf(" %c ", correctIndx);
          }
          else {
            printf("_");
          }
        }
      }
    printf("\n");
}

void gallows(int mistakes, char man[]) {
  printf("\nLives left: %d", 6-mistakes);

  printf("\tMistakes: %d\n", mistakes);

        if (mistakes == 1) man[0] = 'O'; 
        else if (mistakes == 2) man[1] = '/';
        else if (mistakes == 3) man[2] = '|';
        else if (mistakes == 4) man[3] = '\\';
        else if (mistakes == 5) man[4] = '/';
        else if (mistakes == 6) man[5] = '\\';
  
    printf("\t _________\n"
           "\t|         |\n"
           "\t|         %c\n"
           "\t|        %c%c%c\n"
           "\t|        %c %c\n"
           "\t|             \n"
           "\t|             \n", man[0], man[1], man[2], man[3], man[4], man[5]);
    printf("==========");
 
}

int main(void) {

  FILE *fp;
  char fileName[25] = "hangmanList.txt";
  fp = fopen(fileName, "r"); 
  srand((unsigned) time(NULL)); 

  int guessCount=0, correctIndx, mistakes=0, tmpNumCorrect=0, numCorrect=0;
  char word[100][50], guessWord[50], guessWordDisplay[50], man[6] = {0};
  int hangmanWins=0, hangmanLosses=0, wordIndx=0;  
  
  welcome();
  system("clear");

  //read in all words 
  while (!(feof(fp))) {
    fscanf(fp,"%s", word[wordIndx]);
    wordIndx++;
  }
  
  //generate random word
  strcpy(guessWord,word[rand () % wordIndx]);
  char guess[strlen(guessWord)+3];

  //load current guess into array
  for (int i=0; i<strlen(guessWord); i++) {
    guessWordDisplay[i] = '_';
    printf("%-4c", guessWordDisplay[i]);
  }

  //user inputs guess letter 

  do {

    do {
    printf("\n\nGuess ==> ");
    scanf(" %c", &guess[guessCount]);
    guess[guessCount] = tolower(guess[guessCount]);

      if (guessFrequency(guess)!=0) {
          printf("\nYou already entered '%c'", guess[guessCount]);
          system("clear");
          updateDashes(1, correctIndx, guessWord, guessWordDisplay);
          gallows(mistakes, man);
      } //doesn't remove points for same guesses
      
    } while (guessFrequency(guess)!=0);
    
    for (int x=0; x<strlen(guessWord); x++) {
      guessWord[x] = tolower(guessWord[x]);
      
      if (guess[guessCount] == guessWord[x]) {
        correctIndx = x;
        tmpNumCorrect++;
        numCorrect++;

        updateDashes(1, correctIndx, guessWord, guessWordDisplay);
       //print all occurances of letters in one shot
      } 
      
    }
    
    //track mistakes 
      if (tmpNumCorrect == 0) {
        mistakes++;
        updateDashes(0, correctIndx, guessWord, guessWordDisplay);
      }
      
    system("clear");
    guessCount++;
  
    gallows(mistakes, man);
    tmpNumCorrect = 0;

      if (numCorrect == strlen(guessWord)) {
        printf("\nGreat job. You won.");
        hangmanWins++;
        break;
      }
    
    else if (mistakes == 6) {
      hangmanLosses++;
      printf("\nYou lost. The word was %s", guessWord);
    }

  } while (mistakes < 6); //continue until word is guessed or mistakes=6

  
  return 0;
}






HERE


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void updateDashes(int a, int correctIndx, char str[50], char str2[50]) {
  printf("\n");
  if (a == 1) {
    for (int x = 0; x<strlen(str2); x++) {
      if( x == correctIndx) {
           str2[correctIndx] = str[correctIndx];
        }
    }
  }
    for (int x = 0; x<strlen(str2); x++) {
      printf("%-4c", str2[x]);
    }  
}

 int guessFrequency(char str[5]) {
  
    int guessRepeat=0; 
    
    for (int i=0; i<strlen(str)-1; i++) {
      for (int j=i+1; j<strlen(str); j++) {
        if (str[i] == str[j]) {
          guessRepeat++;
        }
      }
    }
  
    if (!(guessRepeat)) {
        return 0;
    }
    else {
        return 1;
    }
}

  void updateWordDisplay(int correctIndx[], char *str) {
    printf("\n");
      for (int x=0; x<strlen(str); x++) {

        for (int j=0; j<sizeof(correctIndx); j++) {
          if (x == correctIndx[j]) {
            printf(" %c ", correctIndx);
          }
          else {
            printf("_");
          }
        }
      }
    printf("\n");
}

          //make correct index an array
void gallows(int mistakes, char man[]) {
  printf("\nLives left: %d", 6-mistakes);

  printf("\tMistakes: %d\n", mistakes);

        if (mistakes == 1) man[0] = 'O'; 
        else if (mistakes == 2) man[1] = '/';
        else if (mistakes == 3) man[2] = '|';
        else if (mistakes == 4) man[3] = '\\';
        else if (mistakes == 5) man[4] = '/';
        else if (mistakes == 6) man[5] = '\\';
  
    printf("\t _________\n"
           "\t|         |\n"
           "\t|         %c\n"
           "\t|        %c%c%c\n"
           "\t|        %c %c\n"
           "\t|             \n"
           "\t|             \n", man[0], man[1], man[2], man[3], man[4], man[5]);
    printf("==========");
 
}

int main(void) {

  FILE *fp;
  char fileName[25] = "hangmanList.txt";
  fp = fopen(fileName, "r"); 
  srand((unsigned) time(NULL)); 

    int contHangman, numOfWords=0;
    char c, word[100][50], guessWord[50], guessWordDisplay[50];       
    int wordIndx=0;
    char man[6] = {0};
    int hangmanWins=0, hangmanLosses=0;  
  //WELCOME

      puts("🅦🅔🅛🅒🅞🅜🅔\n🅣🅞"
"\n▒█░▒█ █▀▀█ █▀▀▄ █▀▀▀ █▀▄▀█ █▀▀█ █▀▀▄\n"
"▒█▀▀█ █▄▄█ █░░█ █░▀█ █░▀░█ █▄▄█ █░░█\n"
"▒█░▒█ ▀░░▀ ▀░░▀ ▀▀▀▀ ▀░░░▀ ▀░░▀ ▀░░▀\n"); 

  printf("\n🄿🅁🄴🅂🅂 🄴🄽🅃🄴🅁 🄸🄵 🅈🄾🅄 🄳🄰🅁🄴\n");

  
  getchar();

  //read in all words 
  while (!(feof(fp))) {
    fscanf(fp,"%s", word[wordIndx]);
    wordIndx++;
  }
  numOfWords = wordIndx-1; //remove last blank line
  
  //generate random word
  strcpy(guessWord,word[rand () % wordIndx]);


  //load dashes into array initially 
  for (int i=0; i<strlen(guessWord); i++) {
    //printf("%-4s", "_");
    guessWordDisplay[i] = '_';
    printf("%-4c", guessWordDisplay[i]);
  }
  
  int guessCount=0, score=0;
  char guess[strlen(guessWord)+3];
  int guessIndx=0, correctIndx, mistakes=0;
  char lastGuess;
  int tmpNumCorrect=0;
  int numCorrect=0;
  //user inputs guess letter 

  do {

    do {
    printf("\n\nGuess ==> ");
    scanf(" %c", &guess[guessCount]);
    guess[guessCount] = tolower(guess[guessCount]);
  //how to ensure that user enters
      if (guessFrequency(guess)!=0) {
        printf("\nYou already entered '%c'", guess[guessCount]);
        system("clear");
        updateDashes(1, correctIndx, guessWord, guessWordDisplay);
        gallows(mistakes, man);
        
      }
    } while (guessFrequency(guess)!=0);
    
    for (int x=0; x<strlen(guessWord); x++) {
      guessWord[x] = tolower(guessWord[x]);
      if (guess[guessCount] == guessWord[x]) {
        correctIndx = x;
        tmpNumCorrect++;
        numCorrect++;

        updateDashes(1, correctIndx, guessWord, guessWordDisplay);
 //print all occurances of letters in one shot
    }
      
  }
    
    if (tmpNumCorrect == 0) {
      mistakes++;
      score-=5;
      updateDashes(0, correctIndx, guessWord, guessWordDisplay);
    }
    
    system("clear");
    guessCount++;
  
    gallows(mistakes, man);
    tmpNumCorrect = 0;

  if (numCorrect == strlen(guessWord)) {
    printf("\nGreat job. You won.");
    hangmanWins++;
    break;
  }
    
  else if (mistakes == 6) {
    hangmanLosses++;
    printf("\nYou lost. The word was %s", guessWord);
  }

  } while (mistakes < 6);

  
  return 0;
}

