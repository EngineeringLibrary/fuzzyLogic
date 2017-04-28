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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QTextEdit *textResult;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEquacao;
    QLabel *label_3;
    QPushButton *simularButton;
    QLineEdit *lineValorVar;
    QLabel *label_4;
    QWidget *tab_2;
    QWidget *widget;
    QWidget *widget_2;
    QLabel *label_5;
    QWidget *tab_3;
    QPushButton *pushButton;
    QTextEdit *textEdit;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(402, 435);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 401, 421));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        textResult = new QTextEdit(tab);
        textResult->setObjectName(QStringLiteral("textResult"));
        textResult->setGeometry(QRect(30, 80, 331, 171));
        label = new QLabel(tab);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 381, 31));
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label_2 = new QLabel(tab);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 60, 101, 16));
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        label_2->setFont(font1);
        lineEquacao = new QLineEdit(tab);
        lineEquacao->setObjectName(QStringLiteral("lineEquacao"));
        lineEquacao->setGeometry(QRect(40, 280, 241, 21));
        label_3 = new QLabel(tab);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(40, 260, 121, 16));
        label_3->setFont(font1);
        simularButton = new QPushButton(tab);
        simularButton->setObjectName(QStringLiteral("simularButton"));
        simularButton->setGeometry(QRect(290, 310, 75, 23));
        lineValorVar = new QLineEdit(tab);
        lineValorVar->setObjectName(QStringLiteral("lineValorVar"));
        lineValorVar->setGeometry(QRect(40, 340, 241, 21));
        label_4 = new QLabel(tab);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(40, 320, 131, 16));
        label_4->setFont(font1);
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        widget = new QWidget(tab_2);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 50, 371, 141));
        widget_2 = new QWidget(tab_2);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setGeometry(QRect(10, 230, 371, 141));
        label_5 = new QLabel(tab_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(160, 10, 91, 20));
        label_5->setFont(font);
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        pushButton = new QPushButton(tab_3);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(130, 160, 75, 23));
        textEdit = new QTextEdit(tab_3);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(80, 50, 201, 81));
        tabWidget->addTab(tab_3, QString());
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Simulador de Equa\303\247\303\265es Diferenciais", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Equa\303\247\303\243o Digitada:", Q_NULLPTR));
        lineEquacao->setText(QApplication::translate("MainWindow", "1/1,1,2", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "Digite uma Equa\303\247\303\243o:", Q_NULLPTR));
        simularButton->setText(QApplication::translate("MainWindow", "Simular", Q_NULLPTR));
        lineValorVar->setText(QApplication::translate("MainWindow", "1", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "Digite um Valor para S:", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Tab 1", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "Gr\303\241ficos", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Tab 2", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "PushButton", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "Page", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
