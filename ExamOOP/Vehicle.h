#pragma once
#include<iostream>
#include<string>
#include<fstream>

#include"AllExceptions.h"
//+ Sort under class Vehicle

using namespace std;

class Vehicle // класс-интерфейс, на основе котором будет реализован полиморфизм
{
protected: // возможность наследовани€
	string name;
	string model;
	string typeofveh;
	string gearbox;
	string color;

	long float price;
	int maxspeed; // float никак не может быть, спидометр показывает всегда ц/значени€ 
	int productionyear;

public:
	//================================= ќЌ—“–” “ќ–џ===================
	Vehicle();
	Vehicle(string name, string model, string typeofveh, string gearbox, string color, long float price, int maxspeed, int productionyear);
	Vehicle(const Vehicle& obj);
	virtual ~Vehicle();

	//=================================ќѕ≈–ј“ќ–џ========================
	Vehicle& operator = (const Vehicle& obj);

	//=================================—Ё““Ё–џ========================
	void setName(string name);
	void setModel(string model);
	void setTypeOfVeh(string typeofveh);
	void setGearBox(string gearbox);
	void setColor(string color);
	void setPrice(float price);
	void setMaxSpeed(int maxspeed);
	void setProductionYear(int productionyear);

	//=================================√≈““Ё–џ========================
	string getName()const&;
	string getModel()const&;
	string getTypeOfVeh()const&;
	string getGearBox()const&;
	string getColor()const&;
	long float getPrice()const&;
	int getMaxSpeed()const&;
	int getProductionYear()const&;

	//=================================¬»–“”јЋ№Ќџ≈========================
	virtual void gearBoxes()const;
	virtual void typesOfTransport()const;

	virtual void show()const = 0;		//все методы, что равны нулю будут переданы наследникам на переопределение
	virtual string type()const = 0;
	virtual string toString()const = 0; // красота-лепота
	virtual void save(ofstream& file);  // вот здесь будет пусто, этот класс ничего не сохран€ет
	virtual void load(string tmp);  // и здесь будет пусто, т.к. класс ничего не сохран€ет

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