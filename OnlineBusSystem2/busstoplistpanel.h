#ifndef BUSSTOPLISTPANEL_H
#define BUSSTOPLISTPANEL_H

#include <QtGui>
#include <QWidget>
#include <busstop.h>

class BusStopListPanel : public QWidget
{
    Q_OBJECT

public:
    explicit BusStopListPanel(QWidget *parent = 0);
    void addBusStops(int num, BusStop **busstops);

signals:
    void forwardBusStop(const QString &busstopname);

private slots:
    void showRouteList(const QString &route, BusStop**busstops);
    void isBusStopSelected(QListWidget &busStopList);
    //void displayTime(timeGet(int, QVector<QString>, QVector<int>, QVector<int>, QVector<int>,QVector<int>));

private:    
    QVBoxLayout *busStopListLayout;
    QLineEdit *searchBar;
    QPushButton *searchButton;
    QListWidget *busStopList;
    QScrollArea *busStopListScroll;
    QLabel *busStopLabel;
    QLabel *busIcon;
    QStringList *busRoute;

};

#endif // BUSSTOPLISTPANEL_H
