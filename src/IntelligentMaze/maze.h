#ifndef MAZE_H
#define MAZE_H
#include <QStack>
class MazeWindow;
class InfoWindow;
class MyPoint
{
public:
    int i;
    int j;
    bool state;
    bool visited;
    MyPoint *lastPoint;

    MyPoint();
    MyPoint(int i,int j, bool state = false, bool visited = false);

    bool operator==(const MyPoint& maze);
};
class Maze
{
private:
    MyPoint **m_maze;
    QStack<MyPoint> *m_mazeStack;
    QStack<int> *m_mazeDirStack;
    void resetDir(bool& up, bool& down, bool& right, bool& left);
    MazeWindow* mazeWindow;
    InfoWindow* infoWindow;

    //寻路相关
    int algoIndex;
    void resetPath();
    void findPathBFS();

public:
    int width;
    int height;
    int startPosX;
    int startPosY;
    Maze();
    Maze(int w, int h, int x, int y);

    void setWidth(int w){width = w;}
    void setHeight(int h){height = h;}
    void setStartX(int x){startPosX = x;}
    void setStartY(int y){startPosY = y;}
    void initMaze();
    void createMaze();
    void resetMaze();
    void findPath(int i);
   MyPoint ** getMaze(){return m_maze;}
};

#endif // MAZE_H
