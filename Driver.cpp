#include "Driver.h"

int Driver::driversNum = 0;

Driver::Driver (int id, string firstName, string surname, int driverLicenseNum) {
	this->id = id;
	driversNum++;
	this->firstName = firstName;
	this->surname = surname;
	this->driverLicenseNum = driverLicenseNum;
	this->car = nullptr;
}

Driver::~Driver () {
	driversNum--;
}

int Driver::GetId () {
	return this->id;
}

string Driver::GetFirstName () {
	return this->firstName;
}

string Driver::GetSurname () {
	return this->surname;
}

int Driver::GetLicenseNum () {
	return this->driverLicenseNum;
}

void Driver::GiveTaxiCar (TaxiCar* car) {
	this->car = car;
}
