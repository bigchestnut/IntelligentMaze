#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    mainWidget(new MainWindowContainer())
{
    loadWidget();
}

MainWindow::~MainWindow()
{
}

void MainWindow::loadWidget()
{
    this->setCentralWidget(mainWidget);
    this->setWindowTitle(tr("智能迷宫系统"));
    this->setMinimumSize(1280, 720);
}


