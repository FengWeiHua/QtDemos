#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "SysInfo.h"

#include <QLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , mCpuWidget(this)
    , mMemoryWidget(this)
{
    ui->setupUi(this);
    SysInfo::instance().init();

    mainLayout = new QHBoxLayout(ui->centralWidget);
    ui->centralWidget->setLayout(mainLayout);
    mainLayout->addWidget(&mCpuWidget);
    mainLayout->addWidget(&mMemoryWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}
