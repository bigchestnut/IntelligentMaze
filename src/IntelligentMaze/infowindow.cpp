#include "infowindow.h"

InfoWindow *InfoWindow::getInstance()
{
    static InfoWindow* m_instance;
    if (m_instance == NULL)
        m_instance = new InfoWindow();
    return m_instance;
}

void InfoWindow::addMazeStep(int level,int dir,int i, int j)
{
    QString dirStr ="";
    switch (dir) {
    case 0:
        dirStr = "本次随机方向：上";
        break;
    case 1:
        dirStr = "本次随机方向：下";
        break;
    case 2:
        dirStr ="本次随机方向：左";
        break;
    case 3:
        dirStr ="本次随机方向：右";
        break;
    default:
        dirStr = "开始生成迷宫";
        break;
    }
    m_textBro1->append(dirStr);
   QString deepStr =  QString::number(level);
    m_textBro1->append("深度： "+deepStr);
   QString str =  QString::number(i);
   QString str1 =  QString::number(j);
   m_textBro1->append("位置 X："+str +"   Y: "+str1);
    m_textBro1->append("-------------------");
}

void InfoWindow::mazeReturn(int level,int i,int j)
{
    m_textBro1->append("####回溯####");
    QString deepStr =  QString::number(level);
    m_textBro1->append("深度： "+deepStr);
    QString str =  QString::number(i);
    QString str1 =  QString::number(j);
    m_textBro1->append("位置 X："+str +"   Y: "+str1);
    m_textBro1->append("-------------------");
}

void InfoWindow::mazeEnd()
{
    m_textBro1->append("生成迷宫结束！");
}

void InfoWindow::clearInfo()
{
    m_textBro1->clear();
}

void InfoWindow::addInfo(QString str)
{
    m_textBro1->append(str);
}

void InfoWindow::addDai(int i)
{
}

void InfoWindow::addFindSearch(int i, int j)
{
    m_textBro1->append("递归搜索路径");
   QString str =  QString::number(i);
   QString str1 =  QString::number(j);
   m_textBro1->append("位置 X："+str +"   Y: "+str1);
    m_textBro1->append("-------------------");
}

void InfoWindow::addFindStep(int i, int j)
{
    m_textBro1->append("回溯确认路径");
    QString str =  QString::number(i);
    QString str1 =  QString::number(j);
    m_textBro1->append("位置 X："+str +"   Y: "+str1);
    m_textBro1->append("-------------------");
}

InfoWindow::InfoWindow(QWidget *parent) : QWidget(parent)
  ,mainLayout(new QVBoxLayout())
  ,m_textBro1(new QTextBrowser())
  ,m_textEdit(new QTextEdit())
{
    mainLayout->addWidget(m_textBro1);
    this->setLayout(mainLayout);
}



