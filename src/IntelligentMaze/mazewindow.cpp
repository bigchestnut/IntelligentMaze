#include "mazewindow.h"
#include <QHeaderView>
#include <QTime>
#include <QCoreApplication>
#include <QMessageBox>
MazeWindow::MazeWindow(QWidget *parent) : QWidget(parent)
   ,mainLayout(new QHBoxLayout(this))
   ,m_label(new QLabel())
{
    QFont ft;
    ft.setPointSize(25);
    m_label->setAlignment(Qt::AlignCenter);
    m_label->setFont(ft);
    m_label->setText("欢迎使用智能迷宫系统！");
    mainLayout->addWidget(m_label);
    this->setLayout(mainLayout);
    this->tempCol = 25;
    this->tempRow = 13;
    this->startPosX = 1;
    this->startPosY = 1;
    this->m_stepTime = 50;
    this->m_isCreating = false;
    this->m_isCreatMaze = false;
    this->m_isFindingPath = false;
    this->m_table = NULL;
    this->m_maze = NULL;
}

MazeWindow *MazeWindow::getInstance()
{
    static MazeWindow* m_instance;
    if (m_instance == NULL)
        m_instance = new MazeWindow();
    return m_instance;
}

void MazeWindow::onStep(int i, int j)
{
    if (m_table == NULL)
        return;
    QTableWidgetItem * item =  m_table->item(i, j);
    if (item !=NULL)
        item->setBackgroundColor(QColor(0,255,0));
    //暂停100ms
    QTime t;
    t.start();
    while(t.elapsed()< m_stepTime)
        QCoreApplication::processEvents();
    if (item !=NULL)
        item->setBackgroundColor(QColor(255,255,255));
}

void MazeWindow::onReturn(int dir,int i, int j)
{
    int ii=i,jj=j;
    switch (dir) {
    case 0:
        ii -=1;
        break;
    case 1:
        ii +=1;
        break;
    case 2:
        jj -=1;
        break;
    case 3:
        jj +=1;
        break;
    default:
        break;
    }
    if (m_table == NULL)
        return;
    QTableWidgetItem * item =  m_table->item(ii, jj);
    if (item !=NULL)
        item->setBackgroundColor(QColor(255,0,0));
    //暂停
    QTime t;
    t.start();
    while(t.elapsed()< m_stepTime)
        QCoreApplication::processEvents();
    if (item !=NULL)
        item->setBackgroundColor(QColor(255,255,255));
    item =  m_table->item(i, j);
    if (item !=NULL)
        item->setBackgroundColor(QColor(255,0,0));
    //暂停
    QTime t1;
    t1.start();
    while(t1.elapsed()< m_stepTime)
        QCoreApplication::processEvents();
    if (item !=NULL)
        item->setBackgroundColor(QColor(255,255,255));

}

void MazeWindow::setIsOncreating(bool b)
{
    m_isCreating = b;
}

void MazeWindow::setIsCreated(bool b)
{
    m_isCreatMaze = b;
}

void MazeWindow::onFindStepBack(int dir,int i, int j)
{
    QTableWidgetItem * item =  m_table->item(i, j);
    if (item !=NULL)
        item->setBackgroundColor(QColor(0,255,0));
    //暂停100ms
    QTime t;
    t.start();
    while(t.elapsed()< m_stepTime)
        QCoreApplication::processEvents();

    int ii = i,jj= j;
    switch (dir) {
    case 0:
        return;
        break;
    case 1:
        ii +=1;
        break;
    case 2:
        ii -=1;
        break;
    case 3:
       jj += 1;
        break;
    case 4:
       jj -=1;
        break;
    default:
        break;
    }
    QTableWidgetItem * item0 =  m_table->item(ii, jj);
    if (item0 !=NULL)
        item0->setBackgroundColor(QColor(0,255,0));
    //暂停100ms
    QTime t0;
    t0.start();
    while(t0.elapsed()< m_stepTime)
        QCoreApplication::processEvents();
//    MyPoint** temp = m_maze->getMaze();
//    if(temp == NULL)
//        return;
//    //上
//    if(i>2 && temp[i-1][j].state && temp[i-2][j].visited)
//    {
//        QTableWidgetItem * item1 =  m_table->item(i-1, j);
//        if (item1 !=NULL)
//            item1->setBackgroundColor(QColor(255,255,255));
//        //暂停100ms
//        QTime t1;
//        t1.start();
//        while(t1.elapsed()< m_stepTime)
//            QCoreApplication::processEvents();
//        QTableWidgetItem * item11 =  m_table->item(i-2, j);
//        if (item11 !=NULL)
//            item11->setBackgroundColor(QColor(255,255,255));
//        //暂停100ms
//        QTime t11;
//        t11.start();
//        while(t11.elapsed()< m_stepTime)
//            QCoreApplication::processEvents();
//    }
//    //下
//    if(i<row - 2 && temp[i+1][j].state && temp[i+2][j].visited)
//    {
//        QTableWidgetItem * item1 =  m_table->item(i+1, j);
//        if (item1 !=NULL)
//            item1->setBackgroundColor(QColor(255,255,255));
//        //暂停100ms
//        QTime t1;
//        t1.start();
//        while(t1.elapsed()< m_stepTime)
//            QCoreApplication::processEvents();
//        QTableWidgetItem * item11 =  m_table->item(i+2, j);
//        if (item11 !=NULL)
//            item11->setBackgroundColor(QColor(255,255,255));
//        //暂停100ms
//        QTime t11;
//        t11.start();
//        while(t11.elapsed()< m_stepTime)
//            QCoreApplication::processEvents();
//    }
//    //左
//    if(j >2 && temp[i][j-1].state && temp[i][j-2].visited )
//    {
//        QTableWidgetItem * item1 =  m_table->item(i, j-1);
//        if (item1 !=NULL)
//            item1->setBackgroundColor(QColor(255,255,255));
//        //暂停100ms
//        QTime t1;
//        t1.start();
//        while(t1.elapsed()< m_stepTime)
//            QCoreApplication::processEvents();
//        QTableWidgetItem * item11 =  m_table->item(i, j-2);
//        if (item11 !=NULL)
//            item11->setBackgroundColor(QColor(255,255,255));
//        //暂停100ms
//        QTime t11;
//        t11.start();
//        while(t11.elapsed()< m_stepTime)
//            QCoreApplication::processEvents();
//    }
//    //右
//    if(j < column -2 && temp[i][j+1].state && temp[i][j+2].visited)
//    {
//        QTableWidgetItem * item1 =  m_table->item(i, j+1);
//        if (item1 !=NULL)
//            item1->setBackgroundColor(QColor(255,255,255));
//        //暂停100ms
//        QTime t1;
//        t1.start();
//        while(t1.elapsed()< m_stepTime)
//            QCoreApplication::processEvents();
//        QTableWidgetItem * item11 =  m_table->item(i, j+2);
//        if (item11 !=NULL)
//            item11->setBackgroundColor(QColor(255,255,255));
//        //暂停100ms
//        QTime t11;
//        t11.start();
//        while(t11.elapsed()< m_stepTime)
//            QCoreApplication::processEvents();
//    }
}

void MazeWindow::onFindStep(int dir,int i, int j)
{
    int ii = i,jj= j;
    switch (dir) {
    case 1:
        ii +=1;
        break;
    case 2:
        ii -=1;
        break;
    case 3:
       jj += 1;
        break;
    case 4:
       jj -=1;
        break;
    default:
        break;
    }
    QTableWidgetItem * item1 =  m_table->item(ii, jj);
    if (item1 !=NULL)
        item1->setBackgroundColor(QColor(255,255,0));
    if (dir == 0)
        return;
    //暂停100ms
    QTime t1;
    t1.start();
    while(t1.elapsed()< m_stepTime)
        QCoreApplication::processEvents();

    QTableWidgetItem * item =  m_table->item(i, j);
    if (item !=NULL)
        item->setBackgroundColor(QColor(255,255,0));
    //暂停100ms
    QTime t;
    t.start();
    while(t.elapsed()< m_stepTime)
        QCoreApplication::processEvents();

}

void MazeWindow::onFindReturn(int i, int j)
{

}

void MazeWindow::resetFind()
{
    MyPoint **m_temp = m_maze->getMaze();
    //重置寻路结果
    for (int i = 0; i < row;i++ )
    {
        for(int j = 0; j< column;j++)
        {
            QTableWidgetItem * item =  m_table->item(i, j);
            if (item == NULL)
                continue;
            if(m_temp[i][j].state )
                item->setBackgroundColor(QColor(255,255,255));
        }
    }
}

void MazeWindow::clearNotPath()
{
    MyPoint **m_temp = m_maze->getMaze();
    //清除非路径
    for (int i = 0; i < row;i++ )
    {
        for(int j = 0; j< column;j++)
        {
            QTableWidgetItem * item =  m_table->item(i, j);
            if (item == NULL)
                continue;
            if(m_temp[i][j].state && m_temp[i][j].isPath == false )
            {
                item->setBackgroundColor(QColor(255,255,255));
            }
        }
    }
}



void MazeWindow::createMaze()
{
    if (m_isCreating)
    {
        QMessageBox::information(this, tr("警告"),tr("正在生成迷宫中，请稍后再试！"));
        return;
    }
    if (m_isFindingPath)
    {
        QMessageBox::information(this, tr("警告"),tr("正在自动寻路中，请稍后再试！"));
        return;
    }
    if(m_label)
    {
        mainLayout->removeWidget(m_label);
        m_label = NULL;
    }
    initMaze();
    if (m_maze != NULL)
    {
        delete m_maze;
        m_maze = NULL;
    }
    m_maze = new Maze(column, row,startPosX,startPosY);
    m_maze->resetMaze();
    m_maze->createMaze();
}

void MazeWindow::setMazeCol(int col)
{
    this->tempCol = col;
}

void MazeWindow::setMazeRow(int r)
{
    this->tempRow = r;
}

void MazeWindow::setStartX(int x)
{
    this->startPosX = x;
}

void MazeWindow::setStartY(int y)
{
    this->startPosY = y;
}

void MazeWindow::setStepTime(int t)
{
    this->m_stepTime = t;
}

void MazeWindow::findPath(int i)
{
    if(m_isCreating)
    {
        QMessageBox::information(this, tr("警告"),tr("请耐心等待迷宫生成完毕！"));
        return;
    }
    if (m_isCreatMaze ==false)
    {
        QMessageBox::information(this, tr("警告"),tr("请先生成迷宫！"));
        return;
    }
    if (m_isFindingPath)
    {
        QMessageBox::information(this, tr("警告"),tr("正在自动寻路中，请稍后再试！"));
        return;
    }
    m_maze->findPath(i);
}

void MazeWindow::setFindPath(bool b)
{
    m_isFindingPath = b;
}

void MazeWindow::initMaze()
{
    if (m_table != NULL)
    {
        //删除上一次表格
        for (int i = 0; i < row;i++ )
        {
            for(int j = 0; j< column;j++)
            {
                m_table->removeCellWidget(i,j);
            }
        }
        mainLayout->removeWidget(m_table);
        m_table = NULL;
    }
    column = tempCol;
    row = tempRow;
    m_table = new QTableWidget(row, column);
    //初始化表格
    for (int i = 0; i < row;i++ )
    {
        for(int j = 0; j< column;j++)
        {
            m_table->setItem(i, j, new QTableWidgetItem());
            QTableWidgetItem * item =  m_table->item(i, j);
            if (item == NULL)
                continue;
            item->setBackgroundColor(QColor(125,125,125));
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

}




