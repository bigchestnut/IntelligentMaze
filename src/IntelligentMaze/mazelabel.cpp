#include "mazelabel.h"

MazeLabel::MazeLabel(QWidget *parent) : QWidget(parent)
  ,mainLayout(new QHBoxLayout())
  ,leftLayout(new QVBoxLayout())
  ,rightLayout(new QVBoxLayout())
  ,m_widthLayout(new QHBoxLayout())
  ,m_heightLayout(new QHBoxLayout())
  ,m_startPosXLayout(new QHBoxLayout())
  ,m_startPosYLayout(new QHBoxLayout())
  ,m_widthLabel(new QLabel(tr("宽度(3~25,奇数)：     ")))
  ,m_heightLabel(new QLabel(tr("高度(3~13,奇数)：     ")))
  ,m_startPosX(new QLabel(tr("初始X(1~宽度-2,奇数)：")))
  ,m_startPosY(new QLabel(tr("初始Y(1~高度-2,奇数)：")))
  ,m_widthBox(new QSpinBox())
  ,m_heightBox(new QSpinBox())
  ,m_startPosXBox(new QSpinBox())
  ,m_startPosYBox(new QSpinBox())
  ,m_sliderLayout(new QHBoxLayout())
  ,m_sliderLabel(new QLabel(tr("生成速度:")))
  ,m_slider(new QSlider())
  ,m_PushButton(new QPushButton(tr("生成迷宫")))
{
    mazeWindow = MazeWindow::getInstance();
    m_widthLayout->addWidget(m_widthLabel);
    m_widthLayout->addWidget(m_widthBox);
    m_widthBox->setRange(3,25);
    m_widthBox->setSingleStep(2);
    m_widthBox->setFocusPolicy(Qt::NoFocus);
    m_widthBox->setValue(25);
    m_heightLayout->addWidget(m_heightLabel);
    m_heightLayout->addWidget(m_heightBox);
    m_heightBox->setRange(3,13);
    m_heightBox->setSingleStep(2);
    m_heightBox->setFocusPolicy(Qt::NoFocus);
    m_heightBox->setValue(13);
    m_startPosXLayout->addWidget(m_startPosX);
    m_startPosXLayout->addWidget(m_startPosXBox);
    m_startPosXBox->setRange(1,23);
    m_startPosXBox->setSingleStep(2);
    m_startPosXBox->setFocusPolicy(Qt::NoFocus);
    m_startPosXBox->setValue(1);
    m_startPosYLayout->addWidget(m_startPosY);
    m_startPosYLayout->addWidget(m_startPosYBox);
    m_startPosYBox->setRange(1,11);
    m_startPosYBox->setSingleStep(2);
    m_startPosYBox->setFocusPolicy(Qt::NoFocus);
    m_startPosYBox->setValue(1);
    leftLayout->addLayout(m_widthLayout);
    leftLayout->addLayout(m_heightLayout);
    leftLayout->addLayout(m_startPosXLayout);
    leftLayout->addLayout(m_startPosYLayout);

    //右侧
    rightLayout->addLayout(m_sliderLayout);
    rightLayout->addWidget(m_PushButton);
    m_sliderLayout->addWidget(m_sliderLabel);
    m_sliderLayout->addWidget(m_slider);
    m_slider->setRange(10,600);
    m_slider->setValue(50);
    mainLayout->addLayout(leftLayout);
    mainLayout->addLayout(rightLayout);
    //信号槽
    connect(m_PushButton,SIGNAL(clicked()), mazeWindow , SLOT(createMaze()));
    connect(m_widthBox,SIGNAL(valueChanged(int )),this,SLOT(handleWidthBox(int )));
    connect(m_heightBox,SIGNAL(valueChanged(int )),this,SLOT(handleHeightBox(int )));
    connect(m_startPosXBox,SIGNAL(valueChanged(int )),mazeWindow,SLOT(setStartX(int)));
    connect(m_startPosYBox,SIGNAL(valueChanged(int )),mazeWindow,SLOT(setStartY(int )));
    connect(m_slider, SIGNAL(valueChanged(int)),mazeWindow, SLOT(setStepTime(int)));
    this->setLayout(mainLayout);
}

void MazeLabel::handleWidthBox(int w)
{
    m_startPosXBox->setMaximum(w-2);
    mazeWindow->setMazeCol(w);
}

void MazeLabel::handleHeightBox(int h)
{
    m_startPosYBox->setMaximum(h-2);
    mazeWindow->setMazeRow(h);
}
