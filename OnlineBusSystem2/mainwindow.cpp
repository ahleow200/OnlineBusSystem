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
    BusStop *a1busstop=bs->getRoute("A1");
    for(int i=0;i<17;i++)
    {
        qDebug()<<a1busstop[i].getName();
    }
}

MainWindow::~MainWindow()
{

}
