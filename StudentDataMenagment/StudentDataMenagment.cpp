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
	string id_str;
	Osoba osoba;

	fstream plik("Input.txt", ios::in | ios::out | ios::binary);

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
				ID = menu.get_id();
				id_str = menu.convid(ID);
				db.deleteStudent("Input.txt", id_str);
				break;
			case 3:
				ID = menu.get_id();
				osoba = db.wczytajOsobe(plik, ID);
				if (osoba.id == 0) {
					cout << "Nie znaleziono osoby o podanym ID." << endl;
					return 0;
				}
				cout << "Aktualne dane osoby o ID " << osoba.id << ":" << endl;
				cout << "Imie: " << osoba.imie << endl;
				cout << "Nazwisko: " << osoba.nazwisko << endl;
				cout << "Wiek: " << osoba.wiek << endl;
				cout << "Podaj nowe imie: ";
				cin >> osoba.imie;
				cout << "Podaj nowe nazwisko: ";
				cin >> osoba.nazwisko;
				cout << "Podaj nowy wiek: ";
				cin >> osoba.wiek;
				db.editStudent(plik, ID, osoba);
				plik.close();
				break;
			case 4:
				ID = menu.get_id();
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


