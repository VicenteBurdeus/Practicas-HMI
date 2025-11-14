/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <iconcombobox.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout;
    QHBoxLayout *cajaCombo;
    IconComboBox *comboBox;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *nameEdit;
    QLineEdit *lastNameEdit;
    QLabel *label_2;
    QTableView *tableView;
    QLabel *label;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QPushButton *addButton;
    QPushButton *deleteButton;
    QSpacerItem *verticalSpacer_2;
    QPushButton *clearButton;
    QSpacerItem *horizontalSpacer;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(580, 294);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(24, 12, -1, -1);
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        cajaCombo = new QHBoxLayout();
        cajaCombo->setObjectName("cajaCombo");
        cajaCombo->setContentsMargins(-1, -1, -1, 12);
        comboBox = new IconComboBox(centralwidget);
        comboBox->setObjectName("comboBox");

        cajaCombo->addWidget(comboBox);

        horizontalSpacer_2 = new QSpacerItem(80, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        cajaCombo->addItem(horizontalSpacer_2);


        gridLayout->addLayout(cajaCombo, 2, 1, 1, 1);

        nameEdit = new QLineEdit(centralwidget);
        nameEdit->setObjectName("nameEdit");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Maximum, QSizePolicy::Policy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(nameEdit->sizePolicy().hasHeightForWidth());
        nameEdit->setSizePolicy(sizePolicy1);
        nameEdit->setMinimumSize(QSize(200, 0));

        gridLayout->addWidget(nameEdit, 0, 1, 1, 1);

        lastNameEdit = new QLineEdit(centralwidget);
        lastNameEdit->setObjectName("lastNameEdit");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(lastNameEdit->sizePolicy().hasHeightForWidth());
        lastNameEdit->setSizePolicy(sizePolicy2);
        lastNameEdit->setMinimumSize(QSize(200, 0));

        gridLayout->addWidget(lastNameEdit, 1, 1, 1, 1);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        tableView = new QTableView(centralwidget);
        tableView->setObjectName("tableView");
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy3.setHorizontalStretch(1);
        sizePolicy3.setVerticalStretch(1);
        sizePolicy3.setHeightForWidth(tableView->sizePolicy().hasHeightForWidth());
        tableView->setSizePolicy(sizePolicy3);
        tableView->setSizeIncrement(QSize(0, 0));
        tableView->setBaseSize(QSize(250, 0));
        tableView->setAutoFillBackground(true);
        tableView->setSizeAdjustPolicy(QAbstractScrollArea::SizeAdjustPolicy::AdjustToContentsOnFirstShow);
        tableView->setAlternatingRowColors(true);
        tableView->setSelectionMode(QAbstractItemView::SelectionMode::SingleSelection);
        tableView->horizontalHeader()->setDefaultSectionSize(100);

        gridLayout->addWidget(tableView, 3, 1, 1, 1);

        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        label->setMargin(0);

        gridLayout->addWidget(label, 0, 0, 1, 1);


        horizontalLayout->addLayout(gridLayout);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        verticalSpacer = new QSpacerItem(20, 25, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout->addItem(verticalSpacer);

        addButton = new QPushButton(centralwidget);
        addButton->setObjectName("addButton");
        QSizePolicy sizePolicy4(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(addButton->sizePolicy().hasHeightForWidth());
        addButton->setSizePolicy(sizePolicy4);

        verticalLayout->addWidget(addButton);

        deleteButton = new QPushButton(centralwidget);
        deleteButton->setObjectName("deleteButton");
        deleteButton->setEnabled(false);

        verticalLayout->addWidget(deleteButton);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        clearButton = new QPushButton(centralwidget);
        clearButton->setObjectName("clearButton");

        verticalLayout->addWidget(clearButton);

        verticalLayout->setStretch(0, 2);
        verticalLayout->setStretch(1, 1);
        verticalLayout->setStretch(2, 1);
        verticalLayout->setStretch(3, 6);
        verticalLayout->setStretch(4, 1);

        horizontalLayout->addLayout(verticalLayout);

        horizontalSpacer = new QSpacerItem(20, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 580, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        QWidget::setTabOrder(nameEdit, lastNameEdit);
        QWidget::setTabOrder(lastNameEdit, comboBox);
        QWidget::setTabOrder(comboBox, addButton);
        QWidget::setTabOrder(addButton, deleteButton);
        QWidget::setTabOrder(deleteButton, clearButton);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Formulario usuarios", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Apellidos:", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Nombre:", nullptr));
        addButton->setText(QCoreApplication::translate("MainWindow", "A\303\261adir/modificar", nullptr));
        deleteButton->setText(QCoreApplication::translate("MainWindow", "Eliminar", nullptr));
        clearButton->setText(QCoreApplication::translate("MainWindow", "Limpiar Todo", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
