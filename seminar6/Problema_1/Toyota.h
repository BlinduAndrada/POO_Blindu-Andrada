#ifndef TOYOTA_H_INCLUDED
#define TOYOTA_H_INCLUDED

#include "Car.h"

class Toyota : public Car {

	int fuelCapacity;
	int fuelConsumption;
	int averageSpeed[4];
	char* name;
public:
	Toyota();
	
	float carTime(bool&, int, int);
	char* GetName()const;

};

#endif // !TOYOTA_H_INCLUDED
