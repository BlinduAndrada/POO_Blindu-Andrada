#include "Hyundai.h"

Hyundai::Hyundai() {
	fuelCapacity = 50;
	fuelConsumption = 5;
	averageSpeed[Rain] = 65;
	averageSpeed[Sunny] = 120;
	averageSpeed[Snow] = 70;
	averageSpeed[Fog] = 45;
	name = (char*)"Hyndai";
}

float Hyundai::carTime(bool& verify, int weather, int CircuitLenght) {
	auto speed = averageSpeed[weather];
	//auto hours = static_cast<float>(fuelCapacity / fuelConsumption);
	auto hours = fuelCapacity / fuelConsumption;
	auto distance = hours * speed;
	verify = distance > CircuitLenght;

	return (hours * CircuitLenght / distance);

}

char* Hyundai::GetName()const {

	return name;
}