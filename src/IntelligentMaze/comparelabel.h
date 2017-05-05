#ifndef COMPARELABEL_H
#define COMPARELABEL_H

#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QCheckBox>
#include <QPushButton>
class CompareLabel : public QWidget
{
    Q_OBJECT
public:
    explicit CompareLabel(QWidget *parent = 0);

signals:

public slots:
private:
    QHBoxLayout*  mainLayout;
    QVBoxLayout*  leftLayout;
    QPushButton*   m_PushButton;
    QCheckBox* m_Button1;
    QCheckBox* m_Button2;
    QCheckBox* m_Button3;
    QCheckBox* m_Button4;
};

#endif // COMPARELABEL_H
