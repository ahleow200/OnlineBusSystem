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
    mainWindowLayout = new QGridLayout();
    createTitleBar();
    createBusStopList();
    createBusTimePanel();
    createMapPanel();

    QWidget *window = new QWidget();
    window->setLayout(mainWindowLayout);

    setCentralWidget(window);

    myTimerId=0;
    timerCount=0;

    bs=new BusSimulator();
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
        QVector<int> time=bs->getTiming("House 7", false);
        QVector<int> nextTime= bs->getTiming("House 7",true);
        QVector<int> occupancy= bs->getOccupancy("House 7");
        QVector<int> occupancyLimit=bs->getOccupancyLimit("House 7");
        QVector<QString> service=bs->getService("House 7");
        qDebug()<<"House 7 crowdedness: "<<bs->getCrowdedness("House 7");
        for(int i=0;i<service.count();i++)
        {
            if(occupancyLimit[i]>60)
                qDebug()<<service[i]<<" occupancy:"<<0<<"/"<<60<<" next bus:"<<time[i]<<" "<<nextTime[i];
            else
                qDebug()<<service[i]<<" occupancy:"<<occupancy[i]<<"/"<<occupancyLimit[i]<<" next bus:"<<time[i]<<" "<<nextTime[i];
        }
        bs->advanceAllBus();
        bs->addCrowd();
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
    busStopList = new QListWidget();

    searchBar = new QLineEdit();
    searchButton = new QPushButton("Search");
    busStopLabel = new QLabel("Science"); //test
    busIcon = new QLabel("bus"); //test

    busStopSearchColumn->addWidget(searchBar);
    busStopSearchColumn->addWidget(searchButton);

    busStopObject->addWidget(busStopLabel);
    busStopObject->addWidget(busIcon);

    //busStopListScroll->addWidget(busStopObject);
    /*
    busStopList->addLayout(busStopObject);
    busStopList->addLayout(busStopObject);
    busStopList->addLayout(busStopObject);
    busStopList->addLayout(busStopObject);
    busStopList->addLayout(busStopObject);
    */

    busStopList->addItem(new QListWidgetItem("Science"));
    busStopList->addItem(new QListWidgetItem("Science"));
    busStopList->addItem(new QListWidgetItem("Science"));
    busStopList->addItem(new QListWidgetItem("Science"));
    busStopList->addItem(new QListWidgetItem("Science"));

    busStopList->setItemWidget(new QListWidgetItem("Science"),busIcon);

    busStopList->setFixedHeight(400);
    //busStopList->setLayout(busStopObject);

    busStopListLayout->addLayout(busStopSearchColumn);
    busStopListLayout->addWidget(busStopList);

    mainWindowLayout->addLayout(busStopListLayout,0,0);

/*
    QWidget *window = new QWidget();
    window->setLayout(busStopListLayout);

    setCentralWidget(window);
*/
}

void MainWindow::createBusTimePanel()
{        
    QLabel *nextBusTime;
    QLabel *nextTwoBusTime;
    QLabel *minLabel;

    timePanel = new QHBoxLayout();
    leftPanel = new QVBoxLayout();
    estimateTime = new QVBoxLayout();
    occupancyBox = new QHBoxLayout();
    timeObject = new QHBoxLayout();
    timeObject2 = new QHBoxLayout();

    busName = new QLabel("A1");
    occupancyLabel = new QLabel("Occupancy: ");
    vacancyLabel = new QLabel("40");
    slashLabel = new QLabel("/");
    busSeatLabel = new QLabel("60");

    occupancyBox->addWidget(occupancyLabel);
    occupancyBox->addWidget(vacancyLabel);
    occupancyBox->addWidget(slashLabel);
    occupancyBox->addWidget(busSeatLabel);

    nextBusTime = new QLabel("7");
    nextTwoBusTime = new QLabel("20");
    //nextTwoBusTime = new QLabel("22");
    minLabel = new QLabel("min");

    timeObject->addWidget(nextBusTime);
    timeObject->addWidget(minLabel);

    timeObject2->addWidget(nextTwoBusTime);
    timeObject2->addWidget(minLabel);

    leftPanel->addWidget(busName);
    leftPanel->addLayout(occupancyBox);

    estimateTime->addLayout(timeObject);
    estimateTime->addLayout(timeObject2);

    timePanel->addLayout(leftPanel);
    timePanel->addLayout(estimateTime);

    mainWindowLayout->addLayout(timePanel,1,0);
}

void MainWindow::createMapPanel()
{
    mapLabel = new QLabel("Map is here.");

    mapLabel->setFixedHeight(300);
    mapLabel->setFixedWidth(800);

    mainWindowLayout->addWidget(mapLabel,0,1);
}
