#include "mainwindow.h"
#include "bussimulator.h"
#include "busstop.h"
#include <QtDebug>

class BusSimulator;
class BusStop;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    BusSimulator *bs=new BusSimulator();

    //testing for printing all bus stops for a bus route
    QString *a1busstop=bs->getRoute("A1");
    QString *cbusstop=bs->getRoute("C");
    QString *d2busstop=bs->getRoute("D2");
    qDebug()<<"A1 Bus Stops============================";
    for(int i=0;i<17;i++)
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
    QVector<int> time=bs->getTiming("LT29", false);
    QVector<int> nextTime= bs->getTiming("LT29",true);
    QVector<int> occupancy= bs->getOccupancy("LT29");
    QVector<QString> service=bs->getService("LT29");
    qDebug()<<service.count();
    qDebug()<<"LT29 crowdedness:"<<bs->getCrowdedness("LT29");
    for(int i=0;i<service.count();i++)
    {
        qDebug()<<service[i]<<" occupancy:"<<occupancy[i]<<" next bus:"<<time[i]<<" "<<nextTime[i];
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
