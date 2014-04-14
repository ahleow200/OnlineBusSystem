#include "waittimewidget.h"

WaitTimeWidget::WaitTimeWidget(QWidget *parent) :
    QWidget(parent)
{
    QHBoxLayout *timePanel = new QHBoxLayout();
    QVBoxLayout *leftPanel = new QVBoxLayout();
    QVBoxLayout *estimateTime = new QVBoxLayout();

    QHBoxLayout *occupancyBox = new QHBoxLayout();

    QHBoxLayout *topRow = new QHBoxLayout();

    busStopName = new QLabel("After Science park Drive");
    refreshTimeButton = new QPushButton("Refresh");
    topRow->addWidget(busStopName);
    topRow->addWidget(refreshTimeButton);

    QHBoxLayout *bottomRow = new QHBoxLayout();
    crowdnessNumber = new QLabel("30");
    QLabel *crowdnessLabel = new QLabel("Crowdness: ");
    bottomRow->addWidget(crowdnessLabel);
    bottomRow->addWidget(crowdnessNumber);

    QVBoxLayout *busStopTimeInfoBox = new QVBoxLayout();
    busStopTimeInfoBox->addLayout(topRow);
    busStopTimeInfoBox->addLayout(bottomRow);


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

    QVBoxLayout *waitingTimePanel = new QVBoxLayout();
    waitingTimePanel->addLayout(busStopTimeInfoBox);
    waitingTimePanel->addLayout(timePanel);

    setLayout(waitingTimePanel);
}
