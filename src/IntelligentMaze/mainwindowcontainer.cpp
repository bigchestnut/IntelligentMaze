#include "mainwindowcontainer.h"

MainWindowContainer::MainWindowContainer(QWidget *parent) : QWidget(parent),
      mainLayout(new QVBoxLayout(this)),
      upWindow(new UpWindowContainer()),
      downWindow(new DownWindowContainer())
{
    mainLayout->addWidget(upWindow);
    mainLayout->addWidget(downWindow);
    this->setLayout(mainLayout);
}
