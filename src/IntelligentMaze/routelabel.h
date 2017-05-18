#ifndef ROUTELABEL_H
#define ROUTELABEL_H

#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QRadioButton>
#include <QPushButton>
#include "mazewindow.h"
class RouteLabel : public QWidget
{
    Q_OBJECT
public:
    explicit RouteLabel(QWidget *parent = 0);

signals:

public slots:
private slots:
    void findPath();
private:
    QHBoxLayout*  mainLayout;
    QVBoxLayout*  leftLayout;
    QPushButton*   m_PushButton;
    QRadioButton* m_Button1;
    QRadioButton* m_Button2;
    QRadioButton* m_Button3;
    //QRadioButton* m_Button4;
    MazeWindow* mazeWindow;
};

#endif // ROUTELABEL_H
