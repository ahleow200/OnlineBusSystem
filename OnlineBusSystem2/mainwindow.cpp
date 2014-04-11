#include "mainwindow.h"
#include "bussimulator.h"
#include "busstop.h"
#include <QtDebug>

class BusSimulator;
class BusStop;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    mainWindowLayout = new QGridLayout();
    createTitleBar();
    createBusStopList();
    createBusTimePanel();

    QWidget *window = new QWidget();
    window->setLayout(mainWindowLayout);

    setCentralWidget(window);

    BusSimulator *bs=new BusSimulator();

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
    //nextTwoBusTime = new QLabel("22");
    minLabel = new QLabel("min");

    timeObject->addWidget(nextBusTime);
    timeObject->addWidget(minLabel);

    leftPanel->addWidget(busName);
    leftPanel->addLayout(occupancyBox);

    estimateTime->addLayout(timeObject);
    estimateTime->addLayout(timeObject);

    timePanel->addLayout(leftPanel);
    timePanel->addLayout(estimateTime);

    mainWindowLayout->addLayout(timePanel,1,0);
}
