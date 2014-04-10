#include "bussimulator.h"
#include "bus.h"
#include "busstop.h"
#include <QtGui>

class Bus;
class BusStop;
class BusSimulator;

BusSimulator::BusSimulator()
{
    initialize();
}

void BusSimulator::initialize()
{
    //initialize bus
    for(int i=0;i<26;i++)
    {
        //bus[i]=new Bus();
        bus[i].initialize(i);
    }

    A1ID=-1;
    A2ID=-1;
    BID=-1;
    CID=-1;
    D1ID=-1;
    D2ID=-1;

    //initialize bus stop
    //busstop[0]=new BusStop();
    busstop[0].initialize("PGP Terminal");
    //busstop[1]=new BusStop();
    busstop[1].initialize("After Science Park Drive");
    //busstop[2]=new BusStop();
    busstop[2].initialize("KR MRT Station");
    //busstop[3]=new BusStop();
    busstop[3].initialize("NUH");
    //busstop[4]=new BusStop();
    busstop[4].initialize("LT29");
    //busstop[5]=new BusStop();
    busstop[5].initialize("University Hall");
    //busstop[6]=new BusStop();
    busstop[6].initialize("Opp University Health Centre");
    //busstop[7]=new BusStop();
    busstop[7].initialize("Yushof Ishak House");
    //busstop[8]=new BusStop();
    busstop[8].initialize("Central Library");
    //busstop[9]=new BusStop();
    busstop[9].initialize("LT13");
    //busstop[10]=new BusStop();
    busstop[10].initialize("AS7");
    //busstop[11]=new BusStop();
    busstop[11].initialize("COM2");
    //busstop[12]=new BusStop();
    busstop[12].initialize("BIZ2");
    //busstop[13]=new BusStop();
    busstop[13].initialize("Opp House 12");
    //busstop[14]=new BusStop();
    busstop[14].initialize("House 7");
    //busstop[15]=new BusStop();
    busstop[15].initialize("Between House 14 & 15");
    //busstop[16]=new BusStop();
    busstop[16].initialize("House 12");
    //busstop[17]=new BusStop();
    busstop[17].initialize("Opp Hon Sui Sen Memorial Library");
    //busstop[18]=new BusStop();
    busstop[18].initialize("Temasek Hall");
    //busstop[19]=new BusStop();
    busstop[19].initialize("Eusoff Hall");
    //busstop[20]=new BusStop();
    busstop[20].initialize("Ventus");
    //busstop[21]=new BusStop();
    busstop[21].initialize("Computer Centre");
    //busstop[22]=new BusStop();
    busstop[22].initialize("Opp Yushof Ishak House");
    //busstop[23]=new BusStop();
    busstop[23].initialize("Museum");
    //busstop[24]=new BusStop();
    busstop[24].initialize("University Health Centre");
    //busstop[25]=new BusStop();
    busstop[25].initialize("Opp University Hall");
    //busstop[26]=new BusStop();
    busstop[26].initialize("Block S17");
    //busstop[27]=new BusStop();
    busstop[27].initialize("Opp NUH");
    //busstop[28]=new BusStop();
    busstop[28].initialize("Opp KR MRT Station");
    //busstop[29]=new BusStop();
    busstop[29].initialize("The Japanese Primary School");
    //busstop[30]=new BusStop();
    busstop[30].initialize("Block E3A");
    //busstop[31]=new BusStop();
    busstop[31].initialize("Raffles Hall");
    //busstop[32]=new BusStop();
    busstop[32].initialize("Opp Block EA");
    //busstop[33]=new BusStop();
    busstop[33].initialize("University Town");
    //busstop[34]=new BusStop();
    busstop[34].initialize("Kent Ridge Crescent");

    //initialize A1 Route
    for(int i=0;i<16;i++)
    {
        A1Route[i]=&busstop[i];
        A1BusStop[i]=busstop[i].getName();
    }
    A1Route[16]=&busstop[0];
    A1BusStop[16]=busstop[0].getName();

    //initialize A2 Route
    A2Route[0]=&busstop[0];
    A2Route[1]=&busstop[15];
    A2Route[2]=&busstop[16];
    A2Route[3]=&busstop[17];
    A2Route[4]=&busstop[11];
    A2Route[5]=&busstop[18];
    A2Route[6]=&busstop[19];
    A2Route[7]=&busstop[20];
    A2Route[8]=&busstop[21];
    A2Route[9]=&busstop[22];
    A2Route[10]=&busstop[23];
    A2Route[11]=&busstop[24];
    A2Route[12]=&busstop[25];
    A2Route[13]=&busstop[26];
    A2Route[14]=&busstop[27];
    A2Route[15]=&busstop[28];
    A2Route[16]=&busstop[0];

    A2BusStop[0]=busstop[0].getName();
    A2BusStop[1]=busstop[15].getName();
    A2BusStop[2]=busstop[16].getName();
    A2BusStop[3]=busstop[17].getName();
    A2BusStop[4]=busstop[11].getName();
    A2BusStop[5]=busstop[18].getName();
    A2BusStop[6]=busstop[19].getName();
    A2BusStop[7]=busstop[20].getName();
    A2BusStop[8]=busstop[21].getName();
    A2BusStop[9]=busstop[22].getName();
    A2BusStop[10]=busstop[23].getName();
    A2BusStop[11]=busstop[24].getName();
    A2BusStop[12]=busstop[25].getName();
    A2BusStop[13]=busstop[26].getName();
    A2BusStop[14]=busstop[27].getName();
    A2BusStop[15]=busstop[28].getName();
    A2BusStop[16]=busstop[0].getName();


    //initialize B Route
    BRoute[0]=&busstop[29];
    BRoute[1]=&busstop[30];
    BRoute[2]=&busstop[23];
    BRoute[3]=&busstop[7];
    BRoute[4]=&busstop[8];
    BRoute[5]=&busstop[9];
    BRoute[6]=&busstop[10];
    BRoute[7]=&busstop[11];
    BRoute[8]=&busstop[18];
    BRoute[9]=&busstop[19];
    BRoute[10]=&busstop[20];
    BRoute[11]=&busstop[21];
    BRoute[12]=&busstop[22];
    BRoute[13]=&busstop[31];
    BRoute[14]=&busstop[30];
    BRoute[15]=&busstop[32];

    BBusStop[0]=busstop[29].getName();
    BBusStop[1]=busstop[30].getName();
    BBusStop[2]=busstop[23].getName();
    BBusStop[3]=busstop[7].getName();
    BBusStop[4]=busstop[8].getName();
    BBusStop[5]=busstop[9].getName();
    BBusStop[6]=busstop[10].getName();
    BBusStop[7]=busstop[11].getName();
    BBusStop[8]=busstop[18].getName();
    BBusStop[9]=busstop[19].getName();
    BBusStop[10]=busstop[20].getName();
    BBusStop[11]=busstop[21].getName();
    BBusStop[12]=busstop[22].getName();
    BBusStop[13]=busstop[31].getName();
    BBusStop[14]=busstop[30].getName();
    BBusStop[15]=busstop[32].getName();

    //initialize C Route
    CRoute[0]=&busstop[29];
    CRoute[1]=&busstop[30];
    CRoute[2]=&busstop[23];
    CRoute[3]=&busstop[24];
    CRoute[4]=&busstop[25];
    CRoute[5]=&busstop[26];
    CRoute[6]=&busstop[4];
    CRoute[7]=&busstop[5];
    CRoute[8]=&busstop[6];
    CRoute[9]=&busstop[31];
    CRoute[10]=&busstop[30];
    CRoute[11]=&busstop[32];

    CBusStop[0]=busstop[29].getName();
    CBusStop[1]=busstop[30].getName();
    CBusStop[2]=busstop[23].getName();
    CBusStop[3]=busstop[24].getName();
    CBusStop[4]=busstop[25].getName();
    CBusStop[5]=busstop[26].getName();
    CBusStop[6]=busstop[4].getName();
    CBusStop[7]=busstop[5].getName();
    CBusStop[8]=busstop[6].getName();
    CBusStop[9]=busstop[31].getName();
    CBusStop[10]=busstop[30].getName();
    CBusStop[11]=busstop[32].getName();

    //initialize D1 Route
    D1Route[0]=&busstop[17];
    D1Route[1]=&busstop[11];
    D1Route[2]=&busstop[20];
    D1Route[3]=&busstop[21];
    D1Route[4]=&busstop[22];
    D1Route[5]=&busstop[23];
    D1Route[6]=&busstop[33];
    D1Route[7]=&busstop[34];
    D1Route[8]=&busstop[7];
    D1Route[9]=&busstop[8];
    D1Route[10]=&busstop[9];
    D1Route[11]=&busstop[10];
    D1Route[12]=&busstop[11];
    D1Route[13]=&busstop[12];

    D1BusStop[0]=busstop[17].getName();
    D1BusStop[1]=busstop[11].getName();
    D1BusStop[2]=busstop[20].getName();
    D1BusStop[3]=busstop[21].getName();
    D1BusStop[4]=busstop[22].getName();
    D1BusStop[5]=busstop[23].getName();
    D1BusStop[6]=busstop[33].getName();
    D1BusStop[7]=busstop[34].getName();
    D1BusStop[8]=busstop[7].getName();
    D1BusStop[9]=busstop[8].getName();
    D1BusStop[10]=busstop[9].getName();
    D1BusStop[11]=busstop[10].getName();
    D1BusStop[12]=busstop[11].getName();
    D1BusStop[13]=busstop[12].getName();

    //initialize D2 Route
    D2Route[0]=&busstop[0];
    D2Route[1]=&busstop[2];
    D2Route[2]=&busstop[4];
    D2Route[3]=&busstop[5];
    D2Route[4]=&busstop[6];
    D2Route[5]=&busstop[23];
    D2Route[6]=&busstop[33];
    D2Route[7]=&busstop[24];
    D2Route[8]=&busstop[25];
    D2Route[9]=&busstop[26];
    D2Route[10]=&busstop[28];
    D2Route[11]=&busstop[0];

    D2BusStop[0]=busstop[0].getName();
    D2BusStop[1]=busstop[2].getName();
    D2BusStop[2]=busstop[4].getName();
    D2BusStop[3]=busstop[5].getName();
    D2BusStop[4]=busstop[6].getName();
    D2BusStop[5]=busstop[23].getName();
    D2BusStop[6]=busstop[33].getName();
    D2BusStop[7]=busstop[24].getName();
    D2BusStop[8]=busstop[25].getName();
    D2BusStop[9]=busstop[26].getName();
    D2BusStop[10]=busstop[28].getName();
    D2BusStop[11]=busstop[0].getName();

    //initialize position of all bus to -1
    for(int i=0;i<17;i++){
        A1Position[i]=-1;
        A2Position[i]=-1;
        nextA1Position[i]=-1;
        nextA2Position[i]=-1;
        if(i<16)
        {
            BPosition[i]=-1;
            nextBPosition[i]=-1;
        }
        if(i<12)
        {
            CPosition[i]=-1;
            D2Position[i]=-1;
            nextCPosition[i]=-1;
            nextD2Position[i]=-1;
        }
        if(i<14)
        {
            D1Position[i]=-1;
            nextD1Position[i]=-1;
        }
    }

    //simulate position for testing purpose
    A1Position[2]=bus[0].getID();
    nextA1Position[0]=bus[6].getID();
    A2Position[0]=bus[1].getID();
    BPosition[0]=bus[2].getID();
    CPosition[0]=bus[3].getID();
    D1Position[0]=bus[4].getID();
    D2Position[0]=bus[5].getID();
    bus[0].addPassenger(30);
    bus[3].addPassenger(20);
    bus[5].addPassenger(10);

    //qDebug()<<"Before initialization of service";
    //initialize service for bus stops
    for(int i=0;i<17;i++){
        A1Route[i]->addService("A1");
    }
    for(int i=0;i<17;i++){
        A2Route[i]->addService("A2");
    }
    for(int i=0;i<16;i++){
        BRoute[i]->addService("B");
    }
    for(int i=0;i<12;i++){
        CRoute[i]->addService("C");
    }
    for(int i=0;i<14;i++){
        D1Route[i]->addService("D1");
    }
    for(int i=0;i<12;i++){
        D2Route[i]->addService("D2");
    }
}

int BusSimulator::getCrowdedness(const QString &busstopname)
{
    int busstopindex=getBusStopIndex(busstopname);
    return busstop[busstopindex].getCrowdedness();
}

QVector<QString> BusSimulator::getService(const QString &busstopname)
{
    int busstopindex=getBusStopIndex(busstopname);
    //qDebug()<<busstopindex;
    QVector<QString> service=busstop[busstopindex].getService();
    //qDebug()<<"service count: "<<service.count();
    return service;
}

QString* BusSimulator::getRoute(const QString &route)
{
    if(route=="A1")
        return A1BusStop;
    else if(route=="A2")
        return A2BusStop;
    else if(route=="B")
        return BBusStop;
    else if(route=="C")
        return CBusStop;
    else if(route=="D1")
        return D1BusStop;
    else
        return D2BusStop;
}

//TODO: clean up this method
/*BusStop BusSimulator::getBusStop(const QString &route, int order)
{
    if(route=="A1")
        return A1Route[order];
    else if(route=="A2")
        return A2Route[order];
    else if(route=="B")
        return BRoute[order];
    else if(route=="C")
        return CRoute[order];
    else if(route=="D1")
        return D1Route[order];
    else
        return D2Route[order];
}*/

void BusSimulator::dispatchBus(const QString &route)
{
    //find an available bus
    for(int i=0;i<26;i++)
    {
        if(bus[i].isDispatched()==false)
            bus[i].setDispatchStatus(route, true);
    }
}

int BusSimulator::getBusStopIndex(const QString &busstopname)
{
    int busstopindex=-1;
    //find the bus stop
    for(int i=0;i<34;i++)
    {
        if(busstop[i].getName()==busstopname)
        {
            busstopindex=i;
            break;
        }
    }
    return busstopindex;
}

QVector<int> BusSimulator::getTiming(const QString &busstopname, bool nextBus)
{
    int busstopindex=getBusStopIndex(busstopname);
    int startIndex=-1;
    QVector<int> time;
    QVector<QString> service= busstop[busstopindex].getService();

    //calculate time for all bus service in this bus stop
    for(int i=0;i<service.count();i++)
    {
        startIndex=getStartIndex(service[i], busstop[busstopindex].getName());
        if(startIndex<=0)
        {
            time.append(0);
        }
        else
        {
            //calculate time for coming bus and the subsequent bus
            time.append(calculateTime(service[i],startIndex, nextBus));
        }
    }

    return time;
}

QVector<int> BusSimulator::getOccupancy(const QString &busstopname)
{
    int busstopindex=getBusStopIndex(busstopname);
    QVector<int> occupancy;
    QVector<QString> service= busstop[busstopindex].getService();

    //calculate occupancy for all bus service in this bus stop
    for(int i=0;i<service.count();i++)
    {
        if(service[i]=="A1")
            occupancy.append(getBusOccupancy(A1ID));
        else if(service[i]=="A2")
            occupancy.append(getBusOccupancy(A2ID));
        else if(service[i]=="B")
            occupancy.append(getBusOccupancy(BID));
        else if(service[i]=="C")
            occupancy.append(getBusOccupancy(CID));
        else if(service[i]=="D1")
            occupancy.append(getBusOccupancy(D1ID));
        else if(service[i]=="D2")
            occupancy.append(getBusOccupancy(D2ID));
    }

    return occupancy;

}

int BusSimulator::getBusOccupancy(int busID)
{
    if(busID>-1)
        return bus[busID].getOccupancy();
    else
        return 0;
}

int BusSimulator::getStartIndex(const QString &route, const QString &busstopname){

    int startIndex=-1;

    //find the bus stop we want to view the timing in
    if(route=="A1")
    {
        for(int i=0;i<17;i++)
        {
            if(A1BusStop[i]==busstopname)
                startIndex=i;
        }
    }
    else if(route=="A2")
    {
        for(int i=0;i<17;i++)
        {
            if(A2BusStop[i]==busstopname)
                startIndex=i;
        }
    }
    else if(route=="B")
    {
        for(int i=0;i<16;i++)
        {
            if(BBusStop[i]==busstopname)
                startIndex=i;
        }
    }
    else if(route=="C")
    {
        for(int i=0;i<12;i++)
        {
            if(CBusStop[i]==busstopname)
                startIndex=i;
        }
    }
    else if(route=="D1")
    {
        for(int i=0;i<14;i++)
        {
            if(D1BusStop[i]==busstopname)
                startIndex=i;
        }
    }
    else if(route=="D2")
    {
        for(int i=0;i<12;i++)
        {
            if(D2BusStop[i]==busstopname)
                startIndex=i;
        }
    }

    return startIndex;
}

int BusSimulator::calculateTime(const QString &route, int startIndex, bool nextBus)
{
    int time=0;
    bool found=false;
    if(route=="A1")
    {
        for(int i=startIndex;i>-1;i--)
        {
            if(nextBus==false && A1Position[i]!=-1)
            {
                found=true;
                A1ID=A1Position[i];
                break;
            }else if(nextA1Position[i]!=-1){
                found=true;
                break;
            }
            time+=2;
        }
    }
    else if(route=="A2")
    {
        for(int i=startIndex;i>-1;i--)
        {
            if(nextBus==false && A2Position[i]!=-1)
            {
                found=true;
                A2ID=A2Position[i];
                break;
            }else if(nextA2Position[i]!=-1){
                found=true;
                break;
            }
            time+=2;
        }
    }
    else if(route=="B")
    {
        for(int i=startIndex;i>-1;i--)
        {
            if(nextBus==false && BPosition[i]!=-1)
            {
                found=true;
                BID=BPosition[i];
                break;
            }else if(nextBPosition[i]!=-1){
                found=true;
                break;
            }
            time+=2;
        }
    }
    else if(route=="C")
    {
        for(int i=startIndex;i>-1;i--)
        {
            if(nextBus==false && CPosition[i]!=-1)
            {
                found=true;
                CID=CPosition[i];
                break;
            }else if(nextCPosition[i]!=-1){
                found=true;
                break;
            }
            time+=2;
        }
    }
    else if(route=="D1")
    {
        for(int i=startIndex;i>-1;i--)
        {
            if(nextBus==false && D1Position[i]!=-1)
            {
                found=true;
                D1ID=D1Position[i];
                break;
            }else if(nextD1Position[i]!=-1){
                found=true;
                break;
            }
            time+=2;
        }
    }
    else if(route=="D2")
    {
        for(int i=startIndex;i>-1;i--)
        {
            if(nextBus==false && D2Position[i]!=-1)
            {
                found=true;
                D2ID=D2Position[i];
                break;
            }else if(nextD2Position[i]!=-1){
                found=true;
                break;
            }
            time+=2;
        }
    }

    if(found)
        return time;
    else
        return 0;
}
