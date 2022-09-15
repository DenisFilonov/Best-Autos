#pragma once
#include "Vehicle.h"

#include<iostream>
#include<string>
#include<fstream>

using namespace std;

class Motorcycle :
    public Vehicle
{
protected: 
    /*Хотел сделать наследование по мотоциклам, но понял, что по сути скутера и квадроциклы мало чем отличаются от мотоциклов, 
    кроме как количество колёс у квадроцикла и может, чуть лучше грузоподъёмность
    I wanted to make motorcycle inheritance, but I realized that, in essence, scooters and ATVs are not much different from motorcycles,
     except for the number of wheels on an ATV and maybe a little better load capacity */

    int amountofwheels;

public:
    Motorcycle();
    Motorcycle(const Motorcycle& obj);
    Motorcycle(string name, string model, string typeofveh, string gearbox, string color, float price, int maxspeed, int productionyear, int amountofwheels);
    ~Motorcycle();

    void setAmountofwheels(int amountofwheels);
    int getAmountofwheels()const&;

    virtual void show()const override;
    virtual string type()const override;
    virtual string toString()const override;
    virtual void save(ofstream& file)override;
    virtual void load(string tmp)override;
};

