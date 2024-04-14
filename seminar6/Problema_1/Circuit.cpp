#include "Circuit.h"

Circuit::Circuit() {
	 CircuitLenght = 0;
	 carsIndex = 0;
	 weather = 0;
	 for (auto i = 0; i < 100; i++) {
		 timeToFinish[i] = 0;
		 finish[i] = 0;
		 car[i] = nullptr;
	 }
	 

}

Circuit::~Circuit() {
	for (auto i = 0; i < carsIndex; i++)
		delete[] car[i];
	delete[] car;

}

void Circuit::SetLength(int dist) {
	CircuitLenght = dist;
}

void Circuit::SetWeather(int w) {
	weather = w;
}

void Circuit::AddCar(Car* c) {
	car[carsIndex++] = c;
}

void Circuit::Race() {
	for (auto i = 0; i < carsIndex; i++) {
		bool verify = 0;
		timeToFinish[i] = car[i]->carTime(verify,weather,CircuitLenght);
		finish[i] = verify;
	}
}

void Circuit::ShowFinalRanks() {
	cout << "The time for each car that finished: \n";

	// Descending Sort for 'car' vector 
	for (auto i = 0; i < carsIndex - 1; i++) {
		for (auto j = i + 1; j < carsIndex; j++) {
			if (timeToFinish[i] < timeToFinish[j])
				swap(timeToFinish[i],timeToFinish[j]);
			
		}
	}

	for (auto i = 0; i < carsIndex ; i++) 
		if(finish[i])
			cout << car[i]->GetName() << " - " << timeToFinish[i] << '\n';

}

void Circuit::ShowWhoDidNotFinish() {
	cout << "The time for each car that didn't finished: \n";
	
	for (auto i = 0; i < carsIndex; i++)
		if (!finish[i])
			cout << car[i]->GetName() << " - " << timeToFinish[i] << '\n';

}
