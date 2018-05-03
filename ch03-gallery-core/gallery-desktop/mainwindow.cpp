#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QStackedWidget>
#include <QItemSelectionModel>

#include "gallerywidget.h"
#include "picturewidget.h"
#include "albummodel.h"
#include "picturemodel.h"
#include "thumbnailproxymodel.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , mGalleryWidget(new GalleryWidget(this))
    , mPictureWidget(new PictureWidget(this))
    , mStackWidget(new QStackedWidget(this))
{
    ui->setupUi(this);

    AlbumModel *albumModel = new AlbumModel(this);
    QItemSelectionModel *albumSelectionModel = new QItemSelectionModel(albumModel, this);
    mGalleryWidget->setAlbumModel(albumModel);
    mGalleryWidget->setAlbumSelectionModel(albumSelectionModel);

    PictureModel *pictureModel = new PictureModel(*albumModel, this);
    ThumbnailProxyModel *thumbnailModel = new ThumbnailProxyModel(this);
    thumbnailModel->setSourceModel(pictureModel);

    QItemSelectionModel *pictureSelectionModel = new QItemSelectionModel(thumbnailModel, this);
    mGalleryWidget->setPictureModel(thumbnailModel);
    mGalleryWidget->setPictureSelectionModel(pictureSelectionModel);
    mPictureWidget->setModel(thumbnailModel);
    mPictureWidget->setSelectionModel(pictureSelectionModel);

    connect(mGalleryWidget, &GalleryWidget::picutreActivated,
            this, &MainWindow::displayPicture);

    connect(mPictureWidget, &PictureWidget::backToGallery,
            this, &MainWindow::displayGallery);

    mStackWidget->addWidget(mGalleryWidget);
    mStackWidget->addWidget(mPictureWidget);
    displayGallery();

    setCentralWidget(mStackWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::displayGallery()
{
    mStackWidget->setCurrentWidget(mGalleryWidget);
}

void MainWindow::displayPicture(const QModelIndex &index)
{
    Q_UNUSED(index);
    mStackWidget->setCurrentWidget(mPictureWidget);
}
