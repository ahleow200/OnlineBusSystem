#include "bus.h"

//constructor
Bus::Bus(int id)
{
    route="None";
    this->busID=id;
    occupancy=0;
    dispatchStatus=false;
}

//public getter methods

QString Bus::getRoute(){
    return route;
}

int Bus::getID(){
    return id;
}

int Bus::getOccupancy(){
    return occupancy;
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
