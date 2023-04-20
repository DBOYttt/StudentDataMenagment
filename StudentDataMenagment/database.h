#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <cstdio>
#include <chrono>
#include <thread>

using namespace std;

class database
{
public:
	void saveinformation(int& inf, string& inf2, string& inf3, int& inf4);
	int lastid(int _id);
	int findstudent(int & search_id);

	vector<vector<string>> readData(string fileName);
	void writeData(string fileName, vector<vector<string>> data);
	void deleteStudent(string fileName, string id);

	void fileEdit(string filename, string Name, string Surname, int age, int id);
	void list(string file);
	void findPersonByName(string name, string filename);
};

