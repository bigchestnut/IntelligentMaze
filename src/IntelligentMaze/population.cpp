#include "population.h"
#include <QTimer>
#include <QTime>
#include <maze.h>
#include <mazewindow.h>
Population::Population()
{

}

Population::Population(int x, int y)
{
    this->num = (x / 2) *( y/2)  * 2;
    for (int i = 0;i<num;i++)
    {
        this->vector.append(new Genome(x,y));
    }
    this->timeOut = false;
}

bool Population::evolution()
{
     QVector<Genome*> new_vector;
     while(new_vector.size() < this->num)
     {
        Genome* child_a = this->select();
        Genome* child_b = this->select();

        child_a->crossover(child_b);
        child_a->mutate();
        child_b->mutate();
        new_vector.append(child_a);
        new_vector.append(child_b);
     }
     vector.clear();
     vector = new_vector;
}

int Population::checkEnd()
{
    for (int i = 0;i<num;i++)
    {
        if (vector.at(i)->isRes())
            return i;
    }
    return -1;
}

Genome *Population::getResGen(int i)
{
    for (int i = 0;i<num;i++)
    {
        if (vector.at(i)->isRes())
            return vector[i];
    }
}

Genome* Population::select()
{
     qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
     int t = qrand()%(this->num /3);
     for(int i = 0; i< this->num; i++)
     {
         if (vector.at(i)->fitness <= t)
             return vector[i];
     }
}

void Population::timeEnd()
{
    this->timeOut = true;
}

Genome::Genome(int x, int y)
{
    this->x = x;
    this->y = y;
    this->len = (x / 2) * (y / 2);
    MazeWindow * ins = MazeWindow::getInstance();
    this->maze = ins->getMaze()->getMaze();
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    for (int i=0;i<len;i++)
    {
        this->gen.append(qrand()%4);//0-3上下左右
    }
    this->fit();
}

Genome *Genome::crossover(Genome *dad)
{
    int x = qrand()%this->len;
    if (qrand()%10>CROSSOVER_RATE)
    {
        for(int i=0;i<x;i++)
        {
            int temp = this->gen.at(i);
            this->gen[i] = dad->gen[i];
            dad->gen[i] =temp;
        }
    }
}

Genome *Genome::mutate()
{
    for(int i=0;i<x;i++)
    {
        qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
        if (qrand()%10<MUTATION_RATE)
        {
             this->gen[i] = 1 - this->gen[i];
         }
    }
}

bool Genome::isRes()
{
    if (this->fitness == 0)
        return true;
}

void Genome::fit()
{
    int now_x = 1;
    int now_y = 1;
    for(int i=0;i<len;i++)
    {
        int dir = gen.at(i);
        if((now_x == this->x -2) && (now_y == this->y -2) )
        {
            this->fitness = 0;
            return;
        }
        switch (dir) {
        case 0:
            if(now_x -1<=0 || maze[now_x - 1][now_y].state == false)
            {
                    this->fitness = qAbs(now_x - x) + qAbs(now_y - y);
                        return;
            }
            now_x -=2;
            break;
        case 1:
            if(now_x +1 >=this->x -1 || maze[now_x+1][now_y].state == false)
            {
                    this->fitness = qAbs(now_x - x) + qAbs(now_y - y);
                        return;
            }
            now_x +=2;
            break;
        case 2:
            if(now_y -1 <=0 || maze[now_x][now_y-1].state == false)
            {
                    this->fitness = qAbs(now_x - x) + qAbs(now_y - y);
                        return;
            }
            now_y -=2;
            break;
        case 3:
            if(now_y +1 >=this->y -1 || maze[now_x][now_y+1].state == false)
            {
                    this->fitness = qAbs(now_x - x) + qAbs(now_y - y);
                        return;
            }
            now_y +=2;
            break;
        default:
            break;
        }
    }
    this->fitness = this->len;
}
