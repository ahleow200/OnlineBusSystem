#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "bussimulator.h"
#include "waittimewidget.h"
#include "busstoplistpanel.h"

#include <QtGui>

class Bus;
class BusStop;
class BusSimulator;
class ImageWidget;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
    //void initialize(BusSimulator **bs);
    //bool updateAllowed();
    //void toggleUpdate();


signals:
	void routeGet(const QString &str, BusStop** result);
	
public slots:
	void selectRoute(const QString &str);

private:
    void createTitleBar();
    void createBusStopList();
    void createBusTimePanel();
    void createMapPanel();
    void createAction();
    int getCount(const QString &route);

    BusStop** getRoute(const QString &str);
    void getLocation(const QString &str);

    QGridLayout *mainWindowLayout;

    //title panel
    QLabel *leftTitle;
    QLabel *middleTitle;
    QPushButton *loginButton;
    QHBoxLayout *titleLayout;

    //bus stop list panel
    BusStopListPanel *busStopListPanel;

    //time panel
    WaitTimeWidget *waitTimeWidget;

    //map panel
    QComboBox *busList;
    QLabel *mapLabel;
    ImageWidget *imageWidget;


    int myTimerId;
    BusSimulator *bs;
    int timerCount;
    QString routeSelected;
    bool isChecked;

protected:
    void timerEvent(QTimerEvent *event);
    void showEvent(QShowEvent *event);
    void hideEvent(QHideEvent *event);

};

#endif // MAINWINDOW_H
