#include "Toyota.h"

Toyota::Toyota() {
	fuelCapacity = 50;
	fuelConsumption = 8;
	averageSpeed[Rain] = 80;
	averageSpeed[Sunny] = 130;
	averageSpeed[Snow] = 50;
	averageSpeed[Fog] = 45;
	name = (char*)"Toyota";
}

float Toyota::carTime(bool& verify, int weather, int CircuitLenght) {
	auto speed = averageSpeed[weather];
	//auto hours = static_cast<float>(fuelCapacity / fuelConsumption);
	auto hours = fuelCapacity / fuelConsumption;
	auto distance = hours * speed;
	verify = distance > CircuitLenght;

	return (hours * CircuitLenght / distance);

}

char* Toyota::GetName()const {

	return name;
}
