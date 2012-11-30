#ifndef REPOMODEL_H
#define REPOMODEL_H

#include "../../CuCareModel/ModelFiles.h"
#include "Database.h"
#include <sstream>

class RepoModel
{
public:
    RepoModel();

    string getAuditCommand();

    bool dbexists(Database db);
    void createDb(Database db);
};

#endif // REPOMODEL_H
