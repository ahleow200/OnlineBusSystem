#include "imagewidget.h"
#include "busstop.h"
#include <QtGui>

class BusStop;

ImageWidget::ImageWidget(QWidget *parent): QWidget(parent)
{	
	image = QImage("./a1.png"); // Get image
    input = QPixmap::fromImage(image);
    update();
	
	//layer = new QWidget(this);
	//layer->move(0,0);
	//layer->resize(700,550);
	//QPushButton *btn;
	
	/*for (int i=0;i<5;i++){
		btn = new QPushButton("press",this);	
		btn->move(10*(i+1),200);
		btn->show();
	}*/

	
	/*QPushButton *btn = new QPushButton(tr("Bus stop"),this);
	btn->move(200,200);
	btn->show();*/
	
	
	/*for (int i=0;i<busstop.size();i++){
		//get location
		QVector<int> location = busstop[i].getLocation();
		QString name = busstop[i].getName();
		int x = location[0];
		int y = location[1];
		QPushButton *btn;
		if (x > 0 && y > 0){
			btn = new QPushButton(tr("Bus stop"),this);
			btn->move(x,y);
			bth.show();
		}
	}*/	
}

void ImageWidget::test(const QString &route)
{	
	//delete layer;
	QList<QWidget *> widgets = findChildren<QWidget *>();
	foreach(QWidget * widget, widgets)
	{
		delete widget;
	}
	setImage(route);
	//layer = new QWidget(this);
	//layer->move(0,0);
	//layer->resize(700,550);
	QPushButton *btn = new QPushButton(this);
	btn->move(200,200);
	btn->show();
	connect(btn, SIGNAL(clicked()), 
		btn, SLOT(hide()));	
}
//slot
void ImageWidget::displayRoute(const QString &route, BusStop**busstops)
{
	//delete all widget
	QList<QWidget *> widgets = findChildren<QWidget *>();
	foreach(QWidget * widget, widgets)
	{
		delete widget;
	}
	setImage(route);
	//layer = new QWidget(this);
	//layer->move(0,0);
	//layer->resize(700,550);
	addButton(busstops);
}

void ImageWidget::checkTime(){
	emit check(stopName);
}


// methods
void ImageWidget::setImage(const QString &route){
    QImage image;

    if (route.compare("A2")==0){
        image = QImage("./a2_1.png"); // Get image
        input = QPixmap::fromImage(image);
        update();
        return;
    }
	
	if (route.compare("A1")==0){
        image = QImage("./a1.png"); // Get image
        input = QPixmap::fromImage(image);
        update();
        return;
    }
	
	if (route.compare("D1")==0){
        image = QImage("./d1.png"); // Get image
        input = QPixmap::fromImage(image);
        update();
        return;
    }
	
	if (route.compare("D2")==0){
        image = QImage("./d2.png"); // Get image
        input = QPixmap::fromImage(image);
        update();
        return;
    }
}

void ImageWidget::addButton(BusStop** busstops){
	for (int i=0;i<busstops.count();i++){
		QVector<int> location = busstop[i]->getLocation();
		stopName = busstop[i]->getName();
		int x = location[0];
		int y = location[1];
		QPushButton *btn;
		if (x > 0 && y > 0){
			btn = new QPushButton("Bus stop",this);
			btn->move(x,y);
			bth.show();
		}
		connect(btn, SIGNAL(clicked()), 
		this, SLOT(checkTime()));	
	}	
}

void ImageWidget::paintEvent(QPaintEvent *event){

    QPainter painter(this);
    QRect rect = event->rect();
    painter.drawPixmap(rect, input, rect);
}

void ImageWidget::mousePressEvent(QMouseEvent *event)
 {
     if (event->button() == Qt::LeftButton) {
         qDebug ("x is %d, y is %d",event->x(),event->y());
     }
 }
