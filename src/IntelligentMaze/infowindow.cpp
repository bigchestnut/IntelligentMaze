#include "infowindow.h"

InfoWindow::InfoWindow(QWidget *parent) : QWidget(parent)
  ,mainLayout(new QVBoxLayout())
  ,m_textBro1(new QTextBrowser())
  ,m_textBro2(new QTextBrowser())
  ,m_switchBtn(new QPushButton())
{
    m_textBro1->setText("信息");
    m_textBro2->setText("比较");
    m_switchBtn->setText("切换");
    mainLayout->addWidget(m_textBro1, 5);
    mainLayout->addWidget(m_switchBtn, 1);
    this->setLayout(mainLayout);
}
