#ifndef ADDAIRPLANEDIALOG_H
#define ADDAIRPLANEDIALOG_H

#include <QDialog>

namespace Ui {
class AddAirplaneDialog;
}

class AddAirplaneDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddAirplaneDialog(QWidget *parent = nullptr);
    ~AddAirplaneDialog();

    QString getConstructor() const;
    QString getName() const;

private:
    Ui::AddAirplaneDialog *ui;
};

#endif // ADDAIRPLANEDIALOG_H
