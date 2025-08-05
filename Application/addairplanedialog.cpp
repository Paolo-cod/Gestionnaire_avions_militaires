#include "addairplanedialog.h"
#include "ui_addairplanedialog.h"

AddAirplaneDialog::AddAirplaneDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddAirplaneDialog)
{
    ui->setupUi(this);
    setWindowTitle(QObject::tr("New airplane creation"));
}

AddAirplaneDialog::~AddAirplaneDialog()
{
    delete ui;
}

QString AddAirplaneDialog::getConstructor() const {
    return ui->lineEdit_constructorName->text();
}

QString AddAirplaneDialog::getName() const {
    return ui->lineEdit_Name->text();
}
