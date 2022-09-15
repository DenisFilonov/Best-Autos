#include "System.h"

System::System()
{
}

System::~System()
{
	for (Client* ptr: clientbase)
	{
		ptr->~Client();
	}

	for (Staff* ptr: staffbase)
	{
		ptr->~Staff();
	}
}

void System::addClient(Client* obj)
{
	clientbase.push_back(obj);
}

void System::addStaff(Staff* obj)
{
	staffbase.push_back(obj);
}

void System::delClient(string name)
{
    int check = 0;
    for (cl = clientbase.begin(); cl != clientbase.end(); cl++)
    {
        list<Client*>::iterator del = cl;
        cl++;

        if ((*(del))->getName() == name)
        {
            clientbase.erase(del);
            check++;
        }
    }

    if (check == 0) cout << "\tThe client [" << name << "] wasn't found. Please, check the information you enter.\n";
    else cout << "\tThe client [" << name << "] was deleted succesfully.\n";
}

void System::delStaff(string name)
{
    int check = 0;
    for (st = staffbase.begin(); st != staffbase.end(); st++)
    {
        list<Staff*>::iterator del = st;
        st++;

        if ((*(del))->getName() == name)
        {
            staffbase.erase(del);
            check++;
        }
    }

    if (check == 0) cout << "\tThe worker [" << name << "] wasn't found. Please, check the information you enter.\n";
    else cout << "\tThe worker [" << name << "] was deleted succesfully.\n";
}

list<Staff*>::iterator System::findStaffByName(string name)
{
    for (st = staffbase.begin(); st != staffbase.end(); st++)
    {
        if ((*(st))->getName() == name)
        {
            break;
        }
    }
    return st;
}

list<Client*>::iterator System::findClientByName(string name)
{
    for (cl = clientbase.begin(); cl != clientbase.end(); cl++)
    {
        if ((*(cl))->getName() == name)
        {
            break;
        }
    }
    return cl;
}

void System::showClient(string name)
{
    cl = findClientByName(name);
    if (cl != clientbase.end())
    {
        (*(cl))->show();
    }
    else
    {
        cout << "\tThe client [" << name << "] wasn't found. Please, check the information you enter.\n";
    }
}

void System::showStaff(string name)
{
    st = findStaffByName(name);
    if (st != staffbase.end())
    {
        (*(st))->show();
    }
    else
    {
        cout << "\tThe worker [" << name << "] wasn't found. Please, check the information you enter.\n";
    }
}

void System::showAllClient()
{
    for (Client* ptr : clientbase)
    {
        ptr->show();
    }
}

void System::showAllStaff()
{
    for (Staff* ptr : staffbase)
    {
        ptr->show();
    }
}

void System::changeClientsInfo(string name)
{
    cl = findClientByName(name);
    if (cl != clientbase.end())
    {
        int menu;
        int val;
        int64_t ival;
        string s;
        cout << "\n\tMENU TO CHANGE CLIENT INFORMATION";
        do
        {
            cout << "\n1) Change name.";
            cout << "\n2) Change ID number.";
            cout << "\n3) Change phone number.";
            cout << "\n4) Change address.";
            cout << "\n5) Change e-mail.";
            cout << "\n6) Change sum of purchase.";
            cout << "\n7) Change amount of purchase.";
            cout << "\n8) Change all of this.";
            cout << "\n0. Turn back.\nChoice: ";
            cin >> menu;
            switch (menu)
            {
            case 1:
                cout << "\nInput name: ";
                cin.ignore();
                getline(cin, s);

                (*(cl))->setName(s);
                cout << "\tName changed succesfully.\n";
                break;

            case 2:
                cout << "\nInput ID number: ";
                cin >> ival;

                (*(cl))->setIdNumber(ival);
                cout << "\tID number changed succesfully.\n";
                break;

            case 3:
                cout << "\nInput phone number: ";
                cin.ignore();
                getline(cin, s);

                (*(cl))->setPhNumber(s);
                cout << "\tPhone number changed succesfully.\n";
                break;

            case 4:
                cout << "\nInput address: ";
                cin.ignore();
                getline(cin, s);

                (*(cl))->setAddress(s);
                cout << "\tAddress number changed succesfully.\n";
                break;

            case 5:
                cout << "\nInput e-mail: ";
                cin.ignore();
                getline(cin, s);

                (*(cl))->setEmail(s);
                cout << "\tE-mail number changed succesfully.\n";
                break;

            case 6:
                cout << "\nInput sum of purchase: ";
                cin >> ival;

                (*(cl))->setSumOfPurchase(ival);
                cout << "\tSum of purchase changed succesfully.\n";
                break;

            case 7:
                cout << "\nInput amount of purchase: ";
                cin >> val;

                (*(cl))->setAmountOfPurchase(val);
                cout << "\tAmount of purchase changed succesfully.\n";
                break;

            case 8:
                cout << "\nInput name: ";
                cin.ignore();
                getline(cin, s);
                (*(cl))->setName(s);

                cout << "Input ID number: ";
                cin >> ival;
                (*(cl))->setIdNumber(ival);

                cout << "Input phone number: ";
                cin.ignore();
                getline(cin, s);
                (*(cl))->setPhNumber(s);

                cout << "Input address: ";
                getline(cin, s);
                (*(cl))->setAddress(s);

                cout << "Input e-mail: ";
                getline(cin, s);
                (*(cl))->setEmail(s);

                cout << "Input sum of purchase: ";
                cin >> ival;
                (*(cl))->setSumOfPurchase(ival);

                cout << "Input amount of purchase: ";
                cin >> val;
                (*(cl))->setAmountOfPurchase(val);

                cout << "\tAll information changed succesfully.\n";
                break;


            default: if (menu > 8 || menu != 0 || menu < 0) cout << "\tWrong menu item selected.\n"; break;
            }

        } while (menu != 0);
    }
}

void System::changeStaffsInfo(string name)
{
    st = findStaffByName(name);
    if (st != staffbase.end())
    {
        int menu;
        int val;
        int64_t ival;
        string s;
        cout << "\n\tMENU TO CHANGE STAFF INFORMATION";
        do
        {
            cout << "\n1) Change name.";
            cout << "\n2) Change ID number.";
            cout << "\n3) Change position.";
            cout << "\n4) Change phone number.";
            cout << "\n5) Change address.";
            cout << "\n6) Change sum of purchase.";
            cout << "\n7) Change amount of purchase.";
            cout << "\n8) Change all of this.";
            cout << "\n0. Turn back.\nChoice: ";
            cin >> menu;
            switch (menu)
            {
            case 1:
                cout << "\nInput name: ";
                cin.ignore();
                getline(cin, s);

                (*(st))->setName(s);
                cout << "\tName changed succesfully.\n";
                break;

            case 2:
                cout << "\nInput ID number: ";
                cin >> ival;

                (*(st))->setIdNumber(ival);
                cout << "\tID number changed succesfully.\n";
                break;

            case 3:
                cout << "\nInput position: ";
                cin.ignore();
                getline(cin, s);

                (*(st))->setPosition(s);
                cout << "\tPosition changed succesfully.\n";
                break;

            case 4:
                cout << "\nInput phone number: ";
                cin.ignore();
                getline(cin, s);

                (*(st))->setPhNumber(s);
                cout << "\tPhone number changed succesfully.\n";
                break;

            case 5:
                cout << "\nInput address: ";
                cin.ignore();
                getline(cin, s);

                (*(st))->setAddress(s);
                cout << "\tAddress number changed succesfully.\n";
                break;

            case 6:
                cout << "\nInput sum of purchase: ";
                cin >> ival;

                (*(st))->setSumOfPurchase(ival);
                cout << "\tSum of purchase changed succesfully.\n";
                break;

            case 7:
                cout << "\nInput amount of purchase: ";
                cin >> val;

                (*(st))->setAmountOfPurchase(val);
                cout << "\tAmount of purchase changed succesfully.\n";
                break;

            case 8:
                cout << "\nInput name: ";
                cin.ignore();
                getline(cin, s);
                (*(st))->setName(s);

                cout << "Input ID number: ";
                cin >> ival;
                (*(st))->setIdNumber(ival);

                cout << "Input position: ";
                cin.ignore();
                getline(cin, s);

                (*(st))->setPosition(s);

                cout << "Input phone number: ";
                cin.ignore();
                getline(cin, s);
                (*(st))->setPhNumber(s);

                cout << "Input address: ";
                getline(cin, s);
                (*(st))->setAddress(s);

                cout << "Input sum of purchase: ";
                cin >> ival;
                (*(st))->setSumOfPurchase(ival);

                cout << "Input amount of purchase: ";
                cin >> val;
                (*(st))->setAmountOfPurchase(val);

                cout << "\tAll information changed succesfully.\n";
                break;


            default: if (menu > 8 || menu != 0 || menu < 0) cout << "\tWrong menu item selected.\n"; break;
            }

        } while (menu != 0);
    }
}

void System::saveSystem()
{
    ofstream fw("System.txt");
    if (fw.is_open())
    {
        for (Client* ptr : clientbase)
        {
            ptr->save(fw);
        }
        for (Staff* ptr : staffbase)
        {
            ptr->save(fw);
        }
        fw.close();
        cout << "\nAll information is saved succesfully!\n";
    }
    else
    {
        cout << "\n\tSome system error!\n";
    }
}

void System::loadSystem()
{
    ifstream fr("System.txt");
    Staff* stf = nullptr;
    Client* clt = nullptr;

    if (fr.is_open())
    {
        string tmp;
        while (!fr.eof())
        {
            getline(fr, tmp);

            if (tmp == "Staff")
            {
                stf = new Staff();
                stf->load(fr);
                staffbase.push_back(stf);
            }
            else if (tmp == "Client")
            {
                clt = new Client();
                clt->load(fr);
                clientbase.push_back(clt);
            }
        }
        fr.close();
        cout << "\nAll information is loaded succesfully!\n";
    }
    else
    {
        cout << "\n\tSome system error!\n";
    }
}
