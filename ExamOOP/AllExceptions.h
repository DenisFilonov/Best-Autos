#pragma once
#include<iostream>
#include<string>

using namespace std;

class AllExceptions
{
public:
	virtual void showWhat() = 0;
};
//======================================================================================================Vehicle======================================
/*
	string name;
	string model;
	string typeofveh;
	string gearbox;
	string color;

	long float price;
	int maxspeed; 
	int productionyear;
*/
class NameException : public AllExceptions
{
public:
	virtual void showWhat()override
	{
		cout << "\n\tThe name is set incorrectly, check the input data!\n";
	}
};

class ModelException : public AllExceptions
{
public:
	virtual void showWhat()override
	{
		cout << "\n\tThe model is set incorrectly, check the input data!\n";
	}
};

class TypeVehException : public AllExceptions
{
public:
	virtual void showWhat()override
	{
		cout << "\n\tThe type of vehicle is set incorrectly, check the input data!\n";
	}
};

class GearboxException : public AllExceptions
{
public:
	virtual void showWhat()override
	{
		cout << "\n\tThe gearbox is set incorrectly, check the input data!\n";
	}
};

class ColorException : public AllExceptions
{
public:
	virtual void showWhat()override
	{
		cout << "\n\tThe color is set incorrectly, check the input data!\n";
	}
};

class PriceException : public AllExceptions
{
public:
	virtual void showWhat()override
	{
		cout << "\n\tThe price is set incorrectly, check the input data!\n";
	}
};

class MaxSpeedException : public AllExceptions
{
public:
	virtual void showWhat()override
	{
		cout << "\n\tThe maximal speed is set incorrectly, check the input data!\n";
	}
};

class ProdYearException : public AllExceptions
{
public:
	virtual void showWhat()override
	{
		cout << "\n\tThe production year is set incorrectly, check the input data!\n";
	}
};

//======================================================================================================Car======================================

class CarClassException : public AllExceptions
{
public:
	virtual void showWhat()override
	{
		cout << "\n\tThe car class is set incorrectly, check the input data!\nPlease enter only one character from this list: {A, B, C, D, E, F, M, N, J}\n";
	}
};

//======================================================================================================Minivan===================================

class AmountOfSeatsException : public AllExceptions
{
public:
	virtual void showWhat()override
	{
		cout << "\n\tThe amount of seats is set incorrectly, check the input data!\nMinivans are available for 5, 7, 8, 9, 10 and 20 seats.\n";
	}
};

//======================================================================================================Lorry=====================================

class CarryingWeightException : public AllExceptions
{
public:
	virtual void showWhat()override
	{
		cout << "\n\tThe carrying weight is set incorrectly, check the input data!\nCannot set weight less than 0 and more than 40.\n";
	}
};

//======================================================================================================Motorcycle=================================

class AmountOfWheelsException : public AllExceptions
{
public:
	virtual void showWhat()override
	{
		cout << "\n\tThe amount of wheels is set incorrectly, check the input data!\nPlease, enter value 2 or 3.\n";
	}
};

//======================================================================================================Dealership=====================================

class DealershipNameException : public AllExceptions
{
public:
	virtual void showWhat()override
	{
		cout << "\n\tThe name of dealership is set incorrectly, check the input data!\n";
	}
};

//======================================================================================================Client=====================================

class IdNumberException : public AllExceptions
{
public:
	virtual void showWhat()override
	{
		cout << "\n\tThe ID number is set incorrectly, check the input data!\n";
	}
};

class PhNumberException : public AllExceptions
{
public:
	virtual void showWhat()override
	{
		cout << "\n\tThe phone number is set incorrectly, check the input data!\n";
	}
};

class AddressException : public AllExceptions
{
public:
	virtual void showWhat()override
	{
		cout << "\n\tThe address number is set incorrectly, check the input data!\n";
	}
};

class EmailException : public AllExceptions
{
public:
	virtual void showWhat()override
	{
		cout << "\n\tThe e-mail number is set incorrectly, check the input data!\n";
	}
};

class PurchasesException : public AllExceptions
{
public:
	virtual void showWhat()override
	{
		cout << "\n\tThe value of purchase is set incorrectly, check the input data, can't be negative value!\n";
	}
};

//======================================================================================================Staff=====================================

class PositionException : public AllExceptions
{
public:
	virtual void showWhat()override
	{
		cout << "\n\tThe position is set incorrectly, check the input data!\n";
	}
};