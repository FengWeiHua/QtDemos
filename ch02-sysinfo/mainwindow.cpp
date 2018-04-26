#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "SysInfo.h"

#include <QLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , mCpuWidget(this)
{
    ui->setupUi(this);
    SysInfo::instance().init();

    mainLayout = new QHBoxLayout(ui->centralWidget);
    ui->centralWidget->setLayout(mainLayout);
    mainLayout->addWidget(&mCpuWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}
