#include "Database.h"
#include "Repository.h"
#include <iostream>
#include "Tests.h"

void Tests::databaseExample()
{
    Database * db = new Database();

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
    Repository* pRepo = new Repository();
    AdminAssistant* newAA = new AdminAssistant("Im a test!",
                                               "Noodles",
                                               "Pasta",
                                               Date(12,
                                                    12,
                                                    2012),
                                               ContactInfo("613-256-6880",
                                                           "613-293-8843",
                                                           "ddenis@connect.carleton.ca",
                                                           "ddenis@gmail.com"),
                                               Address("Canada",
                                                       "Ottawa",
                                                       "1268 Cobden Road",
                                                       "nooooo",
                                                       "K2C 3A2"),
                                               false);
    try
    {
        if(pRepo->createAdminAssistant(newAA))
            cout << "Created successfully.\n";
    }

    UserFilter filter;
    filter.usernameSetMatch(true);
    vector<AdminAssistant *>* results = NULL;
    try
    {
        if(pRepo->pullAdminAssistant(newAA, filter, results))
            cout << "Pulled successfully.\n";

        cout << newAA->getUsername() << ", " <<
                newAA->getFirstName() << ", " <<
                newAA->getLastName() << ", " <<
                newAA->getDateOfBirth().getDay() << ", " <<
                newAA->getDateOfBirth().getMonth() << ", " <<
                newAA->getDateOfBirth().getYear() << ", " <<
                newAA->getContact().getWorkPhone() << ", " <<
                newAA->getContact().getCellPhone() << ", " <<
                newAA->getContact().getEmail() << ", " <<
                newAA->getContact().getWorkEmail() << ", " <<
                newAA->getAddress().getCountry() << ", " <<
                newAA->getAddress().getCity() << ", " <<
                newAA->getAddress().getLineOne() << ", " <<
                newAA->getAddress().getLineTwo() << ", " <<
                newAA->getAddress().getPostalCode() << ", " <<
                newAA->isDeleted() << "\n";
    }
    catch(const char * err)
    {
        cout << err << "\n";
    }

    newAA->setFirstName("NOT Noodles");

    if(pRepo->pushUser(newAA))
        cout << "Pushed successfully\n";
    else
        cout << pRepo->getDbErrorText() << "\n";

    try
    {
        if(pRepo->pullAdminAssistant(newAA, filter, results))
            cout << "Pulled successfully.\n";

        cout << newAA->getUsername() << ", " <<
                newAA->getFirstName() << ", " <<
                newAA->getLastName() << ", " <<
                newAA->getDateOfBirth().getDay() << ", " <<
                newAA->getDateOfBirth().getMonth() << ", " <<
                newAA->getDateOfBirth().getYear() << ", " <<
                newAA->getContact().getWorkPhone() << ", " <<
                newAA->getContact().getCellPhone() << ", " <<
                newAA->getContact().getEmail() << ", " <<
                newAA->getContact().getWorkEmail() << ", " <<
                newAA->getAddress().getCountry() << ", " <<
                newAA->getAddress().getCity() << ", " <<
                newAA->getAddress().getLineOne() << ", " <<
                newAA->getAddress().getLineTwo() << ", " <<
                newAA->getAddress().getPostalCode() << ", " <<
                newAA->isDeleted() << "\n";
    }
    catch(const char * err)
    {
        cout << err << "\n";
    }

    delete pRepo;
    cout << "Completion.\n";
}

