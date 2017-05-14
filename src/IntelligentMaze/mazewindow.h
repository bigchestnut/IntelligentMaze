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
        void setMazeCol(int col);
        void setMazeRow(int r);
        void setStartX(int x);
        void setStartY(int y);
private:
    explicit MazeWindow(QWidget *parent = 0);
    QHBoxLayout * mainLayout;
    QTableWidget* m_table;
    Maze*     m_maze;
    MyPoint ** m_mazeStruct;
    int column;
    int row;
    int tempCol;
    int tempRow;//刚设置的、没有生成的宽高
    int startPosX;
    int startPosY;
    void initMaze();
};

#endif // MAZEWINDOW_H
