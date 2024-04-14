#ifndef MAZDA_H_INCLUDED
#define MAZDA_H_INCLUDED

#include "Car.h"

class Mazda : public Car {

	int fuelCapacity;
	int fuelConsumption;
	int averageSpeed[4];
	char* name;
public:
	Mazda();

	float carTime(bool&, int, int);
	char* GetName()const;

};

#endif // !MAZDA_H_INCLUDED
