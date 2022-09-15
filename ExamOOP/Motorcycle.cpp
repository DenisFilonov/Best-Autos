#include "Motorcycle.h"

Motorcycle::Motorcycle()
{
    name = "Suzuki";
    model = "Hayabusa ";
    typeofveh = "Motorcycle";
    gearbox = "Automatic transmission";
    color = "Red";
    price = 1'550'000;
    maxspeed = 300;
    productionyear = 2020;
    amountofwheels = 2;
}

Motorcycle::Motorcycle(const Motorcycle& obj)
{
}

Motorcycle::Motorcycle(string name, string model, string typeofveh, string gearbox, string color, float price, int maxspeed, int productionyear, int amountofwheels)
    : Vehicle(name, model, typeofveh, gearbox, color, price, maxspeed, productionyear)
{
    if (amountofwheels < 2 || amountofwheels > 3) throw new AmountOfWheelsException();
    this->amountofwheels = amountofwheels;
}

Motorcycle::~Motorcycle()
{
}

void Motorcycle::setAmountofwheels(int amountofwheels)
{
    if (amountofwheels < 2 || amountofwheels > 3) throw new AmountOfWheelsException();
    
    this->amountofwheels = amountofwheels;
}

int Motorcycle::getAmountofwheels() const&
{
    return amountofwheels;
}

void Motorcycle::show() const
{
    cout << "\n\tINFO:";
    cout << "\nType: " << type();
    cout << "\nName: " << name;
    cout << "\nModel: " << model;
    cout << "\Type of vehicle: " << typeofveh;
    cout << "\nType of transmission: " << gearbox;
    cout << "\nColor: " << color;
    cout << "\nPrice: " << price;
    cout << "\nMaximal speed: " << maxspeed;
    cout << "\nProduction year: " << productionyear;
    cout << "\nAmount of wheels: " << amountofwheels << endl;
}

string Motorcycle::type() const
{
    return "Motorcycle";
}

string Motorcycle::toString() const
{
    return type() + "+" + name + "+" + model + "+" + typeofveh + "+" + gearbox + "+"
        + color + "+" + to_string(price) + "+" + to_string(maxspeed) + "+" + to_string(productionyear) + "+" + to_string(amountofwheels) + "+";
}

void Motorcycle::save(ofstream& file)
{
    file << toString() << endl;
}

void Motorcycle::load(string tmp)
{
    // ifstream& file || string tmp
    tmp.erase(0, tmp.find("+") + 1);

    name = tmp.substr(0, tmp.find("+") + 1);
    tmp.erase(0, tmp.find("+") + 1);

    model = tmp.substr(0, tmp.find("+") + 1);
    tmp.erase(0, tmp.find("+") + 1);

    typeofveh = tmp.substr(0, tmp.find("+") + 1);
    tmp.erase(0, tmp.find("+") + 1);

    gearbox = tmp.substr(0, tmp.find("+") + 1);
    tmp.erase(0, tmp.find("+") + 1);

    color = tmp.substr(0, tmp.find("+") + 1);
    tmp.erase(0, tmp.find("+") + 1);

    price = atof(tmp.c_str());
    tmp.erase(0, tmp.find("+") + 1);

    maxspeed = atoi(tmp.c_str());
    tmp.erase(0, tmp.find("+") + 1);

    productionyear = atoi(tmp.c_str());
    tmp.erase(0, tmp.find("+") + 1);

    amountofwheels = atoi(tmp.c_str());
    tmp.erase(0, tmp.find("+") + 1);

    tmp.clear();

}
