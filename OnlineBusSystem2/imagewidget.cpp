#include "imagewidget.h"
#include "busstop.h"
#include <QtGui>

class BusStop;

ImageWidget::ImageWidget(QWidget *parent): QWidget(parent)
{	
    image = QImage("./a1.png"); // Get image
    input = QPixmap::fromImage(image);
    update();
}

/*void ImageWidget::test(const QString &route)
{
    //delete layer;
    QList<QWidget *> widgets = findChildren<QWidget *>();
    foreach(QWidget * widget, widgets)
    {
        delete widget;
    }
    //setImage(route);
    //layer = new QWidget(this);
    //layer->move(0,0);
    //layer->resize(700,550);
    QPushButton *btn = new QPushButton(this);
    btn->move(200,200);
    btn->show();
    connect(btn, SIGNAL(clicked()),
        btn, SLOT(hide()));
}*/

//slot
void ImageWidget::displayRoute(const QString &route, BusStop**busstops)
{
	//delete all widget
    //qDebug ("Clear widgets!");
	QList<QWidget *> widgets = findChildren<QWidget *>();
	foreach(QWidget * widget, widgets)
	{
		delete widget;
	}
	//setImage(route);
	//layer = new QWidget(this);
	//layer->move(0,0);
	//layer->resize(700,550);
	//addButton(busstops);

	int count;
	if (route == "A2"){
		image = QImage("./a2_1.png"); // Get image
		input = QPixmap::fromImage(image);
		update();
		count = 17;
		addButton(count,busstops);
		return;
	}
	
	if (route == "A1"){
		image = QImage("./a1.png"); // Get image
		input = QPixmap::fromImage(image);
		update();
		count = 16;
		addButton(count,busstops);
		return;
	}
	
	if (route == "D1"){
		image = QImage("./d1.png"); // Get image
		input = QPixmap::fromImage(image);
		update();
		count = 14;
		addButton(count,busstops);
		return;
	}
	
	if (route == "D2"){
		image = QImage("./d2.png"); // Get image
		input = QPixmap::fromImage(image);
		update();
		count = 12;
		addButton(count,busstops);
		return;
	}
}

void ImageWidget::checkTime(){
	emit check(stopName);
}

void ImageWidget::displayBus(QVector<QVector<int> > locationList){
    QPushButton *btn;
    for (int i=0;i<locationList.count();i++){
        QVector<int> item = locationList.at(i);
        int x = item[0];
        int y = item[1];
        btn = new QPushButton(this);
        QPixmap pixmap("./bus_red.png");
        btn->move(x,y);
        btn->setIcon(QIcon(pixmap));
        btn->setIconSize(pixmap.rect().size());
        btn->show();
        //qDebug("Bus created!");
    }
}

void ImageWidget::remove(const QString &route, BusStop** stops){
    QList<QWidget *> widgets = findChildren<QWidget *>();
    foreach(QWidget * widget, widgets)
    {
        delete widget;
    }
    int num = getCount(route);
    addButton(num,stops);
    //qDebug("Bus removed, Bus stops added!");


}


// methods
/*
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
}*/

void ImageWidget::addButton(int num,BusStop** busstops){
	for (int i=0;i<num;i++){
		QVector<int> location = busstops[i]->getLocation();
		stopName = busstops[i]->getName();
		int x = location[0];
		int y = location[1];
		QPushButton *btn;
		if (x > 0 && y > 0){
			btn = new QPushButton(this);
			QPixmap pixmap("./stops_icon.png");
			btn->move(x,y);
			btn->setIcon(QIcon(pixmap));
			btn->setIconSize(pixmap.rect().size());
			btn->show();
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

int ImageWidget::getCount(const QString &route){
    int count;
    if (route == "A1")
        count = 16;
    else if (route == "A2")
        count = 17;
    else if (route == "D1")
        count = 14;
    else
        count = 12;
    //qDebug("No of bus stops %d", count);
    return count;
}

