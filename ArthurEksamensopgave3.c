#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define NUMBER_OF_MATCHES 182
#define NUMBER_OF_TEAMS 14
#define LENGTH_OF_TEAMNAME 4
#define TIME_DATE_LENGTH 6
#define LENGTH_OF_WEEKDAY 4

/*Structs*/
struct match{
  char weekday[LENGTH_OF_WEEKDAY];
  char date[TIME_DATE_LENGTH];
  char time[TIME_DATE_LENGTH];
  char team1[LENGTH_OF_TEAMNAME];
  char team2[LENGTH_OF_TEAMNAME];
  int team1Goals;
  int team2Goals;
  int crowd;
};

struct team{
  char *teamName;
  int points;
  int goalsScored;
  int goalsAgainst;
};

typedef struct match match;
typedef struct team team;

/*Prototypes*/
void readMatches(match matches[]);

void calculateStandings(match matches[], team teams[]);
void insertGame(team teams[], char *inputString, int points, int goalsScored, int goalsAgainst);
int findIndex(team teams[], char *input);
int hash(const char *inputString);
char* allocateTeamName(int length);
void printStandings(team teams[]);
int compareTeams(const void *p1, const void *p2);

int main(void){
  match matches[NUMBER_OF_MATCHES];
  team teams[NUMBER_OF_TEAMS];

  readMatches(matches);
  calculateStandings(matches, teams);
  printStandings(teams);

  return EXIT_SUCCESS;
}

void readMatches(match matches[]){
  int i;
  FILE *fp;
  
  fp = fopen("kampe-2019-2020.txt","r");
  
  if (fp == NULL){
    printf("Error opening file\n");
    exit(EXIT_FAILURE);
  } else {
    printf("Success\n");
  }
  
  for (i = 0; i < NUMBER_OF_MATCHES; i++){
    fscanf(fp," %s %s %s %s - %s %d - %d %d\n", matches[i].weekday, matches[i].date,
           matches[i].time, matches[i].team1, matches[i].team2, &matches[i].team1Goals,
           &matches[i].team2Goals, &matches[i].crowd);
  }
  fclose(fp);
  fp = NULL;
}


void calculateStandings(match matches[], team teams[]){
  int team1Points, team2Points, i;
  for (i = 0; i < NUMBER_OF_MATCHES; i++){
    if (matches[i].team1Goals < matches[i].team2Goals){
      team1Points = 0;
      team2Points = 3;
    } else if (matches[i].team1Goals == matches[i].team2Goals){
      team1Points = 1;
      team2Points = 1;
    } else {
      team1Points = 3;
      team2Points = 0;
    }
    insertGame(teams, matches[i].team1, team1Points, matches[i].team1Goals, matches[i].team2Goals);
    insertGame(teams, matches[i].team2, team2Points, matches[i].team2Goals, matches[i].team1Goals);
  }
  qsort(teams, NUMBER_OF_TEAMS, sizeof(team), &compareTeams);
}

void insertGame(team teams[], char *inputString, int points, int goalsScored, int goalsAgainst){
  int index;
  index = findIndex(teams, inputString);
  
  /*Add points and goals to existing team*/
  if (index != -1){
    teams[index].points += points;
    teams[index].goalsScored += goalsScored;
    teams[index].goalsAgainst += goalsAgainst;
  } else {
    index = hash(inputString);
    
    while (teams[index].teamName != NULL && strcmp(teams[index].teamName, inputString) != 0) {
      index = (index + 1) % NUMBER_OF_TEAMS;
    }
    
    teams[index].teamName = allocateTeamName(strlen(inputString));
    strcpy(teams[index].teamName, inputString);
    
    teams[index].points = points;
    teams[index].goalsScored = goalsScored;
    teams[index].goalsAgainst = goalsAgainst;
  }
}

int findIndex(team teams[], char *input){
  int index = hash(input);
  while (teams[index].teamName != NULL && strcmp(teams[index].teamName, input) != 0) {
    index = (index + 1) % NUMBER_OF_TEAMS;
  }
  if (teams[index].teamName == NULL){
    return -1;
  } else if (strcmp(teams[index].teamName, input) == 0){
    return index;
  } else {
    return -1;
  }
}

char* allocateTeamName(int length){
  char* teamName = (char *) malloc(length * sizeof(char));
  return teamName;
}

/*Hash function based on Kurt Nørmark's hash function in program "a3.c" from Lesson 9*/
int hash(const char *inputString){
  int index, length;
  length = strlen(inputString);
  index = inputString[0] + inputString[length/2] + inputString[length - 1];
  return index % NUMBER_OF_TEAMS;
}

void printStandings(team teams[]){
  int i;
  printf("Holdnavn  Point  Maal-af-hold  Maal-mod-hold\n");
  for (i = 0; i < NUMBER_OF_TEAMS; i++){
    printf("%-8s  %5d  %12d  %13d\n", teams[i].teamName, teams[i].points, teams[i].goalsScored, teams[i].goalsAgainst);
  }
}

int compareTeams(const void *p1, const void *p2){
  team *tp1 = (team *) p1, *tp2 = (team *) p2;
  int result;
  if (tp1->points < tp2->points){
    result = 1;
  } else if (tp1->points > tp2->points){
    result = -1;
  } else {
    if ((tp1->goalsScored - tp1->goalsAgainst) < (tp2->goalsScored - tp2->goalsAgainst)){
      result = 1;
    } else if ((tp1->goalsScored - tp1->goalsAgainst) > (tp2->goalsScored - tp2->goalsAgainst)) {
      result = -1;
    } else {
      result = 0;
    }
  }
  return result;
}
