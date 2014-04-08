#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    createTitleBar();
}

MainWindow::~MainWindow()
{

}

void MainWindow::createTitleBar()
{
    titleLayout = new QHBoxLayout();

    leftTitle = new QLabel("NUS");
    middleTitle = new QLabel("Online Bus System");
    loginButton = new QPushButton("Login");

    titleLayout->addWidget(leftTitle);
    titleLayout->addWidget(middleTitle);
    titleLayout->addWidget(loginButton);

    QWidget *window = new QWidget();
    window->setLayout(titleLayout);

    setMenuWidget(window);
}
