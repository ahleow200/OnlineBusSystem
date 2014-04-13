#include "busstoplistpanel.h"

BusStopListPanel::BusStopListPanel(QWidget *parent) :
    QWidget(parent)
{
    QVBoxLayout *busStopListLayout = new QVBoxLayout();
    QHBoxLayout *busStopSearchColumn = new QHBoxLayout();
    QHBoxLayout *busStopObject = new QHBoxLayout();

    busStopList = new QListWidget();
    QListWidgetItem *item = new QListWidgetItem(busStopList);

    busStopList->addItem(item);

    searchBar = new QLineEdit();
    searchButton = new QPushButton("Search");
    busStopLabel = new QLabel("Arts"); //test
    busIcon = new QLabel("bus"); //test

    busStopSearchColumn->addWidget(searchBar);
    busStopSearchColumn->addWidget(searchButton);

    busStopObject->addWidget(busStopLabel);
    busStopObject->addWidget(busIcon);

    //busStopListScroll->addWidget(busStopObject);

    busStopList->addItem(new QListWidgetItem("Science"));
    busStopList->addItem(new QListWidgetItem("Science"));
    busStopList->addItem(new QListWidgetItem("Science"));
    busStopList->addItem(new QListWidgetItem("Science"));
    busStopList->addItem(new QListWidgetItem("Science"));

    busStopList->setItemWidget(item,busStopLabel);
    busStopList->setFixedHeight(300);
    //busStopList->setLayout(busStopObject);

    busStopListLayout->addLayout(busStopSearchColumn);
    busStopListLayout->addWidget(busStopList);

    setLayout(busStopListLayout);
}
