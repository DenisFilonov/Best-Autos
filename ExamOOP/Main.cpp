#include"Dealership.h"
#include"System.h"

int main()
{
	cout << "\tStarting the application.\n";
	System BestAutos;
	BestAutos.loadSystem();

	Dealership* BA = new Dealership("The Best Autos");



	string s1 = "", s2 = "", s3 = "", s4 = "", s5 = "", s6 = "";
	float fval1 = 0.0, fval2 = 0.0;
	int ival1 = 0, ival2 = 0, ival3 = 0;
	int64_t val1 = 0, val2 = 0;


	int menu, menu1, menu2;
	string start;
	do
	{
		cout << "\n1. System operations.";
		cout << "\n2. Dealership operations.";
		cout << "\n0. Exit and save.\nChoise: ";
		cin >> menu;

		switch (menu)
		{
		case 1:
			do
			{
				cout << "\n\tMENU FOR WORKING WITH SYSTEM";
				cout << "\n1) Staff.";
				cout << "\n2) Clients.";
				cout << "\n0. Back to main menu.\nChoise: ";
				cin >> menu1;

				switch (menu1)
				{
				case 1:
					do
					{
						cout << "\n\tMENU FOR WORKING WITH STAFF";
						cout << "\n1) Add employee.";
						cout << "\n2) Delete employee.";
						cout << "\n3) Change employee's information.";
						cout << "\n4) Show current employee.";
						cout << "\n5) Show list of employees.";
						cout << "\n0. Back to previous menu.\nChoise: ";
						cin >> menu2;

						switch (menu2)
						{
						case 1:
							cout << "\nInput name: ";
							cin.ignore();
							getline(cin, s1);

							cout << "Input ID number: ";
							cin >> val1;

							cout << "Input phone number: ";
							cin.ignore();
							getline(cin, s2);

							cout << "Input address: ";
							getline(cin, s3);

							cout << "Input e-mail: ";
							getline(cin, s4);

							cout << "Input sum of purchase: ";
							cin >> val2;

							cout << "Input amount of purchase: ";
							cin >> ival2;
							try
							{
								BestAutos.addStaff(new Staff(s1, val1, s2, s3, s4, val2, ival2));
							}
							catch (AllExceptions* obj)
							{
								obj->showWhat();
							}
							break;

						case 2:
							cout << "\nInput name: ";
							cin.ignore();
							getline(cin, s1);

							BestAutos.delStaff(s1);
							break;

						case 3:
							cout << "\nInput name: ";
							cin.ignore();
							getline(cin, s1);

							BestAutos.changeStaffsInfo(s1);
							break;

						case 4:
							cout << "\nInput name: ";
							cin.ignore();
							getline(cin, s1);

							BestAutos.showStaff(s1);
							break;

						case 5:
							BestAutos.showAllStaff();
							break;

						default: if (menu2 > 5 || menu2 != 0 || menu2 < 0) cout << "\tWrong menu item selected.\n"; break;
						}
					} while (menu2 != 0);
					break;

				case 2:
					do
					{
						cout << "\n\tMENU FOR WORKING WITH CLIENTS";
						cout << "\n1) Add client.";
						cout << "\n2) Delete client.";
						cout << "\n3) Change client's information.";
						cout << "\n4) Show current client.";
						cout << "\n5) Show list of clients.";
						cout << "\n0. Back to previous menu.\nChoise: ";
						cin >> menu2;

						switch (menu2)
						{
						case 1:
							cout << "\nInput name: ";
							cin.ignore();
							getline(cin, s1);

							cout << "Input ID number: ";
							cin >> val1;

							cout << "Input phone number: ";
							cin.ignore();
							getline(cin, s2);

							cout << "Input address: ";
							getline(cin, s3);

							cout << "Input e-mail: ";
							getline(cin, s4);

							cout << "Input sum of purchase: ";
							cin >> val2;

							cout << "Input amount of purchase: ";
							cin >> ival1;
							try
							{
								BestAutos.addClient(new Client(s1, val1, s2, s3, s4, val2, ival1));
							}
							catch (AllExceptions* obj)
							{
								obj->showWhat();
							}
							break;

						case 2:
							cout << "\nInput name: ";
							cin.ignore();
							getline(cin, s1);

							BestAutos.delClient(s1);
							break;

						case 3:
							cout << "\nInput name: ";
							cin.ignore();
							getline(cin, s1);

							BestAutos.changeClientsInfo(s1);
							break;

						case 4:
							cout << "\nInput name: ";
							cin.ignore();
							getline(cin, s1);

							BestAutos.showClient(s1);
							break;

						case 5:
							BestAutos.showAllClient();
							break;

						default: if (menu2 > 5 || menu2 != 0 || menu2 < 0) cout << "\tWrong menu item selected.\n"; break;
						}
					} while (menu2 != 0);
					break;

				default: if (menu1 > 2 || menu1 != 0 || menu1 < 0) cout << "\tWrong menu item selected.\n"; break;
				}
			} while (menu1 != 0);
			break;

		case 2:
			cout << "Please, input department, which needed to load: ";
			cin >> start;

			BA->load(start); //Opole
			do
			{
				cout << "\n\tMENU FOR WORKING WITH DEALERSHIP";
				cout << "\n1) Add vehicles.";
				cout << "\n2) Delete vehicles.";
				cout << "\n3) Show all vehicles.";
				cout << "\n4) Sort by price up.";
				cout << "\n0. Back to main menu.\nChoise: ";
				cin >> menu1;

				switch (menu1)
				{
				case 1:
					do
					{
						cout << "\n\tMENU FOR ADDING VEHICLES";
						cout << "\n1) Add a car.";
						cout << "\n2) Add a minivan.";
						cout << "\n3) Add a lorry.";
						cout << "\n4) Add a motorcycle.";
						cout << "\n0. Back to main menu.\nChoise: ";
						cin >> menu2;

						switch (menu2)
						{
						case 1:
							cout << "\nInput name: ";
							cin.ignore();
							getline(cin, s1);

							cout << "Input model: ";
							getline(cin, s2);

							cout << "Input type of car: ";
							getline(cin, s3);

							cout << "Input gearbox: ";
							getline(cin, s4);

							cout << "Input color: ";
							getline(cin, s5);

							cout << "Input price: ";
							cin >> fval1;

							cout << "Input maximal speed: ";
							cin >> ival1;

							cout << "Input production year: ";
							cin >> ival2;

							cout << "Input car class: ";
							cin.ignore();
							getline(cin, s6);
							try
							{
								BA->add(new Car(s1, s2, s3, s4, s5, fval1, ival1, ival2, s6));
							}
							catch (AllExceptions* obj)
							{
								obj->showWhat();
							}
							break;

						case 2:
							cout << "\nInput name: ";
							cin.ignore();
							getline(cin, s1);

							cout << "Input model: ";
							getline(cin, s2);

							cout << "Input type of car: ";
							getline(cin, s3);

							cout << "Input gearbox: ";
							getline(cin, s4);

							cout << "Input color: ";
							getline(cin, s5);

							cout << "Input price: ";
							cin >> fval1;

							cout << "Input maximal speed: ";
							cin >> ival1;

							cout << "Input production year: ";
							cin >> ival2;

							cout << "Input car class: ";
							cin.ignore();
							getline(cin, s6);

							cout << "Input amount of seats: ";
							cin >> ival3;
							try
							{
								BA->add(new Minivan(s1, s2, s3, s4, s5, fval1, ival1, ival2, s6, ival3));
							}
							catch (AllExceptions* obj)
							{
								obj->showWhat();
							}
							break;

						case 3:
							cout << "\nInput name: ";
							cin.ignore();
							getline(cin, s1);

							cout << "Input model: ";
							getline(cin, s2);

							cout << "Input type of car: ";
							getline(cin, s3);

							cout << "Input gearbox: ";
							getline(cin, s4);

							cout << "Input color: ";
							getline(cin, s5);

							cout << "Input price: ";
							cin >> fval1;

							cout << "Input maximal speed: ";
							cin >> ival1;

							cout << "Input production year: ";
							cin >> ival2;

							cout << "Input car class: ";
							cin.ignore();
							getline(cin, s6);

							cout << "Input carrying weight: ";
							cin >> fval2;
							try
							{
								BA->add(new Lorry(s1, s2, s3, s4, s5, fval1, ival1, ival2, s6, fval2));
							}
							catch (AllExceptions* obj)
							{
								obj->showWhat();
							}
							break;

						case 4:
							cout << "\nInput name: ";
							cin.ignore();
							getline(cin, s1);

							cout << "Input model: ";
							getline(cin, s2);

							cout << "Input type of car: ";
							getline(cin, s3);

							cout << "Input gearbox: ";
							getline(cin, s4);

							cout << "Input color: ";
							getline(cin, s5);

							cout << "Input price: ";
							cin >> fval1;

							cout << "Input maximal speed: ";
							cin >> ival1;

							cout << "Input production year: ";
							cin >> ival2;

							cout << "Input amount of wheels: ";
							cin >> ival3;
							try
							{
								BA->add(new Motorcycle(s1, s2, s3, s4, s5, fval1, ival1, ival2, ival3));
							}
							catch (AllExceptions* obj)
							{
								obj->showWhat();
							}
							break;

						default: if (menu2 > 4 || menu2 != 0 || menu2 < 0) cout << "\tWrong menu item selected.\n"; break;
						}
					} while (menu2 != 0);
					break;

				case 2:
					cout << "\nInput car name: ";
					cin.ignore();
					getline(cin, s1);

					BA->del(s1);
					break;

				case 3:
					BA->show();
					break;

				case 4:
					BA->sort();
					break;

				default: if (menu1 > 4 || menu1 != 0 || menu1 < 0) cout << "\tWrong menu item selected.\n"; break;
				}
			} while (menu1 != 0);
			break;

		default: if (menu > 2 || menu != 0 || menu < 0) cout << "\tWrong menu item selected.\n"; break;
		}
	} while (menu != 0);

	BestAutos.saveSystem();
	BA->save(start);
	cout << "\tExiting the application.\n";
	return 0;
}