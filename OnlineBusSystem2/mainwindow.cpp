#include "mainwindow.h"
#include "bussimulator.h"
#include "busstop.h"
#include "imagewidget.h"
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
    createAction();

    QWidget *window = new QWidget();
    window->setLayout(mainWindowLayout);

    setCentralWidget(window);

    myTimerId=0;
    timerCount=0;

    bs=new BusSimulator();
    routeSelected = "A1";
    isChecked = false;
    emit routeGet(routeSelected, getRoute(routeSelected));	
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
        time=bs->getTiming("Opp KR MRT Station", false);
        nextTime= bs->getTiming("Opp KR MRT Station",true);
        occupancy= bs->getOccupancy("Opp KR MRT Station");
        occupancyLimit=bs->getOccupancyLimit("Opp KR MRT Station");
        service=bs->getService("Opp KR MRT Station");
        qDebug()<<"Opp KR MRT Station crowdedness: "<<bs->getCrowdedness("Opp KR MRT Station");

        for(int i=0;i<service.count();i++)
        {
            if(occupancyLimit[i]>60)
                qDebug()<<service[i]<<" occupancy:"<<0<<"/"<<60<<" next bus:"<<time[i]<<" "<<nextTime[i];
            else
                qDebug()<<service[i]<<" occupancy:"<<occupancy[i]<<"/"<<occupancyLimit[i]<<" next bus:"<<time[i]<<" "<<nextTime[i];
        }

        //bs->advanceAllBus();
        //bs->addCrowd();

        timerCount++;
    }
    else
        QWidget::timerEvent(event); // propagate

}

void MainWindow::createAction()
{
	connect(busList, SIGNAL(activated(const QString &)), 
		this, SLOT(selectRoute(const QString &)));
	
	connect(this, SIGNAL(routeGet(const QString &, BusStop**)),imageWidget, SLOT(displayRoute(const QString &, BusStop**)));

    connect(this, SIGNAL(routeGet(const QString &, BusStop**)),busStopListPanel, SLOT(showRouteList(const QString &, BusStop**)));

    connect(busStopListPanel, SIGNAL(forwardBusStop(const QString &)),this, SLOT(getTime(const QString &)));

    connect(this, SIGNAL(routeGet(const QString &, BusStop**)),busStopListPanel, SLOT(showRouteList(const QString &, BusStop**)));

    connect(imageWidget, SIGNAL(check(const QString &)), this, SLOT(getTime(const QString &)));

    connect(this, SIGNAL(timeGet(int, QVector<QString>, QVector<int>, QVector<int>, QVector<int>,QVector<int>)),waitTimeWidget, SLOT(displayTime(int, QVector<QString>, QVector<int>, QVector<int>, QVector<int>,QVector<int>)));

    connect(checkLocation, SIGNAL(toggled(bool)), this, SLOT(check(bool)));

    connect(this, SIGNAL(locationGet(QVector<QVector<int> >)), imageWidget, SLOT(displayBus(QVector<QVector<int> >)));

    connect(this, SIGNAL(uncheck(const QString &, BusStop**)), imageWidget, SLOT(remove(const QString &, BusStop**)));
}

//GUI
void MainWindow::createTitleBar()
{
    titleLayout = new QHBoxLayout();

    leftTitle = new QLabel("NUS");
    middleTitle = new QLabel("Online Bus System");
    loginButton = new QPushButton("Login");
    loginButton->setFixedWidth(100);

    titleLayout->addWidget(leftTitle);
    titleLayout->addWidget(middleTitle);
    titleLayout->addWidget(loginButton);

    QWidget *window = new QWidget();
    window->setLayout(titleLayout);

    setMenuWidget(window);

}

void MainWindow::createBusStopList()
{
	busStopListPanel = new BusStopListPanel();
    mainWindowLayout->addWidget(busStopListPanel,0,0);
}

void MainWindow::createBusTimePanel()
{        
    waitTimeWidget = new WaitTimeWidget();
    mainWindowLayout->addWidget(waitTimeWidget,1,0);
}

void MainWindow::createMapPanel()
{
    QVBoxLayout *mapPanel = new QVBoxLayout();
    QHBoxLayout *hbox = new QHBoxLayout();
    QStringList buses;
    buses << "A1" << "A2" << "D1" << "D2";

    busList = new QComboBox();
    busList->setFixedWidth(100);
    busList->addItems(buses);

    checkLocation = new QCheckBox("Check Location");
    dispatch = new QPushButton("Dispatch");
    dispatch->setFixedWidth(100);

    hbox->addWidget(busList);
    hbox->addWidget(checkLocation);
    hbox->addWidget(dispatch);

    //mapLabel = new QLabel("Map is here.");
    //mapLabel->setFixedHeight(300);
    //mapLabel->setFixedWidth(800);
    imageWidget = new ImageWidget();
	imageWidget->setFixedHeight(600);
    imageWidget->setFixedWidth(900);

    mapPanel->addLayout(hbox);
    mapPanel->addWidget(imageWidget);

    mainWindowLayout->addLayout(mapPanel,0,1);
}

//slot methods
void MainWindow::selectRoute(const QString &route){
	routeSelected = route;
	if (isChecked){
		getLocation(routeSelected);
        //qDebug("check location!");
	} else {
        //qDebug("get route information!");
		emit routeGet(route, getRoute(routeSelected));		
	}
}

void MainWindow::getTime(const QString &stopName){
    int num = bs->getCrowdedness(stopName);
    //qDebug("There are %d people waiting", num);
    QVector<QString> service = bs->getService(stopName);
    QVector<int> nextTime = bs->getTiming(stopName, false);
    QVector<int> nextNxtTime = bs->getTiming(stopName, true);
    QVector<int> occupancy = bs->getOccupancy(stopName);
    QVector<int> limit = bs->getOccupancyLimit(stopName);
    emit timeGet(num,service,nextTime,nextNxtTime,occupancy,limit);
}

void MainWindow::check(bool flag){
    if (flag){
        isChecked = true;
        qDebug("Check activated!");
        qDebug() << routeSelected;
        getLocation(routeSelected);
    } else {
        isChecked = false;
        qDebug("Check closed!");
        emit uncheck(routeSelected,getRoute(routeSelected));
    }

}

//methods
BusStop** MainWindow::getRoute(const QString &route){
	//qDebug ("Checking route.....");
    BusStop** result = bs->getRoute(route);
	//qDebug()<< result[0]->getName();
	//qDebug()<< result[1]->getName();
	//qDebug()<< result[2]->getName();
	return result;
	
}

void MainWindow::getLocation(const QString &route){
    int *result = bs->getBusPosition(route);
    BusStop** stops = bs->getRoute(route);
    //int index;
    int count = getCount(route);
    QVector<QVector<int> > locationList;
    for (int i=0;i<count;i++){
        if (result[i] != -1){
            QVector<int> location = stops[i]->getLocation();
            locationList.append(location);
        }
    }
    //qDebug("Get location! Ready to print...");
    emit locationGet(locationList);

}

int MainWindow::getCount(const QString &route){
	int count;
	if (route == "A1")
		count = 16;
	else if (route == "A2")
		count = 17;
	else if (route == "D1")
		count = 14;
	else
		count = 12;
    return count;
} 

