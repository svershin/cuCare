#ifndef REPOMODEL_H
#define REPOMODEL_H

#include "../CuCareModel/ModelFiles.h"
#include "Database.h"
#include <sstream>
#include <fstream>

class RepoModel
{
public:
    RepoModel();

    string getAuditCommand(int day, int month, int year);

    bool dbexists(Database *db);
    void createDb(Database *db);

private:
    string getUserTableCommand();
    string getFollowupTableCommand();
    string getConsultationTableCommand();
    string getPatientTableCommand();
};

#endif // REPOMODEL_H
