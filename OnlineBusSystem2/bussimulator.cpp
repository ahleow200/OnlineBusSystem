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
    // Create seed for the random
    // That is needed only once on application startup
    time = QTime::currentTime();
    qsrand((uint)time.msec());

    //initialize bus
    for(int i=0;i<BusCount;i++)
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

    currentA1=-1;
    currentA2=-1;
    currentB=-1;
    currentC=-1;
    currentD1=-1;
    currentD2=-1;

    //initialize bus stop
    busstop[0].initialize("PGP Terminal",493,413);
    busstop[1].initialize("After Science Park Drive",673,334);
    busstop[2].initialize("KR MRT Station",645,252);
    busstop[3].initialize("NUH",576,202);
    busstop[4].initialize("LT29",429,194);
    busstop[5].initialize("University Hall",337,237);
    busstop[6].initialize("Opp University Health Centre",188,222);
    busstop[7].initialize("Yushof Ishak House",136,230);
    busstop[8].initialize("Central Library",98,346);
    busstop[9].initialize("LT13",47,457);
    busstop[10].initialize("AS7",117,488);
    busstop[11].initialize("COM2",185,435);
    busstop[12].initialize("BIZ2",258,444);
    busstop[13].initialize("Opp House 12",342,394);
    busstop[14].initialize("House 7",373,409);
    busstop[15].initialize("Between House 14 & 15",385,426);
    busstop[16].initialize("House 12",347,420);
    busstop[17].initialize("Opp Hon Sui Sen Memorial Library",275,459);
    busstop[18].initialize("Temasek Hall",134,521);
    busstop[19].initialize("Eusoff Hall",62,505);
    busstop[20].initialize("Ventus",31,436);
    busstop[21].initialize("Computer Centre",94,307);
    busstop[22].initialize("Opp Yushof Ishak House",113,227);
    busstop[23].initialize("Museum",43,139);
    busstop[24].initialize("University Health Centre",211,199);
    busstop[25].initialize("Opp University Hall",291,224);
    busstop[26].initialize("Block S17",441,178);
    busstop[27].initialize("Opp NUH",539,175);
    busstop[28].initialize("Opp KR MRT Station",654,243);
    busstop[29].initialize("The Japanese Primary School",0,0);
    busstop[30].initialize("Block E3A",0,0);
    busstop[31].initialize("Raffles Hall",0,0);
    busstop[32].initialize("Opp Block EA",0,0);
    busstop[33].initialize("University Town",121,17);
    busstop[34].initialize("Kent Ridge Crescent",0,0);
	
	//initialize All Route
	for(int i=0;i<BusStopCount;i++){
		AllRoute[i]= &busstop[i];
		AllBusStop[i]=busstop[i].getName();
	}
    //initialize A1 Route
    for(int i=0;i<A1BusStopCount-1;i++)
    {
        A1Route[i]=&busstop[i];
        A1BusStop[i]=busstop[i].getName();
    }
    A1Route[A1BusStopCount-1]=&busstop[0];
    A1BusStop[A1BusStopCount-1]=busstop[0].getName();

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
    for(int i=0;i<A2BusStopCount;i++){
        A2Position[i]=-1;
        if(i<A1BusStopCount)
        {
            A1Position[i]=-1;
            BPosition[i]=-1;
        }
        if(i<CBusStopCount)
        {
            CPosition[i]=-1;
            D2Position[i]=-1;
        }
        if(i<D1BusStopCount)
        {
            D1Position[i]=-1;
        }
    }

    //simulate position for testing purpose
    /*A1Position[2]=bus[0].getID();
    A1Position[13]=bus[6].getID();
    A2Position[0]=bus[1].getID();
    BPosition[0]=bus[2].getID();
    CPosition[0]=bus[3].getID();
    D1Position[0]=bus[4].getID();
    D2Position[0]=bus[5].getID();
    bus[0].addPassenger(30);
    bus[3].addPassenger(20);
    bus[5].addPassenger(10);*/

    //qDebug()<<"Before initialization of service";
    //initialize service for bus stops
    for(int i=0;i<A1BusStopCount;i++){
        A1Route[i]->addService("A1");
    }
    for(int i=0;i<A2BusStopCount;i++){
        A2Route[i]->addService("A2");
    }
    for(int i=0;i<BBusStopCount;i++){
        BRoute[i]->addService("B");
    }
    for(int i=0;i<CBusStopCount;i++){
        CRoute[i]->addService("C");
    }
    for(int i=0;i<D1BusStopCount;i++){
        D1Route[i]->addService("D1");
    }
    for(int i=0;i<D2BusStopCount;i++){
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

/*
BusStop* BusSimulator::getRoute(const QString &route)
{	
	if(route=="All")
		return AllRoute;
    else if(route=="A1")
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
*/

int BusSimulator::getBusStopIndex(const QString &busstopname)
{
    int busstopindex=-1;
    //find the bus stop
    for(int i=0;i<BusStopCount;i++)
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
            time.append(calculateTime(service[i],startIndex,nextBus));
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

QVector<int> BusSimulator::getOccupancyLimit(const QString &busstopname)
{
    int busstopindex=getBusStopIndex(busstopname);
    QVector<int> occupancyLimit;
    QVector<QString> service= busstop[busstopindex].getService();

    //calculate occupancy for all bus service in this bus stop
    for(int i=0;i<service.count();i++)
    {
        if(service[i]=="A1")
            occupancyLimit.append(bus[A1ID].getOccupancyLimit());
        else if(service[i]=="A2")
            occupancyLimit.append(bus[A2ID].getOccupancyLimit());
        else if(service[i]=="B")
            occupancyLimit.append(bus[BID].getOccupancyLimit());
        else if(service[i]=="C")
            occupancyLimit.append(bus[CID].getOccupancyLimit());
        else if(service[i]=="D1")
            occupancyLimit.append(bus[D1ID].getOccupancyLimit());
        else if(service[i]=="D2")
            occupancyLimit.append(bus[D2ID].getOccupancyLimit());
    }

    return occupancyLimit;
}

int BusSimulator::getBusOccupancy(int busID)
{
    if(busID>-1)
        return bus[busID].getOccupancy();
    else
        return 0;
}

int BusSimulator::getStartIndex(const QString &route, const QString &busstopname){

    //find the bus stop we want to view the timing in
    if(route=="A1")
    {
        for(int i=0;i<A1BusStopCount;i++)
        {
            if(A1BusStop[i]==busstopname)
                return i;
        }
    }
    else if(route=="A2")
    {
        for(int i=0;i<A2BusStopCount;i++)
        {
            if(A2BusStop[i]==busstopname)
                return i;
        }
    }
    else if(route=="B")
    {
        for(int i=0;i<BBusStopCount;i++)
        {
            if(BBusStop[i]==busstopname)
                return i;
        }
    }
    else if(route=="C")
    {
        for(int i=0;i<CBusStopCount;i++)
        {
            if(CBusStop[i]==busstopname)
                return i;
        }
    }
    else if(route=="D1")
    {
        for(int i=0;i<D1BusStopCount;i++)
        {
            if(D1BusStop[i]==busstopname)
                return i;
        }
    }
    else if(route=="D2")
    {
        for(int i=0;i<D2BusStopCount;i++)
        {
            if(D2BusStop[i]==busstopname)
                return i;
        }
    }

    return -1;
}

int BusSimulator::calculateTime(const QString &route, int startIndex, bool nextBus)
{
    int time=0;
    bool found=false;
    if(route=="A1")
    {
        for(int i=startIndex;i>-1;i--)
        {
            if(A1Position[i]!=-1)
            {
                if(nextBus==false)
                {
                    found=true;
                    A1ID=A1Position[i];
                    currentA1=i;
                    qDebug()<<"start index= "<<startIndex<<"current A1= "<<currentA1;
                    break;
                }
                else
                {
                    if(i!=currentA1)
                    {
                        found=true;
                        break;
                    }
                }
            }
            time+=2;
        }
    }
    else if(route=="A2")
    {
        for(int i=startIndex;i>-1;i--)
        {
            if(A2Position[i]!=-1)
            {           
                if(nextBus==false)
                {
                    found=true;
                    A2ID=A2Position[i];
                    currentA2=i;
                    break;
                }
                else
                {
                    if(i!=currentA2)
                    {
                        found=true;
                        break;
                    }
                }

            }
            time+=2;
        }
    }
    else if(route=="B")
    {
        for(int i=startIndex;i>-1;i--)
        {
            if(BPosition[i]!=-1)
            {
                if(nextBus==false)
                {
                    found=true;
                    BID=BPosition[i];
                    currentB=i;
                    break;
                }
                else
                {
                    if(i!=currentB)
                    {
                        found=true;
                        break;
                    }
                }

            }
            time+=2;
        }
    }
    else if(route=="C")
    {
        for(int i=startIndex;i>-1;i--)
        {
            if(CPosition[i]!=-1)
            {       
                if(nextBus==false)
                {
                    found=true;
                    CID=CPosition[i];
                    currentC=i;
                    break;
                }
                else
                {
                    if(i!=currentC)
                    {
                        found=true;
                        break;
                    }
                }

            }
            time+=2;
        }
    }
    else if(route=="D1")
    {
        for(int i=startIndex;i>-1;i--)
        {
            if(D1Position[i]!=-1)
            {
                if(nextBus==false)
                {
                    found=true;
                    D1ID=D1Position[i];
                    currentD1=i;
                    break;
                }
                else
                {
                    if(i!=currentD1)
                    {
                        found=true;
                        break;
                    }
                }

            }
            time+=2;
        }
    }
    else if(route=="D2")
    {
        for(int i=startIndex;i>-1;i--)
        {
            if(D2Position[i]!=-1)
            {            
                if(nextBus==false)
                {
                    found=true;
                    D2ID=D2Position[i];
                    currentD2=i;
                    break;
                }
                else
                {
                    if(i!=currentD2)
                    {
                        found=true;
                        break;
                    }
                }

            }
            time+=2;
        }
    }

    if(found)
        return time;
    else
        return 0;
}

int BusSimulator::getAvailableBus(){
    //find an available bus
    for(int i=0;i<BusCount;i++)
    {
        if(bus[i].isDispatched()==false)
        {
            return i;
        }
    }
    return -1;
}

QString BusSimulator::dispatchBus(const QString &route)
{
    int availableBusID=getAvailableBus();

    //check if there's any bus available. If not, return.
    if(availableBusID==-1)
        return "Currently, there's no available bus to be dispatched.";

    //you cannot dispatch bus if there is still bus with the same service in its starting point
    if(route=="A1" && A1Position[0]==-1)
    {
        bus[availableBusID].setDispatchStatus("A1",true);
        A1Position[0]=bus[availableBusID].getID();
        boardPassenger("A1",0);
        if(findBusPosition("A1")==-1) //if there's no bus dispatched yet
            currentA1=0;
        return "Successfully dispatched an A1 bus";
    }
    else if(route=="A2" && A2Position[0]==-1)
    {
        bus[availableBusID].setDispatchStatus("A2",true);
        A2Position[0]=bus[availableBusID].getID();
        boardPassenger("A2",0);
        if(findBusPosition("A2")==-1) //if there's no bus dispatched yet
            currentA2=0;
        return "Successfully dispatched an A2 bus";
    }
    else if(route=="B" && BPosition[0]==-1)
    {
        bus[availableBusID].setDispatchStatus("B",true);
        BPosition[0]=bus[availableBusID].getID();
        boardPassenger("B",0);
        if(findBusPosition("B")==-1) //if there's no bus dispatched yet
            currentB=0;
        return "Successfully dispatched a B bus";
    }
    else if(route=="C" && CPosition[0]==-1)
    {
        bus[availableBusID].setDispatchStatus("C",true);
        CPosition[0]=bus[availableBusID].getID();
        boardPassenger("C",0);
        if(findBusPosition("C")==-1) //if there's no bus dispatched yet
            currentC=0;
        return "Successfully dispatched a C bus";
    }
    else if(route=="D1" && D1Position[0]==-1)
    {
        bus[availableBusID].setDispatchStatus("D1",true);
        D1Position[0]=bus[availableBusID].getID();
        boardPassenger("D1",0);
        if(findBusPosition("D1")==-1) //if there's no bus dispatched yet
            currentD1=0;
        return "Successfully dispatched a D1 bus";
    }
    else if(route=="D2" && D2Position[0]==-1)
    {
        bus[availableBusID].setDispatchStatus("D2",true);
        D2Position[0]=bus[availableBusID].getID();
        boardPassenger("D2",0);
        if(findBusPosition("D2")==-1) //if there's no bus dispatched yet
            currentD2=0;
        return "Successfully dispatched a D2 bus";
    }
    else
    {
        return "A bus with the same service is still in its starting point. Please wait a moment.";
    }
}

void BusSimulator::advanceAllBus(){
    advanceBus("A1");
    advanceBus("A2");
    advanceBus("B");
    advanceBus("C");
    advanceBus("D1");
    advanceBus("D2");
}

void BusSimulator::advanceBus(const QString &route)
{
    bool currentModified=false;

    if(route=="A1")
    {
        for(int i=A1BusStopCount-2;i>-1;i--)
        {
            //if found a bus on route, advance its position
            if(A1Position[i]!=-1)
            {
                //if found a bus ending its route, terminate its service
                if(i+1==A1BusStopCount-1)
                {
                    bus[A1Position[i]].setDispatchStatus("A1",false);
                    A1Position[i]=-1;
                    //find the subsequent bus
                    currentA1=findBusPosition("A1");
                }

                if(currentA1!=-1){
                    //advance the bus by one stop
                    A1Position[i+1]=A1Position[i];
                    A1Position[i]=-1;
                    boardPassenger("A1",i+1);
                    //qDebug()<<"A1Position[i]="<<A1Position[i+1]<<"A1Position[i-1]="<<A1Position[i];
                    if(currentModified==false)
                    {
                        currentA1++;
                        currentModified=true;
                    }
                }
            }
        }
        //qDebug()<<"current A1 is now= "<<currentA1<<" A1 Position= "<<A1Position[currentA1];
    }
    else if(route=="A2")
    {
        for(int i=A2BusStopCount-2;i>-1;i--)
        {
            //if found a bus on route, advance its position
            if(A2Position[i]!=-1)
            {
                //if found a bus ending its route, terminate its service
                if(i+1==A2BusStopCount-1)
                {
                    bus[A2Position[i]].setDispatchStatus("A2",false);
                    A2Position[i]=-1;
                    //find the subsequent bus
                    currentA2=findBusPosition("A2");
                }

                if(currentA2!=-1){
                    //advance the bus by one stop
                    A2Position[i+1]=A2Position[i];
                    A2Position[i]=-1;
                    boardPassenger("A2",i+1);
                    if(currentModified==false)
                    {
                        currentA2++;
                        currentModified=true;
                    }
                }
            }
        }
    }
    else if(route=="B")
    {
        for(int i=BBusStopCount-2;i>-1;i--)
        {
            //if found a bus on route, advance its position
            if(BPosition[i]!=-1)
            {
                //if found a bus ending its route, terminate its service
                if(i+1==BBusStopCount-1)
                {
                    bus[BPosition[i]].setDispatchStatus("B",false);
                    BPosition[i]=-1;
                    //find the subsequent bus
                    currentB=findBusPosition("B");
                }

                if(currentB!=-1)
                {
                    //advance the bus by one stop
                    BPosition[i+1]=BPosition[i];
                    BPosition[i]=-1;
                    boardPassenger("B",i+1);
                    if(currentModified==false)
                    {
                        currentB++;
                        currentModified=true;
                    }
                }
            }
        }
    }
    else if(route=="C")
    {
        for(int i=CBusStopCount-2;i>-1;i--)
        {
            //if found a bus on route, advance its position
            if(CPosition[i]!=-1)
            {
                //if found a bus ending its route, terminate its service
                if(i+1==CBusStopCount-1)
                {
                    bus[CPosition[i]].setDispatchStatus("C",false);
                    CPosition[i]=-1;
                    //find the subsequent bus
                    currentC=findBusPosition("C");
                }

                if(currentC!=-1)
                {
                    //advance the bus by one stop
                    CPosition[i+1]=CPosition[i];
                    CPosition[i]=-1;
                    boardPassenger("C",i+1);
                    if(currentModified==false)
                    {
                        currentC++;
                        currentModified=true;
                    }
                }
            }
        }
    }
    else if(route=="D1")
    {
        for(int i=D1BusStopCount-2;i>-1;i--)
        {
            //if found a bus on route, advance its position
            if(D1Position[i]!=-1)
            {
                //if found a bus ending its route, terminate its service
                if(i+1==D1BusStopCount-1)
                {
                    bus[D1Position[i]].setDispatchStatus("D1",false);
                    D1Position[i]=-1;
                    //find the subsequent bus
                    currentD1=findBusPosition("D1");
                }

                if(currentD1!=-1)
                {
                    //advance the bus by one stop
                    D1Position[i+1]=D1Position[i];
                    D1Position[i]=-1;
                    boardPassenger("D1",i+1);
                    if(currentModified==false)
                    {
                        currentD1++;
                        currentModified=true;
                    }
                }
            }
        }
    }
    else if(route=="D2")
    {
        for(int i=D2BusStopCount-2;i>-1;i--)
        {
            //if found a bus on route, advance its position
            if(D2Position[i]!=-1)
            {
                //if found a bus ending its route, terminate its service
                if(i+1==D2BusStopCount-1)
                {
                    bus[D2Position[i]].setDispatchStatus("D2",false);
                    D2Position[i]=-1;
                    //find the subsequent bus
                    currentD2=findBusPosition("D2");
                }

                if(currentD2!=-1)
                {
                    //advance the bus by one stop
                    D2Position[i+1]=D2Position[i];
                    D2Position[i]=-1;
                    boardPassenger("D2",i+1);
                    if(currentModified==false)
                    {
                        currentD2++;
                        currentModified=true;
                    }
                }
            }
        }
    }
}

int BusSimulator::findBusPosition(const QString &route)
{
    if(route=="A1")
    {
        for(int i=A1BusStopCount-1;i>-1;i--)
        {
            if(A1Position[i]!=-1)
                return i;
        }
    }
    else if(route=="A2")
    {
        for(int i=A2BusStopCount-1;i>-1;i--)
        {
            if(A2Position[i]!=-1)
                return i;
        }
    }
    else if(route=="B")
    {
        for(int i=BBusStopCount-1;i>-1;i--)
        {
            if(BPosition[i]!=-1)
                return i;
        }
    }
    else if(route=="C")
    {
        for(int i=CBusStopCount-1;i>-1;i--)
        {
            if(CPosition[i]!=-1)
                return i;
        }
    }
    else if(route=="D1")
    {
        for(int i=D1BusStopCount-1;i>-1;i--)
        {
            if(D1Position[i]!=-1)
                return i;
        }
    }
    else if(route=="D2")
    {
        for(int i=D2BusStopCount-1;i>-1;i--)
        {
            if(D2Position[i]!=-1)
                return i;
        }
    }

    return -1;
}

int* BusSimulator::getBusPosition(const QString &route)
{
    if(route=="A1")
        return A1Position;
    else if(route=="A2")
        return A2Position;
    else if(route=="B")
        return BPosition;
    else if(route=="C")
        return CPosition;
    else if(route=="D1")
        return D1Position;
    else
        return D2Position;
}

int BusSimulator::randInt(int low, int high)
{
// Random number between low and high
return qrand() % ((high + 1) - low) + low;
}

void BusSimulator::addCrowd()
{
    // Get random value between 0-100
    int randomValue;
    for(int i=0;i<BusStopCount;i++)
    {
        randomValue = randInt(0,2);
        busstop[i].addToCrowd(randomValue);
    }
}

void BusSimulator::boardPassenger(const QString &route, int index)
{
    int passenger;
    int occupancy;
    int occupancyLimit;
    int availableSpace;
    if(route=="A1")
    {
        occupancy=bus[A1Position[index]].getOccupancy();
        occupancyLimit=bus[A1Position[index]].getOccupancyLimit();
        //alight passengers
        bus[A1Position[index]].subtractPassenger(randInt(0,occupancy));

        //board passengers
        if(bus[A1Position[index]].isFull()==false)
        {
            passenger=randInt(0,A1Route[index]->getCrowdedness());
            availableSpace=occupancyLimit-occupancy;
            if(passenger>availableSpace)
                bus[A1Position[index]].addPassenger(availableSpace);
            else
            {
                bus[A1Position[index]].addPassenger(passenger);
                A1Route[index]->reduceCrowd(passenger);
            }
        }
    }
    else if(route=="A2")
    {
        occupancy=bus[A2Position[index]].getOccupancy();
        occupancyLimit=bus[A2Position[index]].getOccupancyLimit();
        //alight passengers
        bus[A2Position[index]].subtractPassenger(randInt(0,occupancy));

        //board passengers
        if(bus[A2Position[index]].isFull()==false)
        {
            passenger=randInt(0,A2Route[index]->getCrowdedness());
            availableSpace=occupancyLimit-occupancy;
            if(passenger>availableSpace)
                bus[A2Position[index]].addPassenger(availableSpace);
            else
            {
                bus[A2Position[index]].addPassenger(passenger);
                A2Route[index]->reduceCrowd(passenger);
            }
        }
    }
    else if(route=="B")
    {
        occupancy=bus[BPosition[index]].getOccupancy();
        occupancyLimit=bus[BPosition[index]].getOccupancyLimit();
        //alight passengers
        bus[BPosition[index]].subtractPassenger(randInt(0,occupancy));

        //board passengers
        if(bus[BPosition[index]].isFull()==false)
        {
            passenger=randInt(0,BRoute[index]->getCrowdedness());
            availableSpace=occupancyLimit-occupancy;
            if(passenger>availableSpace)
                bus[BPosition[index]].addPassenger(availableSpace);
            else
            {
                bus[BPosition[index]].addPassenger(passenger);
                BRoute[index]->reduceCrowd(passenger);
            }
        }
    }
    else if(route=="C")
    {
        occupancy=bus[CPosition[index]].getOccupancy();
        occupancyLimit=bus[CPosition[index]].getOccupancyLimit();
        //alight passengers
        bus[CPosition[index]].subtractPassenger(randInt(0,occupancy));

        //board passengers
        if(bus[CPosition[index]].isFull()==false)
        {
            passenger=randInt(0,CRoute[index]->getCrowdedness());
            availableSpace=occupancyLimit-occupancy;
            if(passenger>availableSpace)
                bus[CPosition[index]].addPassenger(availableSpace);
            else
            {
                bus[CPosition[index]].addPassenger(passenger);
                CRoute[index]->reduceCrowd(passenger);
            }
        }
    }
    else if(route=="D1")
    {
        occupancy=bus[D1Position[index]].getOccupancy();
        occupancyLimit=bus[D1Position[index]].getOccupancyLimit();
        //alight passengers
        bus[D1Position[index]].subtractPassenger(randInt(0,occupancy));

        //board passengers
        if(bus[D1Position[index]].isFull()==false)
        {
            passenger=randInt(0,D1Route[index]->getCrowdedness());
            availableSpace=occupancyLimit-occupancy;
            if(passenger>availableSpace)
                bus[D1Position[index]].addPassenger(availableSpace);
            else
            {
                bus[D1Position[index]].addPassenger(passenger);
                D1Route[index]->reduceCrowd(passenger);
            }
        }
    }
    else if(route=="D2")
    {
        occupancy=bus[D2Position[index]].getOccupancy();
        occupancyLimit=bus[D2Position[index]].getOccupancyLimit();
        //alight passengers
        bus[D2Position[index]].subtractPassenger(randInt(0,occupancy));

        //board passengers
        if(bus[D2Position[index]].isFull()==false)
        {
            passenger=randInt(0,D2Route[index]->getCrowdedness());
            availableSpace=occupancyLimit-occupancy;
            if(passenger>availableSpace)
                bus[D2Position[index]].addPassenger(availableSpace);
            else
            {
                bus[D2Position[index]].addPassenger(passenger);
                D2Route[index]->reduceCrowd(passenger);
            }
        }
    }
}


