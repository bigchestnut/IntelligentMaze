#include "downwindowcontainer.h"

DownWindowContainer::DownWindowContainer(QWidget *parent) : QWidget(parent)
   ,mainLayout(new QHBoxLayout(this))
   ,infoWindow(new InfoWindow())
{
    mazeWindow = MazeWindow::getInstance();
    mainLayout->addWidget(mazeWindow, 4);
    mainLayout->addWidget(infoWindow, 1);
    this->setLayout(mainLayout);
}
