/*----------------------------------------------------------
*				HTBLA-Leonding / Klasse: 2AHIF
* ---------------------------------------------------------
* Exercise Number: 0
* Title:			car.h
* Author:			Panturu Gloria Sara
* Due Date:		November 30, 2017
* ----------------------------------------------------------
* Description:
* Car abstract data type demo.
* ----------------------------------------------------------
*/
#ifndef ___CAR_H
#define ___CAR_H

enum  Type{AIXAM, FIAT_MULTIPLA, JEEP};
enum Color{RED, GREEN, BLUE, ORANGE, SILVER, BLACK};

typedef struct CarType* Car;

void init();
Car get_car (enum Type type);
Type get_type (Car car);
Color get_color (Car car);
float get_fill_level( Car car);
float get_acceleration_rate ( Car car);
void set_acceleration_rate(Car car, float speed);
int get_speed(Car car);
void accelerate (Car car);
int round(float speed);
#endif
