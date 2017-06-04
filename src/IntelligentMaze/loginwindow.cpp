#include "loginwindow.h"
#include <QMessageBox>
LoginWindow::LoginWindow(QWidget *parent) : QDialog (parent)
,mainLayout(new QVBoxLayout())
,nameLayout(new QHBoxLayout())
,passLayout(new QHBoxLayout())
,loginLayout(new QHBoxLayout())
 ,name(new QLabel(tr("用户名：")))
 ,pass(new QLabel(tr("密  码：")))
  ,nameText(new QLineEdit())
  ,passText(new QLineEdit())
  ,loginBtn(new QPushButton(tr("登录")))
  ,remCheck(new QCheckBox(tr("记住密码")))
{
    nameLayout->addWidget(name,1);
    nameLayout->addWidget(nameText,3);
    nameText->setText("admin");
    passLayout->addWidget(pass,1);
    passLayout->addWidget(passText,3);
    passText->setText("admin");
    loginLayout->addWidget(remCheck);
    loginLayout->addWidget(loginBtn);
    mainLayout->addLayout(nameLayout);
    mainLayout->addLayout(passLayout);
    mainLayout->addLayout(loginLayout);
    setLayout(mainLayout);
    passText->setEchoMode(QLineEdit::Password);
    remCheck->setChecked(true);
    this->setMinimumSize(200,150);
    connect(loginBtn,SIGNAL(clicked(bool)),this,SLOT(open()));
}

void LoginWindow::open()
{
    if(nameText->text().trimmed()== tr("admin") &&
       passText->text().trimmed()==tr("admin"))
    {
        accept();
    }
    else
    {
        QMessageBox::information(this, tr("警告"),tr("用户名或密码错误"));
    }
}
