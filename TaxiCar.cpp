#include "TaxiCar.h"
#include "Customer.h"

TaxiCar::TaxiCar (int id, string brand, string numberPlate, double pricePerKm) {
	this->id = id;
	this->brand = brand;
	this->numberPlate = numberPlate;
	this->passengersNum = 0;
	this->pricePerKm = pricePerKm;
}

TaxiCar::~TaxiCar () {

}

int TaxiCar::GetId () {
	return this->id;
}

string TaxiCar::GetBrand () {
	return this->brand;
}

string TaxiCar::GetNumberPlate () {
	return this->numberPlate;
}

int TaxiCar::GetPassengersNum () {
	return this->passengersNum;
}

double TaxiCar::GetPricePerKm () {
	return this->pricePerKm;
}

