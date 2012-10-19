#include <QtCore/QCoreApplication>
#include <iostream>
#include "Database.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    
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

    vector<vector<string>*>* results = NULL;
    db->query("SELECT * FROM example WHERE x > 5;", results);

    cout << "Queried the database.\n";

    cout << "Results of query:\n\n";
    for(unsigned int i=0;i<results->size();i++)
    {
        for(unsigned int j=0;j<results->at(i)->size();j++)
            cout << results->at(i)->at(j) << ", ";
        cout << "\n";
    }

    cout << "Done!";

    return a.exec();
}
