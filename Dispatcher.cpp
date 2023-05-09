#include "Dispatcher.h"

Dispatcher::Dispatcher (int id, string name, string surname, string area, int maxTaxis) {
	this->id = id;
	this->name = name;
	this->surname = surname;
	this->area = area;
	this->assignedTaxisNum = 0;
	this->maxTaxis = maxTaxis;
	this->taxiCars = new TaxiCar* [maxTaxis];
}

Dispatcher::~Dispatcher () {

}

int Dispatcher::GetId () {
	return this->id;
}

string Dispatcher::GetFirstName () {
	return this->name;
}

string Dispatcher::GetSurname () {
	return this->surname;
}

string Dispatcher::GetArea () {
	return this->area;
}

int Dispatcher::GetAssignedTaxisNum () {
	return this->assignedTaxisNum;
}

int Dispatcher::GetMaxTaxis () {
	return this->maxTaxis;
}

void Dispatcher::AssignTaxiCar (TaxiCar* taxiCar) {
	if (this->assignedTaxisNum == this->maxTaxis) return;
	this->taxiCars [assignedTaxisNum++] = taxiCar;
}

Order* Dispatcher::CreateOrder (int id, Customer* customer, string startingAddress, string endingAddress) {
	
	for (int i = 0; i < this->assignedTaxisNum; i++) {
		TaxiCar* taxi = this->taxiCars [i];
		if (taxi->AddPassenger (customer)) return new Order (id, customer, startingAddress, endingAddress, taxi);
	}
	return nullptr;
}
