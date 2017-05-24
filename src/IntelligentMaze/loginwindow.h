#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QDialog>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QCheckBox>
class LoginWindow : public QDialog
{
    Q_OBJECT
public:
    explicit LoginWindow(QWidget *parent = 0);

signals:
private:
    QVBoxLayout *mainLayout;
    QHBoxLayout *nameLayout;
    QHBoxLayout *passLayout;
    QHBoxLayout *loginLayout;
    QLabel *name;
    QLineEdit *nameText;
    QLabel *pass;
    QLineEdit *passText;
    QPushButton* loginBtn;
    QCheckBox* remCheck;
public slots:
    void open();
};

#endif // LOGINWINDOW_H
