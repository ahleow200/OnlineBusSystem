#include <QApplication>
#include "mainwindow.h"
#include "mainwindowclient.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    MainWindowClient wc;
    BusSimulator *bs=new BusSimulator();

    w.setFixedSize(1024, 768);
    w.initialize(&bs);
    wc.setFixedSize(1024, 768);
    wc.initialize(&bs);
    w.show();
    wc.show();
    while(true)
    {
        bs->delay(3000);
        bs->advanceAllBus();
        bs->addCrowd();
    }

    return a.exec();
}
