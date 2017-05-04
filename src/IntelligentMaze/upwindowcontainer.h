#ifndef UPWINDOWCONTAINER_H
#define UPWINDOWCONTAINER_H

#include <QWidget>
#include <QHBoxLayout>
#include <mazelabel.h>
#include <routelabel.h>
#include <comparelabel.h>
class UpWindowContainer : public QWidget
{
    Q_OBJECT
public:
    explicit UpWindowContainer(QWidget *parent = 0);

signals:

public slots:
private:
    QHBoxLayout * mainLayout;
    MazeLabel * mazeLabel;
    RouteLabel * routeLabel;
    CompareLabel * compareLabel;
};

#endif // UPWINDOWCONTAINER_H
