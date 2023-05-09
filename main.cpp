#include <iostream>
#include <string>

#include "TaxiCompany.h"

using std::cout;
using std::endl;

int main () {
	// vytvo�en� taxislu�by
	TaxiCompany* taxiCompany = new TaxiCompany (5, 7, 3, 15, 15);

	// vytvo�en� dispe�er�
	taxiCompany->AddDispatcher (1, "Ondrej", "Vrchlicky", "Morava", 2);
	taxiCompany->AddDispatcher (2, "Michal", "Prochazka", "Cechy", 3);

	// vytvo�en� �idi��
	taxiCompany->AddDriver (1, "Eva", "Cerna", 954984);
	taxiCompany->AddDriver (2, "Josef", "Novotny", 647529);
	taxiCompany->AddDriver (3, "Matyas", "Kucera", 845248);
	taxiCompany->AddDriver (4, "Johana", "Vesela", 978566);

	// osobn� auta
	taxiCompany->AddTaxiCar (1, "Skoda", "5T49654", 30);
	taxiCompany->AddTaxiCar (2, "BMW", "8A64982", 40);
	taxiCompany->AddTaxiCar (3, "Peugeot", "6P42589", 25);
	// minibusy
	taxiCompany->AddTaxiCar (4, "Mercedes", "6B84297", 6, 45);
	taxiCompany->AddTaxiCar (5, "Renault", "7M61874", 8, 35);

	// vytvo�en� z�kazn�ka
	taxiCompany->AddCustomer (1, "Jan", "Novak", "Praha");
	taxiCompany->AddCustomer (2, "Dan", "Dvorak", "Brno");
	taxiCompany->AddCustomer (3, "Marie", "Svobodova", "Ostrava");

	//Dispatcher dostane auto
	taxiCompany->FindDispatcher (1)->AssignTaxiCar (taxiCompany->FindTaxicar (1));
	taxiCompany->FindDispatcher (1)->AssignTaxiCar (taxiCompany->FindTaxicar (2));
	taxiCompany->FindDispatcher (1)->AssignTaxiCar (taxiCompany->FindTaxicar (3));
	taxiCompany->FindDispatcher (2)->AssignTaxiCar (taxiCompany->FindTaxicar (4));
	taxiCompany->FindDispatcher (2)->AssignTaxiCar (taxiCompany->FindTaxicar (5));

	// z�kazn�k zavol� taxi
	taxiCompany->AddOrder (taxiCompany->FindDispatcher (1)->CreateOrder (1, taxiCompany->FindCustomer (1), taxiCompany->FindCustomer (1)->GetLocation (), "Olomouc"));
	taxiCompany->FindOrder (1)->CalculatePrice (100); // v pr�b�hu j�zdy je mo�n� po��tat sou�asnou cenu za zat�m ujetou vzd�lenost
	taxiCompany->FindOrder(1)->CalculatePrice (50);
	taxiCompany->AddOrder (taxiCompany->FindDispatcher (2)->CreateOrder (2, taxiCompany->FindCustomer (3), taxiCompany->FindCustomer (3)->GetLocation (), "Nymburk"));
	taxiCompany->FindOrder (2)->CalculatePrice (80);

	cout << taxiCompany->printInfo () << endl;
	
	// vypo��t� se cena objedn�vky

	return 0;
}