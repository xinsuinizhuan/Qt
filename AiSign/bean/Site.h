#ifndef SITE_H
#define SITE_H

#include <QList>
#include <QString>

class Room;

/**
 * 考点: 学校
 */
class Site {
public:
    Site();
    QString toString() const;

    QString siteCode;
    QString siteName;
    QString siteAddress;

    QList<Room> rooms;
};

#endif // SITE_H
