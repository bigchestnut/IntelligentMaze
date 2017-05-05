#ifndef MAZELABLE_H
#define MAZELABLE_H

#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QRadioButton>
#include <QPushButton>
class MazeLabel : public QWidget
{
    Q_OBJECT
public:
    explicit MazeLabel(QWidget *parent = 0);

signals:

public slots:
private:
    QHBoxLayout*  mainLayout;
    QVBoxLayout*  leftLayout;
    QPushButton*   m_PushButton;
    QRadioButton* m_Button1;
    QRadioButton* m_Button2;
};

#endif // MAZELABLE_H
