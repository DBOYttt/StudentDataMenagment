#include "Student.h"

Student::Student()
{
	// Constructor
	_firstName = "";
	_lastName = "";
	_age = 0;
	_id = 0;
}

Student::Student(string firstName, string lastName, int age, int id)
{
	_firstName = firstName;
	_lastName = lastName;
	_age = age;
	_id = id;
}



void Student::setStudent(string firstName, string lastName, int age, int id)
{
	_firstName = firstName;
	_lastName = lastName;
	_age = age;
	_id = id;
}

string Student::getfirstName()
{
	return _firstName;
}

string Student::getlastName()
{
	return _lastName;
}

int Student::getage()
{
	return _age;
}

int Student::getID()
{
	return _id;
}

void Student::printstudent()
{
	cout << "ID : " << _id << endl;
	cout << "Name : " << _firstName << endl;
	cout << "lastname : " << _lastName << endl;
	cout << "age : " << _age << endl;
}
