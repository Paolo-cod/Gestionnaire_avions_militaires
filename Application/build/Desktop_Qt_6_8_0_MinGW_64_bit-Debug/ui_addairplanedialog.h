/********************************************************************************
** Form generated from reading UI file 'addairplanedialog.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDAIRPLANEDIALOG_H
#define UI_ADDAIRPLANEDIALOG_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddAirplaneDialog
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label_Name;
    QLineEdit *lineEdit_Name;
    QLabel *label_constructorName;
    QLineEdit *lineEdit_constructorName;

    void setupUi(QDialog *AddAirplaneDialog)
    {
        if (AddAirplaneDialog->objectName().isEmpty())
            AddAirplaneDialog->setObjectName("AddAirplaneDialog");
        AddAirplaneDialog->resize(400, 300);
        buttonBox = new QDialogButtonBox(AddAirplaneDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);
        formLayoutWidget = new QWidget(AddAirplaneDialog);
        formLayoutWidget->setObjectName("formLayoutWidget");
        formLayoutWidget->setGeometry(QRect(40, 90, 353, 81));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName("formLayout");
        formLayout->setContentsMargins(0, 0, 0, 0);
        label_Name = new QLabel(formLayoutWidget);
        label_Name->setObjectName("label_Name");

        formLayout->setWidget(0, QFormLayout::LabelRole, label_Name);

        lineEdit_Name = new QLineEdit(formLayoutWidget);
        lineEdit_Name->setObjectName("lineEdit_Name");

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEdit_Name);

        label_constructorName = new QLabel(formLayoutWidget);
        label_constructorName->setObjectName("label_constructorName");

        formLayout->setWidget(1, QFormLayout::LabelRole, label_constructorName);

        lineEdit_constructorName = new QLineEdit(formLayoutWidget);
        lineEdit_constructorName->setObjectName("lineEdit_constructorName");

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEdit_constructorName);


        retranslateUi(AddAirplaneDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, AddAirplaneDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, AddAirplaneDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(AddAirplaneDialog);
    } // setupUi

    void retranslateUi(QDialog *AddAirplaneDialog)
    {
        AddAirplaneDialog->setWindowTitle(QCoreApplication::translate("AddAirplaneDialog", "Dialog", nullptr));
        label_Name->setText(QCoreApplication::translate("AddAirplaneDialog", "Enter airplane name : ", nullptr));
        label_constructorName->setText(QCoreApplication::translate("AddAirplaneDialog", "Enter ariplane manufacturer", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddAirplaneDialog: public Ui_AddAirplaneDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDAIRPLANEDIALOG_H
