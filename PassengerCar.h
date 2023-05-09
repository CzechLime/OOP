#pragma once

#include "TaxiCar.h"
#include "Customer.h"

using std::string;

class PassengerCar : public TaxiCar {
private:
	Customer* passenger;

public:
	PassengerCar (int id, string brand, string numberPlate, double pricePerKm);
	~PassengerCar ();

	int GetPassengersNum () override;
	bool AddPassenger (Customer* passenger) override;
};