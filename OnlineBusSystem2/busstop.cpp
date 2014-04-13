#include "busstop.h"
#include <QVector>
#include <QtGui>

BusStop::BusStop()
{
}

void BusStop::initialize(const QString &name, int x, int y)
{
    this->name=name;
    crowdedness=0;
	location.append(x);
	location.append(y);
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

void BusStop::reduceCrowd(int people){
    crowdedness-=people;
}

void BusStop::addService(const QString &route){
    if(!service.contains(route))
        service.append(route);
    //qDebug()<<"this bus stop now has"<<service.count()<<" bus services";
}

QVector<QString> BusStop::getService()
{
    return service;
}

QVector<int> BusStop::getLocation(){
	return location;
}
