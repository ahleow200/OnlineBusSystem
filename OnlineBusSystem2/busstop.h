#ifndef BUSSTOP_H
#define BUSSTOP_H
#include <QVector>
#include <QtGui>

class BusStop
{
public:
    BusStop();
    void initialize(const QString &name);

    //getter methods
    QString getName();
    int getCrowdedness();
    QVector<QString> getService();

    //setter methods
    void addToCrowd(int people);
    void reduceCrowd(int people);
    void addService(const QString &route);

private:
    //variables
    QString name;
    int crowdedness;
    QVector<QString> service;
};

#endif // BUSSTOP_H
