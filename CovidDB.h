#ifndef ASSIGNMENT3_COVIDDB_H
#define ASSIGNMENT3_COVIDDB_H

#include "DataEntry.h"
#include <vector>
using namespace std;

class CovidDB {
private:
    int tableSize; //creates hashtable using separate chaining
    vector<vector<DataEntry>> v;

    [[nodiscard]] int hash(string country) const;
    static int compareDates(const string& d1, const string& d2);

    void add(vector<vector<DataEntry>>& table, DataEntry& entry);
    int get(const vector<vector<DataEntry>>& table, const string& country);
    void remove(vector<vector<DataEntry>>& table, const string& country);

public:
    explicit CovidDB(int m) {
        v = vector<vector<DataEntry>>(m);
        this->tableSize = m;
    }

    static vector<string> split(const string& str, char del);

    void add(DataEntry entry){
        add(v, entry);
    }

    DataEntry* get(const string& country){
        auto temp = get(v, country);
        if (temp == -1){
            cout << "Country is not in database" << endl;
            return nullptr;
        }
        return nullptr;
    }

    void remove(const string& country){
        remove(v, country);
    }

    void printTable(){
        for(int i = 0; i < v.size(); i++){
            cout << "\n" << i << " = ";
            for(auto j: v[i]){
                j.printEntry();
            }
        }
    }
};


#endif //ASSIGNMENT3_COVIDDB_H
