#pragma once
#include<iostream>
#include<string>
#include<list>

#include"Vehicle.h"
#include"Car.h"
#include"Minivan.h"
#include"Lorry.h"
#include"Motorcycle.h"

using namespace std;

class Dealership
{
	string name;
	list<Vehicle*> autoshow;
	list<Vehicle*>::iterator p;

public:
	Dealership();
	Dealership(string name);
	~Dealership();

	void show();
	void add(Vehicle* obj);
	void del(string name);
	void sort();

	void find(string name);
	list<Vehicle*>::iterator findElementByName(string name);
	void changeInfo(string name);

	void showByType(string type);

	void save(string name);
	void load(string name);
};

