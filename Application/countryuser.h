#ifndef COUNTRYUSER_H
#define COUNTRYUSER_H

#include <QWidget>
#include <QDate>
#include <QXmlStreamReader>
#include <QXmlStreamWriter>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonValue>

class CountryUser
{
public:
    explicit CountryUser() = delete;
    explicit CountryUser(const QString _countryName, int _numberInService, const QDate& _startDate);

    inline QString getCountryName() const { return countryName; }
    inline int getNumberInService() const { return numberInService; }
    inline QDate getStartDate() const { return startDate; }

    inline void setCountryName(const QString& _countryName) { countryName = _countryName; }
    inline void setNumberInService(int _numberInService) { numberInService = _numberInService; }
    inline void setStartDate(QDate _startDate) { startDate = _startDate; }

    static CountryUser chargerXML(QXmlStreamReader& xml);
    void sauverXML(QXmlStreamWriter& xml) const;

    static CountryUser chargerJSON(const QJsonObject& obj);
    QJsonObject sauverJSON() const;

private:
    QString countryName;
    int numberInService = 0;
    QDate startDate;

};

bool operator ==(const CountryUser &a, const CountryUser &b);

#endif // COUNTRYUSER_H
