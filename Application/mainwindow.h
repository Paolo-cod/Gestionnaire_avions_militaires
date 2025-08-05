#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidgetItem>
#include <QButtonGroup>
#include "application.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

protected:
    void closeEvent(QCloseEvent *event) override;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    SetOfAirplanes airplaneData;
    SetOfAirplanes airplaneDataCopy;
    Application appManager;
    QButtonGroup* categoryGroup;

    void refreshAirplaneList(); // recharge la liste de gauche
    void loadAirplaneDetails(const Airplane& plane); // remplit les champs
    bool interfaceIsChanged;
    QString currentFilename;
    //bool isSelected();
    // Airplane collectFormInputs() const; // créer un avion depuis le formulaire


private slots:
    inline QString getCurrentFilename() { return currentFilename; }
    void clearFields();
    void clearInterface();
    void on_pushButton_ouvrir_clicked();
    void on_pushButton_ajouter_clicked();
    void on_pushButton_supprimer_clicked();
    void on_pushButton_sauvegarder_clicked();
    void on_pushButton_ajouter_ville_clicked();
    void on_listWidget_countriesUsers_itemDoubleClicked(QListWidgetItem *item);
    void on_listWidget_airplanesList_itemClicked(QListWidgetItem *item);
    void on_pushButton_chargerImage_clicked();
    void on_listWidget_countriesUsers_itemClicked(QListWidgetItem *item);
    void on_lineEdit_nickname_textEdited(const QString &arg1);
    void on_lineEdit_constructor_textEdited(const QString &arg1);
    void on_lineEdit_name_textEdited(const QString &arg1);
    void on_lineEdit_maxSpeed_textEdited(const QString &arg1);
    void on_lineEdit_commissioningDate_textEdited(const QString &arg1);
    void on_lineEdit_crewMembers_textEdited(const QString &arg1);
    void on_lineEdit_operationalCeiling_textEdited(const QString &arg1);
    void on_radioButton_observation_clicked();
    void on_radioButton_observation_toggled(bool checked);
    void on_radioButton_entrainement_toggled(bool checked);
    void on_radioButton_intercepteur_toggled(bool checked);
    void on_radioButton_bombardier_toggled(bool checked);
    void on_radioButton_transport_toggled(bool checked);
    void on_radioButton_chasseur_toggled(bool checked);
    void on_radioButton_experimental_toggled(bool checked);
    void on_lineEdit_numberInService_textEdited(const QString &arg1);
    void on_textEdit_longDescription_textChanged();
    void onCategoryChanged(bool checked);
    void on_dateEdit_commissioningDate_dateChanged(const QDate &date);
    void on_dateEdit_startDate_dateChanged(const QDate &date);
    void on_lineEdit_recherche_textEdited(const QString &arg1);
    void on_lineEdit_engienType_textEdited(const QString &arg1);
    void on_spinBox_valueChanged(int arg1);
    void on_pushButton_save_clicked();
};
#endif // MAINWINDOW_H
