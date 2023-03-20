#include <iostream>
#include <string>
#include <vector>

using namespace std;

class MenuOptions {
public:
    void addOption(const std::string& option);
    void printOptions()const;
    int option();

    void getinformation(string& inf1, string& inf2, int& inf3);

    int search_id();
private:
    std::vector<std::string> options_;
};

