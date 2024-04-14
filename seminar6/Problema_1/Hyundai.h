#ifndef HYUNDAI_H_INCLUDED
#define HYUNDAI_H_INCLUDED

#include "Car.h"

class Hyundai : public Car {

	int fuelCapacity;
	int fuelConsumption;
	int averageSpeed[4];
	char* name;
public:
	Hyundai();

	float carTime(bool&, int, int);
	char* GetName()const;

};

#endif // !HYUNDAI_H_INCLUDED
