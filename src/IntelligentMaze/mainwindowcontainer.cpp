#include "mainwindowcontainer.h"

MainWindowContainer::MainWindowContainer(QWidget *parent) : QWidget(parent),
      mainLayout(new QVBoxLayout(this)),
      upWindow(new UpWindowContainer()),
      downWindow(new DownWindowContainer())
{
    mainLayout->addWidget(upWindow, 1);
    mainLayout->addWidget(downWindow, 5);
    this->setLayout(mainLayout);
}
