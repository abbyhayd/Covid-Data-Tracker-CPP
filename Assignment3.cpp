#include <fstream>
#include <iostream>
#include "CovidDB.h"
using namespace std;

int main(){
    int input = -1;

    string date, country;
    int deaths, cases;

    auto table = new CovidDB(17);

    ifstream myfile;
    myfile.open("WHO-COVID-Data-1.csv", ios::in);

    while(input != 0){
        cout << "\nCovid Tracker" << endl;
        cout << "Please choose the operation you want: " << endl;
        cout << "1. Create the initial hash table" << endl
            << "2. Add a new data entry" << endl
            << "3. Get a data entry" << endl
            << "4. Remove a data entry" << endl
            << "5. Display hash table" << endl
            << "0. Quit the system" << endl;

        cin >> input;

        switch(input) {
            case 1: {
                if (myfile.is_open())
                {
                    cout << "File found" << endl;
                    string line;

                    while (getline(myfile, line)) {

                        vector < string > result = CovidDB::split(line, ',');
                        DataEntry oneEntry = DataEntry(result[0], result[1], stoi(result[2]), stoi(result[3]));
                        table->add(oneEntry);

                    }

                    cout << "Table initiated!" << endl;
                } else {
                    cout << "File not found" << endl;
                    cout << "Table uninitiated :(" << endl;
                    return 0;
                }
                break;
            }
            case 2:
            {
                cout << "Enter the date (MM/DD/YYYY): ";
                cin >> date;
                cout << "Enter the country: ";
                cin.ignore();
                getline(cin, country);
                cout << "Enter the cases: ";
                cin >> cases;
                cout << "Enter the deaths: ";
                cin >> deaths;

                DataEntry temp = DataEntry(date, country, cases, deaths);
                table->add(temp);
                cout << "Entry created : " << "\n\t";
                temp.printEntry();
                table->add(temp);
                cout << "Entry added!" << endl;
                break;
            }
            case 3:
            {
                cout << "Enter the country: ";
                cin.ignore();
                getline(cin, country);
                table->get(country);
                break;
            }
            case 4:
            {
                cout << "Enter the country: ";
                cin.ignore();
                getline(cin, country);
                table->remove(country);
                cout << "Country removed!" << endl;
                break;
            }
            case 5:
            {
                table->printTable();
                break;
            }
            case 0:
            {
                cout << "Goodbye!" << endl;
            }
                break;
            default:
                break;
        }
    }
}