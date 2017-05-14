#include "mazewindow.h"
#include <QHeaderView>
MazeWindow::MazeWindow(QWidget *parent) : QWidget(parent)
   ,mainLayout(new QHBoxLayout(this))
{
    this->setLayout(mainLayout);
    //initMaze();
}

MazeWindow *MazeWindow::getInstance()
{
    static MazeWindow* m_instance;
    if (m_instance == NULL)
        m_instance = new MazeWindow();
    return m_instance;
}

void MazeWindow::createMaze()
{
    initMaze();
    if (m_maze != NULL)
    {
        delete m_maze;
        m_maze = NULL;
    }
    m_maze = new Maze(column, row,startPosX,startPosY);
    m_maze->resetMaze();
    m_maze->createMaze();
    MyPoint** temp = m_maze->getMaze();
    if(temp == NULL)
        return;
    for (int i = 0; i < row;i++ )
    {
        for(int j = 0; j< column;j++)
        {
            if(temp[i][j].state == true)
            {
               QTableWidgetItem * item =  m_table->item(i, j);
               if (item == NULL)
                   continue;
               item->setBackgroundColor(QColor(255,255,255));
            }
        }
    }
}

void MazeWindow::setMazeCol(int col)
{
    this->column = col;
    if (m_maze !=NULL)
        m_maze->setWidth(col);
}

void MazeWindow::setMazeRow(int r)
{
    this->row = r;
    if (m_maze !=NULL)
        m_maze->setHeight(r);
}

void MazeWindow::setStartX(int x)
{
    this->startPosX = x;
    if(m_maze != NULL)
        m_maze->setStartX(x);
}

void MazeWindow::setStartY(int y)
{
    this->startPosY = y;
    if(m_maze != NULL)
        m_maze->setStartY(y);
}

void MazeWindow::initMaze()
{
    if (m_table != NULL)
    {
        mainLayout->removeWidget(m_table);
        delete m_table;
        m_table = NULL;
    }
    column = 25;
    row = 13;
    startPosX = 1;
    startPosY = 1;
    m_table = new QTableWidget(row, column);
    m_maze = new Maze(column, row,startPosX,startPosY);
    //初始化表格
    for (int i = 0; i < row;i++ )
    {
        for(int j = 0; j< column;j++)
        {
            m_table->setItem(i, j, new QTableWidgetItem());
        }
    }
    mainLayout->addWidget(m_table);
    //设置表格不可编辑，不可选中
    m_table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    m_table->setSelectionMode(QAbstractItemView::NoSelection);
    //隐藏表头，表格自动填充
    m_table->verticalHeader()->hide();
    m_table->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    m_table->verticalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
    //列
    m_table->horizontalHeader()->hide();
    m_table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    m_table->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
    for (int i = 0; i < row;i++ )
    {
        for(int j = 0; j< column;j++)
        {
                m_table->removeCellWidget(i,j);
               QTableWidgetItem * item =  m_table->item(i, j);
               if (item == NULL)
                   continue;
               item->setBackgroundColor(QColor(125,125,125));
        }
    }
}




