#include "CovidDB.h"

vector<string> CovidDB::split(const string& str, char del){
    vector<string> result;
    // declaring temp string to store the curr "word" upto del
    string temp;
    for(char i : str){
        // If current char is not ',', then append it to the "word", otherwise you have completed the word, and start the next word
        if(i != del){
            temp += i;
        }else{
            result.push_back(temp);
            temp = "";
        }
    }
    // push the last substring after the last ',' to the result
    result.push_back(temp);
    return result;
}

int CovidDB::hash(string country) const{
    int sum = 0;
    for (int i = 1; i <= country.size(); i++) {
        sum += i * (int) country[i - 1];
    }
    sum = sum % tableSize;
    return sum;
}

void CovidDB::add(vector<vector<DataEntry>>& table, DataEntry& entry) {
    int index = hash(entry.getCountry());

    if(table[index].empty()){
        table[index].push_back(entry);
    }else {
        for (auto i: table[index]) {
            if (i.getCountry() == entry.getCountry()) {
                //^compares countries to find if there is already an entry of country

                int test = compareDates(i.getDate(), entry.getDate());

                if (test == -1) {
                    //second entry is newer
                    entry.setCases(i.getCases() + entry.getCases());
                    entry.setDeaths(i.getDeaths() + entry.getDeaths());
                    remove(i.getCountry()); //removes older entry
                    table[index].push_back(entry); //adds newer entry
                } else {
                    //second entry is older
                    i.setCases(i.getCases() + entry.getCases());
                    i.setDeaths(i.getDeaths() + entry.getDeaths());
                    //adds deaths and cases from older entry
                }
                return;
            }
        }
        table[index].push_back(entry); //first data entry of country
    }


}

int CovidDB::compareDates(const string& d1, const string& d2){
    vector<string> date1, date2;
    string s1, s2;

    date1 = split(d1, '/');
    date2 = split(d2, '/');

    int index = 2;
    while (index >= 0){
        s1 += date1[index];
        s2 += date2[index];
        index--;
    }

    if(s1 > s2){ //1 means first date is greater
        return 1;
    }else if(s1 < s2){ //-1 means second date is greater
        return -1;
    }
    return 0; //dates are the same
}


int CovidDB::get(const vector<vector<DataEntry>>& table, const string& country) {
    int index = hash(country);

    for (auto i: table[index]) {
        if (i.getCountry() == country) {
            i.printEntry();
            return 0;
        }
    }
    return -1;
}

void CovidDB::remove(vector<vector<DataEntry>>& table, const string& country) {
    int index = hash(country);

    for(int i = 0; i < table[index].size(); i++){
        if(table[index][i].getCountry() == country){
            table[index].erase(table[index].begin() + i);
        }
    }
}