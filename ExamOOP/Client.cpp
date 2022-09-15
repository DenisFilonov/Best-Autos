#include "Client.h"

Client::Client()
{
    name = "Denis Filonow";
    idnumber = 132645896;
    phnumber = "+48 727 812 235";
    address = "Opole, Koszyka 5";
    email = "denis.filonov@example.com";
    sumofpurchase = 0;
    amountofpurchase = 0;
}

Client::Client(string name, int64_t idnumber, string phnumber, string address, string email, int64_t sumofpurchase, int amountofpurchase)
    : name(name), idnumber(idnumber), phnumber(phnumber), address(address), email(email)
{
    if (name.size() == 0) throw new NameException();
    if (idnumber == 0 || idnumber < 0) throw new IdNumberException;
    if (phnumber.size() == 0) throw new PhNumberException();
    if (address.size() == 0) throw new AddressException();
    if (email.size() == 0) throw new EmailException();
    if (amountofpurchase < 0) throw new PurchasesException();
    if (sumofpurchase < 0) throw new PurchasesException();
}

Client::~Client()
{
}

void Client::setName(string name)
{
    if (name.size() == 0) throw new NameException();

    this->name = name;
}

void Client::setIdNumber(int64_t idnumber)
{
    if (idnumber == 0 || idnumber < 0) throw new IdNumberException;

    this->idnumber = idnumber;
}

void Client::setPhNumber(string phnumber)
{
    if (phnumber.size() == 0) throw new PhNumberException();
    
    this->phnumber = phnumber;
}

void Client::setAddress(string address)
{
    if (address.size() == 0) throw new AddressException();
    
    this->address = address;
}

void Client::setEmail(string email)
{
    if (email.size() == 0) throw new EmailException();
    
    this->email = email;
}

void Client::setAmountOfPurchase(int amountofpurchase)
{
    if (amountofpurchase < 0) throw new PurchasesException();

    this->amountofpurchase = amountofpurchase;
}

void Client::setSumOfPurchase(int sumofpurchase)
{
    if (sumofpurchase < 0) throw new PurchasesException();
    
    this->sumofpurchase = sumofpurchase;
}

string Client::getName() const
{
    return name;
}

int64_t Client::getIdNumber() const
{
    return idnumber;
}

string Client::getPhNumber() const
{
    return phnumber;
}

string Client::getAddress() const
{
    return address;
}

string Client::getEmail() const
{
    return email;
}

int64_t Client::getAmountOfPurchase() const
{
    return amountofpurchase;
}

int64_t Client::getSumOfPurchase() const
{
    return sumofpurchase;
}

void Client::show() const
{
    cout << "\n\tClient's information: "
        << "\nName: " << name
        << "\nIdentification number: " << idnumber
        << "\nPhone number: " << phnumber
        << "\nAddress: " << address        
        << "\nE-mail: " << email
        << "\nSum of purchases: " << sumofpurchase
        << "\nAmount of purchases: " << amountofpurchase << endl;

}

void Client::save(ofstream& file)
{
    file << name << endl << idnumber << endl << phnumber << endl << address << endl << email << endl << sumofpurchase << endl << amountofpurchase << endl;
}

void Client::load(ifstream& file)
{
    getline(file, name);
    file >> idnumber;
    char a = file.get();
    getline(file, phnumber);
    getline(file, address);
    getline(file, email);

    file >> sumofpurchase;
    file >> amountofpurchase;
}
