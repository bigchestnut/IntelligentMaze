/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *gridLayoutWidget;
    QGridLayout *mainlayout;
    QHBoxLayout *horizontalLayout_26;
    QGraphicsView *graphicsView_7;
    QHBoxLayout *horizontalLayout_24;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *radioButton;
    QRadioButton *radioButton_3;
    QPushButton *pushButton;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_3;
    QRadioButton *radioButton_5;
    QRadioButton *radioButton_4;
    QRadioButton *radioButton_2;
    QPushButton *pushButton_2;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_4;
    QCheckBox *checkBox;
    QCheckBox *checkBox_6;
    QCheckBox *checkBox_5;
    QPushButton *pushButton_4;
    QVBoxLayout *verticalLayout_5;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label;
    QLabel *label_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(856, 488);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayoutWidget = new QWidget(centralWidget);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(0, 20, 681, 381));
        mainlayout = new QGridLayout(gridLayoutWidget);
        mainlayout->setSpacing(6);
        mainlayout->setContentsMargins(11, 11, 11, 11);
        mainlayout->setObjectName(QStringLiteral("mainlayout"));
        mainlayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        mainlayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_26 = new QHBoxLayout();
        horizontalLayout_26->setSpacing(6);
        horizontalLayout_26->setObjectName(QStringLiteral("horizontalLayout_26"));
        graphicsView_7 = new QGraphicsView(gridLayoutWidget);
        graphicsView_7->setObjectName(QStringLiteral("graphicsView_7"));

        horizontalLayout_26->addWidget(graphicsView_7);


        mainlayout->addLayout(horizontalLayout_26, 1, 0, 1, 1);

        horizontalLayout_24 = new QHBoxLayout();
        horizontalLayout_24->setSpacing(6);
        horizontalLayout_24->setObjectName(QStringLiteral("horizontalLayout_24"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        radioButton = new QRadioButton(gridLayoutWidget);
        radioButton->setObjectName(QStringLiteral("radioButton"));

        verticalLayout_2->addWidget(radioButton);

        radioButton_3 = new QRadioButton(gridLayoutWidget);
        radioButton_3->setObjectName(QStringLiteral("radioButton_3"));

        verticalLayout_2->addWidget(radioButton_3);


        horizontalLayout->addLayout(verticalLayout_2);

        pushButton = new QPushButton(gridLayoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);


        horizontalLayout_24->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        radioButton_5 = new QRadioButton(gridLayoutWidget);
        radioButton_5->setObjectName(QStringLiteral("radioButton_5"));

        verticalLayout_3->addWidget(radioButton_5);

        radioButton_4 = new QRadioButton(gridLayoutWidget);
        radioButton_4->setObjectName(QStringLiteral("radioButton_4"));

        verticalLayout_3->addWidget(radioButton_4);

        radioButton_2 = new QRadioButton(gridLayoutWidget);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));

        verticalLayout_3->addWidget(radioButton_2);


        horizontalLayout_3->addLayout(verticalLayout_3);

        pushButton_2 = new QPushButton(gridLayoutWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout_3->addWidget(pushButton_2);


        horizontalLayout_24->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        checkBox = new QCheckBox(gridLayoutWidget);
        checkBox->setObjectName(QStringLiteral("checkBox"));

        verticalLayout_4->addWidget(checkBox);

        checkBox_6 = new QCheckBox(gridLayoutWidget);
        checkBox_6->setObjectName(QStringLiteral("checkBox_6"));

        verticalLayout_4->addWidget(checkBox_6);

        checkBox_5 = new QCheckBox(gridLayoutWidget);
        checkBox_5->setObjectName(QStringLiteral("checkBox_5"));

        verticalLayout_4->addWidget(checkBox_5);


        horizontalLayout_4->addLayout(verticalLayout_4);

        pushButton_4 = new QPushButton(gridLayoutWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        horizontalLayout_4->addWidget(pushButton_4);


        horizontalLayout_24->addLayout(horizontalLayout_4);


        mainlayout->addLayout(horizontalLayout_24, 0, 0, 1, 1);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        scrollArea = new QScrollArea(gridLayoutWidget);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 241, 355));
        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_5->addWidget(scrollArea);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_6->addWidget(label);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_6->addWidget(label_2);


        verticalLayout_5->addLayout(horizontalLayout_6);


        mainlayout->addLayout(verticalLayout_5, 0, 1, 2, 1);

        MainWindow->setCentralWidget(centralWidget);
        gridLayoutWidget->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 856, 23));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        radioButton->setText(QApplication::translate("MainWindow", "\347\256\227\346\263\2251", Q_NULLPTR));
        radioButton_3->setText(QApplication::translate("MainWindow", "\347\256\227\346\263\2252", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "\347\224\237\346\210\220\350\277\267\345\256\253", Q_NULLPTR));
        radioButton_5->setText(QApplication::translate("MainWindow", "\347\256\227\346\263\2251", Q_NULLPTR));
        radioButton_4->setText(QApplication::translate("MainWindow", "\347\256\227\346\263\2252", Q_NULLPTR));
        radioButton_2->setText(QApplication::translate("MainWindow", "\347\256\227\346\263\2253", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainWindow", "\350\207\252\345\212\250\345\257\273\350\267\257", Q_NULLPTR));
        checkBox->setText(QApplication::translate("MainWindow", "\347\256\227\346\263\2251", Q_NULLPTR));
        checkBox_6->setText(QApplication::translate("MainWindow", "\347\256\227\346\263\2252", Q_NULLPTR));
        checkBox_5->setText(QApplication::translate("MainWindow", "\347\256\227\346\263\2253", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("MainWindow", "\346\257\224\350\276\203", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "\344\277\241\346\201\257\346\240\217", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "\346\257\224\350\276\203\345\233\276\350\241\250", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
