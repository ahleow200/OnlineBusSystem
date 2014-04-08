#ifndef BUSSIMULATOR_H
#define BUSSIMULATOR_H
#include "bus.h"
#include "busstop.h"
#include <QtGui>

class Bus;
class BusStop;

class BusSimulator
{
public:
    BusSimulator();
    void initialize();
    BusStop* getRoute(const QString &route);
    BusStop getBusStop(const QString &route, int order);
    void dispatchBus(const QString &route);

private:
    //variables
    Bus bus[26]; //total number of bus to be simulated
    BusStop busstop[34]; //total number of bus stop to be simulated
    BusStop A1Route[17];
    BusStop A2Route[17];
    BusStop BRoute[16];
    BusStop CRoute[12];
    BusStop D1Route[14];
    BusStop D2Route[12];

    int A1Position[17];
    int A2Position[17];
    int BPosition[16];
    int CPosition[12];
    int D1Position[14];
    int D2Position[12];

};

#endif // BUSSIMULATOR_H
