#include "Database.h"
#include <iostream>
#include "Tests.h"

void Tests::DatabaseExample()
{
    cout << "Hello, Server!\n";

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

    cout << "Done!";
}
