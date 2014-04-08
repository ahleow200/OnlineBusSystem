#include "bussimulator.h"

BusSimulator::BusSimulator()
{
    initialize();
}

void BusSimulator::initialize()
{
    //initialize bus
    for(int i=0;i<26;i++)
    {
        bus[i]=new Bus(i);
    }

    //initialize bus stop
    busstop[0]=new BusStop("PGP Terminal");
    busstop[1]=new BusStop("After Science Park Drive");
    busstop[2]=new BusStop("KR MRT Station");
    busstop[3]=new BusStop("NUH");
    busstop[4]=new BusStop("LT29");
    busstop[5]=new BusStop("University Hall");
    busstop[6]=new BusStop("Opp University Health Centre");
    busstop[7]=new BusStop("Yushof Ishak House");
    busstop[8]=new BusStop("Central Library");
    busstop[9]=new BusStop("LT13");
    busstop[10]=new BusStop("AS7");
    busstop[11]=new BusStop("COM2");
    busstop[12]=new BusStop("BIZ2");
    busstop[13]=new BusStop("Opp House 12");
    busstop[14]=new BusStop("House 7");
    busstop[15]=new BusStop("Between House 14 & 15");
    busstop[16]=new BusStop("House 12");
    busstop[17]=new BusStop("Opp Hon Sui Sen Memorial Library");
    busstop[18]=new BusStop("Temasek Hall");
    busstop[19]=new BusStop("Eusoff Hall");
    busstop[20]=new BusStop("Ventus");
    busstop[21]=new BusStop("Computer Centre");
    busstop[22]=new BusStop("Opp Yushof Ishak House");
    busstop[23]=new BusStop("Museum");
    busstop[24]=new BusStop("University Health Centre");
    busstop[25]=new BusStop("Opp University Hall");
    busstop[26]=new BusStop("Block S17");
    busstop[27]=new BusStop("Opp NUH");
    busstop[28]=new BusStop("Opp KR MRT Station");
    busstop[29]=new BusStop("The Japanese Primary School");
    busstop[30]=new BusStop("Block E3A");
    busstop[31]=new BusStop("Raffles Hall");
    busstop[32]=new BusStop("Opp Block EA");
    busstop[33]=new BusStop("University Town");
    busstop[34]=new BusStop("Kent Ridge Crescent");

    //initialize A1 Route
    for(int i=0;i<16;i++)
    {
        A1Route[i]=busstop[i];
    }

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
