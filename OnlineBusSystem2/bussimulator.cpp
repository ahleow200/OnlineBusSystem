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
        A1Route[i]=busstop[i];
    }
    A1Route[16]=busstop[0];

    //initialize A2 Route
    A2Route[0]=busstop[0];
    A2Route[1]=busstop[15];
    A2Route[2]=busstop[16];
    A2Route[3]=busstop[17];
    A2Route[4]=busstop[11];
    A2Route[5]=busstop[18];
    A2Route[6]=busstop[19];
    A2Route[7]=busstop[20];
    A2Route[8]=busstop[21];
    A2Route[9]=busstop[22];
    A2Route[10]=busstop[23];
    A2Route[11]=busstop[24];
    A2Route[12]=busstop[25];
    A2Route[13]=busstop[26];
    A2Route[14]=busstop[27];
    A2Route[15]=busstop[28];
    A2Route[16]=busstop[0];

    //initialize B Route
    BRoute[0]=busstop[29];
    BRoute[1]=busstop[30];
    BRoute[2]=busstop[23];
    BRoute[3]=busstop[7];
    BRoute[4]=busstop[8];
    BRoute[5]=busstop[9];
    BRoute[6]=busstop[10];
    BRoute[7]=busstop[11];
    BRoute[8]=busstop[18];
    BRoute[9]=busstop[19];
    BRoute[10]=busstop[20];
    BRoute[11]=busstop[21];
    BRoute[12]=busstop[22];
    BRoute[13]=busstop[31];
    BRoute[14]=busstop[30];
    BRoute[15]=busstop[32];

    //initialize C Route
    CRoute[0]=busstop[29];
    CRoute[1]=busstop[30];
    CRoute[2]=busstop[23];
    CRoute[3]=busstop[24];
    CRoute[4]=busstop[25];
    CRoute[5]=busstop[26];
    CRoute[6]=busstop[4];
    CRoute[7]=busstop[5];
    CRoute[8]=busstop[6];
    CRoute[9]=busstop[31];
    CRoute[10]=busstop[30];
    CRoute[11]=busstop[32];

    //initialize D1 Route
    D1Route[0]=busstop[17];
    D1Route[1]=busstop[11];
    D1Route[2]=busstop[20];
    D1Route[3]=busstop[21];
    D1Route[4]=busstop[22];
    D1Route[5]=busstop[23];
    D1Route[6]=busstop[33];
    D1Route[7]=busstop[34];
    D1Route[8]=busstop[7];
    D1Route[9]=busstop[8];
    D1Route[10]=busstop[9];
    D1Route[11]=busstop[10];
    D1Route[12]=busstop[11];
    D1Route[13]=busstop[12];

    //initialize D2 Route
    D2Route[0]=busstop[0];
    D2Route[1]=busstop[2];
    D2Route[2]=busstop[4];
    D2Route[3]=busstop[5];
    D2Route[4]=busstop[6];
    D2Route[5]=busstop[23];
    D2Route[6]=busstop[33];
    D2Route[7]=busstop[24];
    D2Route[8]=busstop[25];
    D2Route[9]=busstop[26];
    D2Route[10]=busstop[28];
    D2Route[11]=busstop[0];

    //initialize position of all bus to -1
    for(int i=0;i<17;i++){
        A1Position[i]=-1;
        A2Position[i]=-1;
        if(i<16)
            BPosition[i]=-1;
        if(i<12)
        {
            CPosition[i]=-1;
            D2Position[i]=-1;
        }
        if(i<14)
            D1Position[i]=-1;
    }
}

BusStop* BusSimulator::getRoute(const QString &route)
{
    if(route=="A1")
        return A1Route;
    else if(route=="A2")
        return A2Route;
    else if(route=="B")
        return BRoute;
    else if(route=="C")
        return CRoute;
    else if(route=="D1")
        return D1Route;
    else
        return D2Route;
}

//TODO: return timing info & crowdedness info of bus stop
BusStop BusSimulator::getBusStop(const QString &route, int order)
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
}

void BusSimulator::dispatchBus(const QString &route)
{
    //find an available bus
    for(int i=0;i<26;i++)
    {
        if(bus[i].isDispatched()==false)
            bus[i].setDispatchStatus(route, true);
    }
}
