#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QString>

#include "AlbumDao.h"
#include "picturedao.h"

class QSqlQuery;
class QSqlDatabase;

const QString DATABASE_FILENAME = "gallery.db";

class DatabaseManager
{
public:
    static DatabaseManager& instance();
    ~DatabaseManager();

    static void debugQuery(const QSqlQuery &query);

protected:
    DatabaseManager(const QString &path = DATABASE_FILENAME);
    DatabaseManager& operator=(const DatabaseManager &rhs);

private:
    QSqlDatabase *mDatabase;

public:
    const AlbumDao mAlbumDao;
    const PictureDao mPictureDao;
};

#endif // DATABASEMANAGER_H
