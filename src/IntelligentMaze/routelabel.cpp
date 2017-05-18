#include "routelabel.h"

RouteLabel::RouteLabel(QWidget *parent) : QWidget(parent)
  ,mainLayout(new QHBoxLayout())
  ,leftLayout(new QVBoxLayout())
  ,m_Button1(new QRadioButton())
  ,m_Button2(new QRadioButton())
  ,m_Button3(new QRadioButton())
  //,m_Button4(new QRadioButton())
  ,m_PushButton(new QPushButton(tr("开始寻路")))
{
    mazeWindow = MazeWindow::getInstance();
    m_Button1->setText(tr("宽度优先搜索"));
    m_Button1->setChecked(true);
    m_Button2->setText(tr("深度优先搜索"));
    m_Button3->setText(tr("启发式搜索"));
//    m_Button4->setText(tr("遗传算法"));
    leftLayout->addWidget(m_Button1);
    leftLayout->addWidget(m_Button2);
    leftLayout->addWidget(m_Button3);
//    leftLayout->addWidget(m_Button4);
    mainLayout->addLayout(leftLayout, 2);
    mainLayout->addStretch(1);
    mainLayout->addWidget(m_PushButton,2);
    mainLayout->addStretch(1);
    //信号和槽
    connect(m_PushButton,SIGNAL(clicked(bool)),this,SLOT(findPath()));
    this->setLayout(mainLayout);
}

void RouteLabel::findPath()
{
    if (m_Button1->isChecked())
        mazeWindow->findPath(1);
    if (m_Button2->isChecked())
        mazeWindow->findPath(2);
    if (m_Button3->isChecked())
        mazeWindow->findPath(3);
//    if (m_Button4->isChecked())
//        mazeWindow->findPath(4);
}
