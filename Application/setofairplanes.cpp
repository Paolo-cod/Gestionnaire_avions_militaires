#include "setofairplanes.h"

SetOfAirplanes::SetOfAirplanes()
{}

void SetOfAirplanes::addAirplane(const Airplane& airplane) {
    airplanes.append(airplane);
}

void SetOfAirplanes::removeAirplane(const QString& name) {
    for (int i = 0; i < airplanes.size(); ++i) {
        if (airplanes[i].getName() == name) {
            airplanes.remove(i);
            return;
        }
    }
}

Airplane* SetOfAirplanes::findAirplane(const QString& name) {
    for (int i = 0; i < airplanes.size(); ++i) {
        if (airplanes[i].getName() == name) {
            return &airplanes[i];
        }
    }
    return nullptr;
}

QJsonArray SetOfAirplanes::sauverJSON() const
{
    QJsonArray array;
    for (const Airplane& airplane:airplanes){
        array.append(airplane.sauverJSON());
    }
    return array;
}

void SetOfAirplanes::chargerJSON(const QJsonArray &array)
{
    airplanes.clear();
    for(const QJsonValue& value:array){
        airplanes.append(Airplane::chargerJSON(value.toObject()));
    }
}

bool operator==(const SetOfAirplanes& a, const SetOfAirplanes& b) {
    return a.getAirplanes() == b.getAirplanes();
}


