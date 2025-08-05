#include "countryuser.h"

CountryUser::CountryUser(const QString _countryName, int _numberInService, const QDate& _startDate)
    : countryName(_countryName), numberInService(_numberInService), startDate(_startDate)
{}

CountryUser CountryUser::chargerXML(QXmlStreamReader& xml)
{
    QString name;
    int number = 0;
    QDate date;

    while (!(xml.isEndElement() && xml.name() == "country")) {
        xml.readNext();
        if (xml.isStartElement()) {
            QString tag = xml.name().toString();
            if (tag == "name") name = xml.readElementText();
            else if (tag == "number") number = xml.readElementText().toInt();
            else if (tag == "startDate") date = QDate::fromString(xml.readElementText(), Qt::ISODate);
        }
    }
    return CountryUser(name, number, date);
}


void CountryUser::sauverXML(QXmlStreamWriter &xml) const
{
    xml.writeStartElement("country");
    xml.writeTextElement("name", countryName);
    xml.writeTextElement("number", QString::number(numberInService));
    xml.writeTextElement("startDate", startDate.toString(Qt::ISODate));
    xml.writeEndElement();
}

CountryUser CountryUser::chargerJSON(const QJsonObject &obj)
{
    QString name = obj["name"].toString();
    int number = obj["number"].toInt();
    QDate startDate = QDate::fromString(obj["startDate"].toString(), Qt::ISODate);
    return CountryUser(name, number, startDate);
}

QJsonObject CountryUser::sauverJSON() const
{
    QJsonObject obj;
    obj["name"] = countryName;
    obj["number"] = numberInService;
    obj["startDate"] = startDate.toString(Qt::ISODate);
    return obj;
}

bool operator==(const CountryUser& a, const CountryUser& b) {
    return a.getCountryName() == b.getCountryName() &&
           a.getNumberInService() == b.getNumberInService() &&
           a.getStartDate() == b.getStartDate();
}






