#include "mazelabel.h"

MazeLabel::MazeLabel(QWidget *parent) : QWidget(parent)
  ,mainLayout(new QHBoxLayout())
  ,leftLayout(new QVBoxLayout())
  ,m_Button1(new QRadioButton())
  ,m_Button2(new QRadioButton())
  ,m_PushButton(new QPushButton(tr("生成迷宫")))
{
    mazeWindow = MazeWindow::getInstance();
    m_Button1->setText(tr("递归回溯"));
    m_Button2->setText(tr("递归回溯"));
    leftLayout->addWidget(m_Button1);
    leftLayout->addWidget(m_Button2);
    mainLayout->addLayout(leftLayout, 1);
    mainLayout->addWidget(m_PushButton,1);
    //信号槽
    connect(m_PushButton,SIGNAL(clicked()), mazeWindow , SLOT(createMaze()));
    this->setLayout(mainLayout);
}

void MazeLabel::handleClicked()
{
    printf("aaaaaaaaaaaaaaaaaaa");
}
