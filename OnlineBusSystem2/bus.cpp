#include "bus.h"
#include <QtGui>
//constructor
Bus::Bus()
{
}

void Bus::initialize(int id){
    route="None";
    this->busID=id;
    occupancy=0;
    occupancyLimit=60;
    dispatchStatus=false;
}

//public getter methods

QString Bus::getRoute(){
    return route;
}

int Bus::getID(){
    return busID;
}

int Bus::getOccupancy(){
    return occupancy;
}

int Bus::getOccupancyLimit(){
    return occupancyLimit;
}

bool Bus::isDispatched(){
    return dispatchStatus;
}

//public setter methods

bool Bus::setDispatchStatus(const QString &route, bool status){
    if(status==true)
        this->route=route;
    else
        this->route="None";
    dispatchStatus=status;
    return dispatchStatus;
}

void Bus::addPassenger(int passenger)
{
    occupancy+=passenger;
}
