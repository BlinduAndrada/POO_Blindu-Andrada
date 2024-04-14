#ifndef NISSAN_H_INCLUDED
#define NISSAN_H_INCLUDED

#include "Car.h"

class Nissan : public Car {

	int fuelCapacity;
	int fuelConsumption;
	int averageSpeed[4];
	char* name;
public:
	Nissan();

	float carTime(bool&, int, int);
	char* GetName()const;

};

#endif // !NISSAN_H_INCLUDED
