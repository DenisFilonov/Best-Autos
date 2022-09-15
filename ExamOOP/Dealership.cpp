#include "Dealership.h"

Dealership::Dealership()
{
    name = "The best Autos";
}

Dealership::Dealership(string name)
{
    if (name.size() == 0) throw new DealershipNameException();
    this->name = name;
}

Dealership::~Dealership()
{
    for (Vehicle* item : autoshow)
    {
        item->~Vehicle();
    }
}

void Dealership::show()
{
    cout << "\n\tList of cars in dealership:\n";

    for (p = autoshow.begin(); p != autoshow.end(); p++)
    {
        (*(p))->show();
    }
}

void Dealership::add(Vehicle* obj)
{
    autoshow.push_back(obj);
    cout << "\tThe vehicle [" << obj->getName() << "] was added succesfully.\n";
}

void Dealership::del(string name)
{
    int check = 0;
    for (p = autoshow.begin(); p != autoshow.end(); p++)
    {
        list<Vehicle*>::iterator del = p;
        p++;

        if ((*(del))->getName() == name)
        {
            autoshow.erase(del);
            check++;
        }
    }

    if (check == 0) cout << "\tThe vehicle [" << name << "] wasn't found. Please, check the information you enter.\n";
    else cout << "\tThe vehicle [" << name << "] was deleted succesfully.\n";
}

void Dealership::sort()
{
    CompareVeh obj;
    autoshow.sort(obj);
}

void Dealership::find(string name)
{
	p = findElementByName(name);

    if (p != autoshow.end())
    {
        (*(p))->show();
    }
    else
    {
        cout << "\tThe vehicle [" << name << "] wasn't found. Please, check the information you enter.\n";
    }
}

list<Vehicle*>::iterator Dealership::findElementByName(string name)
{
    for (p = autoshow.begin(); p != autoshow.end(); p++)
    {
        if ((*(p))->getName() == name)
        {
            break;
        }
    }
    return p;
}

void Dealership::changeInfo(string name)
{
	p = findElementByName(name);

	if (p != autoshow.end())
	{
		cout << "\n\tMENU FOR INFORMATION CHANGING";
		int menu;

		string s1 = "";
		int ival1 = 0;
		float fval1 = 0.0;
		//string name, string model, string typeofveh, string gearbox, string color, float price, int maxspeed, int productionyear
		if ((*(p))->type() == "Car")//string carclass
		{
			do 
			{
				cout << "\n1) Change name.";
				cout << "\n2) Change model.";
				cout << "\n3) Change type of car.";
				cout << "\n4) Change gearbox.";
				cout << "\n5) Change color.";
				cout << "\n6) Change price.";
				cout << "\n7) Change maximal speed.";
				cout << "\n8) Change production year.";
				cout << "\n9) Change car class.";
				cout << "\n10) Change all of this.";
				cout << "\n0. Turn back.\nChoice: ";
				cin >> menu;
				switch (menu)
				{
				case 1:
					cout << "\nInput name: ";
					cin.ignore();
					getline(cin, s1);

					(*(p))->setName(s1);
					cout << "\tName changed succesfully.\n";
					break;

				case 2:
					cout << "\nInput model: ";
					cin.ignore();
					getline(cin, s1);

					(*(p))->setModel(s1);
					cout << "\tModel changed succesfully.\n";
					break;

				case 3:
					cout << "\nInput type of car: ";
					cin.ignore();
					getline(cin, s1);

					(*(p))->setTypeOfVeh(s1);
					cout << "\tType of car changed succesfully.\n";
					break;

				case 4:
					cout << "\nInput gearbox: ";
					cin.ignore();
					getline(cin, s1);

					(*(p))->setGearBox(s1);
					cout << "\tGearbox changed succesfully.\n";
					break;

				case 5:
					cout << "\nInput color: ";
					cin.ignore();
					getline(cin, s1);

					(*(p))->setColor(s1);
					cout << "\tColor changed succesfully.\n";
					break;

				case 6:
					cout << "\nInput price: ";
					cin >> fval1;

					(*(p))->setPrice(fval1);
					cout << "\tPrice changed succesfully.\n";
					break;

				case 7:
					cout << "\nInput maximal speed: ";
					cin >> ival1;

					(*(p))->setMaxSpeed(ival1);
					cout << "\tMaximal speed changed succesfully.\n";
					break;

				case 8:
					cout << "\nInput production year: ";
					cin >> ival1;

					(*(p))->setProductionYear(ival1);
					cout << "\tProduction year changed succesfully.\n";
					break;

				case 9:
					cout << "\nInput car class: ";
					cin.ignore();
					getline(cin, s1);

					((Car*)*p)->setCarClass(s1);
					cout << "\tCar class changed succesfully.\n";
					break;

				case 10:
					cout << "\nInput name: ";
					cin.ignore();
					getline(cin, s1);
					(*(p))->setGearBox(s1);

					cout << "Input model: ";
					getline(cin, s1);
					(*(p))->setModel(s1);

					cout << "Input type of car: ";
					getline(cin, s1);
					(*(p))->setTypeOfVeh(s1);

					cout << "Input gearbox: ";
					getline(cin, s1);
					(*(p))->setGearBox(s1);

					cout << "Input color: ";
					getline(cin, s1);
					(*(p))->setColor(s1);

					cout << "Input price: ";
					cin >> fval1;
					(*(p))->setPrice(fval1);

					cout << "Input maximal speed: ";
					cin >> ival1;
					(*(p))->setMaxSpeed(ival1);

					cout << "Input production year: ";
					cin >> ival1;
					(*(p))->setProductionYear(ival1);

					cout << "Input car class: ";
					cin.ignore();
					getline(cin, s1);
					((Car*)*p)->setCarClass(s1);

					cout << "\tAll information changed succesfully.\n";
					break;

				default: if (menu > 10 || menu != 0 || menu < 0) cout << "\tWrong menu item selected.\n"; break;
				}
			} while (menu != 0);
		}
		else if ((*(p))->type() == "Minivan") //int amountofseats
		{
			do
			{
				cout << "\n1) Change name.";
				cout << "\n2) Change model.";
				cout << "\n3) Change type of minivan.";
				cout << "\n4) Change gearbox.";
				cout << "\n5) Change color.";
				cout << "\n6) Change price.";
				cout << "\n7) Change maximal speed.";
				cout << "\n8) Change production year.";
				cout << "\n9) Change car class.";
				cout << "\n10) Change amount of seats.";
				cout << "\n11) Change all of this.";
				cout << "\n0. Turn back.\nChoice: ";
				cin >> menu;
				switch (menu)
				{
				case 1:
					cout << "\nInput name: ";
					cin.ignore();
					getline(cin, s1);

					(*(p))->setName(s1);
					cout << "\tName changed succesfully.\n";
					break;

				case 2:
					cout << "\nInput model: ";
					cin.ignore();
					getline(cin, s1);

					(*(p))->setModel(s1);
					cout << "\tModel changed succesfully.\n";
					break;

				case 3:
					cout << "\nInput type of minivan, or type {NONE}: ";
					cin.ignore();
					getline(cin, s1);

					(*(p))->setTypeOfVeh(s1);
					cout << "\tType of car changed succesfully.\n";
					break;

				case 4:
					cout << "\nInput gearbox: ";
					cin.ignore();
					getline(cin, s1);

					(*(p))->setGearBox(s1);
					cout << "\tGearbox changed succesfully.\n";
					break;

				case 5:
					cout << "\nInput color: ";
					cin.ignore();
					getline(cin, s1);

					(*(p))->setColor(s1);
					cout << "\tColor changed succesfully.\n";
					break;

				case 6:
					cout << "\nInput price: ";
					cin >> fval1;

					(*(p))->setPrice(fval1);
					cout << "\tPrice changed succesfully.\n";
					break;

				case 7:
					cout << "\nInput maximal speed: ";
					cin >> ival1;

					(*(p))->setMaxSpeed(ival1);
					cout << "\tMaximal speed changed succesfully.\n";
					break;

				case 8:
					cout << "\nInput production year: ";
					cin >> ival1;

					(*(p))->setProductionYear(ival1);
					cout << "\tProduction year changed succesfully.\n";
					break;

				case 9:
					cout << "\nInput car class: ";
					cin.ignore();
					getline(cin, s1);

					((Minivan*)*p)->setCarClass(s1);
					cout << "\tCar class changed succesfully.\n";
					break;

				case 10:
					cout << "\nInput amount of seats: ";
					cin >> ival1;

					((Minivan*)*p)->setAmountOfSeats(ival1);
					cout << "\tAmount of seats year changed succesfully.\n";
					break;

				case 11:
					cout << "\nInput name: ";
					cin.ignore();
					getline(cin, s1);
					(*(p))->setName(s1);

					cout << "Input model: ";
					getline(cin, s1);
					(*(p))->setModel(s1);

					cout << "Input type of car: ";
					getline(cin, s1);
					(*(p))->setTypeOfVeh(s1);

					cout << "Input gearbox: ";
					getline(cin, s1);
					(*(p))->setGearBox(s1);

					cout << "Input color: ";
					getline(cin, s1);
					(*(p))->setColor(s1);

					cout << "Input price: ";
					cin >> fval1;
					(*(p))->setPrice(fval1);

					cout << "Input maximal speed: ";
					cin >> ival1;
					(*(p))->setMaxSpeed(ival1);

					cout << "Input production year: ";
					cin >> ival1;
					(*(p))->setProductionYear(ival1);

					cout << "Input car class: ";
					cin.ignore();
					getline(cin, s1);
					((Minivan*)*p)->setCarClass(s1);

					cout << "Input amount of seats: ";
					cin >> ival1;
					((Minivan*)*p)->setAmountOfSeats(ival1);

					cout << "\tAll information changed succesfully.\n";
					break;

				default: if (menu > 11 || menu != 0 || menu < 0) cout << "\tWrong menu item selected.\n"; break;
				}
			} while (menu != 0);
		}
		else if ((*(p))->type() == "Lorry") //float carryingweight
		{
			do
			{
				cout << "\n1) Change name.";
				cout << "\n2) Change model.";
				cout << "\n3) Change type of lorry.";
				cout << "\n4) Change gearbox.";
				cout << "\n5) Change color.";
				cout << "\n6) Change price.";
				cout << "\n7) Change maximal speed.";
				cout << "\n8) Change production year.";
				cout << "\n9) Change car class.";
				cout << "\n10) Change carrying weight.";
				cout << "\n11) Change all of this.";
				cout << "\n0. Turn back.\nChoice: ";
				cin >> menu;
				switch (menu)
				{
				case 1:
					cout << "\nInput name: ";
					cin.ignore();
					getline(cin, s1);

					(*(p))->setName(s1);
					cout << "\tName changed succesfully.\n";
					break;

				case 2:
					cout << "\nInput model: ";
					cin.ignore();
					getline(cin, s1);

					(*(p))->setModel(s1);
					cout << "\tModel changed succesfully.\n";
					break;

				case 3:
					cout << "\nInput type of lorry, or type {NONE}: ";
					cin.ignore();
					getline(cin, s1);

					(*(p))->setTypeOfVeh(s1);
					cout << "\tType of car changed succesfully.\n";
					break;

				case 4:
					cout << "\nInput gearbox: ";
					cin.ignore();
					getline(cin, s1);

					(*(p))->setGearBox(s1);
					cout << "\tGearbox changed succesfully.\n";
					break;

				case 5:
					cout << "\nInput color: ";
					cin.ignore();
					getline(cin, s1);

					(*(p))->setColor(s1);
					cout << "\tColor changed succesfully.\n";
					break;

				case 6:
					cout << "\nInput price: ";
					cin >> fval1;

					(*(p))->setPrice(fval1);
					cout << "\tPrice changed succesfully.\n";
					break;

				case 7:
					cout << "\nInput maximal speed: ";
					cin >> ival1;

					(*(p))->setMaxSpeed(ival1);
					cout << "\tMaximal speed changed succesfully.\n";
					break;

				case 8:
					cout << "\nInput production year: ";
					cin >> ival1;

					(*(p))->setProductionYear(ival1);
					cout << "\tProduction year changed succesfully.\n";
					break;

				case 9:
					cout << "\nInput car class: ";
					cin.ignore();
					getline(cin, s1);

					((Lorry*)*p)->setCarClass(s1);
					cout << "\tCar class changed succesfully.\n";
					break;

				case 10:
					cout << "\nInput carrying weight: ";
					cin >> fval1;

					((Lorry*)*p)->setCarryingWeight(fval1);
					cout << "\tCarrying weight of seats year changed succesfully.\n";
					break;

				case 11:
					cout << "\nInput name: ";
					cin.ignore();
					getline(cin, s1);
					(*(p))->setName(s1);


					cout << "Input model: ";
					getline(cin, s1);
					(*(p))->setModel(s1);

					cout << "Input type of lorry, or type {NONE}: ";
					getline(cin, s1);
					(*(p))->setTypeOfVeh(s1);

					cout << "Input gearbox: ";
					getline(cin, s1);
					(*(p))->setGearBox(s1);

					cout << "Input color: ";
					getline(cin, s1);
					(*(p))->setColor(s1);

					cout << "Input price: ";
					cin >> fval1;
					(*(p))->setPrice(fval1);

					cout << "Input maximal speed: ";
					cin >> ival1;
					(*(p))->setMaxSpeed(ival1);

					cout << "Input production year: ";
					cin >> ival1;
					(*(p))->setProductionYear(ival1);

					cout << "Input car class: ";
					cin.ignore();
					getline(cin, s1);
					((Lorry*)*p)->setCarClass(s1);

					cout << "Input carrying weight: ";
					cin >> fval1;
					((Lorry*)*p)->setCarryingWeight(fval1);

					cout << "\tAll information changed succesfully.\n";
					break;

				default: if (menu > 11 || menu != 0 || menu < 0) cout << "\tWrong menu item selected.\n"; break;
				}
			} while (menu != 0);
		}
		else if ((*(p))->type() == "Motorcycle") //int amountofwheels
		{
			do //string name, string model, string typeofveh, string gearbox, string color, float price, int maxspeed, int productionyear, string carclass
			{
				cout << "\n1) Change name.";
				cout << "\n2) Change model.";
				cout << "\n3) Change type of motorcycle.";
				cout << "\n4) Change gearbox.";
				cout << "\n5) Change color.";
				cout << "\n6) Change price.";
				cout << "\n7) Change maximal speed.";
				cout << "\n8) Change production year.";
				cout << "\n9) Change amount of wheels.";
				cout << "\n10) Change all of this.";
				cout << "\n0. Turn back.\nChoice: ";
				cin >> menu;
				switch (menu)
				{
				case 1:
					cout << "\nInput name: ";
					cin.ignore();
					getline(cin, s1);

					(*(p))->setName(s1);
					cout << "\tName changed succesfully.\n";
					break;

				case 2:
					cout << "\nInput model: ";
					cin.ignore();
					getline(cin, s1);

					(*(p))->setModel(s1);
					cout << "\tModel changed succesfully.\n";
					break;

				case 3:
					cout << "\nInput type of motorcycle, or type {NONE}: ";
					cin.ignore();
					getline(cin, s1);

					(*(p))->setTypeOfVeh(s1);
					cout << "\tType of car changed succesfully.\n";
					break;

				case 4:
					cout << "\nInput gearbox: ";
					cin.ignore();
					getline(cin, s1);

					(*(p))->setGearBox(s1);
					cout << "\tGearbox changed succesfully.\n";
					break;

				case 5:
					cout << "\nInput color: ";
					cin.ignore();
					getline(cin, s1);

					(*(p))->setColor(s1);
					cout << "\tColor changed succesfully.\n";
					break;

				case 6:
					cout << "\nInput price: ";
					cin >> fval1;

					(*(p))->setPrice(fval1);
					cout << "\tPrice changed succesfully.\n";
					break;

				case 7:
					cout << "\nInput maximal speed: ";
					cin >> ival1;

					(*(p))->setMaxSpeed(ival1);
					cout << "\tMaximal speed changed succesfully.\n";
					break;

				case 8:
					cout << "\nInput production year: ";
					cin >> ival1;

					(*(p))->setProductionYear(ival1);
					cout << "\tProduction year changed succesfully.\n";
					break;

				case 9:
					cout << "\nInput amount of wheels: ";
					cin >> ival1;

					((Motorcycle*)*p)->setAmountofwheels(ival1);
					cout << "\tAmount of wheels changed succesfully.\n";
					break;

				case 10:
					cout << "\nInput name: ";
					cin.ignore();
					getline(cin, s1);
					(*(p))->setName(s1);

					cout << "Input model: ";
					getline(cin, s1);
					(*(p))->setModel(s1);

					cout << "Input type of motorcycle, or type {NONE}: ";
					getline(cin, s1);
					(*(p))->setTypeOfVeh(s1);

					cout << "Input gearbox: ";
					getline(cin, s1);
					(*(p))->setGearBox(s1);

					cout << "Input color: ";
					getline(cin, s1);
					(*(p))->setColor(s1);

					cout << "Input price: ";
					cin >> fval1;
					(*(p))->setPrice(fval1);

					cout << "Input maximal speed: ";
					cin >> ival1;
					(*(p))->setMaxSpeed(ival1);

					cout << "Input production year: ";
					cin >> ival1;
					(*(p))->setProductionYear(ival1);

					cout << "Input amount of wheels: ";
					cin >> ival1;
					((Motorcycle*)*p)->setAmountofwheels(ival1);

					cout << "\tAll information changed succesfully.\n";
					break;

				default: if (menu > 10 || menu != 0 || menu < 0) cout << "\tWrong menu item selected.\n"; break;
				}
			} while (menu != 0);
		}
	}
	else
	{
		cout << "\tThe vehicle [" << name << "] wasn't found. Please, check the information you enter.\n";
	}
}

void Dealership::showByType(string type)
{
    for (p = autoshow.begin(); p != autoshow.end(); p++)
    {
        if ((*(p))->getName() == type)
        {
            (*(p))->show();
        }
    }
}

void Dealership::save(string name)
{
    ofstream fw(name + ".txt");
    if (fw.is_open())
    {
        for (Vehicle* item : autoshow)
        {
            item->save(fw);
        }
        fw.close();
        cout << "\nAll information is saved succesfully!\n";
    }
    else
    {
        cout << "\n\tSome error!\n";
    }
}

void Dealership::load(string name)
{
	ifstream fr(name + ".txt");
	Vehicle* ptr = nullptr;

	if (fr.is_open())
	{
		string p;
		while (!fr.eof())
		{
			getline(fr, p);

			if (p.substr(0, p.find("+")) == "Car")
			{
				ptr = new Car();
				//((Car*)ptr)->load(p);
				ptr->load(p);
				add(ptr);
			}
			else if (p.substr(0, p.find("+")) == "Minivan")
			{
				ptr = new Minivan();
				//((Minivan*)ptr)->load(p);
				ptr->load(p);
				add(ptr);
			}
			else if (p.substr(0, p.find("+")) == "Lorry")
			{
				ptr = new Lorry();
				//((Lorry*)ptr)->load(p);
				ptr->load(p);
				add(ptr);
			}
			else if (p.substr(0, p.find("+")) == "Motorcycle")
			{
				ptr = new Motorcycle();
				//((Motorcycle*)ptr)->load(p);
				ptr->load(p);
				add(ptr);
			}
		}
		fr.close();
		cout << "\nAll information is loaded succesfully!\n";
	}
	else
	{
		cout << "\n\tSome error!\n";
	}
}