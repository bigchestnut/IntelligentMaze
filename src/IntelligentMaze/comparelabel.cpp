#include "comparelabel.h"

CompareLabel::CompareLabel(QWidget *parent) : QWidget(parent)
  ,mainLayout(new QVBoxLayout())
  ,m_sliderLayout(new QHBoxLayout())
  ,m_sliderLabel(new QLabel(tr("单步速度：")))
  ,m_slowLabel(new QLabel(tr("慢")))
  ,m_fastLabel(new QLabel(tr("快")))
  ,m_slider(new QSlider(Qt::Horizontal))
{
    mazeWindow = MazeWindow::getInstance();

    m_slider->setRange(10,600);
    m_slider->setValue(50);
    m_sliderLayout->addWidget(m_fastLabel);
    m_sliderLayout->addWidget(m_slider);
    m_sliderLayout->addWidget(m_slowLabel);
    mainLayout->addWidget(m_sliderLabel,1);
    mainLayout->addLayout(m_sliderLayout, 1);
    this->setLayout(mainLayout);

    connect(m_slider, SIGNAL(valueChanged(int)),mazeWindow, SLOT(setStepTime(int)));
}
