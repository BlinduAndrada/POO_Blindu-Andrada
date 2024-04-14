#include "Nissan.h"

Nissan::Nissan() {
	fuelCapacity = 41;
	fuelConsumption = 6;
	averageSpeed[Rain] = 30;
	averageSpeed[Sunny] = 80;
	averageSpeed[Snow] = 45;
	averageSpeed[Fog] = 20;
	name = (char*)"Nissan";
}

float Nissan::carTime(bool& verify, int weather, int CircuitLenght) {
	auto speed = averageSpeed[weather];
	//auto hours = static_cast<float>(fuelCapacity / fuelConsumption);
	auto hours = fuelCapacity / fuelConsumption;
	auto distance = hours * speed;
	verify = distance > CircuitLenght;

	return (hours * CircuitLenght / distance);

}

char* Nissan::GetName()const {
	
	return name;
}