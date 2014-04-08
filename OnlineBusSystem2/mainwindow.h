#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "bussimulator.h"
#include <QtGui>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>

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

    QLabel *leftTitle;
    QLabel *middleTitle;
    QPushButton *loginButton;
    QHBoxLayout *titleLayout;

};

#endif // MAINWINDOW_H
