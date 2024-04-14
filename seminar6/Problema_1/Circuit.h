#ifndef CIRCUIT_H_INCLUDED
#define CIRCUIT_H_INCLUDED

#include "Libs.h";

#include "Mazda.h"
#include "Toyota.h"
#include "Hyundai.h"
#include "Nissan.h"

class Circuit {

private:
	Car* car[100];
	int CircuitLenght;
	int timeToFinish[100];
	bool finish[100];
	int carsIndex;
	int weather;

public:

	Circuit();
	~Circuit();

	void SetLength(int);
	void SetWeather(int);
	
	void AddCar(Car*);

	void Race();

	void ShowFinalRanks();
	void ShowWhoDidNotFinish();
};

#endif // !CIRCUIT_H_INCLUDED
