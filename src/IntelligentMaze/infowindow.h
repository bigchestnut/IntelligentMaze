#ifndef INFOWINDOW_H
#define INFOWINDOW_H

#include <QWidget>
#include <QVBoxLayout>
#include <QTextBrowser>
#include <QPushButton>
#include <QTextEdit>
#include <QScrollArea>
class InfoWindow : public QWidget
{
    Q_OBJECT
public:
    static InfoWindow* getInstance();
    void addMazeStep(int level, int dir, int i, int j);//dir方向
    void mazeReturn(int level, int i, int j);
    void mazeEnd();
    void clearInfo();
    void addInfo(QString str);
    void addDai(int i);
    //寻路相关
    void addFindSearch(int i, int j);
    void addFindStep(int i,int j);
signals:

public slots:
private:
    explicit InfoWindow(QWidget *parent = 0);
    QVBoxLayout* mainLayout;
    QTextBrowser* m_textBro1;
    QTextBrowser* m_textBro2;
    QTextEdit* m_textEdit;
    //QPushButton* m_switchBtn;
};

#endif // INFOWINDOW_H
