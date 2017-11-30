/*----------------------------------------------------------
*				HTBLA-Leonding / Klasse: 2AHIF
* ---------------------------------------------------------
* Exercise Number: 0
* Title:			car.cpp
* Author:			Panturu Gloria Sara
* Due Date:		November 30, 2017
* ----------------------------------------------------------
*/
#include <stdio.h>
#include "car.h"

struct CarType
{
  enum Type type;
  enum Color color;
  float fill_level;
  float acceleration_rate;
  float speed;
};

static CarType aixam1 = {AIXAM, RED, 16, 0, 0};
static CarType multipla1= {FIAT_MULTIPLA, GREEN , 65, 0, 0};
static CarType multipla2 = {FIAT_MULTIPLA, BLUE , 65, 0, 0};
static CarType multipla3 = {FIAT_MULTIPLA, ORANGE , 65, 0, 0};
static CarType jeep1 = {JEEP, SILVER, 80, 0, 0};
static CarType jeep2 = {JEEP, BLACK, 80, 0, 0};

struct RentalRecord
{
  bool is_rented;
  Car car;
};

static RentalRecord rental_record[6] =
{{false, &aixam1}, {false, &multipla1}, {false, &multipla2},
 {false, &multipla3}, {false, &jeep1}, {false, &jeep2}};

void init()
{
for (int i = 0; i < 6; i++) {
  rental_record[i].is_rented= false;
  rental_record[i].car->speed = 0;
  rental_record[i].car->acceleration_rate = 0;
  }
}

Car get_car (enum Type type)
{
  for (int i = 0; i < 6; i++) {
    if (rental_record[i].car->type == type && rental_record[i].is_rented == false) {
      rental_record[i].is_rented = true;
      return rental_record[i].car;
    }
  }
  return 0;
}

 Type get_type (Car car)
{
 return car->type;
}

Color get_color (Car car)
{
return car->color;
}

float get_fill_level( Car car)
{
return car->fill_level;
}

float get_acceleration_rate ( Car car)
{
return car->acceleration_rate;
}

void set_acceleration_rate( Car car, float rate)
{
  if (car->type == AIXAM && rate > 1.00) {
    rate = 1.00;
  }
  else if (car->type == FIAT_MULTIPLA && rate> 2.26) {
    rate = 2.26;
  }
  else if (car->type == JEEP && rate > 3.14) {
   rate = 3.14;
  }
  else if((car->type == AIXAM ||car->type == FIAT_MULTIPLA || car->type == JEEP)&& rate < -8.00)
  {
    rate = -8.00;
  }
car->acceleration_rate = rate;
}

int get_speed(Car car)
{
return round(car->speed);
}

void accelerate (Car car)
{
  car->speed= (car->acceleration_rate*3.6+ car->speed);
  if(car->type == AIXAM && car->speed > 45)car->speed = 45;
  if(car->type == JEEP && car->speed > 196)car->speed = 196;
  if(car->type == FIAT_MULTIPLA && car->speed > 170) car->speed = 170;
}

int round(float speed)
{
  return (speed +0.5);
}
