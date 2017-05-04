#include "upwindowcontainer.h"

UpWindowContainer::UpWindowContainer(QWidget *parent) : QWidget(parent),
    mainLayout(new QHBoxLayout()),
    mazeLabel(new MazeLabel()),
    routeLabel(new RouteLabel()),
    compareLabel(new CompareLabel())
{
    mainLayout->addWidget(mazeLabel);
    mainLayout->addWidget(routeLabel);
    mainLayout->addWidget(compareLabel);
    this->setLayout(mainLayout);
}
