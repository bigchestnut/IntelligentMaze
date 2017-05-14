#include "maze.h"
#include <QTime>
void Maze::resetDir(bool &up, bool &down, bool &right, bool &left)
{
    up = false;
    down = false;
    right = false;
    left = false;
}

Maze::Maze()
{

}

Maze::Maze(int w, int h, int x, int y)
{
    this->width = w;
    this->height = h;
    startPosX = x;
    startPosY = y;
    initMaze();
}

void Maze::initMaze()
{
    m_maze =new MyPoint*[height];
    for(int i=0; i < height ; i++)
    {
          m_maze[i] = new MyPoint[width];
          for (int j=0; j<width; j++)
          {
               m_maze[i][j].i = i;
               m_maze[i][j].j = j;
               m_maze[i][j].state = false;
          }
    }
    m_mazeStack = new QStack<MyPoint>();
}


void Maze::createMaze()
{
    int i=startPosY,j=startPosX;
    m_maze[i][j].state=true;

    MyPoint temp;
    temp.i=i;
    temp.j=j;
    temp.state=true;
    bool up=false, down=false, right=false, left=false;
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    while(true)
    {
        temp.i=i;
        temp.j=j;
        int randNum=qrand()%4;
        switch(randNum)
        {
case 0://上
        if(!up&&i>2&&m_maze[i-2][j].state==false)
        {
            m_mazeStack->push(temp);
            m_maze[i-2][j].state=true;
            m_maze[i-1][j].state=true;
            i=i-2;
            resetDir(up, down, right, left);
        }
        else
            up=true;
        break;
case 1://下
        if(!down&&i<height-2&&m_maze[i+2][j].state==false)
        {
            m_mazeStack->push(temp);
            m_maze[i+2][j].state=true;
            m_maze[i+1][j].state=true;
            i=i+2;
            resetDir(up, down, right, left);
        }
        else
            down=true;
        break;
case 2://左
        if(!left&&j>2&&m_maze[i][j-2].state==false)
        {
            m_mazeStack->push(temp);
            m_maze[i][j-2].state=true;
            m_maze[i][j-1].state=true;
            j=j-2;
            resetDir(up, down, right, left);
        }
        else
            left=true;
        break;
case 3://右
        if(!right&&j<width-2&&m_maze[i][j+2].state==false)
        {
            m_mazeStack->push(temp);
            m_maze[i][j+2].state=true;
            m_maze[i][j+1].state=true;
            j=j+2;
            resetDir(up, down, right, left);
        }
        else
            right=true;
        break;
        }
        if(up&&down&&right&&left)//如果当前访问节点四个方向都没有可拆的节点，回溯
        {
            if(!m_mazeStack->empty())
            {
                i=m_mazeStack->top().i;
                j=m_mazeStack->top().j;
                m_mazeStack->pop();
                resetDir(up, down, right, left);
            }
            else//如果栈为空的话就返回，此时迷宫矩阵已经创建完毕
            {
                return;
            }
        }
    }
}

void Maze::resetMaze()
{
    for(int i=0; i < height ; i++)
    {
          for (int j=0; j<width; j++)
          {
               m_maze[i][j].i = i;
               m_maze[i][j].j = j;
               m_maze[i][j].state = false;
          }
    }
}

MyPoint::MyPoint()
{

}

MyPoint::MyPoint(int i, int j, bool state)
{
    this->i = i;
    this->j = j;
    this->state = state;
}
