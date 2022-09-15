#pragma once
#include<iostream>
#include<string>
#include<fstream>

#include"AllExceptions.h"

using namespace std;

class Client
{
	string name;
	int64_t idnumber;
	string phnumber;
	string address;
	string email;

	int64_t sumofpurchase;
	int amountofpurchase;

public:
	Client();
	Client(string name, int64_t idnumber, string phnumber, string address, string email, int64_t sumofpurchase = 0, int amountofpurchase = 0);
	~Client();

	void setName(string name);
	void setIdNumber(int64_t idnumber);
	void setPhNumber(string phnumber);
	void setAddress(string address);	
	void setEmail(string email);
	void setAmountOfPurchase(int amountofpurchase);
	void setSumOfPurchase(int sumofpurchase);

	string getName()const;
	int64_t getIdNumber()const;
	string getPhNumber()const;
	string getAddress()const;
	string getEmail()const;
	int64_t getAmountOfPurchase()const;
	int64_t getSumOfPurchase()const;

	void show()const;

	void save(ofstream& file);
	void load(ifstream& file);
};

/*
bool upBuyes(const Client* a, const Client* b)
{
	return a->getSumOfPurchase() > b->getSumOfPurchase();
}

bool dwBuyes(const Client* a, const Client* b)
{
	return !upBuyes(a, b);
}

bool upAmount(const Client* a, const Client* b)
{
	return a->getAmountOfPurchase() > b->getAmountOfPurchase();
}

bool dwAmount(const Client* a, const Client* b)
{
	return !upAmount(a, b);
}
*/