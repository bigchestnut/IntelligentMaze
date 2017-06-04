#ifndef MAZEWINDOW_H
#define MAZEWINDOW_H

#include <QWidget>
#include <QVBoxLayout>
#include <QTableWidget>
#include <maze.h>
#include <QLabel>
class MazeWindow : public QWidget
{
    Q_OBJECT
public:
    static MazeWindow* getInstance();
    //生成迷宫相关
    void onStep(int i, int j);
    void onReturn(int dir, int i, int j);
    void setIsOncreating(bool b);
    void setIsCreated(bool b);
    //寻路相关
    void onFindStepBack(int dir, int i, int j);
    void onFindStep(int dir,int i,int j);
    void onFindReturn(int i,int j);
    void setGreen(int i, int j);
    void resetFind();
    void clearNotPath();
    Maze* getMaze();
signals:

public slots:
        //  生成迷宫相关
        void createMaze();
        void setMazeCol(int col);
        void setMazeRow(int r);
        void setStartX(int x);
        void setStartY(int y);
        void setStepTime(int t);
        // 自动寻路相关
        void findPath(int i);
        void setFindPath(bool b);
private:
    explicit MazeWindow(QWidget *parent = 0);
    QVBoxLayout * mainLayout;
    QTableWidget* m_table;
    Maze*     m_maze;
    QLabel*   m_label;
    int column;
    int row;
    int tempCol;
    int tempRow;//刚设置的、没有生成的宽高
    int startPosX;
    int startPosY;
    int m_stepTime;//单步时间
    bool m_isCreating;
    bool m_isCreatMaze;
    bool m_isFindingPath;
    void initMaze();
};

#endif // MAZEWINDOW_H
