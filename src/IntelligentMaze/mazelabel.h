#ifndef MAZELABLE_H
#define MAZELABLE_H

#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QRadioButton>
#include <QPushButton>
#include <QLabel>
#include <QSpinBox>
#include "mazewindow.h"

class MazeLabel : public QWidget
{
    Q_OBJECT
public:
    explicit MazeLabel(QWidget *parent = 0);

signals:

public slots:
    void handleWidthBox( int w);
    void handleHeightBox(int h);
private:
    QHBoxLayout*  mainLayout;
    QHBoxLayout*  m_widthLayout;
    QHBoxLayout*  m_heightLayout;
    QHBoxLayout*  m_startPosXLayout;
    QHBoxLayout*  m_startPosYLayout;
    QVBoxLayout*  leftLayout;
    QPushButton*   m_PushButton;
    QSpinBox* m_widthBox;
    QSpinBox* m_heightBox;
    QSpinBox* m_startPosXBox;
    QSpinBox* m_startPosYBox;
    QLabel* m_widthLabel;
    QLabel* m_heightLabel;
    QLabel* m_startPosX;
    QLabel* m_startPosY;
//    QRadioButton* m_Button1;
//    QRadioButton* m_Button2;
    MazeWindow * mazeWindow;
};

#endif // MAZELABLE_H
