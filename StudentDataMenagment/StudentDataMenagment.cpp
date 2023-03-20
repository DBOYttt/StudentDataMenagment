#include <iostream>
#include "Student.h"
#include "menu.h"
#include "database.h"

using namespace std;

int main()
{
    Student s;
	MenuOptions menu;
	database db;
	string firstName;
	string lastName;
	int ID;
	int age;
	int option;


	//adding menu options
	menu.addOption("1. Dodaj Studenta");
	menu.addOption("2. Usun Studenta");
	menu.addOption("3. aktualizuj Studenta");
	menu.addOption("4. wyszukaj Studenta");
	menu.addOption("0. wylancz program");

	while (true) {

		//print menu options
		menu.printOptions();
		//take from user option numebr
		option = menu.option();

		switch (option)
		{
			case 1:
				ID = db.lastid();
				menu.getinformation(firstName, lastName, age);
				db.saveinformation(++ID, firstName, lastName, age);
				break;
			case 2:
				cout << "gut" << endl;
				break;
			case 3:
				cout << "gut" << endl;
				break;
			case 4:
				ID = menu.search_id();
				db.findstudent(ID);
				break;
			case 0:
				return 0;
			default:
				cout << "Nieprawidlowa opcja." << endl;
				break;

		}
		cout << "Nacisnij Enter, aby wrocic do menu wyboru." << endl;
		cin.ignore();
		cin.get();
	}
	return 0;
}


