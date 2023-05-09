#pragma once

#include <iostream>
#include <string>

class Customer;

using std::string;

class TaxiCar {
private:
	int id;
	string brand; // zna�ka auta
	string numberPlate; // SPZ
	double pricePerKm; // cena za km j�zdy

protected:
	int passengersNum; // po�et lid�

public:
	TaxiCar (int id, string brand, string numberPlate, double pricePerKm); // konstruktor
	~TaxiCar ();

	int GetId ();
	virtual string GetBrand ();
	virtual string GetNumberPlate ();
	virtual int GetPassengersNum ();
	virtual double GetPricePerKm ();

	virtual bool AddPassenger (Customer* passenger) = 0;
};
