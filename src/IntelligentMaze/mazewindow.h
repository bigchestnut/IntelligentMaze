#ifndef MAZEWINDOW_H
#define MAZEWINDOW_H

#include <QWidget>
#include <QHBoxLayout>
#include <QTableWidget>
#include <maze.h>

class MazeWindow : public QWidget
{
    Q_OBJECT
public:
    static MazeWindow* getInstance();
signals:

public slots:
        void createMaze();
private:
    explicit MazeWindow(QWidget *parent = 0);
    QHBoxLayout * mainLayout;
    QTableWidget* m_table;
    Maze*     m_maze;
    MyPoint ** m_mazeStruct;
    int column;
    int row;
    void initMaze();
};

#endif // MAZEWINDOW_H
