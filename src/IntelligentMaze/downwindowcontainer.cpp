#include "downwindowcontainer.h"

DownWindowContainer::DownWindowContainer(QWidget *parent) : QWidget(parent),
    mainLayout(new QHBoxLayout(this)),
    mazeWindow(new MazeWindow()),
    infoWindow(new InfoWindow())
{
    mainLayout->addWidget(mazeWindow, 4);
    mainLayout->addWidget(infoWindow, 1);
    this->setLayout(mainLayout);
}
