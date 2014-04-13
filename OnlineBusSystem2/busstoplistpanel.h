#ifndef BUSSTOPLISTPANEL_H
#define BUSSTOPLISTPANEL_H

#include <QtGui>
#include <QWidget>

class BusStopListPanel : public QWidget
{
    Q_OBJECT
public:
    explicit BusStopListPanel(QWidget *parent = 0);

signals:

public slots:

private:
    QLineEdit *searchBar;
    QPushButton *searchButton;
    QListWidget *busStopList;
    QScrollArea *busStopListScroll;
    QLabel *busStopLabel;
    QLabel *busIcon;

};

#endif // BUSSTOPLISTPANEL_H
