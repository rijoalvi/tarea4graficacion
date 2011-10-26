/********************************************************************************
** Form generated from reading UI file 'ventanaprincipal.ui'
**
** Created: Wed Oct 26 13:20:35 2011
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VENTANAPRINCIPAL_H
#define UI_VENTANAPRINCIPAL_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>
#include <paneldibujo.h>

QT_BEGIN_NAMESPACE

class Ui_VentanaPrincipal
{
public:
    QWidget *centralWidget;
    PanelDibujo *AreaDibujo;
    QPushButton *botonDibujar;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *VentanaPrincipal)
    {
        if (VentanaPrincipal->objectName().isEmpty())
            VentanaPrincipal->setObjectName(QString::fromUtf8("VentanaPrincipal"));
        VentanaPrincipal->resize(649, 440);
        centralWidget = new QWidget(VentanaPrincipal);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        AreaDibujo = new PanelDibujo(centralWidget);
        AreaDibujo->setObjectName(QString::fromUtf8("AreaDibujo"));
        AreaDibujo->setGeometry(QRect(20, 20, 391, 341));
        botonDibujar = new QPushButton(centralWidget);
        botonDibujar->setObjectName(QString::fromUtf8("botonDibujar"));
        botonDibujar->setGeometry(QRect(480, 20, 97, 27));
        VentanaPrincipal->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(VentanaPrincipal);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 649, 27));
        VentanaPrincipal->setMenuBar(menuBar);
        mainToolBar = new QToolBar(VentanaPrincipal);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        VentanaPrincipal->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(VentanaPrincipal);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        VentanaPrincipal->setStatusBar(statusBar);

        retranslateUi(VentanaPrincipal);

        QMetaObject::connectSlotsByName(VentanaPrincipal);
    } // setupUi

    void retranslateUi(QMainWindow *VentanaPrincipal)
    {
        VentanaPrincipal->setWindowTitle(QApplication::translate("VentanaPrincipal", "VentanaPrincipal", 0, QApplication::UnicodeUTF8));
        botonDibujar->setText(QApplication::translate("VentanaPrincipal", "Dibujar!", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class VentanaPrincipal: public Ui_VentanaPrincipal {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VENTANAPRINCIPAL_H
