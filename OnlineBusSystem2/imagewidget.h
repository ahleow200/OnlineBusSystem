#ifndef IMAGEWIDGET_H
#define IMAGEWIDGET_H

#include <QWidget>
#include <QImage>
#include <QPixmap>
#include <QtGui>
#include "busstop.h"

class BusStop;

class ImageWidget: public QWidget
{
    Q_OBJECT

public:
    ImageWidget(QWidget *parent = 0);
    //void setImage(const QString &route);
    void addButton(int num, BusStop **busstops);
	
signals:
    void check(const QString &str);
	
public slots:
    void displayRoute(const QString &route, BusStop **busstops);
    //void test(const QString &route);
    void checkTime();
    void displayBus(QVector<QVector<int> > locationList);
    void remove(const QString &route,BusStop** stops);

protected:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    int getCount(const QString &route);


private:
    QImage image;
    QPixmap input;
    QString stopName;
	//QGridLayout *LayerLayout;
	//QWidget *layer;
};

#endif // IMAGEWIDGET_H
