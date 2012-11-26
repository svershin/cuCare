#include "QueryResult.h"
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

QueryResult::QueryResult(vector< vector <string>* >* pResults, map<int, string>* pColumns)
    : pRows(pResults),
      pColNames (pColumns),
      currRow(0)
{
}

QueryResult::~QueryResult()
{
    for(unsigned int i = 0; i < pRows->size(); i++)
        delete pRows->at(i);
    delete pRows;
    delete pColNames;
}

void QueryResult::setRow(const unsigned int row) throw (string)
{
    if(row < pRows->size())
        currRow = row;
    else
        throw "Row index out of bounds.";
}

bool QueryResult::nextRow()
{
    if(currRow + 1 < pRows->size())
    {
        currRow++;
        return true;
    }
    return false;
}

unsigned int QueryResult::numRows() { return pRows->size(); }
unsigned int QueryResult::rowSize() { return pRows->at(currRow)->size(); }

vector<string> QueryResult::getWholeRow(const unsigned int row) throw (string)
{
    if(row < pRows->size())
        return (*pRows->at(row));
    else
        throw "Row index out of bounds.";
}

string QueryResult::operator [](const unsigned int index) throw (string)
{
    if(index < pRows->at(currRow)->size())
        return pRows->at(currRow)->at(index);
    else
        throw "Row index out of bounds.";
}

string QueryResult::getColName(int index)
{
    return (*pColNames)[index];
}
