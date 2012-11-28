#include "ServerController.h"
#include "iostream"
#include <QtCore>

using namespace std;


/*
  DESTRUCTOR
  */
//
ServerController::~ServerController()
{
    haveInstance = false;
}



/*
  MAKE INSTANCE
  Purpose:
    Instantiates the Singleton ServerController object.

  Return value:
    If creation was successful, true is returned. If an instance of ServerController already existed, false is returned.

  IMPORTANT NOTE:
    timeString must be of format "h:mm:ss", and use 24-hour time. Example: use strings like "9:45:45" or "23:34:56".
    If in invalid timeString is encountered, a string exception will be thrown.
    */
//
bool ServerController::makeInstance(const string& timeString)
{
    if(haveInstance)
    {
        return false;
    }
    else
    {
        instance = new ServerController(timeString);
        haveInstance = true;
        return true;
    }
}



/*
  GET INSTANCE
    Purpose:
        Accesses the static instance of ServerController
    Return value:
        Pointer to the static instance of ServerController
    */
//
ServerController *ServerController::getInstance()
{
    if(haveInstance)
    {
        return instance;
    }
    else
    {
        throw(string("ServerController has not been instantiated"));
    }
}



/*
  CREATE
    Purpose:
        Create a new object in the database
    Return value:
        bool indicating whether or not the creation was successful
    Output parameters:
        pOutID will hold the ID of the newly created object
        pErrorString will hold an error message in the event of an unsuccessful create
    */
//
bool ServerController::create(string objectType, map<string, string> *pObjectMap, int *pOutID, string *pErrorString)
{
    try
    {
        if(repository.create(StorageObject(string("I don't know what this is"), string("stuff"), *pObjectMap), *pOutID))
        {
            return true;
        }
        else
        {
            throw(string("unkown error saving to storage"));
        }
    }
    catch(string errStr)
    {
        *pErrorString = errStr;
        return false;
    }
    catch(...)
    {
        *pErrorString = "an unkown error occurred";
        return false;
    }
}


/*
  PUSH
    Purpose:
        Push changes to an object to the database
    Return value:
        bool indicating whether or not the push was successful
    Output parameters:
        pErrorString will hold an error message in the event of an unsuccessful push
    */
//
bool ServerController::push(string objectType, map<string, string> *pObjectMap, string *pErrorString)
{
    try
    {
        if(repository.push(StorageObject(string("I don't know what this is"), string("stuff"), *pObjectMap)))
        {
            return true;
        }
        else
        {
            throw(string("unkown error saving to storage"));
        }
    }
    catch(string errStr)
    {
        *pErrorString = errStr;
        return false;
    }
    catch(...)
    {
        *pErrorString = "an unkown error occurred";
        return false;
    }
}



/*
  PULL
    Purpose:
        Pull data about objects from the database
    Return value:
        bool indicating whether or not the pull was successful
    Output parameters:
        pObjectList is a pointer to a list of map pointers. The maps are newed' inside this function. pObjectList is not.
        pErrorString will hold an error message in the event of an unsuccessful pull
    */
//
bool ServerController::pull(string objectType, map<string, string> *pObjectMap, list< map<string, string> *> *pObjectList, string *pErrorString)
{
    list<StorageObject> *pStorageObjectList = NULL;// confirm that Repository will be newing this stuff


    try
    {
        if(repository.pull(StorageObject(string("I don't know what this is"), string("stuff"), *pObjectMap), pStorageObjectList))
        {
            if(pObjectList == NULL) {throw(string("null list pointer returned on server"));}
            list<StorageObject>::iterator it = pStorageObjectList->begin();
            while(it != pStorageObjectList->end())
            {
                map<string, string> *tempPObjectMap = new map<string, string>();
                *tempPObjectMap = it->getValues();
                pObjectList->push_back(tempPObjectMap);
                it++;
            }

            delete pStorageObjectList;
            return true;
        }
        else
        {
            delete pStorageObjectList;
            throw(string("unkown error saving to storage"));
        }
    }
    catch(string errStr)
    {
        *pErrorString = errStr;
        return false;
    }
    catch(...)
    {
        *pErrorString = "an unkown error occurred";
        return false;
    }
    return true;
}



/*
  RUN AUDIT
    Purpose:
        Run the server's daily audit process - update overdue follow-ups in the database
    */
//
void ServerController::runAudit()
{
    repository.runAudit(1, 1, 1);
}


/*
  CONSTRUCTOR
    */
//
ServerController::ServerController(string timeOfDay)
    :
      ticker (AuditTimer(timeOfDay, this)),
      repository(Repository())
{}


/*
    Initialization of the static data members that deal with the Singleton nature of ServerController
    */
bool ServerController::haveInstance = false;

ServerController *ServerController::instance = NULL;
