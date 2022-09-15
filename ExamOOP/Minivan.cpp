#include "Minivan.h"

Minivan::Minivan()
{
    name = "Renault";
    model = "Fluence";
    typeofveh = "Sedan";
    gearbox = "Manual Transmission";
    color = "White";
    price = 1'750'000;
    maxspeed = 230;
    productionyear = 2012;
    carclass = "M";
    amountofseats = 9;
}

Minivan::Minivan(const Minivan& obj)
{
    this->name = obj.name;
    this->model = obj.model;
    this->typeofveh = obj.typeofveh;
    this->gearbox = obj.gearbox;
    this->color = obj.color;
    this->price = obj.price;
    this->maxspeed = obj.maxspeed;
    this->productionyear = obj.productionyear;
    this->carclass = obj.carclass;

    this->amountofseats = obj.amountofseats;
}

Minivan::Minivan(string name, string model, string typeofveh, string gearbox, string color, float price, int maxspeed, int productionyear, string carclass, int amountofseats)
    : Car(name, model, typeofveh, gearbox, color, price, maxspeed, productionyear, carclass)
{
    // 5, 7, 8, 9, 10 and 20
    if (amountofseats != 5 || amountofseats != 7 || amountofseats != 8 || amountofseats != 9 || amountofseats != 10 || amountofseats != 20) throw new AmountOfSeatsException();
    this->amountofseats = amountofseats;
}

Minivan::~Minivan()
{
}

void Minivan::setAmountOfSeats(int amountofseats)
{
    if (amountofseats != 5 || amountofseats != 7 || amountofseats != 8 || amountofseats != 9 || amountofseats != 10 || amountofseats != 20) throw new AmountOfSeatsException();
    this->amountofseats = amountofseats;
}

int Minivan::getAmountOfSeats() const&
{
    return amountofseats;
}

void Minivan::show() const
{
    Car::show();
    cout << "Amount of seats: " << amountofseats << endl;
}

string Minivan::type() const
{
    return "Minivan";
}

string Minivan::toString() const
{
    return type() + "+" + name + "+" + model + "+" + typeofveh + "+" + gearbox + "+"
        + color + "+" + to_string(price) + "+" + to_string(maxspeed) + "+" + to_string(productionyear) + "+" + carclass + "+" + to_string(amountofseats) + "+";
}

void Minivan::save(ofstream& file)
{
    file << toString() << endl;
}

void Minivan::load(string tmp)
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

    carclass = tmp.substr(0, tmp.find("+") + 1);
    tmp.erase(0, tmp.find("+") + 1);

    amountofseats = atoi(tmp.c_str());
    tmp.clear(); // Записали, сколько мест в минивэне, и очистили строку.
}
