#include "mainwindow.h"
#include "bussimulator.h"
#include "busstop.h"
#include <QtDebug>

class BusSimulator;
class BusStop;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    createTitleBar();

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
    /*
    QLineEdit *searchBar;
    QPushButton *searchButton;
    QVBoxLayout *busStopListLayout;
    QHBoxLayout *busStopObject;
    QScrollArea *busStopListScroll;
    QPushButton *busStopButton;
    QLabel *busIcon;

    searchBar = new QLineEdit();
    searchButton = new QPushButton("Search");
    */
}

void MainWindow::createBusTimePanel()
{

}
