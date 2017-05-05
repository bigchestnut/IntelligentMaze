#ifndef MAZEWINDOW_H
#define MAZEWINDOW_H

#include <QWidget>
#include <QHBoxLayout>
#include <QGraphicsView>
#include <QPaintEvent>
#include <QPainter>
class MazeWindow : public QWidget
{
    Q_OBJECT
public:
    explicit MazeWindow(QWidget *parent = 0);

signals:

public slots:

private:
    void paintEvent();
    QHBoxLayout * mainLayout;
    QGraphicsView * m_graphView;
};

#endif // MAZEWINDOW_H
