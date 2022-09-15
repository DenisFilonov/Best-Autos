#pragma once
#include"Client.h"
#include"Staff.h"
#include<list>

using namespace std;

class System
{
	list<Staff*> staffbase;
	list<Client*> clientbase;

	list<Staff*>::iterator st;
	list<Client*>::iterator cl;

public:
	System();
	~System();

	void addClient(Client* obj);
	void addStaff(Staff* obj);

	void delClient(string name);
	void delStaff(string name);

	/*void sort(bool(*cmp)(const Client*, const Client*))const&;
	void sort(bool(*cmp)(const Staff*, const Staff*))const&;*/

	list<Staff*>::iterator findStaffByName(string name);
	list<Client*>::iterator findClientByName(string name);

	void showClient(string name);
	void showStaff(string name);

	void showAllClient();
	void showAllStaff();

	void changeClientsInfo(string name);
	void changeStaffsInfo(string name);

	void saveSystem();
	void loadSystem();
};