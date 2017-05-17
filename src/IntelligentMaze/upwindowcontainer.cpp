#include "upwindowcontainer.h"

UpWindowContainer::UpWindowContainer(QWidget *parent) : QWidget(parent),
    mainLayout(new QHBoxLayout()),
    mazeLabel(new MazeLabel()),
    routeLabel(new RouteLabel()),
    compareLabel(new CompareLabel())
{
    mainLayout->addWidget(mazeLabel, 2);
    mainLayout->addWidget(routeLabel, 2);
    mainLayout->addWidget(compareLabel, 1);
    this->setLayout(mainLayout);
}
