#ifndef BUSSIMULATOR_H
#define BUSSIMULATOR_H
#include "bus.h"
#include "busstop.h"
#include <QtGui>

class Bus;
class BusStop;

const int BusCount=26;
const int BusStopCount=35;
const int A1BusStopCount=16;
const int A2BusStopCount=17;
const int BBusStopCount=16;
const int CBusStopCount=12;
const int D1BusStopCount=14;
const int D2BusStopCount=12;

class BusSimulator
{
public:
    BusSimulator();
    void initialize();
    int getCrowdedness(const QString &busstopname);
    BusStop* getRoute(const QString &route);
    QVector<QString> getService(const QString &busstopname);
    //BusStop getBusStop(const QString &route, int order);
    QVector<int> getTiming(const QString &busstopname, bool nextBus);
    QVector<int> getOccupancy(const QString &busstopname);
    QVector<int> getOccupancyLimit(const QString &busstopname);


    //simulation methods
    QString dispatchBus(const QString &route);
    void advanceAllBus();
    int* getBusPosition(const QString &route);
    void addCrowd();
    void boardPassenger(const QString &route, int index);

private:
    //variables

    Bus bus[BusCount]; //total number of bus to be simulated
    BusStop busstop[BusStopCount]; //total number of bus stop to be simulated
	BusStop *AllRoute[BusStopCount];
    BusStop *A1Route[A1BusStopCount];
    BusStop *A2Route[A2BusStopCount];
    BusStop *BRoute[BBusStopCount];
    BusStop *CRoute[CBusStopCount];
    BusStop *D1Route[D1BusStopCount];
    BusStop *D2Route[D2BusStopCount];
	
    QString A1BusStop[A1BusStopCount];
    QString A2BusStop[A2BusStopCount];
    QString BBusStop[BBusStopCount];
    QString CBusStop[CBusStopCount];
    QString D1BusStop[D1BusStopCount];
    QString D2BusStop[D2BusStopCount];

    int A1Position[A1BusStopCount];
    int A2Position[A2BusStopCount];
    int BPosition[BBusStopCount];
    int CPosition[CBusStopCount];
    int D1Position[D1BusStopCount];
    int D2Position[D2BusStopCount];

    int A1ID;
    int A2ID;
    int BID;
    int CID;
    int D1ID;
    int D2ID;

    int currentA1;
    int currentA2;
    int currentB;
    int currentC;
    int currentD1;
    int currentD2;

    int getBusStopIndex(const QString &busstopname);
    int getBusOccupancy(int busID);
    int getStartIndex(const QString &route, const QString &busstopname);
    int calculateTime(const QString &route, int startIndex, bool nextBus);
    int getAvailableBus();
    void advanceBus(const QString &route);
    int findBusPosition(const QString &route);
    int randInt(int low, int high);

    QTime time;

};

#endif // BUSSIMULATOR_H
