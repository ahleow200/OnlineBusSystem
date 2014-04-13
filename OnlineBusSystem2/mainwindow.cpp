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
}

MainWindow::~MainWindow()
{

}

void MainWindow::initialize(BusSimulator **bs)
{
    myTimerId=0;
    timerCount=0;
    this->bs=bs;
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
            (*bs)->dispatchBus("A1");
            (*bs)->dispatchBus("A2");
            (*bs)->dispatchBus("B");
            (*bs)->dispatchBus("C");
            (*bs)->dispatchBus("D1");
            (*bs)->dispatchBus("D2");
            timerCount=0;
        }

        //get bus location
        int *a1position=(*bs)->getBusPosition("A1");
        int *a2position=(*bs)->getBusPosition("A2");
        int *bposition=(*bs)->getBusPosition("B");
        int *cposition=(*bs)->getBusPosition("C");
        int *d1position=(*bs)->getBusPosition("D1");
        int *d2position=(*bs)->getBusPosition("D2");

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
        QVector<int> time=(*bs)->getTiming("House 7", false);
        QVector<int> nextTime= (*bs)->getTiming("House 7",true);
        QVector<int> occupancy= (*bs)->getOccupancy("House 7");
        QVector<int> occupancyLimit=(*bs)->getOccupancyLimit("House 7");
        QVector<QString> service=(*bs)->getService("House 7");
        qDebug()<<"House 7 crowdedness: "<<(*bs)->getCrowdedness("House 7");
        for(int i=0;i<service.count();i++)
        {
            if(occupancyLimit[i]>60)
                qDebug()<<service[i]<<" occupancy:"<<0<<"/"<<60<<" next bus:"<<time[i]<<" "<<nextTime[i];
            else
                qDebug()<<service[i]<<" occupancy:"<<occupancy[i]<<"/"<<occupancyLimit[i]<<" next bus:"<<time[i]<<" "<<nextTime[i];
        }

        //print all bus location
        qDebug()<<"A2=================================================";
        qDebug()<<"0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16";
        QString a2map;
        for(int i=0;i<A2BusStopCount;i++)
        {
            if(a2position[i]!=-1)
                a2map.append("[v] ");
                //qDebug("[v] ");
            else
                a2map.append("[] ");
                //qDebug("[] ");
        }
        qDebug()<<a2map;
        time=(*bs)->getTiming("Opp KR MRT Station", false);
        nextTime= (*bs)->getTiming("Opp KR MRT Station",true);
        occupancy= (*bs)->getOccupancy("Opp KR MRT Station");
        occupancyLimit=(*bs)->getOccupancyLimit("Opp KR MRT Station");
        service=(*bs)->getService("Opp KR MRT Station");
        qDebug()<<"Opp KR MRT Station crowdedness: "<<(*bs)->getCrowdedness("Opp KR MRT Station");
        for(int i=0;i<service.count();i++)
        {
            if(occupancyLimit[i]>60)
                qDebug()<<service[i]<<" occupancy:"<<0<<"/"<<60<<" next bus:"<<time[i]<<" "<<nextTime[i];
            else
                qDebug()<<service[i]<<" occupancy:"<<occupancy[i]<<"/"<<occupancyLimit[i]<<" next bus:"<<time[i]<<" "<<nextTime[i];
        }

        //(*bs)->advanceAllBus();
        //(*bs)->addCrowd();
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
    waitTimeWidget = new WaitTimeWidget();
    mainWindowLayout->addWidget(waitTimeWidget,1,0);
}

void MainWindow::createMapPanel()
{
    QVBoxLayout *mapPanel = new QVBoxLayout();
    QStringList buses;
    buses << "A1" << "A2" << "D1" << "D2";

    busList = new QComboBox();
    busList->setFixedWidth(100);
    busList->addItems(buses);

    mapLabel = new QLabel("Map is here.");

    //mapLabel->setFixedHeight(300);
    mapLabel->setFixedWidth(800);

    mapPanel->addWidget(busList);
    mapPanel->addWidget(mapLabel);


    mainWindowLayout->addLayout(mapPanel,0,1);

    //mainWindowLayout->addWidget(waitTimeWidget,0,1);
}
