#ifndef MAINWINDOWCONTAINER_H
#define MAINWINDOWCONTAINER_H

#include <QWidget>
#include <QHBoxLayout>
#include<upwindowcontainer.h>
#include <downwindowcontainer.h>
class MainWindowContainer : public QWidget
{
    Q_OBJECT
public:
    explicit MainWindowContainer(QWidget *parent = 0);

signals:

public slots:
private:
    QVBoxLayout * mainLayout;
    UpWindowContainer * upWindow;
    DownWindowContainer * downWindow;
};

#endif // MAINWINDOWCONTAINER_H
