#include "application.h"
#include <QFile>

Application::Application() {}

bool Application::chargerXML(const QString& filePath, SetOfAirplanes& data) {
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) return false;

    QXmlStreamReader xml(&file);

    while (!xml.atEnd() && !xml.hasError()) {
        xml.readNext();
        if (xml.isStartElement() && xml.name() == "airplanes") {
            while (!(xml.tokenType() == QXmlStreamReader::EndElement && xml.name() == "airplanes")) {
                xml.readNext();
                if (xml.isStartElement() && xml.name() == "airplane") {
                    data.addAirplane(Airplane::chargerXML(xml));
                }
            }
        }
    }

    file.close();
    return !xml.hasError();
}

bool Application::sauverXML(const QString& filePath, const SetOfAirplanes& data) {
    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) return false;

    QXmlStreamWriter xml(&file);
    xml.setAutoFormatting(true);
    xml.writeStartDocument();
    xml.writeStartElement("airplanes");

    for (const Airplane& plane : data.getAirplanes()) {
        plane.sauverXML(xml);
    }

    xml.writeEndElement(); // </airplanes>
    xml.writeEndDocument();

    file.close();
    return true;
}

bool Application::chargerJSON(const QString &filePath, SetOfAirplanes &data)
{
    QFile file(filePath);
    if(!file.open(QIODevice::ReadOnly)) return false;

    QByteArray jsonData = file.readAll();
    QJsonDocument doc=QJsonDocument::fromJson(jsonData);
    if (!doc.isArray()) return false;

    data.chargerJSON(doc.array());
    file.close();
    return true;
}

bool Application::sauverJSON (const QString &filePath, const SetOfAirplanes &data)
{
    QFile file (filePath);
    if(!file.open(QIODevice::WriteOnly)) return false;

    QJsonArray array = data.sauverJSON();
    QJsonDocument doc (array);
    file.write(doc.toJson());
    file.close();
    return true;
}
