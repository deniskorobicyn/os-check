#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QProcess>
#include <QMessageBox>
#include <iostream>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton, SIGNAL(released()), this, SLOT(reboot()));
}
void MainWindow::reboot(){
#ifdef Q_OS_LINUX
    QProcess::execute("dbus-send --system --print-reply --dest=org.freedesktop.login1 /org/freedesktop/login1 \"org.freedesktop.login1.Manager.Reboot\" boolean:true");
#elif defined(Q_OS_WINDOWS)
    QProcess::execute("shutdown -r");
#else
    QMessageBox messageBox;
    messageBox.critical(0,"Error","Unsupported OS !");
    messageBox.setFixedSize(500,200);
#endif

}

MainWindow::~MainWindow()
{
    delete ui;
}
