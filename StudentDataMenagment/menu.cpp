#include "menu.h"

void MenuOptions::addOption(const std::string& option)
{
     options_.push_back(option);    
}

void MenuOptions::printOptions() const {
 
    for (const auto& option : options_) {
        std::cout << option << '\n';
    }
}

int MenuOptions::option()
{
    int option;
    cin >> option;
    return option;
}

void MenuOptions::getinformation(string& inf1, string& inf2, int& inf3)
{

	cout << "firstName :" << endl;
	cin >> inf1;
	cout << "LastName :" << endl;
	cin >> inf2;
	cout << "age :" << endl;
	cin >> inf3;



}

int MenuOptions::search_id()
{
    int search_id;
    cout << "Podaj ID studenta do wyszukania: ";
    cin >> search_id;
    return search_id;
}
