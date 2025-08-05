#include "airplane.h"

Airplane::Airplane(QString _constructor, QString _name)
    : constructor(_constructor), name(_name)
 {}

Airplane Airplane::chargerXML(QXmlStreamReader &xml)
{
    Airplane plane("", "");

    while (!(xml.isEndElement() && xml.name() == "airplane")) {
        if (xml.isStartElement()) {
            QString tag = xml.name().toString();

            if (tag == "constructor") plane.setConstructor(xml.readElementText());

            else if (tag == "name") plane.setName(xml.readElementText());

            else if (tag == "nickname") plane.setNickname(xml.readElementText());

            else if (tag == "image_filename") plane.setImageFilename(xml.readElementText());

            else if (tag == "category") plane.setCategory(xml.readElementText());

            else if (tag == "long_description") plane.setDescription(xml.readElementText());

            else if (tag == "crew_members") plane.setCrewMembers(xml.readElementText().toInt());

            else if (tag == "commissioning_date") plane.setCommissioningDate(QDate::fromString(xml.readElementText(), Qt::ISODate));

            else if (tag == "engineCount") plane.setEngineCount(xml.readElementText().toInt());

            else if (tag == "engineType") plane.setEngineType(xml.readElementText());

            else if (tag == "operational_ceiling") plane.setOperationalCeiling(xml.readElementText().toInt());

            else if (tag == "max_speed") plane.setMaxSpeed(xml.readElementText().toDouble());

            else if (tag == "countriesUsers") {
                QVector<CountryUser> countryList;
                while (!(xml.isEndElement() && xml.name() == "countriesUsers")) {
                    xml.readNext();
                    if (xml.isStartElement() && xml.name() == "country") {
                        CountryUser countryUser = CountryUser::chargerXML(xml);
                        countryList.append(countryUser);
                    }
                }
                plane.setCountriesUsers(countryList);
            }
        }
        xml.readNext();
    }

    return plane;
}

void Airplane::sauverXML(QXmlStreamWriter &xml) const
{
    xml.writeStartElement("airplane"); // <airplane>

    xml.writeTextElement("constructor", constructor);
    xml.writeTextElement("name", name);
    xml.writeTextElement("nickname", nickname);
    xml.writeTextElement("image_filename", image_filename);
    xml.writeTextElement("category", category);
    xml.writeTextElement("long_description", long_description);
    xml.writeTextElement("crew_members", QString::number(crew_members));
    xml.writeTextElement("commissioning_date", commissioning_date.toString(Qt::ISODate));
    xml.writeTextElement("engineCount", QString::number(engineCount));
    xml.writeTextElement("engineType", engineType);
    xml.writeTextElement("operational_ceiling", QString::number(operational_ceiling));
    xml.writeTextElement("max_speed", QString::number(max_speed));

    xml.writeStartElement("countriesUsers"); // <countriesUsers>
    for (const auto& country : countriesUsers) {
        country.sauverXML(xml);
    }
    xml.writeEndElement(); // </countriesUsers>

    xml.writeEndElement(); // </airplane>
}

Airplane Airplane::chargerJSON(const QJsonObject &obj)
{
    Airplane airplane ("","");
    airplane.setName(obj["name"].toString());
    airplane.setConstructor(obj["constructor"].toString());
    airplane.setNickname(obj["nickname"].toString());
    airplane.setDescription(obj["long_description"].toString());
    airplane.setCategory(obj["category"].toString());
    airplane.setCrewMembers(obj["crew_members"].toInt());
    airplane.setCommissioningDate(QDate::fromString(obj["commissioning_date"].toString(), Qt::ISODate));
    airplane.setEngineCount(obj["engineCount"].toInt());
    airplane.setEngineType(obj["engineType"].toString());
    airplane.setOperationalCeiling(obj["operational_ceiling"].toInt());
    airplane.setMaxSpeed(obj["max_speed"].toDouble());
    airplane.setImageFilename(obj["image_filename"].toString());

    QVector<CountryUser> cuList;
    QJsonArray countriesArray = obj["countriesUsers"].toArray();
    for (const QJsonValue& value: countriesArray){
        cuList.append(CountryUser::chargerJSON(value.toObject()));
    }
    airplane.setCountriesUsers(cuList);

    return airplane;
}

QJsonObject Airplane::sauverJSON() const
{
    QJsonObject obj;
    obj["name"]=name;
    obj["constructor"]=constructor;
    obj["nickname"]=nickname;
    obj["long_description"]=long_description;
    obj["category"]=category;
    obj["crew_members"]=crew_members;
    obj["commissioning_date"]=commissioning_date.toString(Qt::ISODate);
    obj["engineCount"]=engineCount;
    obj["engineType"]=engineType;
    obj["operational_ceiling"]=operational_ceiling;
    obj["max_speed"]=max_speed;
    obj["image_filename"] = image_filename;

    QJsonArray countriesArray;
    for (const CountryUser& country: countriesUsers){
        countriesArray.append(country.sauverJSON());
    }

    obj["countriesUsers"] = countriesArray;

    return obj;

}


bool operator==(const Airplane& a, const Airplane& b) {
    return a.getConstructor() == b.getConstructor() &&
           a.getName() == b.getName() &&
           a.getNickname() == b.getNickname() &&
           a.getImageFilename() == b.getImageFilename() &&
           a.getDescription() == b.getDescription() &&
           a.getMaxSpeed() == b.getMaxSpeed() &&
           a.getCommissioningDate() == b.getCommissioningDate() &&
           a.getCrewMembers() == b.getCrewMembers() &&
           a.getOperationalCeiling() == b.getOperationalCeiling() &&
           a.getCategory() == b.getCategory() &&
           a.getEngineCount() == b.getEngineCount() &&
           a.getEngineType() == b.getEngineType() &&
           a.getCountriesUsers() == b.getCountriesUsers();
}




