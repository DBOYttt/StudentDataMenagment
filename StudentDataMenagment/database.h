#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <cstdio>
using namespace std;

class database
{
public:
	void saveinformation(int& inf, string& inf2, string& inf3, int& inf4);
	int lastid();
	int findstudent(int & search_id);
};

