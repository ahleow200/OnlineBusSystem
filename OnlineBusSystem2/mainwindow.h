#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "bussimulator.h"
#include <QtGui>

class Bus;
class BusStop;
class BusSimulator;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    void createTitleBar();
    void createBusStopList();
    void createBusTimePanel();

    QGridLayout *mainWindowLayout;

    //title panel
    QLabel *leftTitle;
    QLabel *middleTitle;
    QPushButton *loginButton;
    QHBoxLayout *titleLayout;

    //bus stop list panel
    QLineEdit *searchBar;
    QPushButton *searchButton;
    QVBoxLayout *busStopListLayout;
    QListWidget *busStopList;
    QHBoxLayout *busStopSearchColumn;
    QHBoxLayout *busStopObject;
    QScrollArea *busStopListScroll;
    QLabel *busStopLabel;
    QLabel *busIcon;

    //time panel
    QHBoxLayout *timePanel;
    QVBoxLayout *leftPanel;
    QVBoxLayout *estimateTime;

    QHBoxLayout *occupancyBox;
    QHBoxLayout *timeObject;

    QLabel *busName;
    QLabel *occupancyLabel;
    QLabel *vacancyLabel;
    QLabel *slashLabel;
    QLabel *busSeatLabel;

    QLabel *nextBusTime;
    QLabel *nextTwoBusTime;
    QLabel *minLabel;

    //map panel


};

#endif // MAINWINDOW_H
