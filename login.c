#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
  char uName[25], pass[25];
  int adminOrUser, hangW, hangL, ticW, ticL, quizW, quizL;
} User;



void printInfo(int numUsers, User players[], char username[]) {
  printf("\t\t\tHi %s!\n\n", username);
  printf("#%12s | %7s %s  %7s %s  %7s %s\n", "user", "hangW", "hangL", "ticW", "ticL", "quizW", "quizL");
  for (int i=0; i<numUsers; i++) {
    for (int x=0; x<70; x++) {
      printf("-"); 
    }
    printf("\n%d) %10s | %3d %8d %7d %5d %7d %6d\n", i+1, players[i].uName, players[i].hangW, players[i].hangL, players[i].ticW, players[i].ticL, players[i].quizW, players[i].quizL);
  }
  printf("\n\n");
}
  
void gameStatsDisplay(int numUsers, User players[], int gameStats)  {
        if (gameStats == 1) { //HANGMAN
          printf("%12s | %7s %s\n", "user", "hangW", "hangL");
            
            for (int x=0; x<30; x++) {
              printf("-"); 
            }
          
            for (int i=0; i<numUsers; i++) {
              printf("\n%12s | %7d %3d\n", players[i].uName, players[i].hangW, players[i].hangL);
          }
        }
        else if (gameStats == 2) { //TIC TAC TOE
          printf("%12s | %7s %s\n", "user", "ticW", "ticL");
            
            for (int x=0; x<30; x++) {
              printf("-"); 
            }

            for (int i=0; i<numUsers;i++) {
              printf("\n%12s | %7d %3d\n", players[i].uName, players[i].ticW, players[i].ticL);
            }
        }
        else { //QUIZ
          printf("%12s | %7s %s\n", "user", "quizW", "quizL");
            
            for (int x=0; x<30; x++) {
              printf("-"); 
            }
              for (int i=0; i<numUsers; i++) {
                printf("\n%12s | %7d %3d\n", players[i].uName, players[i].quizW, players[i].quizL); 
              }
        }
}

void userOnlyStat(User players[], int userStat) {
    printf("#%12s | %7s %s  %7s %s  %7s %s\n", "user", "hangW", "hangL", "ticW", "ticL", "quizW", "quizL");
      for (int x=0; x<70; x++) {
        printf("-"); 
      }
    printf("\n%d) %10s | %3d %8d %7d %5d %7d %6d\n", userStat, players[userStat-1].uName, players[userStat-1].hangW, players[userStat-1].hangL, players[userStat-1].ticW, players[userStat-1].ticL, players[userStat-1].quizW, players[userStat-1].quizL);
 
}
    
  
int invalidUser(User players[], int numUsers) {
  int error=0;
  for (int i=0; i<numUsers; i++) {
    if (strcmp(players[numUsers].uName, players[i].uName)==0) {
      error = 1;
    }
  }
  
  return error;
}

int main() {
  srand(time(NULL));  

  FILE *fp;
  char fileName[25] = "users.txt", userName[50], password[50];
  User players[100];
  int userIndx=-1, passIndx = -1, i=0, numUsers=0, adminChoice;
  int hangmanWins=0, hangmanLosses=0, ticWins=0, ticLosses=0, quizWins=0, quizLosses=0;
  int userNum, adminUserChoice, statsChoice, gameStats, userStat, proceedOrQuit;

  fp = fopen("users.txt", "r");

while(!(feof(fp))) {
      fscanf(fp, "%s %s %d %d %d %d %d %d %d", players[i].uName, players[i].pass, &players[i].adminOrUser, &players[i].hangW, &players[i].hangL, &players[i].ticW, &players[i].ticL, &players[i].quizW, &players[i].quizL);
      numUsers++;
      i++;
}
  numUsers--;
  
  //read in all data into structure
i=0; 

  while(userIndx==-1) {
    printf("Enter username >> ");
    scanf("%s", userName);
      for (int x=0; x<numUsers;x++) {
        if (strcmp(players[x].uName, userName) == 0) {
          userIndx = x;
          system("clear");
          break;
        }
      }
      
    if (userIndx==-1) {
        system("clear");
        printf("\nSorry, that is a invalid username.\n");
      } 

  } //username and failsafe
  
int x=0;

do {
    printf("Enter password >> ");
    scanf("%s", password);
    if (strcmp(players[userIndx].pass,password)==0) {
        x=0;
        system("clear");
        break;
    }
    else {
      system("clear");
      printf("\nSorry, that is an invalid password.\n");
      x++;
    } 
} while(x!=0); //password

    if (players[userIndx].adminOrUser==1) {

  do {
    system("clear");
    printInfo(numUsers, players, userName);
      //display structure
      do {
        printf("Would you like to\n1: delete users\n2: add users\n3: see stats?\n=> ");
        scanf("%d", &adminChoice);
        system("clear");
        if (adminChoice!=1 && adminChoice!=2 && adminChoice!=3) {
          printInfo(numUsers, players, userName);
          printf("Sorry, that was an invalid choice.\n");
        }
  } while(adminChoice!=1 && adminChoice!=2 && adminChoice!=3);
    
    printInfo(numUsers, players, userName);
    //delete users
    if (adminChoice==1) {
      fclose(fp);
      fp = fopen("users.txt", "w+");
      
      do {
        printf("Which user would you like to delete? ");
        scanf("%d", &userNum);
      } while(userNum == 0 || userNum>numUsers);
      userIndx = userNum-1;
      
      for (x=userIndx;x<numUsers-1;x++) {
            strcpy(players[x].uName, players[x+1].uName);
            strcpy(players[x].pass, players[x+1].pass);
            players[x].adminOrUser = players[x+1].adminOrUser;
            players[x].hangW = players[x+1].hangW;
            players[x].hangL = players[x+1].hangW; 
            players[x].ticW = players[x+1].ticW;
            players[x].ticL = players[x+1].ticL;
            players[x].quizW = players[x+1].quizW;
            players[x].quizL = players[x+1].quizL;
      } //move chosen down a spot
      numUsers--; 
  
      for (int i=0; i<numUsers; i++) {
  
        fprintf(fp, "%s %s %d %d %d %d %d %d %d\n", players[i].uName, players[i].pass, players[i].adminOrUser, players[i].hangW, players[i].hangL, players[i].ticW, players[i].ticL, players[i].quizW, players[i].quizL);
      } //save updated into file
      system("clear");
      printInfo(numUsers, players, userName);
    }
    //add users
    else if (adminChoice == 2) {

      do {
        printf("Would you like to add\n1: Admin\n2: User\n=>");
        scanf("%d", &adminUserChoice);
        system("clear");
        if (adminUserChoice!=2 && adminUserChoice!=1) {
          printf("\nSorry, that is a invalid choice.\n");
        } 
      } while (adminUserChoice!=2 && adminUserChoice!=1);

    do {
      printf("\nUser %d) Username: ", numUsers+1);
      scanf("%s", players[numUsers].uName); 
      system("clear");
      if (invalidUser(players, numUsers)) {
        printf("Sorry that username is already taken.");
      }
    } while(invalidUser(players, numUsers));
  
      printf("\n%s's Password: ", players[numUsers].uName);
      scanf("%s", players[numUsers].pass);
      
      //admin addition 
        if (adminUserChoice==1){
          players[numUsers].adminOrUser = 1;
        } 
      //user addition
        else {
          players[numUsers].adminOrUser = 0;
        } 
      numUsers++;
      
      fclose(fp);
      fp = fopen("users.txt", "w+");
      
        for (int i=0; i<numUsers; i++) { //save updated
      
          fprintf(fp, "%s %s %d %d %d %d %d %d %d\n", players[i].uName, players[i].pass, players[i].adminOrUser, players[i].hangW, players[i].hangL, players[i].ticW, players[i].ticL, players[i].quizW, players[i].quizL);
          }
      
    }
    
  //view stats
    else {
      system("clear");
      do {
        printf("\nWould you like to see\n1: All stats\n2: Game Stats\n3: User Stats\n=>");
        scanf("%d", &statsChoice);
        system("clear");
        if (statsChoice!=1 && statsChoice!=2 && statsChoice!=3) {
          printf("\nSorry, that is invalid.\n");        }
      } while (statsChoice!=1 && statsChoice!=2 && statsChoice!=3);
        //all stats
        if (statsChoice == 1) {
          printInfo(numUsers, players, userName);
        }
        //game stats
        else if (statsChoice == 2) {
          do {
            printf("Stats for\n1: Hangman\n2: Tic Tac Toe\n3: Math Quiz\n=>");
            scanf("%d", &gameStats);
            system("clear");
            if (gameStats!=1 && gameStats!=2 && gameStats!=3) {
              printf("Sorry, that was invalid.");
            }
          } while(gameStats!=1 && gameStats!=2 && gameStats!=3);
          gameStatsDisplay(numUsers, players, gameStats);
        }   
        //user stats
        else {
          do {
            printf("User #: ");
            scanf("%d", &userStat);
          } while (userStat == 0 || userStat>numUsers); 
          userOnlyStat(players, userStat);
        } //print file line at index of user#
    }
      do {
        printf("\nWould you like to\n1: Proceed\n2: Quit\n=>");
        scanf("%d", &proceedOrQuit);
      } while(proceedOrQuit!=2 && proceedOrQuit!=1);

      
  } while(proceedOrQuit==1);
   //fclose(fp);
  }

  //reg user playing game
  else {
    
    //write statistics in
    fclose(fp);
    fp = fopen("users.txt", "w+");

    for (int i=0; i<numUsers; i++) { //save updated
          fprintf(fp, "%s %s %d %d %d %d %d %d %d\n", players[i].uName, players[i].pass, players[i].adminOrUser, players[i].hangW, players[i].hangL, players[i].ticW, players[i].ticL, players[i].quizW, players[i].quizL);
    }
  }

    return 0;
}

