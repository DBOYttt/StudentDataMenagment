#include "database.h"

void database::saveinformation(int& inf, string& inf2, string& inf3, int& inf4)
{
    {
        if (inf == 0) {
            inf = 1;
        }

        ofstream file_obj;
        file_obj.open("Input.txt", ios::app);

        file_obj << inf << ";" << inf2 << ";" << inf3 << ";" << inf4 << "\n";

        file_obj.close();
    }
}

int database::lastid()
{

	int last_id = 0;
	string line;
	ifstream file("Input.txt");

	if (file.is_open())
	{
		while (getline(file, line))
		{
			// dzielimy wiersz na pola, korzystaj¹c z separatora ";"
			string id_str = line.substr(0, line.find(';'));
			int id = stoi(id_str);
			// jeœli ID jest wiêksze ni¿ poprzednie, to aktualizujemy wartoœæ last_id
			if (id > last_id)
			{
				last_id = id;
			}
			else
			{
				last_id = 0;
			}
		}
		file.close();

		return last_id;
	}

}

int database::findstudent(int & search_id)
{
	ifstream infile("input.txt");

	if (!infile.is_open()) {
		cout << "Nie mozna otworzyc pliku" << endl;
	}



	string line;
	while (getline(infile, line)) {
		
		string id_str = line.substr(0, line.find(';'));
		int id = stoi(id_str);

		if (id == search_id) {
			string firstName = line.substr(line.find(';') + 1, line.find_last_of(';') - line.find(';') - 7);
			string lastName = line.substr(line.find(';') + 9); //line.find_last_of(';') + 1
			string age_str = line.substr(line.find_last_of(';') + 1);//line.find_last_of(';') - 2, 2
			cout << "ID: " << id << endl;
			cout << "Imie: " << firstName << endl;
			cout << "Nazwisko: " << lastName << endl;
			cout << "Wiek: " << age_str << endl;
			break;
		}
	}

	infile.close();

	return 0;
}

vector<vector<string>> database::readData(string fileName)
{
	vector<vector<string>> data;
	ifstream file(fileName);
	string line;
	while (getline(file, line)) {
		vector<string> record;
		size_t pos = 0;
		string token;
		while ((pos = line.find(";")) != string::npos) {
			token = line.substr(0, pos);
			record.push_back(token);
			line.erase(0, pos + 1);
		}
		record.push_back(line);
		data.push_back(record);
	}
	file.close();
	return data;
}

void database::writeData(string fileName, vector<vector<string>> data)
{
		ofstream file(fileName);
		for (vector<string> record : data) {
			for (int i = 0; i < record.size() - 1; i++) {
				file << record[i] << ";";
			}
			file << record[record.size() - 1] << "\n";
		}
		file.close();
}

void database::deleteStudent(string fileName, string id)
{
	vector<vector<string>> data = readData(fileName);
		for (int i = 0; i < data.size(); i++) {
			if (data[i][0] == id) {
				data.erase(data.begin() + i);
				break;
			}
		}
		writeData(fileName, data);
}

