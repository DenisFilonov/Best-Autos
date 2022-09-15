#pragma once
#include<iostream>
#include<string>
#include<fstream>

#include"AllExceptions.h"

using namespace std;

class Staff
{
	string name;
	int64_t idnumber;
	string position;
	string phnumber;
	string address;

	int64_t sumofpurchase;
	int amountofpurchase;

public:
	Staff();
	Staff(string name, int64_t idnumber, string position, string phnumber, string address, int64_t sumofpurchase = 0, int amountofpurchase = 0);
	~Staff();

	void setName(string name);
	void setIdNumber(int64_t idnumber);
	void setPosition(string position);
	void setPhNumber(string phnumber);
	void setAddress(string address);

	void setAmountOfPurchase(int amountofpurchase);
	void setSumOfPurchase(int sumofpurchase);

	string getName()const;
	int64_t getIdNumber()const;
	string getPosition()const;
	string getPhNumber()const;
	string getAddress()const;

	int64_t getAmountOfPurchase()const;
	int64_t getSumOfPurchase()const;

	void show()const;

	void save(ofstream& file);
	void load(ifstream& file);
};

/*
bool upSales(const Staff* a, const Staff* b)
{
	return a->getSumOfPurchase() > b->getSumOfPurchase();
}

bool dwSales(const Staff* a, const Staff* b)
{
	return !upSales(a, b);
}

bool upAmount(const Staff* a, const Staff* b)
{
	return a->getAmountOfPurchase() > b->getAmountOfPurchase();
}

bool dwAmount(const Staff* a, const Staff* b)
{
	return !upAmount(a, b);
}
*/