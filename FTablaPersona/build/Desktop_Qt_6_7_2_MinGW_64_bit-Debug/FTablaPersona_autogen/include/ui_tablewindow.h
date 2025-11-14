/********************************************************************************
** Form generated from reading UI file 'tablewindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TABLEWINDOW_H
#define UI_TABLEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TableWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QTableView *tableView;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer_3;
    QPushButton *addButton;
    QPushButton *updateButton;
    QPushButton *deleteButton;
    QSpacerItem *verticalSpacer_4;
    QPushButton *clearButton;
    QSpacerItem *horizontalSpacer;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *TableWindow)
    {
        if (TableWindow->objectName().isEmpty())
            TableWindow->setObjectName("TableWindow");
        TableWindow->resize(400, 300);
        centralwidget = new QWidget(TableWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName("horizontalLayout");
        tableView = new QTableView(centralwidget);
        tableView->setObjectName("tableView");
        tableView->setSizeAdjustPolicy(QAbstractScrollArea::SizeAdjustPolicy::AdjustToContentsOnFirstShow);
        tableView->setSelectionMode(QAbstractItemView::SelectionMode::SingleSelection);

        horizontalLayout->addWidget(tableView);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalSpacer_3 = new QSpacerItem(20, 25, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout_2->addItem(verticalSpacer_3);

        addButton = new QPushButton(centralwidget);
        addButton->setObjectName("addButton");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(addButton->sizePolicy().hasHeightForWidth());
        addButton->setSizePolicy(sizePolicy);

        verticalLayout_2->addWidget(addButton);

        updateButton = new QPushButton(centralwidget);
        updateButton->setObjectName("updateButton");
        updateButton->setEnabled(false);
        sizePolicy.setHeightForWidth(updateButton->sizePolicy().hasHeightForWidth());
        updateButton->setSizePolicy(sizePolicy);

        verticalLayout_2->addWidget(updateButton);

        deleteButton = new QPushButton(centralwidget);
        deleteButton->setObjectName("deleteButton");
        deleteButton->setEnabled(false);

        verticalLayout_2->addWidget(deleteButton);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_4);

        clearButton = new QPushButton(centralwidget);
        clearButton->setObjectName("clearButton");

        verticalLayout_2->addWidget(clearButton);

        verticalLayout_2->setStretch(0, 2);
        verticalLayout_2->setStretch(1, 1);
        verticalLayout_2->setStretch(3, 1);
        verticalLayout_2->setStretch(4, 6);
        verticalLayout_2->setStretch(5, 1);

        horizontalLayout->addLayout(verticalLayout_2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        TableWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(TableWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 400, 21));
        TableWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(TableWindow);
        statusbar->setObjectName("statusbar");
        TableWindow->setStatusBar(statusbar);

        retranslateUi(TableWindow);

        QMetaObject::connectSlotsByName(TableWindow);
    } // setupUi

    void retranslateUi(QMainWindow *TableWindow)
    {
        TableWindow->setWindowTitle(QCoreApplication::translate("TableWindow", "MainWindow", nullptr));
        addButton->setText(QCoreApplication::translate("TableWindow", "A\303\261adir", nullptr));
        updateButton->setText(QCoreApplication::translate("TableWindow", "Modificar", nullptr));
        deleteButton->setText(QCoreApplication::translate("TableWindow", "Eliminar", nullptr));
        clearButton->setText(QCoreApplication::translate("TableWindow", "Vaciar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TableWindow: public Ui_TableWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TABLEWINDOW_H
