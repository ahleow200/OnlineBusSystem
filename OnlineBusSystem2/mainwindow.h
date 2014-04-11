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
    QHBoxLayout *busStopSearchColumn;
    QHBoxLayout *busStopObject;
    QScrollArea *busStopListScroll;
    QPushButton *busStopButton;
    QLabel *busIcon;

    int myTimerId;
    BusSimulator *bs;
    int timerCount;

protected:
    void timerEvent(QTimerEvent *event);
    void showEvent(QShowEvent *event);
    void hideEvent(QHideEvent *event);

};

#endif // MAINWINDOW_H
