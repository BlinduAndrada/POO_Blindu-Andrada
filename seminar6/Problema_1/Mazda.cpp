#include "Mazda.h"

Mazda::Mazda() {
	fuelCapacity = 51;
	fuelConsumption = 7;
	averageSpeed[Rain] = 50;
	averageSpeed[Sunny] = 150;
	averageSpeed[Snow] = 30;
	averageSpeed[Fog] = 40;
	name = (char*)"Mazda";
}

float Mazda::carTime(bool& verify, int weather, int CircuitLenght) {
	auto speed = averageSpeed[weather];
	//auto hours = static_cast<float>(fuelCapacity / fuelConsumption);
	auto hours = fuelCapacity / fuelConsumption;
	auto distance = hours * speed;
	verify = distance > CircuitLenght;

	return (hours * CircuitLenght / distance);

}

char* Mazda::GetName()const {

	return name;
}