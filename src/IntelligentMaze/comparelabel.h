#ifndef COMPARELABEL_H
#define COMPARELABEL_H

#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QSlider>
#include <mazewindow.h>
class CompareLabel : public QWidget
{
    Q_OBJECT
public:
    explicit CompareLabel(QWidget *parent = 0);

signals:

public slots:
private:
    QVBoxLayout*  mainLayout;
    QHBoxLayout* m_sliderLayout;
    QLabel* m_sliderLabel;
    QLabel* m_slowLabel;
    QLabel* m_fastLabel;
    QSlider* m_slider;

    MazeWindow * mazeWindow;
};

#endif // COMPARELABEL_H
