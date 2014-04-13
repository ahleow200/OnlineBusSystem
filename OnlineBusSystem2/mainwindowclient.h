#ifndef MAINWINDOWCLIENT_H
#define MAINWINDOWCLIENT_H

#include "bussimulator.h"
#include "mainwindow.h"
#include <QtGui>

class Bus;
class BusStop;
class BusSimulator;

class MainWindowClient : public QMainWindow
{
    Q_OBJECT

public:
    MainWindowClient(QWidget *parent = 0);
    ~MainWindowClient();
    void initialize(BusSimulator **bs);

private:
    void createTitleBar();
    void createBusStopList();
    void createBusTimePanel();
    void createMapPanel();

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
    QHBoxLayout *timeObject2;

    QLabel *busName;
    QLabel *occupancyLabel;
    QLabel *vacancyLabel;
    QLabel *slashLabel;
    QLabel *busSeatLabel;

    QLabel *nextBusTime;
    QLabel *nextTwoBusTime;
    QLabel *minLabel;

    //map panel
    QComboBox *busList;
    QLabel *mapLabel;


    int myTimerId;
    BusSimulator **bs;

    protected:
        void timerEvent(QTimerEvent *event);
        void showEvent(QShowEvent *event);
        void hideEvent(QHideEvent *event);

};
#endif // MAINWINDOWCLIENT_H
