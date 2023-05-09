#pragma once

#include "TaxiCar.h"
#include "Customer.h"

using std::string;

class Minibus : public TaxiCar {
private:
	int capacity;
	Customer** passengers; // mùže vézt více zákazníkù
public:
	Minibus (int id, string brand, string numberPlate, int capacity, double pricePerKm);
	~Minibus ();

	bool AddPassenger (Customer* passenger) override;
	int GetPassengersNum () override;
};

