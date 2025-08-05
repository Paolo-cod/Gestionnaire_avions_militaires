/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen_file;
    QAction *actionSave_file;
    QAction *actionSave_as;
    QAction *actionFiltrer;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_10;
    QHBoxLayout *horizontalLayout_7;
    QVBoxLayout *verticalLayout_11;
    QVBoxLayout *verticalLayout_10;
    QHBoxLayout *horizontalLayout_13;
    QVBoxLayout *verticalLayout_3;
    QComboBox *comboBox_filtrage;
    QLineEdit *lineEdit_recherche;
    QListWidget *listWidget_airplanesList;
    QHBoxLayout *horizontalLayout_15;
    QPushButton *pushButton_ouvrir;
    QPushButton *pushButton_sauvegarder;
    QHBoxLayout *horizontalLayout_16;
    QPushButton *pushButton_ajouter;
    QPushButton *pushButton_supprimer;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_9;
    QLabel *label_nickname;
    QLabel *label_constructor;
    QLabel *label_name;
    QLabel *label_maxSpeed;
    QLabel *label_qtyEngiens;
    QLabel *label;
    QLabel *label_commissioningDate;
    QLabel *label_crewMembers;
    QLabel *label_operationalCeiling;
    QVBoxLayout *verticalLayout_6;
    QLineEdit *lineEdit_nickname;
    QLineEdit *lineEdit_constructor;
    QLineEdit *lineEdit_name;
    QLineEdit *lineEdit_maxSpeed;
    QSpinBox *spinBox;
    QLineEdit *lineEdit_engienType;
    QDateEdit *dateEdit_commissioningDate;
    QLineEdit *lineEdit_crewMembers;
    QLineEdit *lineEdit_operationalCeiling;
    QHBoxLayout *horizontalLayout_6;
    QGroupBox *groupBox_categories;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_14;
    QRadioButton *radioButton_observation;
    QRadioButton *radioButton_entrainement;
    QHBoxLayout *horizontalLayout_12;
    QRadioButton *radioButton_intercepteur;
    QRadioButton *radioButton_bombardier;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *radioButton_transport;
    QRadioButton *radioButton_chasseur;
    QRadioButton *radioButton_experimental;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout_8;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_countriesUsers;
    QComboBox *comboBox_countriesUsers;
    QPushButton *pushButton_ajouter_ville;
    QSpacerItem *horizontalSpacer_4;
    QListWidget *listWidget_countriesUsers;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_numberInService;
    QSpacerItem *horizontalSpacer_5;
    QLineEdit *lineEdit_numberInService;
    QHBoxLayout *horizontalLayout_8;
    QVBoxLayout *verticalLayout;
    QLabel *label_dateRecepEtMisEnOeuvre;
    QSpacerItem *horizontalSpacer_6;
    QDateEdit *dateEdit_startDate;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_image;
    QPushButton *pushButton_chargerImage;
    QLabel *label_longDescription;
    QTextEdit *textEdit_longDescription;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuAbout;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(989, 864);
        actionOpen_file = new QAction(MainWindow);
        actionOpen_file->setObjectName("actionOpen_file");
        actionSave_file = new QAction(MainWindow);
        actionSave_file->setObjectName("actionSave_file");
        actionSave_as = new QAction(MainWindow);
        actionSave_as->setObjectName("actionSave_as");
        actionFiltrer = new QAction(MainWindow);
        actionFiltrer->setObjectName("actionFiltrer");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout_10 = new QHBoxLayout(centralwidget);
        horizontalLayout_10->setObjectName("horizontalLayout_10");
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setObjectName("verticalLayout_11");
        verticalLayout_11->setSizeConstraint(QLayout::SizeConstraint::SetDefaultConstraint);
        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setObjectName("verticalLayout_10");
        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName("horizontalLayout_13");
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(5);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setSizeConstraint(QLayout::SizeConstraint::SetDefaultConstraint);
        comboBox_filtrage = new QComboBox(centralwidget);
        comboBox_filtrage->addItem(QString());
        comboBox_filtrage->setObjectName("comboBox_filtrage");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(comboBox_filtrage->sizePolicy().hasHeightForWidth());
        comboBox_filtrage->setSizePolicy(sizePolicy);
        comboBox_filtrage->setMaximumSize(QSize(400, 16777215));

        verticalLayout_3->addWidget(comboBox_filtrage);

        lineEdit_recherche = new QLineEdit(centralwidget);
        lineEdit_recherche->setObjectName("lineEdit_recherche");
        sizePolicy.setHeightForWidth(lineEdit_recherche->sizePolicy().hasHeightForWidth());
        lineEdit_recherche->setSizePolicy(sizePolicy);
        lineEdit_recherche->setMaximumSize(QSize(400, 16777215));

        verticalLayout_3->addWidget(lineEdit_recherche);

        listWidget_airplanesList = new QListWidget(centralwidget);
        listWidget_airplanesList->setObjectName("listWidget_airplanesList");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(listWidget_airplanesList->sizePolicy().hasHeightForWidth());
        listWidget_airplanesList->setSizePolicy(sizePolicy1);
        listWidget_airplanesList->setMaximumSize(QSize(300, 16777215));

        verticalLayout_3->addWidget(listWidget_airplanesList);


        horizontalLayout_13->addLayout(verticalLayout_3);


        verticalLayout_10->addLayout(horizontalLayout_13);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setObjectName("horizontalLayout_15");
        pushButton_ouvrir = new QPushButton(centralwidget);
        pushButton_ouvrir->setObjectName("pushButton_ouvrir");
        pushButton_ouvrir->setMaximumSize(QSize(200, 16777215));

        horizontalLayout_15->addWidget(pushButton_ouvrir);

        pushButton_sauvegarder = new QPushButton(centralwidget);
        pushButton_sauvegarder->setObjectName("pushButton_sauvegarder");
        pushButton_sauvegarder->setMaximumSize(QSize(200, 16777215));

        horizontalLayout_15->addWidget(pushButton_sauvegarder);


        verticalLayout_10->addLayout(horizontalLayout_15);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setObjectName("horizontalLayout_16");
        pushButton_ajouter = new QPushButton(centralwidget);
        pushButton_ajouter->setObjectName("pushButton_ajouter");
        pushButton_ajouter->setMaximumSize(QSize(200, 16777215));

        horizontalLayout_16->addWidget(pushButton_ajouter);

        pushButton_supprimer = new QPushButton(centralwidget);
        pushButton_supprimer->setObjectName("pushButton_supprimer");
        pushButton_supprimer->setMaximumSize(QSize(200, 16777215));

        horizontalLayout_16->addWidget(pushButton_supprimer);


        verticalLayout_10->addLayout(horizontalLayout_16);


        verticalLayout_11->addLayout(verticalLayout_10);


        horizontalLayout_7->addLayout(verticalLayout_11);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName("verticalLayout_5");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setSizeConstraint(QLayout::SizeConstraint::SetMinimumSize);
        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setObjectName("verticalLayout_9");
        label_nickname = new QLabel(centralwidget);
        label_nickname->setObjectName("label_nickname");

        verticalLayout_9->addWidget(label_nickname);

        label_constructor = new QLabel(centralwidget);
        label_constructor->setObjectName("label_constructor");

        verticalLayout_9->addWidget(label_constructor);

        label_name = new QLabel(centralwidget);
        label_name->setObjectName("label_name");

        verticalLayout_9->addWidget(label_name);

        label_maxSpeed = new QLabel(centralwidget);
        label_maxSpeed->setObjectName("label_maxSpeed");

        verticalLayout_9->addWidget(label_maxSpeed);

        label_qtyEngiens = new QLabel(centralwidget);
        label_qtyEngiens->setObjectName("label_qtyEngiens");

        verticalLayout_9->addWidget(label_qtyEngiens);

        label = new QLabel(centralwidget);
        label->setObjectName("label");

        verticalLayout_9->addWidget(label);

        label_commissioningDate = new QLabel(centralwidget);
        label_commissioningDate->setObjectName("label_commissioningDate");

        verticalLayout_9->addWidget(label_commissioningDate);

        label_crewMembers = new QLabel(centralwidget);
        label_crewMembers->setObjectName("label_crewMembers");

        verticalLayout_9->addWidget(label_crewMembers);

        label_operationalCeiling = new QLabel(centralwidget);
        label_operationalCeiling->setObjectName("label_operationalCeiling");

        verticalLayout_9->addWidget(label_operationalCeiling);


        horizontalLayout->addLayout(verticalLayout_9);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName("verticalLayout_6");
        lineEdit_nickname = new QLineEdit(centralwidget);
        lineEdit_nickname->setObjectName("lineEdit_nickname");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(lineEdit_nickname->sizePolicy().hasHeightForWidth());
        lineEdit_nickname->setSizePolicy(sizePolicy2);

        verticalLayout_6->addWidget(lineEdit_nickname);

        lineEdit_constructor = new QLineEdit(centralwidget);
        lineEdit_constructor->setObjectName("lineEdit_constructor");
        sizePolicy2.setHeightForWidth(lineEdit_constructor->sizePolicy().hasHeightForWidth());
        lineEdit_constructor->setSizePolicy(sizePolicy2);

        verticalLayout_6->addWidget(lineEdit_constructor);

        lineEdit_name = new QLineEdit(centralwidget);
        lineEdit_name->setObjectName("lineEdit_name");
        sizePolicy2.setHeightForWidth(lineEdit_name->sizePolicy().hasHeightForWidth());
        lineEdit_name->setSizePolicy(sizePolicy2);

        verticalLayout_6->addWidget(lineEdit_name);

        lineEdit_maxSpeed = new QLineEdit(centralwidget);
        lineEdit_maxSpeed->setObjectName("lineEdit_maxSpeed");
        sizePolicy2.setHeightForWidth(lineEdit_maxSpeed->sizePolicy().hasHeightForWidth());
        lineEdit_maxSpeed->setSizePolicy(sizePolicy2);

        verticalLayout_6->addWidget(lineEdit_maxSpeed);

        spinBox = new QSpinBox(centralwidget);
        spinBox->setObjectName("spinBox");

        verticalLayout_6->addWidget(spinBox);

        lineEdit_engienType = new QLineEdit(centralwidget);
        lineEdit_engienType->setObjectName("lineEdit_engienType");

        verticalLayout_6->addWidget(lineEdit_engienType);

        dateEdit_commissioningDate = new QDateEdit(centralwidget);
        dateEdit_commissioningDate->setObjectName("dateEdit_commissioningDate");
        dateEdit_commissioningDate->setCalendarPopup(true);

        verticalLayout_6->addWidget(dateEdit_commissioningDate);

        lineEdit_crewMembers = new QLineEdit(centralwidget);
        lineEdit_crewMembers->setObjectName("lineEdit_crewMembers");
        sizePolicy2.setHeightForWidth(lineEdit_crewMembers->sizePolicy().hasHeightForWidth());
        lineEdit_crewMembers->setSizePolicy(sizePolicy2);

        verticalLayout_6->addWidget(lineEdit_crewMembers);

        lineEdit_operationalCeiling = new QLineEdit(centralwidget);
        lineEdit_operationalCeiling->setObjectName("lineEdit_operationalCeiling");
        sizePolicy2.setHeightForWidth(lineEdit_operationalCeiling->sizePolicy().hasHeightForWidth());
        lineEdit_operationalCeiling->setSizePolicy(sizePolicy2);

        verticalLayout_6->addWidget(lineEdit_operationalCeiling);


        horizontalLayout->addLayout(verticalLayout_6);


        verticalLayout_5->addLayout(horizontalLayout);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        groupBox_categories = new QGroupBox(centralwidget);
        groupBox_categories->setObjectName("groupBox_categories");
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(groupBox_categories->sizePolicy().hasHeightForWidth());
        groupBox_categories->setSizePolicy(sizePolicy3);
        groupBox_categories->setMaximumSize(QSize(1000, 750));
        verticalLayout_4 = new QVBoxLayout(groupBox_categories);
        verticalLayout_4->setObjectName("verticalLayout_4");
        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName("horizontalLayout_14");
        radioButton_observation = new QRadioButton(groupBox_categories);
        radioButton_observation->setObjectName("radioButton_observation");

        horizontalLayout_14->addWidget(radioButton_observation);

        radioButton_entrainement = new QRadioButton(groupBox_categories);
        radioButton_entrainement->setObjectName("radioButton_entrainement");

        horizontalLayout_14->addWidget(radioButton_entrainement);


        verticalLayout_4->addLayout(horizontalLayout_14);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName("horizontalLayout_12");
        radioButton_intercepteur = new QRadioButton(groupBox_categories);
        radioButton_intercepteur->setObjectName("radioButton_intercepteur");

        horizontalLayout_12->addWidget(radioButton_intercepteur);

        radioButton_bombardier = new QRadioButton(groupBox_categories);
        radioButton_bombardier->setObjectName("radioButton_bombardier");

        horizontalLayout_12->addWidget(radioButton_bombardier);


        verticalLayout_4->addLayout(horizontalLayout_12);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        radioButton_transport = new QRadioButton(groupBox_categories);
        radioButton_transport->setObjectName("radioButton_transport");

        horizontalLayout_2->addWidget(radioButton_transport);

        radioButton_chasseur = new QRadioButton(groupBox_categories);
        radioButton_chasseur->setObjectName("radioButton_chasseur");

        horizontalLayout_2->addWidget(radioButton_chasseur);


        verticalLayout_4->addLayout(horizontalLayout_2);

        radioButton_experimental = new QRadioButton(groupBox_categories);
        radioButton_experimental->setObjectName("radioButton_experimental");

        verticalLayout_4->addWidget(radioButton_experimental);


        horizontalLayout_6->addWidget(groupBox_categories);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_3);


        verticalLayout_5->addLayout(horizontalLayout_6);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);

        verticalLayout_5->addItem(verticalSpacer);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName("verticalLayout_8");
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName("verticalLayout_7");
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_countriesUsers = new QLabel(centralwidget);
        label_countriesUsers->setObjectName("label_countriesUsers");

        horizontalLayout_3->addWidget(label_countriesUsers);

        comboBox_countriesUsers = new QComboBox(centralwidget);
        comboBox_countriesUsers->setObjectName("comboBox_countriesUsers");
        QSizePolicy sizePolicy4(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy4.setHorizontalStretch(10);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(comboBox_countriesUsers->sizePolicy().hasHeightForWidth());
        comboBox_countriesUsers->setSizePolicy(sizePolicy4);

        horizontalLayout_3->addWidget(comboBox_countriesUsers);

        pushButton_ajouter_ville = new QPushButton(centralwidget);
        pushButton_ajouter_ville->setObjectName("pushButton_ajouter_ville");

        horizontalLayout_3->addWidget(pushButton_ajouter_ville);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);


        verticalLayout_7->addLayout(horizontalLayout_3);

        listWidget_countriesUsers = new QListWidget(centralwidget);
        listWidget_countriesUsers->setObjectName("listWidget_countriesUsers");
        QSizePolicy sizePolicy5(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(listWidget_countriesUsers->sizePolicy().hasHeightForWidth());
        listWidget_countriesUsers->setSizePolicy(sizePolicy5);
        listWidget_countriesUsers->setFlow(QListView::Flow::TopToBottom);
        listWidget_countriesUsers->setViewMode(QListView::ViewMode::ListMode);

        verticalLayout_7->addWidget(listWidget_countriesUsers);


        verticalLayout_8->addLayout(verticalLayout_7);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        label_numberInService = new QLabel(centralwidget);
        label_numberInService->setObjectName("label_numberInService");

        horizontalLayout_9->addWidget(label_numberInService);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_5);

        lineEdit_numberInService = new QLineEdit(centralwidget);
        lineEdit_numberInService->setObjectName("lineEdit_numberInService");
        QSizePolicy sizePolicy6(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(lineEdit_numberInService->sizePolicy().hasHeightForWidth());
        lineEdit_numberInService->setSizePolicy(sizePolicy6);

        horizontalLayout_9->addWidget(lineEdit_numberInService);


        verticalLayout_8->addLayout(horizontalLayout_9);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label_dateRecepEtMisEnOeuvre = new QLabel(centralwidget);
        label_dateRecepEtMisEnOeuvre->setObjectName("label_dateRecepEtMisEnOeuvre");

        verticalLayout->addWidget(label_dateRecepEtMisEnOeuvre);


        horizontalLayout_8->addLayout(verticalLayout);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_6);

        dateEdit_startDate = new QDateEdit(centralwidget);
        dateEdit_startDate->setObjectName("dateEdit_startDate");
        dateEdit_startDate->setCalendarPopup(true);

        horizontalLayout_8->addWidget(dateEdit_startDate);


        verticalLayout_8->addLayout(horizontalLayout_8);


        verticalLayout_5->addLayout(verticalLayout_8);


        horizontalLayout_4->addLayout(verticalLayout_5);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);


        horizontalLayout_7->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(5);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setSizeConstraint(QLayout::SizeConstraint::SetDefaultConstraint);
        verticalLayout_2->setContentsMargins(-1, -1, 0, -1);
        label_image = new QLabel(centralwidget);
        label_image->setObjectName("label_image");
        label_image->setMaximumSize(QSize(500, 425));
        label_image->setFrameShape(QFrame::Shape::Box);
        label_image->setFrameShadow(QFrame::Shadow::Raised);
        label_image->setMidLineWidth(0);
        label_image->setScaledContents(true);
        label_image->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_2->addWidget(label_image);

        pushButton_chargerImage = new QPushButton(centralwidget);
        pushButton_chargerImage->setObjectName("pushButton_chargerImage");

        verticalLayout_2->addWidget(pushButton_chargerImage);

        label_longDescription = new QLabel(centralwidget);
        label_longDescription->setObjectName("label_longDescription");
        label_longDescription->setMaximumSize(QSize(500, 375));

        verticalLayout_2->addWidget(label_longDescription);

        textEdit_longDescription = new QTextEdit(centralwidget);
        textEdit_longDescription->setObjectName("textEdit_longDescription");
        QSizePolicy sizePolicy7(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy7.setHorizontalStretch(0);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(textEdit_longDescription->sizePolicy().hasHeightForWidth());
        textEdit_longDescription->setSizePolicy(sizePolicy7);
        textEdit_longDescription->setMaximumSize(QSize(500, 16777215));

        verticalLayout_2->addWidget(textEdit_longDescription);


        horizontalLayout_5->addLayout(verticalLayout_2);


        horizontalLayout_7->addLayout(horizontalLayout_5);


        horizontalLayout_10->addLayout(horizontalLayout_7);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 989, 18));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName("menuFile");
        menuAbout = new QMenu(menubar);
        menuAbout->setObjectName("menuAbout");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuAbout->menuAction());
        menuFile->addAction(actionOpen_file);
        menuFile->addAction(actionSave_file);
        menuFile->addAction(actionSave_as);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionOpen_file->setText(QCoreApplication::translate("MainWindow", "Open file", nullptr));
        actionSave_file->setText(QCoreApplication::translate("MainWindow", "Save file", nullptr));
        actionSave_as->setText(QCoreApplication::translate("MainWindow", "Save as...", nullptr));
        actionFiltrer->setText(QCoreApplication::translate("MainWindow", "Filtrer", nullptr));
        comboBox_filtrage->setItemText(0, QCoreApplication::translate("MainWindow", "Filter A-Z", nullptr));

        lineEdit_recherche->setText(QCoreApplication::translate("MainWindow", "Search...", nullptr));
        pushButton_ouvrir->setText(QCoreApplication::translate("MainWindow", "Open", nullptr));
        pushButton_sauvegarder->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        pushButton_ajouter->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
        pushButton_supprimer->setText(QCoreApplication::translate("MainWindow", "Delete", nullptr));
        label_nickname->setText(QCoreApplication::translate("MainWindow", "NATO reporting name:                                      ", nullptr));
        label_constructor->setText(QCoreApplication::translate("MainWindow", "Manufacturer:                                        ", nullptr));
        label_name->setText(QCoreApplication::translate("MainWindow", "Model :                          ", nullptr));
        label_maxSpeed->setText(QCoreApplication::translate("MainWindow", "Top speed (in km) :                                             ", nullptr));
        label_qtyEngiens->setText(QCoreApplication::translate("MainWindow", "Amount of engins", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Engin type", nullptr));
        label_commissioningDate->setText(QCoreApplication::translate("MainWindow", "Date entered service :                 ", nullptr));
        label_crewMembers->setText(QCoreApplication::translate("MainWindow", "Crew number :  ", nullptr));
        label_operationalCeiling->setText(QCoreApplication::translate("MainWindow", "Max altitude (in km) :                ", nullptr));
        groupBox_categories->setTitle(QCoreApplication::translate("MainWindow", "Category : ", nullptr));
        radioButton_observation->setText(QCoreApplication::translate("MainWindow", "Reconnaissance", nullptr));
        radioButton_entrainement->setText(QCoreApplication::translate("MainWindow", "Training", nullptr));
        radioButton_intercepteur->setText(QCoreApplication::translate("MainWindow", "Interceptor", nullptr));
        radioButton_bombardier->setText(QCoreApplication::translate("MainWindow", "Bomber", nullptr));
        radioButton_transport->setText(QCoreApplication::translate("MainWindow", "Transport", nullptr));
        radioButton_chasseur->setText(QCoreApplication::translate("MainWindow", "Fighter", nullptr));
        radioButton_experimental->setText(QCoreApplication::translate("MainWindow", "Experimental", nullptr));
        label_countriesUsers->setText(QCoreApplication::translate("MainWindow", "Country", nullptr));
        pushButton_ajouter_ville->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
        label_numberInService->setText(QCoreApplication::translate("MainWindow", "The number of machiens in service:", nullptr));
        label_dateRecepEtMisEnOeuvre->setText(QCoreApplication::translate("MainWindow", "Date received and /or put in service :  ", nullptr));
        label_image->setText(QCoreApplication::translate("MainWindow", "Image", nullptr));
        pushButton_chargerImage->setText(QCoreApplication::translate("MainWindow", "Change image", nullptr));
        label_longDescription->setText(QCoreApplication::translate("MainWindow", "Compleate description", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuAbout->setTitle(QCoreApplication::translate("MainWindow", "About", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
