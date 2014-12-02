/********************************************************************************
** Form generated from reading UI file 'frmCheckParser.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMCHECKPARSER_H
#define UI_FRMCHECKPARSER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_frmCheckParser
{
public:
    QWidget *centralwidget;
    QGroupBox *gbSource;
    QPushButton *pbBegin;
    QPushButton *pbLeft;
    QPushButton *pbRight;
    QPushButton *pbEnd;
    QListWidget *lwSource;
    QGroupBox *gbParsed;
    QListWidget *lwParsed;
    QPushButton *pbGetParsed;
    QLineEdit *leRecordNumber;
    QCommandLinkButton *pbGo;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *frmCheckParser)
    {
        if (frmCheckParser->objectName().isEmpty())
            frmCheckParser->setObjectName(QStringLiteral("frmCheckParser"));
        frmCheckParser->resize(1119, 654);
        centralwidget = new QWidget(frmCheckParser);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gbSource = new QGroupBox(centralwidget);
        gbSource->setObjectName(QStringLiteral("gbSource"));
        gbSource->setGeometry(QRect(10, 20, 511, 481));
        pbBegin = new QPushButton(gbSource);
        pbBegin->setObjectName(QStringLiteral("pbBegin"));
        pbBegin->setGeometry(QRect(20, 450, 100, 24));
        pbLeft = new QPushButton(gbSource);
        pbLeft->setObjectName(QStringLiteral("pbLeft"));
        pbLeft->setGeometry(QRect(120, 450, 100, 24));
        pbRight = new QPushButton(gbSource);
        pbRight->setObjectName(QStringLiteral("pbRight"));
        pbRight->setGeometry(QRect(290, 450, 100, 24));
        pbEnd = new QPushButton(gbSource);
        pbEnd->setObjectName(QStringLiteral("pbEnd"));
        pbEnd->setGeometry(QRect(390, 450, 100, 24));
        lwSource = new QListWidget(gbSource);
        lwSource->setObjectName(QStringLiteral("lwSource"));
        lwSource->setGeometry(QRect(10, 30, 491, 411));
        gbParsed = new QGroupBox(centralwidget);
        gbParsed->setObjectName(QStringLiteral("gbParsed"));
        gbParsed->setGeometry(QRect(600, 20, 511, 481));
        lwParsed = new QListWidget(gbParsed);
        lwParsed->setObjectName(QStringLiteral("lwParsed"));
        lwParsed->setGeometry(QRect(10, 30, 491, 411));
        pbGetParsed = new QPushButton(centralwidget);
        pbGetParsed->setObjectName(QStringLiteral("pbGetParsed"));
        pbGetParsed->setGeometry(QRect(530, 40, 61, 441));
        leRecordNumber = new QLineEdit(centralwidget);
        leRecordNumber->setObjectName(QStringLiteral("leRecordNumber"));
        leRecordNumber->setGeometry(QRect(350, 510, 113, 23));
        leRecordNumber->setMaxLength(5);
        pbGo = new QCommandLinkButton(centralwidget);
        pbGo->setObjectName(QStringLiteral("pbGo"));
        pbGo->setGeometry(QRect(470, 500, 31, 41));
        frmCheckParser->setCentralWidget(centralwidget);
        menubar = new QMenuBar(frmCheckParser);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1119, 21));
        frmCheckParser->setMenuBar(menubar);
        statusbar = new QStatusBar(frmCheckParser);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        frmCheckParser->setStatusBar(statusbar);

        retranslateUi(frmCheckParser);

        QMetaObject::connectSlotsByName(frmCheckParser);
    } // setupUi

    void retranslateUi(QMainWindow *frmCheckParser)
    {
        frmCheckParser->setWindowTitle(QApplication::translate("frmCheckParser", "\320\237\321\200\320\276\320\262\320\265\321\200\320\272\320\260 \321\200\320\260\320\261\320\276\321\202\321\213 \320\277\320\260\321\200\321\201\320\265\321\200\320\260", 0));
        gbSource->setTitle(QApplication::translate("frmCheckParser", "\320\230\321\201\321\205\320\276\320\264\320\275\320\260\321\217 \320\267\320\260\320\277\320\270\321\201\321\214", 0));
        pbBegin->setText(QApplication::translate("frmCheckParser", "\320\235\320\260\321\207\320\260\320\273\320\276", 0));
        pbLeft->setText(QApplication::translate("frmCheckParser", "<==", 0));
        pbRight->setText(QApplication::translate("frmCheckParser", "==>", 0));
        pbEnd->setText(QApplication::translate("frmCheckParser", "\320\232\320\276\320\275\320\265\321\206", 0));
        gbParsed->setTitle(QApplication::translate("frmCheckParser", "\320\235\320\276\320\262\320\260\321\217 \320\267\320\260\320\277\320\270\321\201\321\214", 0));
        pbGetParsed->setText(QApplication::translate("frmCheckParser", "==>", 0));
        leRecordNumber->setInputMask(QString());
        pbGo->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class frmCheckParser: public Ui_frmCheckParser {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMCHECKPARSER_H
