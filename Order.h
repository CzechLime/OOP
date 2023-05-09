#pragma once

#include <iostream>
#include "Customer.h"
#include "TaxiCar.h"

using std::string;

class Order { // tøída Objednávka
private:
	int id;
	static int ordersNum;
	Customer* customer;
	TaxiCar* taxiCar;
	int price;
public:
	Order (int id, Customer* customer, string startingAddress, string endingAddress, TaxiCar* taxiCar);
	~Order ();

	int GetId ();
	int GetPrice ();

	int CalculatePrice (int kms);
};

