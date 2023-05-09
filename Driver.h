#pragma once
#include <iostream>
#include "TaxiCar.h"
#include "AbstractPerson.h"

using std::string;

class Driver : public AbstractPerson {
private:
	int id;
	static int driversNum;
	string firstName;
	string surname;
	int driverLicenseNum;
	TaxiCar* car;

public:
	Driver (int id, string firstName, string surname, int driverLicenseNum);
	~Driver ();

	int GetId () override;
	string GetFirstName () override;
	string GetSurname () override;
	int GetLicenseNum ();

	void GiveTaxiCar (TaxiCar* car);
};

