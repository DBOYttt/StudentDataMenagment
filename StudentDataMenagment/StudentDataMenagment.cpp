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
	int _id;
	int age;
	int option;
	string id_str;

	fstream plik("c:\\tmp\\Input.txt");

	//adding menu options
	menu.addOption("1. Dodaj Studenta");
	menu.addOption("2. Usun Studenta");
	menu.addOption("3. aktualizuj Studenta");
	menu.addOption("4. wyszukaj Studenta");
	menu.addOption("5. wyszukaj Studenta po Imieniu");
	menu.addOption("6. lista studentow");
	menu.addOption("0. wylancz program");

	while (true) {

		//print menu options
		menu.printOptions();
		//take from user option numebr
		option = menu.option();

		switch (option)
		{
			case 1:
				_id = s.getID();
				ID = db.lastid(_id);

				menu.getinformation(firstName, lastName, age);
				db.saveinformation(++ID, firstName, lastName, age);
				break;
			case 2:
				ID = menu.get_id();
				id_str = menu.convid(ID);
				db.deleteStudent("c:\\tmp\\Input.txt", id_str);
				break;
			case 3:
				ID = s.getID();
				age = s.getage();
				firstName = s.getfirstName();
				lastName = s.getlastName();
				db.fileEdit("c:\\tmp\\Input.txt",firstName,lastName,age,ID);
				break;
			case 4:
				ID = menu.get_id();
				db.findstudent(ID);
				break;
			case 5:
				cout << "Wpisz imie studenta" << endl;
				cin >> firstName;
				db.findPersonByName(firstName, "c:\\tmp\\Input.txt");
				break;
			case 6:
				db.list("c:\\tmp\\Input.txt");
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


