#include "busstop.h"
#include <QVector>
#include <QtGui>

BusStop::BusStop()
{
}

void BusStop::initialize(const QString &name)
{
    this->name=name;
    crowdedness=0;
}

QString BusStop::getName(){
    return name;
}

int BusStop::getCrowdedness(){
    return crowdedness;
}

void BusStop::addToCrowd(int people){
    crowdedness+=people;
}

void BusStop::addService(const QString &route){
    service.append(route);
    //qDebug()<<"this bus stop now has"<<service.count()<<" bus services";
}

QVector<QString> BusStop::getService()
{
    return service;
}
