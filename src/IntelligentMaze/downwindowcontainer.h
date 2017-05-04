#ifndef DOWNWINDOWCONTAINER_H
#define DOWNWINDOWCONTAINER_H

#include <QWidget>
#include <QHBoxLayout>
#include <mazewindow.h>
#include <infowindow.h>
class DownWindowContainer : public QWidget
{
    Q_OBJECT
public:
    explicit DownWindowContainer(QWidget *parent = 0);

signals:

public slots:
private:
    QHBoxLayout * mainLayout;
    MazeWindow * mazeWindow;
    InfoWindow * infoWindow;
};

#endif // DOWNWINDOWCONTAINER_H
