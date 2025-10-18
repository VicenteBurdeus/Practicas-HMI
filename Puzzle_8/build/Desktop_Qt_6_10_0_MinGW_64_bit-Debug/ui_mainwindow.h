/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QGridLayout *gridLayout;
    QPushButton *pushButton7;
    QPushButton *pushButton3;
    QPushButton *emptyButton;
    QPushButton *pushButton6;
    QPushButton *pushButton4;
    QPushButton *pushButton5;
    QPushButton *pushButton8;
    QPushButton *pushButton1;
    QPushButton *pushButton2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QLabel *labelMoves;
    QPushButton *button_NewGame;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(700, 1000);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(255);
        sizePolicy.setVerticalStretch(255);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(48, 64));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(3);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setSizeConstraint(QLayout::SizeConstraint::SetMinimumSize);
        pushButton7 = new QPushButton(centralwidget);
        pushButton7->setObjectName("pushButton7");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton7->sizePolicy().hasHeightForWidth());
        pushButton7->setSizePolicy(sizePolicy1);
        pushButton7->setMinimumSize(QSize(16, 16));
        pushButton7->setIconSize(QSize(64, 64));

        gridLayout->addWidget(pushButton7, 2, 0, 1, 1);

        pushButton3 = new QPushButton(centralwidget);
        pushButton3->setObjectName("pushButton3");
        sizePolicy1.setHeightForWidth(pushButton3->sizePolicy().hasHeightForWidth());
        pushButton3->setSizePolicy(sizePolicy1);
        pushButton3->setMinimumSize(QSize(16, 16));
        pushButton3->setIconSize(QSize(64, 64));

        gridLayout->addWidget(pushButton3, 0, 2, 1, 1);

        emptyButton = new QPushButton(centralwidget);
        emptyButton->setObjectName("emptyButton");
        sizePolicy1.setHeightForWidth(emptyButton->sizePolicy().hasHeightForWidth());
        emptyButton->setSizePolicy(sizePolicy1);
        emptyButton->setMinimumSize(QSize(16, 16));
        emptyButton->setIconSize(QSize(64, 64));

        gridLayout->addWidget(emptyButton, 2, 2, 1, 1);

        pushButton6 = new QPushButton(centralwidget);
        pushButton6->setObjectName("pushButton6");
        sizePolicy1.setHeightForWidth(pushButton6->sizePolicy().hasHeightForWidth());
        pushButton6->setSizePolicy(sizePolicy1);
        pushButton6->setMinimumSize(QSize(16, 16));
        pushButton6->setIconSize(QSize(64, 64));

        gridLayout->addWidget(pushButton6, 1, 2, 1, 1);

        pushButton4 = new QPushButton(centralwidget);
        pushButton4->setObjectName("pushButton4");
        sizePolicy1.setHeightForWidth(pushButton4->sizePolicy().hasHeightForWidth());
        pushButton4->setSizePolicy(sizePolicy1);
        pushButton4->setMinimumSize(QSize(16, 16));
        pushButton4->setIconSize(QSize(64, 64));

        gridLayout->addWidget(pushButton4, 1, 0, 1, 1);

        pushButton5 = new QPushButton(centralwidget);
        pushButton5->setObjectName("pushButton5");
        sizePolicy1.setHeightForWidth(pushButton5->sizePolicy().hasHeightForWidth());
        pushButton5->setSizePolicy(sizePolicy1);
        pushButton5->setMinimumSize(QSize(16, 16));
        pushButton5->setIconSize(QSize(64, 64));

        gridLayout->addWidget(pushButton5, 1, 1, 1, 1);

        pushButton8 = new QPushButton(centralwidget);
        pushButton8->setObjectName("pushButton8");
        sizePolicy1.setHeightForWidth(pushButton8->sizePolicy().hasHeightForWidth());
        pushButton8->setSizePolicy(sizePolicy1);
        pushButton8->setMinimumSize(QSize(16, 16));
        pushButton8->setIconSize(QSize(64, 64));

        gridLayout->addWidget(pushButton8, 2, 1, 1, 1);

        pushButton1 = new QPushButton(centralwidget);
        pushButton1->setObjectName("pushButton1");
        sizePolicy1.setHeightForWidth(pushButton1->sizePolicy().hasHeightForWidth());
        pushButton1->setSizePolicy(sizePolicy1);
        pushButton1->setMinimumSize(QSize(16, 16));
        pushButton1->setIconSize(QSize(64, 64));

        gridLayout->addWidget(pushButton1, 0, 0, 1, 1);

        pushButton2 = new QPushButton(centralwidget);
        pushButton2->setObjectName("pushButton2");
        sizePolicy1.setHeightForWidth(pushButton2->sizePolicy().hasHeightForWidth());
        pushButton2->setSizePolicy(sizePolicy1);
        pushButton2->setMinimumSize(QSize(16, 16));
        pushButton2->setIconSize(QSize(64, 64));

        gridLayout->addWidget(pushButton2, 0, 1, 1, 1);


        horizontalLayout_2->addLayout(gridLayout);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        verticalSpacer = new QSpacerItem(0, 16, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        horizontalLayout->addItem(verticalSpacer);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        QFont font;
        font.setPointSize(13);
        font.setWeight(QFont::Medium);
        label->setFont(font);

        horizontalLayout_3->addWidget(label);

        labelMoves = new QLabel(centralwidget);
        labelMoves->setObjectName("labelMoves");
        sizePolicy1.setHeightForWidth(labelMoves->sizePolicy().hasHeightForWidth());
        labelMoves->setSizePolicy(sizePolicy1);
        labelMoves->setMinimumSize(QSize(0, 0));

        horizontalLayout_3->addWidget(labelMoves);


        verticalLayout_2->addLayout(horizontalLayout_3);


        horizontalLayout->addLayout(verticalLayout_2);

        button_NewGame = new QPushButton(centralwidget);
        button_NewGame->setObjectName("button_NewGame");
        button_NewGame->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));

        horizontalLayout->addWidget(button_NewGame);


        verticalLayout->addLayout(horizontalLayout);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 700, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton7->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        pushButton3->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        emptyButton->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        pushButton6->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        pushButton4->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        pushButton5->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        pushButton8->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        pushButton1->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        pushButton2->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Movimientos realizados:", nullptr));
        labelMoves->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        button_NewGame->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
