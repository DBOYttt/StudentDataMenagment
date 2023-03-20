#pragma once
#include <iostream>

using namespace std;
class Student
{
private:

	string _firstName;
	string _lastName;
	int _age;
	int _id;
public:
	Student();
	Student(string firstName, string lastName, int age, int id);
	void setStudent(string firstName, string lastName, int age, int id);

	string getfirstName();
	string getlastName();
	int getage();
	int getID();
	void printstudent();
};

