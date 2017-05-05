#include "upwindowcontainer.h"

UpWindowContainer::UpWindowContainer(QWidget *parent) : QWidget(parent),
    mainLayout(new QHBoxLayout()),
    mazeLabel(new MazeLabel()),
    routeLabel(new RouteLabel()),
    compareLabel(new CompareLabel())
{
    mainLayout->addWidget(mazeLabel, 1);
    mainLayout->addWidget(routeLabel, 1);
    mainLayout->addWidget(compareLabel, 1);
    this->setLayout(mainLayout);
}
