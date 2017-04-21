#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    mainLayout(new QVBoxLayout),
    downLayout(new QVBoxLayout),
    upLayout(new QHBoxLayout)
{

    ui->setupUi(this);
    //mainLayout->addLayout(upLayout);
    // mainLayout->addLayout(downLayout);
    //this->setLayout(mainLayout);
    this->setWindowTitle("智能迷宫系统");
    //this->setLayout();
    this->setFixedSize(700,450);
}

MainWindow::~MainWindow()
{
    delete ui;
}
