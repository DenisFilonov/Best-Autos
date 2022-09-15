#include "Lorry.h"

Lorry::Lorry()
{
    name = "VOLVO";
    model = "FMX-500-10X4";
    typeofveh = "Lorry";
    gearbox = "Manual Transmission";
    color = "Gray";
    price = 2'750'000;
    maxspeed = 210;
    productionyear = 2013;
    carclass = "N";

    carryingweight = 2.5;
}

Lorry::Lorry(const Lorry& obj)
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

    this->carryingweight = obj.carryingweight;
}

Lorry::Lorry(string name, string model, string typeofveh, string gearbox, string color, float price, int maxspeed, int productionyear, string carclass, float carryingweight)
    : Car(name, model, typeofveh, gearbox, color, price, maxspeed, productionyear, carclass)
{
    if (carryingweight < 0 || carryingweight > 40) throw new CarryingWeightException();
    this->carryingweight = carryingweight;
}

Lorry::~Lorry()
{
}

void Lorry::setCarryingWeight(float carryingweight)
{
    if (carryingweight < 0 || carryingweight > 40) throw new CarryingWeightException();
    
    this->carryingweight = carryingweight;
}

float Lorry::getCarryingWeight() const&
{
    return carryingweight;
}

void Lorry::show() const
{
    Car::show();
    cout << "Carrying weight: " << carryingweight << "t.\n";
}

string Lorry::type() const
{
    return "Lorry";
}

string Lorry::toString() const
{
    return type() + "+" + name + "+" + model + "+" + typeofveh + "+" + gearbox + "+"
        + color + "+" + to_string(price) + "+" + to_string(maxspeed) + "+" + to_string(productionyear) + "+" + carclass + "+" + to_string(carryingweight) + "+";
}

void Lorry::save(ofstream& file)
{
    file << toString() << endl;
}

void Lorry::load(string tmp)
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

    carryingweight = atof(tmp.c_str());
    tmp.clear(); // Записали, какой груз может перевозить, и очистили строку.
}
