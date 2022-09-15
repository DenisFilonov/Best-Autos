#pragma once
#include<iostream>
#include<string>
#include<fstream>

#include"AllExceptions.h"
//+ Sort under class Vehicle

using namespace std;

class Vehicle // �����-���������, �� ������ ������� ����� ���������� �����������
{
protected: // ����������� ������������
	string name;
	string model;
	string typeofveh;
	string gearbox;
	string color;

	long float price;
	int maxspeed; // float ����� �� ����� ����, ��������� ���������� ������ �/�������� 
	int productionyear;

public:
	//=================================������������===================
	Vehicle();
	Vehicle(string name, string model, string typeofveh, string gearbox, string color, long float price, int maxspeed, int productionyear);
	Vehicle(const Vehicle& obj);
	virtual ~Vehicle();

	//=================================���������========================
	Vehicle& operator = (const Vehicle& obj);

	//=================================�������========================
	void setName(string name);
	void setModel(string model);
	void setTypeOfVeh(string typeofveh);
	void setGearBox(string gearbox);
	void setColor(string color);
	void setPrice(float price);
	void setMaxSpeed(int maxspeed);
	void setProductionYear(int productionyear);

	//=================================�������========================
	string getName()const&;
	string getModel()const&;
	string getTypeOfVeh()const&;
	string getGearBox()const&;
	string getColor()const&;
	long float getPrice()const&;
	int getMaxSpeed()const&;
	int getProductionYear()const&;

	//=================================�����������========================
	virtual void gearBoxes()const;
	virtual void typesOfTransport()const;

	virtual void show()const = 0;		//��� ������, ��� ����� ���� ����� �������� ����������� �� ���������������
	virtual string type()const = 0;
	virtual string toString()const = 0; // �������-������
	virtual void save(ofstream& file);  // ��� ����� ����� �����, ���� ����� ������ �� ���������
	virtual void load(string tmp);  // � ����� ����� �����, �.�. ����� ������ �� ���������

	virtual bool IsCorrectTypeOfTransmission()const&;
	virtual bool IsCorrectTypeOfVeh()const&;	
};


class CompareVeh : public binary_function<Vehicle*, Vehicle*, bool>
{
public:
	bool operator()(const Vehicle* obj1, const Vehicle* obj2) const
	{
		return obj1->getPrice() > obj2->getPrice();
	}
};