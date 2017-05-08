#include "mazewindow.h"
#include <QHeaderView>
MazeWindow::MazeWindow(QWidget *parent) : QWidget(parent)
   ,mainLayout(new QHBoxLayout(this))
{
    column = 25;
    row = 13;
    m_table = new QTableWidget(row, column);
    m_maze = new Maze(column,row);
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
    this->setLayout(mainLayout);
    initMaze();
    // createMaze();
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

void MazeWindow::initMaze()
{
    for (int i = 0; i < row;i++ )
    {
        for(int j = 0; j< column;j++)
        {
               QTableWidgetItem * item =  m_table->item(i, j);
               if (item == NULL)
                   continue;
               item->setBackgroundColor(QColor(125,125,125));
        }
    }
}




