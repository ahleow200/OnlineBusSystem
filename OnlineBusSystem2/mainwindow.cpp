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
    BusStop *a1busstop=bs->getRoute("A1");
    for(int i=0;i<17;i++)
    {
        qDebug()<<a1busstop[i].getName();
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
