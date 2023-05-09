#include "Order.h"

int Order::ordersNum = 0;

Order::Order (int id, Customer* customer, string startingAddress, string endingAddress, TaxiCar* taxiCar) {
	ordersNum++;
	this->id = id;
	this->customer = customer;
	this->taxiCar = taxiCar;
	this->price = 0;
}

Order::~Order () {
	ordersNum--;
}

int Order::GetId () {
	return this->id;
}

int Order::GetPrice () {
	return this->price;
}

int Order::CalculatePrice (int kms) {
	this->price += kms * this->taxiCar->GetPricePerKm ();
	return this->price;
}