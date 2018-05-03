#include "picture.h"

// The ability to call other constructor is a nice addition in C++11
Picture::Picture(const QString &filePath)
    : Picture(QUrl::fromLocalFile(filePath))
{
}

Picture::Picture(const QUrl &fileUrl)
    : mId(-1)
    , mAlbumId(-1)
    , mFileUrl(fileUrl)
{
}

QUrl Picture::fileUrl() const
{
    return mFileUrl;
}

void Picture::setFileUrl(const QUrl &fileUrl)
{
    mFileUrl = fileUrl;
}

int Picture::id() const
{
    return mId;
}

void Picture::setId(int id)
{
    mId = id;
}

int Picture::albumId() const
{
    return mAlbumId;
}

void Picture::setAlbumId(int albumId)
{
    mAlbumId = albumId;
}
