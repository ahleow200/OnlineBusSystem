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

private slots:
    //void viewBusRoute(const QStringList &busStops);
    void showRouteList(const QString &route, BusStop**busstops);

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
