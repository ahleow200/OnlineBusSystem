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
    int getCrowdedness(const QString &busstopname);
    QString* getRoute(const QString &route);
    BusStop getBusStop(const QString &route, int order);
    void dispatchBus(const QString &route);
    QVector<int> getTiming(const QString &busstopname, bool nextBus);
    QVector<int> getOccupancy(const QString &busstopname);
    int getStartIndex(const QString &route, const QString &busstopname);
    int calculateTime(const QString &route, int startIndex, bool nextBus);
    QVector<QString> getService(const QString &busstopname);

private:
    //variables
    Bus bus[26]; //total number of bus to be simulated
    BusStop busstop[35]; //total number of bus stop to be simulated
    BusStop *A1Route[17];
    BusStop *A2Route[17];
    BusStop *BRoute[16];
    BusStop *CRoute[12];
    BusStop *D1Route[14];
    BusStop *D2Route[12];

    QString A1BusStop[17];
    QString A2BusStop[17];
    QString BBusStop[16];
    QString CBusStop[12];
    QString D1BusStop[14];
    QString D2BusStop[12];

    int A1Position[17];
    int A2Position[17];
    int BPosition[16];
    int CPosition[12];
    int D1Position[14];
    int D2Position[12];

    int nextA1Position[17];
    int nextA2Position[17];
    int nextBPosition[16];
    int nextCPosition[12];
    int nextD1Position[14];
    int nextD2Position[12];

    int A1ID;
    int A2ID;
    int BID;
    int CID;
    int D1ID;
    int D2ID;

    int getBusStopIndex(const QString &busstopname);
    int getBusOccupancy(int busID);

};

#endif // BUSSIMULATOR_H