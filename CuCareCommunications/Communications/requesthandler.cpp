#include "requesthandler.h"

RequestHandler::RequestHandler()
    :pRepo (new Repository())
{
}

QByteArray RequestHandler::handleRequest(QVariantMap reqMap)
{
    ModelObject modelObject = MessageParser::qVariantMapToModelObject(reqMap.value("modelObject").toMap());
    int uid = 0;
    switch (reqMap.value("requestType").toInt())
    {
    case(Messenger::CREATE_ADMIN_ASSISTANT):
        pRepo->createAdminAssistant((AdminAssistant*)&modelObject);
        break;
    case(Messenger::CREATE_CONSULTATION):
        pRepo->createConsultation((Consultation*)&modelObject, reqMap.value("physicianId").toInt(), reqMap.value("patientId").toInt(), &uid);

    }
}

