#ifndef INFOWINDOW_H
#define INFOWINDOW_H

#include <QWidget>
#include <QVBoxLayout>
#include <QTextBrowser>
#include <QPushButton>
class InfoWindow : public QWidget
{
    Q_OBJECT
public:
    explicit InfoWindow(QWidget *parent = 0);

signals:

public slots:
private:
    QVBoxLayout* mainLayout;
    QTextBrowser* m_textBro1;
    QTextBrowser* m_textBro2;
    QPushButton* m_switchBtn;
};

#endif // INFOWINDOW_H
