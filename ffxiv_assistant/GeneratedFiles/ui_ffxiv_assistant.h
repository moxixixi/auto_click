/********************************************************************************
** Form generated from reading UI file 'ffxiv_assistant.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FFXIV_ASSISTANT_H
#define UI_FFXIV_ASSISTANT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ffxiv_assistantClass
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *comboBox;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *kRecord_start;
    QPushButton *kRecord_end;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *kDo_start;
    QPushButton *kDo_end;
    QLabel *label_status;

    void setupUi(QWidget *ffxiv_assistantClass)
    {
        if (ffxiv_assistantClass->objectName().isEmpty())
            ffxiv_assistantClass->setObjectName(QStringLiteral("ffxiv_assistantClass"));
        ffxiv_assistantClass->resize(280, 106);
        verticalLayout = new QVBoxLayout(ffxiv_assistantClass);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(6, 4, 6, 4);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(ffxiv_assistantClass);
        label->setObjectName(QStringLiteral("label"));
        label->setMaximumSize(QSize(100, 16777215));

        horizontalLayout->addWidget(label);

        comboBox = new QComboBox(ffxiv_assistantClass);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        horizontalLayout->addWidget(comboBox);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_2 = new QLabel(ffxiv_assistantClass);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_4->addWidget(label_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        kRecord_start = new QPushButton(ffxiv_assistantClass);
        kRecord_start->setObjectName(QStringLiteral("kRecord_start"));

        horizontalLayout_2->addWidget(kRecord_start);

        kRecord_end = new QPushButton(ffxiv_assistantClass);
        kRecord_end->setObjectName(QStringLiteral("kRecord_end"));

        horizontalLayout_2->addWidget(kRecord_end);


        horizontalLayout_4->addLayout(horizontalLayout_2);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_3 = new QLabel(ffxiv_assistantClass);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_5->addWidget(label_3);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        kDo_start = new QPushButton(ffxiv_assistantClass);
        kDo_start->setObjectName(QStringLiteral("kDo_start"));

        horizontalLayout_3->addWidget(kDo_start);

        kDo_end = new QPushButton(ffxiv_assistantClass);
        kDo_end->setObjectName(QStringLiteral("kDo_end"));

        horizontalLayout_3->addWidget(kDo_end);


        horizontalLayout_5->addLayout(horizontalLayout_3);


        verticalLayout->addLayout(horizontalLayout_5);

        label_status = new QLabel(ffxiv_assistantClass);
        label_status->setObjectName(QStringLiteral("label_status"));

        verticalLayout->addWidget(label_status);


        retranslateUi(ffxiv_assistantClass);

        QMetaObject::connectSlotsByName(ffxiv_assistantClass);
    } // setupUi

    void retranslateUi(QWidget *ffxiv_assistantClass)
    {
        ffxiv_assistantClass->setWindowTitle(QApplication::translate("ffxiv_assistantClass", "ffxiv_assistant", nullptr));
        label->setText(QApplication::translate("ffxiv_assistantClass", "\351\200\211\346\213\251FF14\344\270\273\347\250\213\345\272\217", nullptr));
        label_2->setText(QApplication::translate("ffxiv_assistantClass", "\345\275\225\345\261\217", nullptr));
        kRecord_start->setText(QApplication::translate("ffxiv_assistantClass", "\345\274\200\345\247\213", nullptr));
        kRecord_end->setText(QApplication::translate("ffxiv_assistantClass", "\347\273\223\346\235\237", nullptr));
        label_3->setText(QApplication::translate("ffxiv_assistantClass", "\346\211\247\350\241\214", nullptr));
        kDo_start->setText(QApplication::translate("ffxiv_assistantClass", "\345\274\200\345\247\213", nullptr));
        kDo_end->setText(QApplication::translate("ffxiv_assistantClass", "\347\273\223\346\235\237", nullptr));
        label_status->setText(QApplication::translate("ffxiv_assistantClass", "Waiting...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ffxiv_assistantClass: public Ui_ffxiv_assistantClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FFXIV_ASSISTANT_H
