#ifndef BUSSTOPLIST_H
#define BUSSTOPLIST_H

#include <QMainWindow>

class BusStopList : public QListWidget
{
    Q_OBJECT
public:
    explicit BusStopList(QWidget *parent = 0);
    
signals:
    
public slots:
    void updateBusStop(const QString &service);
    
};

#endif // BUSSTOPLIST_H
