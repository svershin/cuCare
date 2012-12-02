#ifndef FACTORY_H
#define FACTORY_H

#include "../../CuCareModel/ModelFiles.h"
#include "../../CuCareModel/Property.h"
#include "../ObjectInterpreter/ObjectInterpreter.h"
#include "../../CuCareCommunications/Communications/ClientNetworkInterface.h"
#include <map>

class Warehouse;

using namespace std;

class Factory
{
public:
    Factory();

    ~Factory();

    // -1 for parentId indicates that you are passing an object which does not have a parent.
    int create(ModelObject *object, int parentId = -1);
    void modify(ModelObject *object);

    /* To filter by specific data members of an object:
     * Create an instance of the object (preferably on the stack, not the heap)
     * Set the data members to the values you would like to search for
     * Go through the property list and remove the ones that do not apply
     */
    list<int> pull(ModelObject *filteredObject, int parentId = -1);

    //A specialized pull for this complicated type of filter
    list<int> pullPatientsByFollowupStatus(ModelObject::FollowupStatus);

private:
    typedef int (Factory::*InstantiationFunction) (map<string, string> *properties, int uid);

    Warehouse *warehouse;
    ClientNetworkInterface cni;

    map<ModelObject::ObjectType, InstantiationFunction> instantiationMap;

    int propertyify(map<string, string> *properties, ModelObject *obj, int uid);
    int instantiateAdminAssistant(map<string, string> *properties, int uid);
    int instantiatePhysician(map<string, string> *properties, int uid);
    int instantiateSysAdmin(map<string, string> *properties, int uid);
    int instantiateConsultation(map<string, string> *properties, int uid);
    int instantiatePatient(map<string, string> *properties, int uid);
    int instantiateReferral(map<string, string> *properties, int uid);
    int instantiateMedicationRenewal(map<string, string> *properties, int uid);
    int instantiateMedicalTest(map<string, string> *properties, int uid);
    int instantiateReturnConsultation(map<string, string> *properties, int uid);

};
#endif // FACTORY_H
