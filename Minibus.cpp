#include "Minibus.h"

Minibus::Minibus (int id, string brand, string numberPlate, int capacity, double pricePerKm) : TaxiCar (id, brand, numberPlate, pricePerKm) {
	this->capacity = capacity;
	this->passengers = new Customer* [capacity];
}

Minibus::~Minibus () {

}

bool Minibus::AddPassenger (Customer* passenger) {
	if (this->capacity == this->passengersNum) return false;
	this->passengers [this->passengersNum++] = passenger;
	return true;
}

int Minibus::GetPassengersNum () {
	return this->passengersNum;
}
