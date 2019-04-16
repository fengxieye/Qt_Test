#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qInfo()<<"main thread "<<QThread::currentThreadId();
    //不能设置this为parent，不然会Cannot move objects with a parent
    //导致还在主线程里
    m_worker = new Worker();
    qInfo()<<"worker parent"<<m_worker->parent();
    m_worker->sigStartWork();
}

MainWindow::~MainWindow()
{
    delete ui;
}
