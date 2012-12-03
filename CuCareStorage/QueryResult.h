#ifndef QUERYRESULT_H
#define QUERYRESULT_H

#include <string>
#include <vector>
#include <map>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;

class QueryResult
{
public:
    QueryResult(vector< vector <string>* >* pRows, map<int, string>* pColumns);
    ~QueryResult();

    string operator [](const unsigned int index) throw (string);

    void setRow(const unsigned int row) throw (string);
    bool nextRow();

    unsigned int numRows();
    unsigned int rowSize();

    string getColName(int index);

    vector<string> getWholeRow(const unsigned int row) throw (string);
private:
    vector< vector <string>* >* pRows;
    map<int, string>* pColNames;

    unsigned int currRow;
};

#endif // QUERYRESULT_H
