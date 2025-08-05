#ifndef APPLICATION_H
#define APPLICATION_H

#include <QString>
#include "setofairplanes.h"

class Application
{
public:
    Application();
    bool chargerXML(const QString& filePath, SetOfAirplanes& data);
    bool sauverXML(const QString& filePath, const SetOfAirplanes& data);

    bool chargerJSON(const QString& filePath, SetOfAirplanes& data);
    bool sauverJSON(const QString& filePath, const SetOfAirplanes& data);
};

#endif // APPLICATION_H
