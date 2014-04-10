#ifndef BUS_H
#define BUS_H
#include<QtGui>
class Bus
{
public:
    Bus();
    void initialize(int id);

    //getter methods
    QString getRoute();
    int getID();
    int getOccupancy();
    int getOccupancyLimit();
    bool isDispatched();

    //setter methods
    bool setDispatchStatus(const QString &route, bool status);
    void addPassenger(int passenger);

private:
    //variables
    QString route;
    int busID;
    int occupancy;
    int occupancyLimit;
    bool dispatchStatus;
};

#endif // BUS_H
