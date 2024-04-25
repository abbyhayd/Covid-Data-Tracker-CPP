//
// Created by wolfi on 11/14/2023.
//

#ifndef ASSIGNMENT3_DATAENTRY_H
#define ASSIGNMENT3_DATAENTRY_H

#include <string>
#include <iostream>
#include <utility>
using namespace std;

class DataEntry {
private:
    string date;
    string country;
    int c_cases;
    int c_deaths;
public:
    DataEntry(){ //empty data entry
        c_cases = 0;
        c_deaths = 0;
    }
    DataEntry(string date, string country, int cases, int deaths){
        this->date = std::move(date);
        this->country = std::move(country);
        c_cases = cases;
        c_deaths = deaths;
    }

    void printEntry(){
        cout << "\tDate = " << this->getDate()
             << "\tCountry = " << this->getCountry()
             << "\tCases = " << this->getCases()
             << "\tDeaths = " << this->getDeaths() << endl;
    }

    string getCountry(){
        return country;
    }

    string getDate(){
        return date;
    }
    void setDate(basic_string<char> input){
        date = std::move(input);
    }


    [[nodiscard]] int getCases() const{
        return c_cases;
    }
    void setCases(int input){
        c_cases = input;
    }

    [[nodiscard]] int getDeaths() const{
        return c_deaths;
    }
    void setDeaths(int input){
        c_deaths = input;
    }
};


#endif //ASSIGNMENT3_DATAENTRY_H
