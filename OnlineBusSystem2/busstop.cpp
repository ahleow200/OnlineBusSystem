#include "busstop.h"

BusStop::BusStop(const QString &name)
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
