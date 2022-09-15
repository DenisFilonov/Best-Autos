#pragma once
#include "Vehicle.h"

#include<iostream>
#include<string>
#include<fstream>

using namespace std;

class Car :
    public Vehicle
{
protected:
    string carclass;
    /*
    А: мини-автомобили;
    B: небольшие городские автомобили;
    C: низший средний класс или гольф-класс;
    D: полноценный средний класс;
    E: представительский или бизнес-класс;
    F: роскошные и люксовые автомобили;
    J: внедорожники;
    M: многоцелевые автомобили, минивэны;
    */

public:
    Car();
    Car(const Car& obj);
    Car(string name, string model, string typeofveh, string gearbox, string color, float price, int maxspeed, int productionyear, string carclass);
    ~Car();

    void setCarClass(string carclass);
    string getCarClass()const&;

    bool isRightCarClass()const;

    virtual void show()const override;		
    virtual string type()const override;
    virtual string toString()const override;
    virtual void save(ofstream& file)override;
    virtual void load(string tmp)override;
};

