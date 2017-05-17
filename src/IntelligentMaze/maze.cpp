#include "maze.h"
#include <QTime>
#include <mazewindow.h>
#include <infowindow.h>
#include <QQueue>
void Maze::resetDir(bool &up, bool &down, bool &right, bool &left)
{
    up = false;
    down = false;
    right = false;
    left = false;
    algoIndex = 0;
}

void Maze::resetPath()
{
    for(int i=0; i < height ; i++)
    {
          for (int j=0; j<width; j++)
          {
               m_maze[i][j].visited = false;
               m_maze[i][j].lastPoint = NULL;
          }
    }
}

void Maze::findPathBFS()
{
    if(m_maze == NULL)
        return;
    ;
    resetPath();
    mazeWindow->setFindPath(true);
    int i=1,j=1;
    QQueue<MyPoint*>* queue = new QQueue<MyPoint*>();
    queue->append(&m_maze[i][j]);

    while(!queue->empty())
    {
        MyPoint* temp = queue->front();
        queue->pop_front();
        i = temp->i;
        j = temp->j;
        m_maze[i][j].visited = true;
        //判断终点
        if (i ==height-2 && j == width - 2 )
        {
            infoWindow->clearInfo();
            mazeWindow->onFindStep(i,j);
            //设置路径
            while(temp->lastPoint != NULL)
            {
                infoWindow->addFindStep(temp->i,temp->j);
                mazeWindow->onFindStep(temp->i,temp->j);
                temp = temp->lastPoint;
            }
            mazeWindow->setFindPath(false);
            return;
        }

        //上
        if(i>2 && m_maze[i-1][j].state && m_maze[i-2][j].visited == false)
        {
            m_maze[i-2][j].lastPoint = temp;
            queue->append(&m_maze[i-2][j]);
        }
        //下
        if(i<height - 2 && m_maze[i+1][j].state && m_maze[i+2][j].visited == false)
        {
            m_maze[i+2][j].lastPoint = temp;
            queue->append(&m_maze[i+2][j]);
        }
        //左
        if(j >2 && m_maze[i][j-1].state && m_maze[i][j-2].visited == false)
        {
            m_maze[i][j-2].lastPoint = temp;
            queue->append(&m_maze[i][j-2]);
        }
        //右
        if(j < width -2 && m_maze[i][j+1].state && m_maze[i][j+2].visited == false)
        {
            m_maze[i][j+2].lastPoint = temp;
            queue->append(&m_maze[i][j+2]);
        }
    }
}

Maze::Maze()
{

}

Maze::Maze(int w, int h, int x, int y)
{
    this->width = w;
    this->height = h;
    this->startPosX = x;
    this->startPosY = y;
    this->mazeWindow = MazeWindow::getInstance();
    this->infoWindow = InfoWindow::getInstance();
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
    m_mazeDirStack = new QStack<int>();
}


void Maze::createMaze()
{
    mazeWindow->setIsOncreating(true);
    infoWindow->clearInfo();
    int level = 1;
    int i=startPosY,j=startPosX;
    m_maze[i][j].state=true;
    mazeWindow->onStep(i,j);
    infoWindow->addMazeStep(level,4,i,j);
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
            m_mazeDirStack->push(0);
            m_maze[i-2][j].state=true;
            m_maze[i-1][j].state=true;
            mazeWindow->onStep(i-1,j);
            mazeWindow->onStep(i-2,j);
            level +=1;
            infoWindow->addMazeStep(level, 0,i-2,j);
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
            m_mazeDirStack->push(1);
            m_maze[i+2][j].state=true;
            m_maze[i+1][j].state=true;
            mazeWindow->onStep(i+1,j);
            mazeWindow->onStep(i+2,j);
            level +=1;
            infoWindow->addMazeStep(level,1,i+2,j);
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
            m_mazeDirStack->push(2);
            m_maze[i][j-2].state=true;
            m_maze[i][j-1].state=true;
            mazeWindow->onStep(i,j-1);
            mazeWindow->onStep(i,j-2);
            level +=1;
            infoWindow->addMazeStep(level,2,i,j-2);
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
            m_mazeDirStack->push(3);
            m_maze[i][j+2].state=true;
            m_maze[i][j+1].state=true;
            mazeWindow->onStep(i,j+1);
            mazeWindow->onStep(i,j+2);
            level +=1;
            infoWindow->addMazeStep(level,3,i,j+2);
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
                int dir = m_mazeDirStack->top();
                m_mazeDirStack->pop();
                level -=1;
                mazeWindow->onReturn(dir,i,j);
                infoWindow->mazeReturn(level, i ,j);
                resetDir(up, down, right, left);
            }
            else//如果栈为空的话就返回，此时迷宫矩阵已经创建完毕
            {
                infoWindow->mazeEnd();
                mazeWindow->setIsOncreating(false);
                mazeWindow->setIsCreated(true);
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

void Maze::findPath(int i)
{
    switch (i) {
    case 1:
        findPathBFS();
        break;
    case 2:
        findPathBFS();
        break;
    case 3:
        findPathBFS();
        break;
    case 4:
        findPathBFS();
        break;
    default:
        findPathBFS();
        break;
    }
}

MyPoint::MyPoint()
{
     this->lastPoint = NULL;
}

MyPoint::MyPoint(int i, int j, bool state, bool visited)
{
    this->i = i;
    this->j = j;
    this->state = state;
    this->visited = visited;
    this->lastPoint = NULL;
}
