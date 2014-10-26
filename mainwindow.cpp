#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSysInfo>
#include <QGuiApplication>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QString os("Unsupported");

#ifdef Q_OS_WIN
    switch(QSysInfo::windowsVersion())
    {
      case QSysInfo::WV_2000: os = "Windows 2000"; break;
      case QSysInfo::WV_XP: os = "Windows XP"; break;
      case QSysInfo::WV_VISTA: os = "Windows Vista"; break;
      case QSysInfo::WV_WINDOWS7: os = "Windows 7"; break;
      case QSysInfo::WV_WINDOWS8: os = "Windows 8"; break;
      default: os = "Windows";
    }
#elif defined(Q_OS_LINUX)
    os = "Linux";
#elif defined(Q_OS_DARWIN)
    os = "Mac OS"
#endif
   ui->label->setText("OS is a " + os);
   ui->label->adjustSize();
}

MainWindow::~MainWindow()
{
    delete ui;
}
