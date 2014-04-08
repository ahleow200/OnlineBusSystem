#ifndef BUSSTOP_H
#define BUSSTOP_H

class BusStop
{
public:
    BusStop(const QString &name);

    //getter methods
    QString getName();
    int getCrowdedness();

    //setter methods
    void addToCrowd(int people);

private:
    //variables
    QString name;
    int crowdedness;
};

#endif // BUSSTOP_H
