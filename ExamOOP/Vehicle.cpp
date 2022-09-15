#include "Vehicle.h"

Vehicle::Vehicle()
{
    name = "Name";
    model = "Model";
    typeofveh = "Type of vehicle";
    gearbox = "Automatic transmission";
    color = "Color";
    price = 400'000;
    maxspeed = 270;
    productionyear = 2010;
}

Vehicle::Vehicle(string name, string model, string typeofveh, string gearbox, string color, long float price, int maxspeed, int productionyear)
    : name(name),model(model),typeofveh(typeofveh), gearbox(gearbox),color(color),price(price),maxspeed(maxspeed),productionyear(productionyear)
{
    if (name.size() == 0) throw new NameException();
    if (model.size() == 0) throw new ModelException();
    if (typeofveh.size() == 0) throw new TypeVehException();
    if (gearbox.size() == 0) throw new GearboxException();
    if (color.size() == 0) throw new ColorException();

    if (price == 0 || price < 0) throw new PriceException();
    if (maxspeed < 50 || maxspeed < 0) throw new MaxSpeedException();
    if (productionyear < 1900 || productionyear > 2999) throw new ProdYearException();
}

Vehicle::Vehicle(const Vehicle& obj)
{
    this->name = obj.name;
    this->model = obj.model;
    this->typeofveh = obj.typeofveh;
    this->gearbox = obj.gearbox;
    this->color = obj.color;
    this->price = obj.price;
    this->maxspeed = obj.maxspeed;
    this->productionyear = obj.productionyear;
}

Vehicle::~Vehicle()
{
}

Vehicle& Vehicle::operator=(const Vehicle& obj)
{
    this->name = obj.name;
    this->model = obj.model;
    this->typeofveh = obj.typeofveh;
    this->gearbox = obj.gearbox;
    this->color = obj.color;
    this->price = obj.price;
    this->maxspeed = obj.maxspeed;
    this->productionyear = obj.productionyear;
    return *this;
}

void Vehicle::setName(string name)
{
    if (name.size() == 0) throw new NameException();
    this->name = name;
}

void Vehicle::setModel(string model)
{
    if (model.size() == 0) throw new ModelException();
    this->model = model;
}

void Vehicle::setTypeOfVeh(string typeofveh)
{
    if (typeofveh.size() == 0) throw new TypeVehException();

    if (IsCorrectTypeOfVeh())
    {
        this->typeofveh = typeofveh;
    }
    else
    {
        cout << "\nUndefinied type of car! Please, check the input data.";
        typesOfTransport();
    }
}

void Vehicle::setGearBox(string gearbox)
{
    if (gearbox.size() == 0) throw new GearboxException();

    if (IsCorrectTypeOfTransmission())
    {
        this->gearbox = gearbox;
    }
    else
    {
        cout << "\nUndefinied type of transmission! Please, check the input data.";
        gearBoxes();
    }
}

void Vehicle::setColor(string color)
{
    if (color.size() == 0) throw new ColorException();

    this->color = color;
}

void Vehicle::setPrice(float price)
{
    if (price == 0 || price < 0) throw new PriceException();
 
    this->price = price;
}

void Vehicle::setMaxSpeed(int maxspeed)
{
    if (maxspeed < 50 || maxspeed < 0) throw new MaxSpeedException();

    this->maxspeed = maxspeed;
}

void Vehicle::setProductionYear(int productionyear)
{
    if (productionyear < 1900 || productionyear > 2999) throw new ProdYearException();

    this->productionyear = productionyear;
}

string Vehicle::getName() const&
{
    return name;
}

string Vehicle::getModel() const&
{
    return model;
}

string Vehicle::getTypeOfVeh() const&
{
    return typeofveh;
}

string Vehicle::getGearBox() const&
{
    return gearbox;
}

string Vehicle::getColor() const&
{
    return color;
}

long float Vehicle::getPrice() const&
{
    return price;
}

int Vehicle::getMaxSpeed() const&
{
    return maxspeed;
}

int Vehicle::getProductionYear() const&
{
    return productionyear;
}

void Vehicle::gearBoxes() const
{
    cout << "\n\tExisting types of gearboxes:"
        << "\n1. Manual Transmission."
        << "\n2. Intelligent manual transmission(IMT)."
        << "\n3. Automated manual transmission(AMT)."
        << "\n4. Automatic transmission(AT)."
        << "\n5. Continuously variable transmission(CVT)."
        << "\n6. Semi - automatic transmission."
        << "\n7. Dual - clutch transmission."
        << "\n8. Sequential transmission.\n";
}

void Vehicle::typesOfTransport() const
{
    cout << "\n\tExisting types of cars:"
        << "\n1. Sedan."
        << "\n2. Universal."
        << "\n3. Hatchback."
        << "\n4. Minivan."
        << "\n5. Crossover."
        << "\n6. Coupe."
        << "\n7. Cabriolet."
        << "\n8. Pickup."
        << "\n9. Lorry.\n"
        << "\n10. Motorcycle.\n";
}

void Vehicle::save(ofstream& file)
{
    // empty
}

void Vehicle::load(string tmp)
{
    // empty
}

bool Vehicle::IsCorrectTypeOfTransmission() const&
{
    if (gearbox == "Manual transmission" || gearbox == "Intelligent manual transmission" || gearbox == "Automated manual" || gearbox == "Automatic transmission" ||
        gearbox == "Continuously variable transmission" || gearbox == "Semi-automatic transmission" || gearbox == "Dual-clutch transmission" || gearbox == "Sequential transmission")
    {
        return true;
    }

    else return false;
}

bool Vehicle::IsCorrectTypeOfVeh() const&
{
    if (typeofveh == "Sedan" || typeofveh == "Universal" || typeofveh == "Hatchback" || typeofveh == "Minivan" || typeofveh == "Crossover" || 
        typeofveh == "Coupe" || typeofveh == "Cabriolet" || typeofveh == "Pickup" || typeofveh == "Lorry" || typeofveh == "Motorcycle" || typeofveh == "NONE")
    {
        return true;
    }

    else return false;
}
