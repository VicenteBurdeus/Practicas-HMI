/********************************************************************************
** Form generated from reading UI file 'dialogpersona.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGPERSONA_H
#define UI_DIALOGPERSONA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <iconcombobox.h>

QT_BEGIN_NAMESPACE

class Ui_DialogPersona
{
public:
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *nameEdit;
    QLineEdit *lastNameEdit;
    QSpacerItem *verticalSpacer;
    QDialogButtonBox *buttonBox;
    QLabel *label_2;
    QHBoxLayout *cajaCombo;
    IconComboBox *comboBox;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer_3;

    void setupUi(QDialog *DialogPersona)
    {
        if (DialogPersona->objectName().isEmpty())
            DialogPersona->setObjectName("DialogPersona");
        DialogPersona->setWindowModality(Qt::WindowModality::ApplicationModal);
        DialogPersona->resize(377, 177);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(DialogPersona->sizePolicy().hasHeightForWidth());
        DialogPersona->setSizePolicy(sizePolicy);
        horizontalLayout = new QHBoxLayout(DialogPersona);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        gridLayout->setSizeConstraint(QLayout::SizeConstraint::SetMinimumSize);
        gridLayout->setContentsMargins(-1, -1, -1, 24);
        label = new QLabel(DialogPersona);
        label->setObjectName("label");
        label->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        label->setMargin(0);

        gridLayout->addWidget(label, 1, 0, 1, 1);

        nameEdit = new QLineEdit(DialogPersona);
        nameEdit->setObjectName("nameEdit");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Maximum, QSizePolicy::Policy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(nameEdit->sizePolicy().hasHeightForWidth());
        nameEdit->setSizePolicy(sizePolicy1);
        nameEdit->setMinimumSize(QSize(200, 0));

        gridLayout->addWidget(nameEdit, 1, 1, 1, 1);

        lastNameEdit = new QLineEdit(DialogPersona);
        lastNameEdit->setObjectName("lastNameEdit");
        sizePolicy.setHeightForWidth(lastNameEdit->sizePolicy().hasHeightForWidth());
        lastNameEdit->setSizePolicy(sizePolicy);
        lastNameEdit->setMinimumSize(QSize(200, 0));

        gridLayout->addWidget(lastNameEdit, 2, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 1, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer, 0, 1, 1, 1);

        buttonBox = new QDialogButtonBox(DialogPersona);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setFocusPolicy(Qt::FocusPolicy::StrongFocus);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);

        gridLayout->addWidget(buttonBox, 4, 1, 1, 1);

        label_2 = new QLabel(DialogPersona);
        label_2->setObjectName("label_2");
        label_2->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        cajaCombo = new QHBoxLayout();
        cajaCombo->setObjectName("cajaCombo");
        cajaCombo->setContentsMargins(-1, -1, -1, 12);
        comboBox = new IconComboBox(DialogPersona);
        comboBox->setObjectName("comboBox");
        comboBox->setFocusPolicy(Qt::FocusPolicy::StrongFocus);

        cajaCombo->addWidget(comboBox);

        horizontalSpacer_2 = new QSpacerItem(80, 20, QSizePolicy::Policy::MinimumExpanding, QSizePolicy::Policy::Minimum);

        cajaCombo->addItem(horizontalSpacer_2);


        gridLayout->addLayout(cajaCombo, 3, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(1, 1, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 5, 1, 1, 1);


        horizontalLayout->addLayout(gridLayout);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        QWidget::setTabOrder(nameEdit, lastNameEdit);
        QWidget::setTabOrder(lastNameEdit, comboBox);

        retranslateUi(DialogPersona);

        QMetaObject::connectSlotsByName(DialogPersona);
    } // setupUi

    void retranslateUi(QDialog *DialogPersona)
    {
        DialogPersona->setWindowTitle(QCoreApplication::translate("DialogPersona", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("DialogPersona", "Nombre:", nullptr));
        label_2->setText(QCoreApplication::translate("DialogPersona", "Apellidos:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogPersona: public Ui_DialogPersona {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGPERSONA_H
