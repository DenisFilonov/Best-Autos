#pragma once
#include "Car.h"

#include<iostream>
#include<string>
#include<fstream>

using namespace std;

class Minivan :
    public Car
{
protected:
    int amountofseats;

public:
    Minivan();
    Minivan(const Minivan& obj);
    Minivan(string name, string model, string typeofveh, string gearbox, string color, float price, int maxspeed, int productionyear, string carclass, int amountofseats);
    ~Minivan();

    void setAmountOfSeats(int amountofseats);
    int getAmountOfSeats()const&;

    virtual void show()const override;
    virtual string type()const override;
    virtual string toString()const override;
    virtual void save(ofstream& file)override;
    virtual void load(string tmp)override;
};

