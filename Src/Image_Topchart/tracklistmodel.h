#ifndef TRACKLISTMODEL_H
#define TRACKLISTMODEL_H

#include <QObject>

class tracklistmodel : public QObject
{
    Q_OBJECT
public:
    explicit tracklistmodel(QObject *parent = nullptr);

signals:

};

#endif // TRACKLISTMODEL_H
