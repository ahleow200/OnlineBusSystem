#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initValues();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initValues()
{
    ui->comboBox->addItem("A1");
}
