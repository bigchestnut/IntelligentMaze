#include "mazewindow.h"

MazeWindow::MazeWindow(QWidget *parent) : QWidget(parent)
    ,mainLayout(new QHBoxLayout(this))
    ,m_graphView(new QGraphicsView())
{
    //mainLayout->addWidget(m_graphView);
    //this->setSizePolicy(QSizePolicy::verticalStretch());
    this->setLayout(mainLayout);
}

void MazeWindow::paintEvent()
{
    QPainter painter(this); //this为绘图设备，即表明在该部件上进行绘制
    painter.drawLine(QPoint(0, 0), QPoint(100, 100));
}
