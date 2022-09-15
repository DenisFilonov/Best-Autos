#include "Staff.h"

Staff::Staff()
{
    name = "Denis Filonow";
    idnumber = 132645896;
    position = "Owner";
    phnumber = "+48 727 812 235";
    address = "Opole, Koszyka 5";
    sumofpurchase = 0;
    amountofpurchase = 0;
}

Staff::Staff(string name, int64_t idnumber, string position, string phnumber, string address, int64_t sumofpurchase, int amountofpurchase)
    : name(name), idnumber(idnumber), position(position), phnumber(phnumber), address(address)

{
    if (name.size() == 0) throw new NameException();
    if (idnumber == 0 || idnumber < 0) throw new IdNumberException;
    if (position.size() == 0) throw new PositionException();
    if (phnumber.size() == 0) throw new PhNumberException();
    if (address.size() == 0) throw new AddressException();
    if (amountofpurchase < 0) throw new PurchasesException();
    if (sumofpurchase < 0) throw new PurchasesException();
}

Staff::~Staff()
{
}

void Staff::setName(string name)
{
    if (name.size() == 0) throw new NameException();

    this->name = name;
}

void Staff::setIdNumber(int64_t idnumber)
{
    if (idnumber == 0 || idnumber < 0) throw new IdNumberException;

    this->idnumber = idnumber;
}

void Staff::setPosition(string position)
{
    if (position.size() == 0) throw new PositionException();

    this->position = position;
}

void Staff::setPhNumber(string phnumber)
{
    if (phnumber.size() == 0) throw new PhNumberException();

    this->phnumber = phnumber;
}

void Staff::setAddress(string address)
{
    if (address.size() == 0) throw new AddressException();

    this->address = address;
}

void Staff::setAmountOfPurchase(int amountofpurchase)
{
    if (amountofpurchase < 0) throw new PurchasesException();

    this->amountofpurchase = amountofpurchase;
}

void Staff::setSumOfPurchase(int sumofpurchase)
{
    if (sumofpurchase < 0) throw new PurchasesException();

    this->sumofpurchase = sumofpurchase;
}
string Staff::getName() const
{
    return name;
}

int64_t Staff::getIdNumber() const
{
    return idnumber;
}

string Staff::getPosition() const
{
    return position;
}

string Staff::getPhNumber() const
{
    return phnumber;
}

string Staff::getAddress() const
{
    return address;
}

int64_t Staff::getAmountOfPurchase() const
{
    return amountofpurchase;
}

int64_t Staff::getSumOfPurchase() const
{
    return sumofpurchase;
}

void Staff::show() const
{
    cout << "\n\tStaff's information: "
        << "\nName: " << name
        << "\nIdentification number: " << idnumber
        << "\nPosition: " << position
        << "\nPhone number: " << phnumber
        << "\nAddress: " << address
        << "\nSum of purchases: " << sumofpurchase
        << "\nAmount of purchases: " << amountofpurchase << endl;
}

void Staff::save(ofstream& file)
{
    file << name << endl << idnumber << endl << position << endl << phnumber << endl << address << endl << sumofpurchase << endl << amountofpurchase << endl;
}

void Staff::load(ifstream& file)
{
    getline(file, name);
    file >> idnumber;
    char a = file.get();
    getline(file, position);
    getline(file, phnumber);
    getline(file, address);

    file >> sumofpurchase;
    file >> amountofpurchase;
}
