#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "addairplanedialog.h"

#include <QXmlStreamReader>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QPixmap>
#include <QCloseEvent>
#include <QDebug>


void MainWindow::closeEvent(QCloseEvent *event)
{
    if(interfaceIsChanged){
        if (!(airplaneData == airplaneDataCopy)) {
            QMessageBox::StandardButton reply = QMessageBox::question(
                this,
                QObject::tr("Changes not saved"),
                QObject::tr("Some modificatioins have been done.\nDo you really want to quit without saving ?"),
                QMessageBox::Yes | QMessageBox::No
                );

            if (reply == QMessageBox::No) {
                event->ignore(); // bloque la fermeture
                return;
            }
        }

        event->accept(); // accepte la fermeture
    }
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle(QObject::tr("Aiplanes_Explorer_DELOFON_KHROMYKH"));

    QStringList countriesList = {
        QObject::tr("France"), QObject::tr("Germany"), QObject::tr("USA"), QObject::tr("Japan"), QObject::tr("China"),
        QObject::tr("Canada"), QObject::tr("Brasil"), QObject::tr("India"), QObject::tr("United Kingdom"), QObject::tr("Australia"),
        QObject::tr("Italia"), QObject::tr("Spain"), QObject::tr("Mexico"), QObject::tr("South Africa"), QObject::tr("Russia"),
        QObject::tr("South Korea"), QObject::tr("Netherlands"), QObject::tr("Sweden"), QObject::tr("Norway"), QObject::tr("Turkuie")
    };
    for (const QString& country : countriesList)
        ui->comboBox_countriesUsers->addItem(country);

    categoryGroup = new QButtonGroup(this);
    categoryGroup->setExclusive(true);  // comportement normal d’un groupe radio

    categoryGroup->addButton(ui->radioButton_observation);
    categoryGroup->addButton(ui->radioButton_entrainement);
    categoryGroup->addButton(ui->radioButton_intercepteur);
    categoryGroup->addButton(ui->radioButton_bombardier);
    categoryGroup->addButton(ui->radioButton_transport);
    categoryGroup->addButton(ui->radioButton_chasseur);
    categoryGroup->addButton(ui->radioButton_experimental);

    connect(ui->actionOpen_file, &QAction::triggered, this, &MainWindow::on_pushButton_ouvrir_clicked);
    connect(ui->actionSave_as, &QAction::triggered, this, &MainWindow::on_pushButton_sauvegarder_clicked);
    connect(ui->actionSave_file, &QAction::triggered, this, &MainWindow::on_pushButton_save_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::refreshAirplaneList()
{
    ui->listWidget_airplanesList->clear();  // Vider la liste existante

    const QVector<Airplane>& avions = airplaneData.getAirplanes();
    for (const Airplane& avion : avions) {
        QString label = avion.getConstructor() + " - " + avion.getName();
        ui->listWidget_airplanesList->addItem(label);
    }

    //interfaceIsChanged=true;
}

void MainWindow::loadAirplaneDetails(const Airplane &plane)
{
    // Charger les champs éditables
    ui->lineEdit_constructor->setText(plane.getConstructor());
    ui->lineEdit_name->setText(plane.getName());
    ui->lineEdit_nickname->setText(plane.getNickname());
    ui->lineEdit_maxSpeed->setText(QString::number(plane.getMaxSpeed()));
    ui->lineEdit_engienType->setText(plane.getEngineType());
    ui->spinBox->setValue(plane.getEngineCount());
    ui->dateEdit_commissioningDate->setDate(plane.getCommissioningDate());
    ui->lineEdit_crewMembers->setText(QString::number(plane.getCrewMembers()));
    ui->lineEdit_operationalCeiling->setText(QString::number(plane.getOperationalCeiling()));

    // Bloquer les signaux (pour ne pas modifier la description de l'airplane courant)
    ui->textEdit_longDescription->blockSignals(true);
    ui->textEdit_longDescription->setPlainText(plane.getDescription());
    ui->textEdit_longDescription->blockSignals(false);

    // Catégorie (radio buttons)
    QString cat = plane.getCategory().toLower();
    if (cat == "observation")
        ui->radioButton_observation->setChecked(true);
    else if (cat == "entrainement")
        ui->radioButton_entrainement->setChecked(true);
    else if (cat == "intercepteur")
        ui->radioButton_intercepteur->setChecked(true);
    else if (cat == "bombardier")
        ui->radioButton_bombardier->setChecked(true);
    else if (cat == "transport")
        ui->radioButton_transport->setChecked(true);
    else if (cat == "chasseur")
        ui->radioButton_chasseur->setChecked(true);
    else if (cat == "experimental")
        ui->radioButton_experimental->setChecked(true);
    else{
        ui->radioButton_observation->setChecked(false);
        ui->radioButton_entrainement->setChecked(false);
        ui->radioButton_intercepteur->setChecked(false);
        ui->radioButton_bombardier->setChecked(false);
        ui->radioButton_transport->setChecked(false);
        ui->radioButton_chasseur->setChecked(false);
        ui->radioButton_experimental->setChecked(false);
    }

    // Charger les pays
    ui->listWidget_countriesUsers->clear();
    for(const CountryUser& country : plane.getCountriesUsers())
        ui->listWidget_countriesUsers->addItem(country.getCountryName());

    // Charger l'image
    if(!plane.getImageFilename().isEmpty()){
        QPixmap pixmap;
        pixmap.load(plane.getImageFilename());
        ui->label_image->setPixmap(pixmap);
        ui->label_image->setScaledContents(true);
    }else{
        ui->label_image->setText(QObject::tr("No image"));
        ui->label_image->setAlignment(Qt::AlignCenter);
    }
}

void MainWindow::clearFields()
{
    // Nettoyer les lineEdits
    ui->lineEdit_nickname->clear();
    ui->lineEdit_constructor->clear();
    ui->lineEdit_name->clear();
    ui->lineEdit_maxSpeed->clear();

    // Nettoyer la date de mise en service
    ui->dateEdit_commissioningDate->blockSignals(true);
    ui->dateEdit_commissioningDate->setDate(QDate(2000, 01, 01));
    ui->dateEdit_commissioningDate->blockSignals(false);


    ui->lineEdit_engienType->clear();

    // Nettoyer le spinBox
    ui->spinBox->blockSignals(true);
    ui->spinBox->setValue(0);
    ui->spinBox->blockSignals(false);

    ui->lineEdit_operationalCeiling->clear();
    ui->lineEdit_numberInService->clear();
    ui->dateEdit_startDate->clear();

    // Nettoyer la description courante
    ui->textEdit_longDescription->blockSignals(true);
    ui->textEdit_longDescription->clear();
    ui->textEdit_longDescription->blockSignals(false);

    // Nettoyer le label de l'image
    ui->label_image->clear();
    ui->label_image->setText(QObject::tr("No image"));
    ui->label_image->setAlignment(Qt::AlignCenter);

    // Nettoyer les boutons
    categoryGroup->setExclusive(false);
    for (QAbstractButton* btn : categoryGroup->buttons())
        btn->setChecked(false);
    categoryGroup->setExclusive(true);

    // Nettoyer la zone des pays
    ui->listWidget_countriesUsers->clear();

    // Nettoyer les lineEdits de
    ui->lineEdit_numberInService->blockSignals(true);
    ui->dateEdit_startDate->blockSignals(true);

    ui->lineEdit_numberInService->clear();
    ui->dateEdit_startDate->clear();

    ui->lineEdit_numberInService->blockSignals(false);
    ui->dateEdit_startDate->blockSignals(false);
}

void MainWindow::clearInterface()
{
    ui->listWidget_airplanesList->clear();
    clearFields();
}



void MainWindow::on_pushButton_ouvrir_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, QObject::tr("Open file"), "", "JSON (*.json);;XML (*.xml)");
    if (fileName.isEmpty()) return;

    currentFilename = fileName;
    clearInterface();
    airplaneData.clear();

    if (fileName.endsWith(".json")){
        appManager.chargerJSON(fileName, airplaneData);
        appManager.chargerJSON(fileName, airplaneDataCopy);
    }
    else if (fileName.endsWith(".xml")){
        appManager.chargerXML(fileName, airplaneData);
        appManager.chargerXML(fileName, airplaneDataCopy);
    }

    refreshAirplaneList();
}


void MainWindow::on_pushButton_ajouter_clicked()
{
    AddAirplaneDialog dialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        QString constructor = dialog.getConstructor().trimmed();
        QString name = dialog.getName().trimmed();

        if (constructor.isEmpty() || name.isEmpty()) {
            QMessageBox::warning(this, QObject::tr("Fields missing"), QObject::tr("Please, enter name and manufaturer"));
            return;
        }

        if (airplaneData.findAirplane(name) != nullptr) {
            QMessageBox::warning(this, QObject::tr("Duplicate"), QObject::tr("This airplane already exists"));
            return;
        }

        clearFields();
        Airplane plane(constructor, name);
        airplaneData.addAirplane(plane);
        refreshAirplaneList();
    }
}


void MainWindow::on_pushButton_supprimer_clicked()
{
    QListWidgetItem* item = ui->listWidget_airplanesList->currentItem();
    if (!item) {
        QMessageBox::information(this, QObject::tr("No airplane"), QObject::tr("Please, choose an airplane to delete"));
        return;
    }

    QString airplaneTitle = item->text();
    QString name = airplaneTitle.section(" - ", 1);

    airplaneData.removeAirplane(name);
    refreshAirplaneList();
    clearInterface();
    interfaceIsChanged=true;
}


void MainWindow::on_pushButton_sauvegarder_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, QObject::tr("Save the file"),
                                                    "", "JSON (*.json);;XML (*.xml)");
    if (fileName.isEmpty()) return;

    bool success = false;
    if (fileName.endsWith(".json"))
        success = appManager.sauverJSON(fileName, airplaneData);
    else if (fileName.endsWith(".xml"))
        success = appManager.sauverXML(fileName, airplaneData);

    if (success)
        QMessageBox::information(this, QObject::tr("Save sucess"), QObject::tr("File saved successfully."));
    else
        QMessageBox::critical(this, QObject::tr("Error"), QObject::tr("Could not save the file."));

    interfaceIsChanged=false;
}

void MainWindow::on_pushButton_save_clicked()
{
    QString fileName = getCurrentFilename();
    if (fileName.isEmpty()) return;

    bool success = false;
    if (fileName.endsWith(".json"))
        success = appManager.sauverJSON(fileName, airplaneData);
    else if (fileName.endsWith(".xml"))
        success = appManager.sauverXML(fileName, airplaneData);

    if (success)
        QMessageBox::information(this, QObject::tr("Save sucess"), QObject::tr("File saved successfully."));
    else
        QMessageBox::critical(this, QObject::tr("Error"), QObject::tr("Could not save the file."));

    interfaceIsChanged=false;
}


void MainWindow::on_pushButton_ajouter_ville_clicked()
{
    QString country = ui->comboBox_countriesUsers->currentText();
    for(int i = 0; i < ui->listWidget_countriesUsers->count(); ++i){
        if (ui->listWidget_countriesUsers->item(i)->text() == country){
            QMessageBox::information(this, QObject::tr("Duplicate"), QObject::tr("This country already exists."));
            return;
        }
    }
    QListWidgetItem* currentAirplane = ui->listWidget_airplanesList->currentItem();
    if (currentAirplane == nullptr){
        QMessageBox::warning(this, QObject::tr("Error"), QObject::tr("Please, selec first an airplane"));
        return;
    }
    QString planeName = currentAirplane->text().section(" - ", 1);
    Airplane* plane = airplaneData.findAirplane(planeName);
    if(plane == nullptr)
        return;

    CountryUser newCountry(country, 0, QDate::currentDate());
    QVector<CountryUser> countries = plane->getCountriesUsers();
    countries.append(newCountry);
    plane->setCountriesUsers(countries);

    ui->listWidget_countriesUsers->addItem(country);

    interfaceIsChanged=true;

}


void MainWindow::on_listWidget_countriesUsers_itemDoubleClicked(QListWidgetItem *item)
{
    QString selectedCountry = item->text();
    // Rechercher l'Avion courant
    QString airplaneName = item->text().section(" - ", 1);
    Airplane* plane = airplaneData.findAirplane(airplaneName);
    if(plane == nullptr)
        return;
    for (const CountryUser& c : plane->getCountriesUsers()){
        if(c.getCountryName() == selectedCountry){
            airplaneData.removeAirplane(c.getCountryName());

            // Nettoyer les champs "numberInservice" et "startDate" (tout en blockant les signaux)
            ui->lineEdit_numberInService->blockSignals(true);
            ui->dateEdit_startDate->blockSignals(true);

            ui->lineEdit_numberInService->clear();
            ui->dateEdit_startDate->clear();

            ui->lineEdit_numberInService->blockSignals(false);
            ui->dateEdit_startDate->blockSignals(false);

            // Suprimer le pays utilisateur en question
            delete item;
            return;
        }
    }
    interfaceIsChanged = true;
}


void MainWindow::on_listWidget_airplanesList_itemClicked(QListWidgetItem *item)
{
    // Récupération du nom de l'airplane courant afin d'effectuer la recherche dans la liste des avions
    QString airplaneName = item->text().section(" - ", 1);
    Airplane* plane = airplaneData.findAirplane(airplaneName);
    if(plane == nullptr)
        return;
    clearFields();
    loadAirplaneDetails(*plane);
}


void MainWindow::on_pushButton_chargerImage_clicked()
{
    // Rechercher l'Avion courant
    QListWidgetItem* selectedAirplane = ui->listWidget_airplanesList->currentItem();
    if(selectedAirplane == nullptr){
        QMessageBox::warning(this, QObject::tr("Error"), QObject::tr("Please, select first an airplane"));
        return;
    }
    QString airplaneName = selectedAirplane->text().section(" - ", 1);
    Airplane* plane = airplaneData.findAirplane(airplaneName);
    if(plane == nullptr){
        QMessageBox::warning(this, QObject::tr("Error"), QObject::tr("Please, select first an airplane"));
        return;
    }
    QString filename = QFileDialog::getOpenFileName(this, QObject::tr("Image"), "", "JPG(*.jpg);; PNG(*.png);; JPEG(*.jpeg)");
    plane->setImageFilename(filename);
    QPixmap pixmap;
    pixmap.load(filename);
    ui->label_image->setPixmap(pixmap);
    ui->label_image->setScaledContents(true);
    interfaceIsChanged = true;

}


void MainWindow::on_listWidget_countriesUsers_itemClicked(QListWidgetItem *item)
{
    QString selectedCountry = item->text();
    // Rechercher l'Avion courant
    QListWidgetItem* selectedAirplane = ui->listWidget_airplanesList->currentItem();
    QString airplaneName = selectedAirplane->text().section(" - ", 1);
    Airplane* plane = airplaneData.findAirplane(airplaneName);
    if(plane == nullptr)
        return;
    for (const CountryUser& c : plane->getCountriesUsers()){
        if(c.getCountryName() == selectedCountry){
            // Charger les champs du pays utilisateur dans les lineEdits correspondants (sans réagir aux signaux de modifications de ces lineEdits là)
            // Bloquer les signaux
            ui->lineEdit_numberInService->blockSignals(true);
            ui->dateEdit_startDate->blockSignals(true);
            // Afficher les infos du pays utilisateur
            ui->lineEdit_numberInService->setText(QString::number(c.getNumberInService()));
            ui->dateEdit_startDate->setDate(c.getStartDate());
            // Réactiver les signaux
            ui->lineEdit_numberInService->blockSignals(false);
            ui->dateEdit_startDate->blockSignals(false);
            return;
        }
    }
    // Nettoyer les champs "numberInservice" et "startDate" (tout en blockant les signaux)
    ui->lineEdit_numberInService->blockSignals(true);
    ui->dateEdit_startDate->blockSignals(true);

    ui->lineEdit_numberInService->clear();
    ui->dateEdit_startDate->clear();

    ui->lineEdit_numberInService->blockSignals(false);
    ui->dateEdit_startDate->blockSignals(false);
}


void MainWindow::on_lineEdit_nickname_textEdited(const QString &arg1)
{
    QListWidgetItem* item = ui->listWidget_airplanesList->currentItem();
    if(item == nullptr)
        return;
    QString airplaneName = item->text().section(" - ", 1);
    Airplane* plane = airplaneData.findAirplane(airplaneName);
    if(!plane)
        return;
    plane->setNickname(arg1);
    interfaceIsChanged = true;
}


void MainWindow::on_lineEdit_constructor_textEdited(const QString &arg1)
{
    QListWidgetItem* item = ui->listWidget_airplanesList->currentItem();
    if(item == nullptr)
        return;
    QString airplaneName = item->text().section(" - ", 1);
    Airplane* plane = airplaneData.findAirplane(airplaneName);
    if(!plane)
        return;
    plane->setConstructor(arg1);
    item->setText(plane->getConstructor() + " - " + plane->getName());
    ui->listWidget_airplanesList->setCurrentItem(item);
    interfaceIsChanged = true;
}


void MainWindow::on_lineEdit_name_textEdited(const QString &arg1)
{
    QListWidgetItem* item = ui->listWidget_airplanesList->currentItem();
    if(item == nullptr)
        return;
    QString airplaneName = item->text().section(" - ", 1);
    Airplane* plane = airplaneData.findAirplane(airplaneName);
    if(!plane)
        return;
    plane->setName(arg1);
    item->setText(plane->getConstructor() + " - " + plane->getName());
    ui->listWidget_airplanesList->setCurrentItem(item);
    interfaceIsChanged = true;
}


void MainWindow::on_lineEdit_maxSpeed_textEdited(const QString &arg1)
{
    QListWidgetItem* item = ui->listWidget_airplanesList->currentItem();
    if(item == nullptr)
        return;
    QString airplaneName = item->text().section(" - ", 1);
    Airplane* plane = airplaneData.findAirplane(airplaneName);
    if(!plane)
        return;
    double maxSpeed = arg1.toDouble();
    plane->setMaxSpeed(maxSpeed);
    interfaceIsChanged = true;
}


void MainWindow::on_lineEdit_commissioningDate_textEdited(const QString &arg1)
{
    // Plus rien à faire (widget Supprimé)
    ;
}


void MainWindow::on_lineEdit_crewMembers_textEdited(const QString &arg1)
{
    QListWidgetItem* item = ui->listWidget_airplanesList->currentItem();
    if(item == nullptr)
        return;
    QString airplaneName = item->text().section(" - ", 1);
    Airplane* plane = airplaneData.findAirplane(airplaneName);
    if(!plane)
        return;
    int crew = arg1.toInt();
    plane->setCrewMembers(crew);
    interfaceIsChanged = true;
}


void MainWindow::on_lineEdit_operationalCeiling_textEdited(const QString &arg1)
{
    QListWidgetItem* item = ui->listWidget_airplanesList->currentItem();
    if(item == nullptr)
        return;
    QString airplaneName = item->text().section(" - ", 1);
    Airplane* plane = airplaneData.findAirplane(airplaneName);
    if(!plane)
        return;
    int ceiling = arg1.toInt();
    plane->setOperationalCeiling(ceiling);
    interfaceIsChanged = true;
}


void MainWindow::on_radioButton_observation_clicked()
{
    // Plus rien à faire (signal changé)
    ;
}

void MainWindow::onCategoryChanged(bool checked) {
    if (!checked) return;

    QListWidgetItem* item = ui->listWidget_airplanesList->currentItem();
    if (!item) return;

    QString airplaneName = item->text().section(" - ", 1);
    Airplane* plane = airplaneData.findAirplane(airplaneName);
    if (!plane) return;

    QString category;
    if (ui->radioButton_chasseur->isChecked()) category = "Chasseur";
    else if (ui->radioButton_bombardier->isChecked()) category = "Bombardier";
    else if (ui->radioButton_transport->isChecked()) category = "Transport";
    else if (ui->radioButton_observation->isChecked()) category = "Observation";
    else if (ui->radioButton_intercepteur->isChecked()) category = "Intercepteur";
    else if (ui->radioButton_experimental->isChecked()) category = "Experimental";
    else if (ui->radioButton_entrainement->isChecked()) category = "Entrainement";

    plane->setCategory(category);
    interfaceIsChanged = true;
}



void MainWindow::on_radioButton_observation_toggled(bool checked)
{
    MainWindow::onCategoryChanged(checked);
}


void MainWindow::on_radioButton_entrainement_toggled(bool checked)
{
    MainWindow::onCategoryChanged(checked);
}


void MainWindow::on_radioButton_intercepteur_toggled(bool checked)
{
    MainWindow::onCategoryChanged(checked);
}


void MainWindow::on_radioButton_bombardier_toggled(bool checked)
{
    MainWindow::onCategoryChanged(checked);
}


void MainWindow::on_radioButton_transport_toggled(bool checked)
{
    MainWindow::onCategoryChanged(checked);
}


void MainWindow::on_radioButton_chasseur_toggled(bool checked)
{
    MainWindow::onCategoryChanged(checked);
}


void MainWindow::on_radioButton_experimental_toggled(bool checked)
{
    MainWindow::onCategoryChanged(checked);
}


void MainWindow::on_lineEdit_numberInService_textEdited(const QString &arg1)
{   
    QListWidgetItem* item = ui->listWidget_airplanesList->currentItem();
    if(item == nullptr)
        return;
    QString airplaneName = item->text().section(" - ", 1);
    Airplane* plane = airplaneData.findAirplane(airplaneName);
    if(!plane)
        return;
    // Obtention du nom du countryUser courant
    QListWidgetItem* selectedCountryItem = ui->listWidget_countriesUsers->currentItem();
    if (!selectedCountryItem) return;

    QString countryName = selectedCountryItem->text();

    // Recherche du CountryUse
    QVector<CountryUser> countries = plane->getCountriesUsers();

    bool alreadyExists = std::any_of(countries.begin(), countries.end(), [&](const CountryUser& c){
        return c.getCountryName() == countryName;
    });

    if (alreadyExists) return;

    for (int i = 0; i < countries.size(); ++i) {
        if (countries[i].getCountryName() == countryName) {
            int number = arg1.toInt();
            countries[i].setNumberInService(number);
            plane->setCountriesUsers(countries);  // appliquer les changements
            break;
        }
    }
    interfaceIsChanged = true;
}


void MainWindow::on_textEdit_longDescription_textChanged()
{
    QListWidgetItem* item = ui->listWidget_airplanesList->currentItem();
    if(item == nullptr)
        return;
    QString airplaneName = item->text().section(" - ", 1);
    Airplane* plane = airplaneData.findAirplane(airplaneName);
    if(!plane)
        return;
    QString longDesctiption = ui->textEdit_longDescription->toPlainText();
    plane->setDescription(longDesctiption);
    interfaceIsChanged = true;
}


void MainWindow::on_dateEdit_commissioningDate_dateChanged(const QDate &date)
{
    QListWidgetItem* item = ui->listWidget_airplanesList->currentItem();
    if(item == nullptr)
        return;
    QString airplaneName = item->text().section(" - ", 1);
    Airplane* plane = airplaneData.findAirplane(airplaneName);
    if(!plane)
        return;

    plane->setCommissioningDate(date);
    interfaceIsChanged = true;
}


void MainWindow::on_dateEdit_startDate_dateChanged(const QDate &date)
{
    QListWidgetItem* item = ui->listWidget_airplanesList->currentItem();
    if(item == nullptr)
        return;
    QString airplaneName = item->text().section(" - ", 1);
    Airplane* plane = airplaneData.findAirplane(airplaneName);
    if(!plane)
        return;
    // Obtention du nom du countryUser courant
    QListWidgetItem* selectedCountryItem = ui->listWidget_countriesUsers->currentItem();
    if (!selectedCountryItem) return;

    QString countryName = selectedCountryItem->text();

    // Recherche du CountryUse
    QVector<CountryUser> countries = plane->getCountriesUsers();
    for (int i = 0; i < countries.size(); ++i) {
        if (countries[i].getCountryName() == countryName) {
            countries[i].setStartDate(date);
            plane->setCountriesUsers(countries);  // appliquer les changements
            break;
        }
    }
    interfaceIsChanged = true;
}


void MainWindow::on_lineEdit_recherche_textEdited(const QString &arg1)
{
    QRegularExpression regex(arg1, QRegularExpression::CaseInsensitiveOption);

    if (!regex.isValid()) {
        // Ne rien filtrer
        return;
    }

    ui->listWidget_airplanesList->clear();

    for (const Airplane& a : airplaneData.getAirplanes()) {
        QString label = a.getConstructor() + " - " + a.getName();

        if (regex.match(a.getName()).hasMatch() || regex.match(a.getConstructor()).hasMatch()) {
            ui->listWidget_airplanesList->addItem(label);
        }
    }
    interfaceIsChanged = true;
}


void MainWindow::on_lineEdit_engienType_textEdited(const QString &arg1)
{
    QListWidgetItem* item = ui->listWidget_airplanesList->currentItem();
    if (!item) return;

    QString airplaneName = item->text().section(" - ", 1);
    Airplane* plane = airplaneData.findAirplane(airplaneName);
    if (!plane) return;

    plane->setEngineType(arg1);
    interfaceIsChanged = true;
}


void MainWindow::on_spinBox_valueChanged(int arg1)
{
    QListWidgetItem* item = ui->listWidget_airplanesList->currentItem();
    if (!item) return;

    QString airplaneName = item->text().section(" - ", 1);
    Airplane* plane = airplaneData.findAirplane(airplaneName);
    if (!plane) return;

    plane->setEngineCount(arg1);
    interfaceIsChanged = true;
}

