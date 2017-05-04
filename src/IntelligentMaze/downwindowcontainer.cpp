#include "downwindowcontainer.h"

DownWindowContainer::DownWindowContainer(QWidget *parent) : QWidget(parent),
    mainLayout(new QHBoxLayout(this)),
    mazeWindow(new MazeWindow()),
    infoWindow(new InfoWindow())
{
    mainLayout->addWidget(mazeWindow);
    mainLayout->addWidget(infoWindow);
    this->setLayout(mainLayout);
}
