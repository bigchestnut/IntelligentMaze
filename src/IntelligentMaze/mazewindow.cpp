#include "mazewindow.h"

MazeWindow::MazeWindow(QWidget *parent) : QWidget(parent),
    mainLayout(new QHBoxLayout(this)),
    m_title(new QLabel())
{
    m_title->setText(tr("迷宫"));
    mainLayout->addWidget(m_title);
    this->setLayout(mainLayout);
}
