#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QString os("Unsupported");

#ifdef Q_OS_WIN32
    os = "Windows";
#elif defined(Q_OS_LINUX)
    os = "Linux";
#endif

   ui->label->setText("OS is a " + os);
}

MainWindow::~MainWindow()
{
    delete ui;
}
