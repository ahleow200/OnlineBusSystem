#include "busstoplistpanel.h"

BusStopListPanel::BusStopListPanel(QWidget *parent) :
    QWidget(parent)
{
    QVBoxLayout *busStopListLayout = new QVBoxLayout();
    QHBoxLayout *busStopSearchColumn = new QHBoxLayout();
    QHBoxLayout *busStopObject = new QHBoxLayout();

    busRoute = new QStringList();
    busStopList = new QListWidget();
    QListWidgetItem *item = new QListWidgetItem(busStopList);

    busStopList->addItem(item);

    searchBar = new QLineEdit();
    searchButton = new QPushButton("Search");
    busStopLabel = new QLabel("Arts"); //test
    busIcon = new QLabel("bus"); //test

    busStopSearchColumn->addWidget(searchBar);
    busStopSearchColumn->addWidget(searchButton);

    //busStopObject->addWidget(busStopLabel);
    //busStopObject->addWidget(busIcon);

    //busStopListScroll->addWidget(busStopObject);
    /*
    busStopList->addItem(new QListWidgetItem("Science"));
    busStopList->addItem(new QListWidgetItem("Science"));
    busStopList->addItem(new QListWidgetItem("Science"));
    busStopList->addItem(new QListWidgetItem("Science"));
    busStopList->addItem(new QListWidgetItem("Science"));

    busStopList->setItemWidget(item,busStopLabel);
    */
    //busStopList->addItems(busRoute);
    busStopList->setFixedHeight(300);
    busStopList->setLayout(busStopObject);

    busStopListLayout->addLayout(busStopSearchColumn);
    busStopListLayout->addWidget(busStopList);

    setLayout(busStopListLayout);

}
/*
void BusStopListPanel::viewBusRoute(const QStringList &busStops)
{
    busStopList->addItems(busStops);
    busStopListLayout->addWidget(busStopList);

    setLayout(busStopListLayout);
}
*/
void BusStopListPanel::showRouteList(const QString &route, BusStop**busstops)
{
    //delete all widget
    qDebug ("Clear widgets");
    busStopList->clear();

    int count;
    if (route == "A2")
    {
        count = 17;
        addBusStops(count,busstops);
        return;
    }

    if (route == "A1")
    {
        count = 16;
        addBusStops(count,busstops);
        return;
    }

    if (route == "D1")
    {
        count = 14;
        addBusStops(count,busstops);
        return;
    }

    if (route == "D2")
    {
        count = 12;
        addBusStops(count,busstops);
        return;
    }
}

void BusStopListPanel::addBusStops(int num, BusStop **busstops)
{
    for (int i=0; i<num; i++)
    {
        busStopList->addItem(busstops[i]->getName());
    }
}
