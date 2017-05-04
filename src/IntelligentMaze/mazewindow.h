#ifndef MAZEWINDOW_H
#define MAZEWINDOW_H

#include <QWidget>
#include <QHBoxLayout>
#include <QLabel>
class MazeWindow : public QWidget
{
    Q_OBJECT
public:
    explicit MazeWindow(QWidget *parent = 0);

signals:

public slots:
private:
    QHBoxLayout * mainLayout;
    QLabel * m_title;
};

#endif // MAZEWINDOW_H
