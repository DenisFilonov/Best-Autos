#pragma once
#include "Car.h"

#include<iostream>
#include<string>
#include<fstream>

using namespace std;

class Lorry :
    public Car
{
protected:
    float carryingweight;

public:
    Lorry();
    Lorry(const Lorry& obj);
    Lorry(string name, string model, string typeofveh, string gearbox, string color, float price, int maxspeed, int productionyear, string carclass, float carryingweight);
    ~Lorry();

    void setCarryingWeight(float carryingweight);
    float getCarryingWeight()const&;

    virtual void show()const override;
    virtual string type()const override;
    virtual string toString()const override;
    virtual void save(ofstream& file)override;
    virtual void load(string tmp)override;
};

