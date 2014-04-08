#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "busstoplist.h"

BusStopList::BusStopList(QWidget *parent) :
    QListWidget(parent)
{
}

void BusStopList::updateBusStop(const QString &service)
{
    if(service=="A1")
    {
        this->clear();
        this->addItem("Science");
        this->addItem("PGP");
        this->addItem("Computing");
        this->addItem("YIH");
    }
    else
    {
        this->clear();
        this->addItem("PGP");
        this->addItem("Computing");
        this->addItem("Temasek");
        this->addItem("Raffles");
    }
}
