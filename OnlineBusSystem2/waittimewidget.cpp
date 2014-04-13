#include "waittimewidget.h"

WaitTimeWidget::WaitTimeWidget(QWidget *parent) :
    QWidget(parent)
{
    QHBoxLayout *timePanel = new QHBoxLayout();
    QVBoxLayout *leftPanel = new QVBoxLayout();
    QVBoxLayout *estimateTime = new QVBoxLayout();

    QHBoxLayout *occupancyBox = new QHBoxLayout();

    nextBusTime = new QString("7 mins");
    nextTwoBusTime = new QString("20 mins");
    QLabel *nextBusLabel = new QLabel("7 mins");
    QLabel *nextTwoBusLabel = new QLabel("20 mins");

    busName = new QLabel("A1");
    occupancyLabel = new QLabel("Occupancy: ");
    vacancyLabel = new QLabel("40");
    slashLabel = new QLabel("/");
    busSeatLabel = new QLabel("60");

    occupancyBox->addWidget(occupancyLabel);
    occupancyBox->addWidget(vacancyLabel);
    occupancyBox->addWidget(slashLabel);
    occupancyBox->addWidget(busSeatLabel);

    leftPanel->addWidget(busName);
    leftPanel->addLayout(occupancyBox);

    estimateTime->addWidget(nextBusLabel);
    estimateTime->addWidget(nextTwoBusLabel);

    timePanel->addLayout(leftPanel);
    timePanel->addLayout(estimateTime);

    setLayout(timePanel);
}
