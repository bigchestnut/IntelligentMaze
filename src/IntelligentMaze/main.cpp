#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    //心跳函数循环
//    while(true)
//    {

//    }
    return a.exec();
}
