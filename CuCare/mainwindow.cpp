#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(MasterController *controllerParam, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    controller(controllerParam)
{
    ui->setupUi(this);

    //Disable UI elements for features not yet implemented
    ui->RunReportsPushButton->setEnabled(false);
    ui->CreateConsultationPushButton->setEnabled(false);

    //Initially, only the patient tab is displayed.
    ui->DisplayTabsWidget->setTabEnabled(1, false);
    ui->DisplayTabsWidget->setTabEnabled(2, false);

    //All of the elements of the patient tab are grayed out until one is
    //selected, or until a new one is to be created
    disablePatientEditing();

    ui->statusbar->showMessage("Welcome to CuCare v0.0.1");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_NewPatientPushButton_clicked()
{
    enablePatientEditing();
}

void MainWindow::on_SelectPatientPushButton_clicked()
{
    Patient *selectedPatient = NULL;
    PatientSelectDialog *patientWindow = new PatientSelectDialog(controller, selectedPatient);

    if (patientWindow->exec() == 1) {
        enablePatientEditing();
    }
}

void MainWindow::enablePatientEditing()
{
    ui->FirstNameLineEdit->setEnabled(true);
    ui->LastNameLineEdit->setEnabled(true);

    ui->WorkPhoneLineEdit->setEnabled(true);
    ui->CellPhoneLineEdit->setEnabled(true);
    ui->EmailLineEdit->setEnabled(true);
    ui->WorkEmailLineEdit->setEnabled(true);

    ui->Address1LineEdit->setEnabled(true);
    ui->Address2LineEdit->setEnabled(true);
    ui->CityLineEdit->setEnabled(true);
    ui->CountryLineEdit->setEnabled(true);
    ui->PostalCodeLineEdit->setEnabled(true);

    ui->DOBDateEdit->setEnabled(true);
    ui->AddedDateEdit->setEnabled(true);
    ui->CardNumberLineEdit->setEnabled(true);
    ui->CardExpirationDateEdit->setEnabled(true);

    ui->DeletePatientPushButton->setEnabled(true);
    ui->PatientNotesTextEdit->setEnabled(true);
}

void MainWindow::disablePatientEditing()
{
    ui->FirstNameLineEdit->setEnabled(false);
    ui->LastNameLineEdit->setEnabled(false);

    ui->WorkPhoneLineEdit->setEnabled(false);
    ui->CellPhoneLineEdit->setEnabled(false);
    ui->EmailLineEdit->setEnabled(false);
    ui->WorkEmailLineEdit->setEnabled(false);

    ui->Address1LineEdit->setEnabled(false);
    ui->Address2LineEdit->setEnabled(false);
    ui->CityLineEdit->setEnabled(false);
    ui->CountryLineEdit->setEnabled(false);
    ui->PostalCodeLineEdit->setEnabled(false);

    ui->DOBDateEdit->setEnabled(false);
    ui->AddedDateEdit->setEnabled(false);
    ui->CardNumberLineEdit->setEnabled(false);
    ui->CardExpirationDateEdit->setEnabled(false);

    ui->DeletePatientPushButton->setEnabled(false);
    ui->PatientNotesTextEdit->setEnabled(false);
}
