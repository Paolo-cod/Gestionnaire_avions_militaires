#include "mainwindow.h"

#include <QApplication>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
    const QString uiLanguages = QLocale::system().name();
    if (translator.load("::/Application/src/S2_01_fr_" + uiLanguages)){
        a.installTranslator(&translator);
    }


    /*QTranslator translator;
    //const QStringList uiLanguages = QLocale::system().uiLanguages();
        if(translator.load(":/Application/src/S2_01_fr_FR.qm")){
        a.installTranslator(&translator);
    }*/

    MainWindow w;
    w.show();
    return a.exec();
}
