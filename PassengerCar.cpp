#include "PassengerCar.h"

PassengerCar::PassengerCar (int id, string brand, string numberPlate, double pricePerKm) : TaxiCar (id,brand, numberPlate, pricePerKm) {
	this->passenger = nullptr;
}

PassengerCar::~PassengerCar () {

}

int PassengerCar::GetPassengersNum () {
	if (this->passenger == nullptr) return 0;
	return 1;
}

bool PassengerCar::AddPassenger (Customer* passenger) {
	if (this->passenger == nullptr) {
		this->passenger = passenger;
		return true;
	}
	return false;
}