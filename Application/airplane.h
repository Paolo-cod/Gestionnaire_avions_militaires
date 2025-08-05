#ifndef AIRPLANE_H
#define AIRPLANE_H

#include "countryuser.h"
#include <QVector>
#include <QString>

class Airplane
{
public:
    Airplane() = delete;
    Airplane(QString _constructor, QString _name);

    // Those are the getters
    inline QString getConstructor() const { return constructor ; }
    inline QString getName() const { return name ; }
    inline QString getNickname() const { return nickname ; }
    inline QString getImageFilename() const { return image_filename ; }
    inline QString getDescription() const { return long_description ; }
    inline double getMaxSpeed() const { return max_speed ; }
    inline QDate getCommissioningDate() const { return commissioning_date ; }
    inline int getCrewMembers() const { return crew_members ; }
    inline int getOperationalCeiling() const { return operational_ceiling ; }
    inline QString getCategory() const { return category ; }

    inline int getEngineCount() const { return engineCount ; }
    inline QString getEngineType() const { return engineType ; }

    inline QVector<CountryUser> getCountriesUsers() const { return countriesUsers ; }

    //Those are the setters
    inline void setConstructor(const QString& _constructor) { constructor = _constructor; }
    inline void setName(const QString& _name) { name = _name ; }
    inline void setNickname(const QString& _nickname) { nickname = _nickname ; }
    inline void setImageFilename(const QString& _image_filename) { image_filename = _image_filename ; }
    inline void setDescription(const QString& long_desc) { long_description = long_desc ; }
    inline void setMaxSpeed(double _speed) { max_speed = _speed; }
    inline void setCommissioningDate(const QDate& _date) { commissioning_date = _date ; }
    inline void setCrewMembers(int _crewMembers) { crew_members = _crewMembers ; }
    inline void setOperationalCeiling(int _ceiling) { operational_ceiling = _ceiling ; }
    inline void setCategory(const QString& _category) { category = _category ; }

    inline void setEngineCount(int _engineCount) { engineCount = _engineCount ; }
    inline void setEngineType(const QString& _engineType) { engineType = _engineType ; }

    inline void setCountriesUsers(const QVector<CountryUser>& _countriesUsers) { countriesUsers = _countriesUsers ; }

    static Airplane chargerXML(QXmlStreamReader& xml);
    void sauverXML(QXmlStreamWriter& xml) const;
    static Airplane chargerJSON(const QJsonObject& obj);
    QJsonObject sauverJSON() const;

private:
    QString constructor;
    QString name;
    QString nickname;
    QString image_filename;
    QString long_description;
    double max_speed = 0.0;
    QDate commissioning_date;
    int crew_members = 0;
    int operational_ceiling = 0;
    QString category;

    // Paramètres à rajouter dans l'interface
    int engineCount = 0;
    QString engineType;

    QVector<CountryUser> countriesUsers;


};
bool operator ==(const Airplane &a, const Airplane &b);

#endif // AIRPLANE_H
