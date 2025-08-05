#ifndef SETOFAIRPLANES_H
#define SETOFAIRPLANES_H

#include "airplane.h"

class SetOfAirplanes
{
public:
    SetOfAirplanes();

    void addAirplane(const Airplane& airplane);
    void removeAirplane(const QString& name);
    Airplane* findAirplane(const QString&_name);
    inline QVector<Airplane> getAirplanes() const { return airplanes; }
    inline void setAirplanes(const QVector<Airplane>& _airplanes) {airplanes = _airplanes; }
    inline void clear() { airplanes.clear(); }

    QJsonArray sauverJSON() const;
    void chargerJSON(const QJsonArray& array);

private:
    QVector<Airplane> airplanes;
};
bool operator ==(const SetOfAirplanes &a, const SetOfAirplanes &b);

#endif // SETOFAIRPLANES_H
