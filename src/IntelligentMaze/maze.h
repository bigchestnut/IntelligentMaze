#ifndef MAZE_H
#define MAZE_H
#include <QStack>

class MyPoint
{
public:
    int i;
    int j;
    bool state;

    MyPoint();
    MyPoint(int i,int j, bool state = false);

    bool operator==(const MyPoint& maze);
};
class Maze
{
private:
    MyPoint **m_maze;
    QStack<MyPoint> *m_mazeStack;
    void resetDir(bool& up, bool& down, bool& right, bool& left);
public:
    int width;
    int height;
    Maze();
    Maze(int w, int h);
    void initMaze();
    void createMaze();
    void resetMaze();
   MyPoint ** getMaze(){return m_maze;}
};

#endif // MAZE_H
