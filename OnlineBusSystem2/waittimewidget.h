#ifndef WAITTIMEWIDGET_H
#define WAITTIMEWIDGET_H

#include <QWidget>
#include <QtGui>

class WaitTimeWidget : public QWidget
{
    Q_OBJECT
public:
    explicit WaitTimeWidget(QWidget *parent = 0);

signals:

public slots:

private:
    //time panel
    void createTimePanel();

    QLabel *busName;
    QLabel *occupancyLabel;
    QLabel *vacancyLabel;
    QLabel *slashLabel;
    QLabel *busSeatLabel;

    QLabel *minLabel;

    const QString *nextBusTime;
    const QString *nextTwoBusTime;

};

#endif // WAITTIMEWIDGET_H
