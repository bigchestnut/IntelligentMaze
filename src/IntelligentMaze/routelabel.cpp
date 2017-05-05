#include "routelabel.h"

RouteLabel::RouteLabel(QWidget *parent) : QWidget(parent)
  ,mainLayout(new QHBoxLayout())
  ,leftLayout(new QVBoxLayout())
  ,m_Button1(new QRadioButton())
  ,m_Button2(new QRadioButton())
  ,m_Button3(new QRadioButton())
  ,m_Button4(new QRadioButton())
  ,m_PushButton(new QPushButton(tr("开始寻路")))
{
    m_Button1->setText(tr("递归回溯"));
    m_Button2->setText(tr("递归回溯"));
    m_Button3->setText(tr("启发式搜索"));
    m_Button4->setText(tr("遗传算法"));
    leftLayout->addWidget(m_Button1);
    leftLayout->addWidget(m_Button2);
    leftLayout->addWidget(m_Button3);
    leftLayout->addWidget(m_Button4);
    mainLayout->addLayout(leftLayout, 2);
    mainLayout->addWidget(m_PushButton,1);
    this->setLayout(mainLayout);
}
