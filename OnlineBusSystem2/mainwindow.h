#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
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

    //title panel
    QLabel *leftTitle;
    QLabel *middleTitle;
    QPushButton *loginButton;
    QHBoxLayout *titleLayout;

    /*
    //bus stop list panel
    QLineEdit *searchBar;
    QPushButton *searchButton;
    QVBoxLayout *busStopListLayout;
    QHBoxLayout *busStopObject;
    QScrollArea *busStopListScroll;
    QPushButton *busStopButton;
    QLabel *busIcon;
    */

};

#endif // MAINWINDOW_H
