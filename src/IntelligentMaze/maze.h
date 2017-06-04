#ifndef MAZE_H
#define MAZE_H
#include <QStack>
class MazeWindow;
class InfoWindow;
class Population;
class Genome;
class MyPoint
{
public:
    int i;
    int j;
    bool state;
    bool visited;
    bool isPath;
    //A*的评估值
    int h;
    int g;
    int openOrClose;//0 都不在 1 open 2 close
    int lastDir;//0 无效 1 2 3 4  上下左右
    MyPoint *lastPoint;

    MyPoint();
    MyPoint(int i, int j, bool state = false, bool visited = false, bool isPath = false);
    bool operator==(const MyPoint& maze);
    bool operator<(const MyPoint& n) const;
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
    void findPathDFS();
    void findPathAStar();
    int getHValue(int i,int j);
    void findPathInherit();
public:
    int width;
    int height;
    int startPosX;
    int startPosY;
    Maze();
    Maze(int w, int h, int x, int y);
    ~Maze();
    void setWidth(int w){width = w;}
    void setHeight(int h){height = h;}
    void setStartX(int x){startPosX = x;}
    void setStartY(int y){startPosY = y;}
    void initMaze();
    void createMaze();
    void resetMaze();
    void findPath(int i);
   MyPoint **getMaze(){return m_maze;}
};

#endif // MAZE_H
