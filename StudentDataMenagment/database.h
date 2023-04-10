#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <cstdio>
using namespace std;

struct Osoba {
	int id;
	string imie;
	string nazwisko;
	int wiek;
};

class database
{
public:
	void saveinformation(int& inf, string& inf2, string& inf3, int& inf4);
	int lastid();
	int findstudent(int & search_id);

	vector<vector<string>> readData(string fileName);
	void writeData(string fileName, vector<vector<string>> data);
	void deleteStudent(string fileName, string id);
	void editStudent(fstream& plik, int id, Osoba osoba);
	Osoba wczytajOsobe(fstream& plik, int id);
};

