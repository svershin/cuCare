#include "../CuCureStorage/Sqlite3Database.h"
#include "../CuCureStorage/Repository.h"
#include "../CuCareModel/Utility.h"
#include <iostream>
#include "Tests.h"

void Tests::databaseExample()
{
    Database * db = new Sqlite3Database();

    cout << "Created the database.\n";

    db->open();

    cout << "Opened the database.\n";

    db->command("CREATE TABLE example (x INTEGER PRIMARY KEY, y TEXT);");

    cout << "Created a table.\n";

    db->command("INSERT INTO example (x, y) VALUES ('5', 'Yellow');");
    db->command("INSERT INTO example (x, y) VALUES ('6', 'Red');");
    db->command("INSERT INTO example (x, y) VALUES ('7', 'Blue');");

    cout << "Inserted values.\n";

    QueryResult* pResults = NULL;
    db->query("SELECT * FROM example WHERE x > 5;", pResults);

    cout << "Queried the database.\n";

    cout << "Results of query:\n\n";

    do
    {
        for(unsigned int i = 0; i < pResults->rowSize(); i++)
            cout << (*pResults)[i];
        cout << "\n";
    }
    while (pResults->nextRow());

    cout << "Done!\n";
}

void Tests::repositoryTest()
{
    cout << "Starting test.\n";
    try
    {
        Repository* pRepo = new Repository();

        map<string, string> userparams;
        userparams["deleted"] = "0";
        userparams["userid"] = "1";
        userparams["username"] = "Guy1";
        userparams["firstname"] = "firstname";
        userparams["lastname"] = "lastname";
        userparams["country"] = "Canada";
        userparams["city"] = "ottawa";
        userparams["addresslineone"] = "1268 Cobden";
        userparams["addresslinetwo"] = "front door";
        userparams["postalcode"] = "k22 22k";
        userparams["workphone"] = "work phoen";
        userparams["cellphone"] = "cell pheon";
        userparams["email"] = "textemaildefaultnull";
        userparams["workemail"] = "theworkemail";
        userparams["birthday"] = "dayofbirth";
        userparams["birthmonth"] = "january";
        userparams["birthyear"] = "1659";
        userparams["objectType"] = "1";

        StorageObject test("USERS", "userid", userparams);
        int uid = 999;
        pRepo->create(test, uid);

        cout << "Creation finished.  Uid is: " << uid << endl;

        map<string, string> filter;
        filter["userid"] = Utility::itos(uid);

        StorageObject pullTest("USERS", "userid", filter);

        list<StorageObject> *pulled;
        pRepo->pull(pullTest,pulled);

        cout << "Pulled: " << pulled->size() << " objects." << endl;

        for(list<StorageObject>::iterator it = pulled->begin(); it != pulled->end(); ++it)
            for(map<string, string>::iterator mapit = (*it).getValues().begin(); (*it).getValues().end(); ++it)
                cout << mapit->first << " : " << mapit->second << endl;
    }
    catch (char const *err)
    {
        cout << err << endl;
    }
}

