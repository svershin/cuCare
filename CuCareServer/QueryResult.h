#ifndef QUERYRESULT_H
#define QUERYRESULT_H

#include <string>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;

class QueryResult
{
public:
    QueryResult(vector< vector <string>* >* pRows);
    ~QueryResult();

    string operator [](const unsigned int index) throw (string);

    void setRow(const unsigned int row) throw (string);
    bool nextRow();

    unsigned int numRows();
    unsigned int rowSize();

    vector<string> getWholeRow(const unsigned int row) throw (string);
private:
    vector< vector <string>* >* pRows;

    unsigned int currRow;
};

#endif // QUERYRESULT_H
