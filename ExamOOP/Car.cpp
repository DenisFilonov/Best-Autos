#include "Car.h"

Car::Car()
{
    name = "Renault";
    model = "Fluence";
    typeofveh = "Sedan";
    gearbox = "Automatic transmission";
    color = "Black";
    price = 750'000;
    maxspeed = 270;
    productionyear = 2015;
    carclass = "C";
}

Car::Car(const Car& obj)
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
}

Car::Car(string name, string model, string typeofveh, string gearbox, string color, float price, int maxspeed, int productionyear, string carclass)
    : Vehicle(name,model,typeofveh,gearbox,color,price,maxspeed,productionyear)
{
    if (carclass.size() == 0 || carclass.size() > 2) throw new CarClassException();
    this->carclass = carclass;
}

Car::~Car()
{
}

void Car::setCarClass(string carclass)
{
    if (carclass.size() == 0 || carclass.size() > 2) throw new CarClassException();

    this->carclass = carclass;
}

string Car::getCarClass() const&
{
    return carclass;
}

bool Car::isRightCarClass() const
{   
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

    if (carclass == "A" || carclass == "B" || carclass == "C" || carclass == "D" || carclass == "E" 
        || carclass == "F" || carclass == "M" || carclass == "N" || carclass == "J")
    {
        return true;
    }
    else return false;
}

void Car::show() const
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
    cout << "\nCar class: " << carclass << endl;
}

string Car::type() const
{
    return "Car";
}

string Car::toString() const
{
    return type() + "+" + name + "+" + model + "+" + typeofveh + "+" + gearbox + "+"
        + color + "+" + to_string(price) + "+" + to_string(maxspeed) + "+" + to_string(productionyear) + "+" + carclass + "+";
}

void Car::save(ofstream& file)
{
    file << toString() << endl;
}

void Car::load(string tmp)
{
    // ifstream& file || string tmp

    /*
    name = "Renault";
    model = "Fluence";
    typeofveh = "Sedan";
    gearbox = "Automatic transmission";
    color = "Black";
    price = 750'000;
    maxspeed = 270;
    productionyear = 2015;
    carclass = "C";

    return type() + "+" + name + "+" + model + "+" + typeofveh + "+" + gearbox + "+"
        + color + "+" + to_string(price) + "+" + to_string(maxspeed) + "+" + to_string(productionyear) + "+" + carclass;
    */
    //tmp = Car+Renault+Fluence+Sedan+Automatic transmission+Black+750000+270+2015+C+

    tmp.erase(0, tmp.find("+") + 1); //Удалили тайп

    name = tmp.substr(0, tmp.find("+") + 1); //Подбираем слово и тут же удаляем его, идём далее до конца строки
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
    tmp.clear(); //Забрали букву С и очистили
}
