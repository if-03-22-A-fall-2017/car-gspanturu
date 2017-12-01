/*----------------------------------------------------------
*				HTBLA-Leonding / Klasse: 2AHIF
* ---------------------------------------------------------
* Exercise Number: 0
* Title:			car_race.cpp
* Author:			Panturu Gloria Sara
* Due Date:		November 30, 2017
* ----------------------------------------------------------
*/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "car.cpp"
#include <string.h>
#include <unistd.h>
#define clear() printf("\033[H\033[J")

#define END 10
#define MAX_CARS 6

struct RaceTrack
{
Car car;
char name[2];
int position;
};

static RaceTrack race_track[MAX_CARS];

void init_racetrack();
void print_cars();
void set_random_acc_rate();
bool is_race_finished();
void move_car_with_highest_speed();

int main(int argc, char * argv[])
{
  bool is_finished = false;
  init_racetrack();
  while (is_finished == false) {
    set_random_acc_rate();
    move_car_with_highest_speed();
    is_finished = is_race_finished();
  }
  return 0;
}

void init_racetrack()
{
  int count_multipla= 0;
  int count_jeep=0;
  for (int i = 0; i < MAX_CARS; i++) {
    race_track[i].car = rental_record[i].car;
    race_track[i].position = 0;
    switch (race_track[i].car->type) {
      case  AIXAM: strcpy(race_track[i].name, "a1");
      break;
      case  FIAT_MULTIPLA: if (count_multipla == 0) {
        strcpy(race_track[i].name, "f1");
        count_multipla++;
      }
        else if(count_multipla==1)
        { strcpy(race_track[i].name, "f2");
        count_multipla++;}
        else
        {strcpy(race_track[i].name, "f3");
        count_multipla++;}
        break;
        case JEEP: if (count_jeep == 0)
        {strcpy(race_track[i].name, "j1");
        count_jeep++;}
        else
        {strcpy(race_track[i].name, "j2");
        count_jeep++;}
        break;
      }
    }
    print_cars();
  }

void print_cars()
{
  clear();
  printf("*Car Race*\n" );
  printf("__________\n" );
  for (int i = 0; i < MAX_CARS; i++) {
      switch (race_track[i].position) {
        case 0:printf(""); break;
        case 1:printf(" "); break;
        case 2:printf("  "); break;
        case 3:printf("   "); break;
        case 4:printf("    "); break;
        case 5:printf("     "); break;
        case 6:printf("      "); break;
        case 7:printf("       "); break;
        case 8:printf("        "); break;
        case 9:printf("         "); break;
        case 10:printf("         "); break;
      }
      printf("%s\n",race_track[i].name );
  }
         sleep(1);
}

void set_random_acc_rate()
{
  for (int i = 0; i < MAX_CARS; i++) {
    race_track[i].car->acceleration_rate = random();
  }
}

bool is_race_finished()
{
  for (int i = 0; i < MAX_CARS; i++) {
    if (race_track[i].position == END) {
      printf("%s has won this race!\n", race_track[i].name );
      return true;
    }
  }
  return false;
}

void move_car_with_highest_speed()
{
  for (int i = 0; i < MAX_CARS; i++) {
     bool is_faster = true;
    for (int j = i+1; j < MAX_CARS; j++) {
      if (race_track[i].car->acceleration_rate < race_track[j].car->acceleration_rate) {
        is_faster = false;
      }
    }
    if (is_faster) {
      race_track[i].position++;
      print_cars();
    }
  }
}
