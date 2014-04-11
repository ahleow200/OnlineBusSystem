#include "mainwindow.h"
#include "bussimulator.h"
#include "busstop.h"
#include <QtDebug>
#include <iostream>
#include <stdio.h>

class BusSimulator;
class BusStop;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    createTitleBar();
    createBusStopList();

    myTimerId=0;
    timerCount=0;

    bs=new BusSimulator();

    //testing for printing all bus stops for a bus route
    QString *a1busstop=bs->getRoute("A1");
    QString *cbusstop=bs->getRoute("C");
    QString *d2busstop=bs->getRoute("D2");
    qDebug()<<"A1 Bus Stops============================";
    for(int i=0;i<16;i++)
    {
        qDebug()<<a1busstop[i];
    }

    qDebug()<<"C Bus Stops============================";
    for(int i=0;i<12;i++)
    {
        qDebug()<<cbusstop[i];
    }

    qDebug()<<"D2 Bus Stops============================";
    for(int i=0;i<12;i++)
    {
        qDebug()<<d2busstop[i];
    }

    //testing for timing calculation
    qDebug()<<"get upcoming bus timing";
    QVector<int> time=bs->getTiming("LT29", false);
    qDebug()<<"get next bus timing";
    QVector<int> nextTime= bs->getTiming("LT29",true);
    QVector<int> occupancy= bs->getOccupancy("LT29");
    QVector<int> occupancyLimit= bs->getOccupancyLimit("LT29");
    QVector<QString> service=bs->getService("LT29");
    qDebug()<<service.count();
    qDebug()<<"LT29 crowdedness:"<<bs->getCrowdedness("LT29");
    for(int i=0;i<service.count();i++)
    {
        qDebug()<<service[i]<<" occupancy:"<<occupancy[i]<<"/"<<occupancyLimit[i]<<" next bus:"<<time[i]<<" "<<nextTime[i];
    }

    time=bs->getTiming("House 7", false);
    qDebug()<<"Timing calculated";
    nextTime=bs->getTiming("House 7",true);
    occupancy= bs->getOccupancy("House 7");
    occupancyLimit=bs->getOccupancyLimit("House 7");
    qDebug()<<"House 7"<<bs->getCrowdedness("House 7");
    service=bs->getService("House 7");
    for(int i=0;i<service.count();i++)
    {
        qDebug()<<service[i]<<" occupancy:"<<occupancy[i]<<"/"<<occupancyLimit[i]<<" next bus:"<<time[i]<<" "<<nextTime[i];
    }

    bs->advanceAllBus();
    bs->dispatchBus("C");
    qDebug()<<"After buses advanced---------------------------------";
    time=bs->getTiming("LT29", false);
    qDebug()<<"Timing calculated";
    nextTime=bs->getTiming("LT29",true);
    occupancy= bs->getOccupancy("LT29");
    occupancyLimit=bs->getOccupancyLimit("LT29");
    qDebug()<<"LT29 crowdedness:"<<bs->getCrowdedness("LT29");
    for(int i=0;i<service.count();i++)
    {
        qDebug()<<service[i]<<" occupancy:"<<occupancy[i]<<"/"<<occupancyLimit[i]<<" next bus:"<<time[i]<<" "<<nextTime[i];
    }

    time=bs->getTiming("House 7", false);
    qDebug()<<"Timing calculated";
    nextTime=bs->getTiming("House 7",true);
    occupancy= bs->getOccupancy("House 7");
    occupancyLimit=bs->getOccupancyLimit("House 7");
    qDebug()<<"House 7"<<bs->getCrowdedness("House 7");
    service=bs->getService("House 7");
    for(int i=0;i<service.count();i++)
    {
        qDebug()<<service[i]<<" occupancy:"<<occupancy[i]<<"/"<<occupancyLimit[i]<<" next bus:"<<time[i]<<" "<<nextTime[i];
    }

    bs->advanceAllBus();
    qDebug()<<"After buses advanced 2nd time---------------------------------";
    time=bs->getTiming("House 7", false);
    qDebug()<<"Timing calculated";
    nextTime=bs->getTiming("House 7",true);
    occupancy= bs->getOccupancy("House 7");
    occupancyLimit=bs->getOccupancyLimit("House 7");
    qDebug()<<"House 7"<<bs->getCrowdedness("House 7");
    service=bs->getService("House 7");
    for(int i=0;i<service.count();i++)
    {
        qDebug()<<service[i]<<" occupancy:"<<occupancy[i]<<"/"<<occupancyLimit[i]<<" next bus:"<<time[i]<<" "<<nextTime[i];
    }

    bs->dispatchBus("A1");
    qDebug()<<"After A1 bus is dispatched---------------------------------";
    time=bs->getTiming("House 7", false);
    qDebug()<<"Timing calculated";
    nextTime=bs->getTiming("House 7",true);
    occupancy= bs->getOccupancy("House 7");
    occupancyLimit=bs->getOccupancyLimit("House 7");
    qDebug()<<"House 7"<<bs->getCrowdedness("House 7");
    service=bs->getService("House 7");
    for(int i=0;i<service.count();i++)
    {
        qDebug()<<service[i]<<" occupancy:"<<occupancy[i]<<"/"<<occupancyLimit[i]<<" next bus:"<<time[i]<<" "<<nextTime[i];
    }
}

MainWindow::~MainWindow()
{

}

//event overwrite
void MainWindow::showEvent(QShowEvent *event)
{
    myTimerId=startTimer(3000);
}

void MainWindow::hideEvent(QHideEvent *event)
{
    killTimer(myTimerId);
}

void MainWindow::timerEvent(QTimerEvent *event)
{
    if (event->timerId() == myTimerId)
    {
        //simulate bus system
        //dispatch buses
        if(timerCount>=6)
        {
            bs->dispatchBus("A1");
            bs->dispatchBus("A2");
            bs->dispatchBus("B");
            bs->dispatchBus("C");
            bs->dispatchBus("D1");
            bs->dispatchBus("D2");
            timerCount=0;
        }

        //get bus location
        int *a1position=bs->getBusPosition("A1");
        int *a2position=bs->getBusPosition("A2");
        int *bposition=bs->getBusPosition("B");
        int *cposition=bs->getBusPosition("C");
        int *d1position=bs->getBusPosition("D1");
        int *d2position=bs->getBusPosition("D2");

        //print all bus location
        qDebug()<<"A1=================================================";
        qDebug()<<"0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15";
        QString a1map;
        for(int i=0;i<A1BusStopCount;i++)
        {
            if(a1position[i]!=-1)
                a1map.append("[v] ");
                //qDebug("[v] ");
            else
                a1map.append("[] ");
                //qDebug("[] ");
        }
        qDebug()<<a1map;
        bs->advanceAllBus();
        timerCount++;
    }
    else
        QWidget::timerEvent(event); // propagate

}

//GUI
void MainWindow::createTitleBar()
{
    titleLayout = new QHBoxLayout();

    leftTitle = new QLabel("NUS");
    middleTitle = new QLabel("Online Bus System");
    loginButton = new QPushButton("Login");

    titleLayout->addWidget(leftTitle);
    titleLayout->addWidget(middleTitle);
    titleLayout->addWidget(loginButton);

    QWidget *window = new QWidget();
    window->setLayout(titleLayout);

    setMenuWidget(window);
}

void MainWindow::createBusStopList()
{
    busStopSearchColumn = new QHBoxLayout();
    busStopObject = new QHBoxLayout();
    busStopListLayout = new QVBoxLayout();

    searchBar = new QLineEdit();
    searchButton = new QPushButton("Search");
    busStopButton = new QPushButton("Science"); //test
    busIcon = new QLabel("bus"); //test


    busStopSearchColumn->addWidget(searchBar);
    busStopSearchColumn->addWidget(searchButton);

    busStopObject->addWidget(busStopButton);
    busStopObject->addWidget(busIcon);

    //busStopListScroll->addWidget(busStopObject);

    busStopListLayout->addLayout(busStopSearchColumn);
    busStopListLayout->addLayout(busStopObject);

    QWidget *window = new QWidget();
    window->setLayout(busStopListLayout);

    setCentralWidget(window);

}

void MainWindow::createBusTimePanel()
{

}
