#include "mainwindow.h"

#include <QWidget>
#include <QImage>
#include <QFileDialog>
#include <QPixmap>
#include <QAction>
#include <QMessageBox>
#include <QDebug>
#include <QScrollArea>
#include <QGridLayout>
#include <QErrorMessage>
#include <QApplication>

//=======================================================================================
MainWindow::MainWindow( QWidget* parent )
    : QMainWindow     ( parent                 )
    , _menu_bar       ( new QMenuBar( this )   )
    , _tool_bar       ( new QToolBar( this )   )
    , _central_widget ( new QWidget( this )    )
    , _status_bar     ( new QStatusBar( this ) )
    , _label          ( new CustomLabel( this ))
    , _image_viewer   ( new QImageViewer()     )
{
    setMenuBar( _menu_bar );
    addToolBar( _tool_bar );
    setCentralWidget( _central_widget );
    setStatusBar( _status_bar );

    /* set menu and toolbar */
    setWindowComponet();

    /* image show widget */
    setQImageViewerWidget();

    /* init resource */
    initImageResource();
}
//=======================================================================================
MainWindow::~MainWindow()
{
    delete _menu_bar;
    delete _tool_bar;
    delete _central_widget;
    delete _status_bar;
    delete _label;
    delete _image_viewer;

    delete _action_open;
    delete _action_close;
    delete _action_last;
    delete _action_next;
    delete _action_to_left;
    delete _action_to_right;
    delete _action_to_enlarge;
    delete _action_to_lessen;
    delete _action_delete;
}
//=======================================================================================


//=======================================================================================
void MainWindow::opened()
{
    auto ok = _image_viewer->openImageFile( "Select image:",
                                            "$$PWD",
                                            "Images (*.jpg *.jpeg *.png *.bmp *.gif)" );
    if (ok)
    {
        QMessageBox::information( this, "Error", "Open a file failed!" );
        return;
    }

    load_img_resource();
}
//=======================================================================================
void MainWindow::closed(void)
{
    initImageResource();
    _image_viewer->closeImageFile();
}
//=======================================================================================
void MainWindow::last(void)
{
    int ret = _image_viewer->last();
    if (ret) {
        QMessageBox::information(this,
                                 tr("Error"),
                                 tr("Open a image, please!"));
        return ;
    }

    load_img_resource();
}

void MainWindow::next(void)
{
    int ret = _image_viewer->next();
    if (ret) {
        QMessageBox::information(this,
                                 tr("Error"),
                                 tr("Open a image, please!"));
        return ;
    }

    load_img_resource();
}

void MainWindow::to_left(void)
{
    int ret = _image_viewer->spinToLeft();
    if (ret) {
        QMessageBox::information(this,
                                 tr("Error"),
                                 tr("Open a image, please!"));
        return ;
    }

    load_img_resource();
}

void MainWindow::to_right(void)
{
    int ret = _image_viewer->spinToRight();
    if (ret) {
        QMessageBox::information(this,
                                 tr("Error"),
                                 tr("Open a image, please!"));
        return ;
    }

    load_img_resource();
}

void MainWindow::to_large(void)
{
    int ret = _image_viewer->zoomIn();
    if (ret) {
        QMessageBox::information(this,
                                 tr("Error"),
                                 tr("Open a image, please!"));
        return ;
    }

    load_img_resource();
}

void MainWindow::to_less(void)
{
    int ret = _image_viewer->zoomOut();
    if (ret) {
        QMessageBox::information(this,
                                 tr("Error"),
                                 tr("Open a image, please!"));
        return ;
    }

    load_img_resource();
}

void MainWindow::deleted(void)
{
    if (!QFile(_image_viewer->filename).exists()) {
        QMessageBox::information(this,
                                 tr("Error"),
                                 tr("Open a image, please!"));
        return ;
    }

    QMessageBox message(QMessageBox::Warning,
                        tr("Warning"),
                        tr("Do you want to delete this image?"),
                        QMessageBox::Yes|QMessageBox::No,
                        NULL);
    if (message.exec() == QMessageBox::No) {
        return ;
    }

    int ret = _image_viewer->delImageFile();
    if (ret) {
        QMessageBox::warning(this,
                             tr("Error"),
                             tr("Delete a image failed!"));
        return ;
    }

    initImageResource();
}
void MainWindow::initImageResource(void)
{
    _label->clear();
    _label->resize(QSize(200, 100));
    setWindowTitle(tr("QImageViewer"));
}

void MainWindow::load_img_resource()
{
    _label->setPixmap(_image_viewer->pixmap);
    _label->resize(_image_viewer->size);
    setWindowTitle(QFileInfo(_image_viewer->filename).fileName() + tr(" - QImageViewer"));
}

void MainWindow::setQImageViewerWidget(void)
{
    auto* imageScrollArea = new QScrollArea( this );
    imageScrollArea->setAlignment( Qt::AlignCenter );
    imageScrollArea->setFrameShape( QFrame::NoFrame );
    imageScrollArea->setWidget( _label );

    auto* mainLayout = new QGridLayout( this );
    mainLayout->addWidget( imageScrollArea, 0, 0 );
    _central_widget->setLayout( mainLayout );
}

void MainWindow::setWindowComponet(void)
{
    _action_open = new QAction(tr("Open"), this);
    _action_open->setShortcut(QKeySequence::Open);
    _action_open->setStatusTip(tr("Open a image."));
    _action_open->setIcon(QIcon(":/images/open.png"));

    _action_close = new QAction(tr("Close"), this);
    _action_close->setShortcut(QKeySequence::Close);
    _action_close->setStatusTip(tr("Close a image."));
    _action_close->setIcon(QIcon(":/images/close.png"));

    _action_last = new QAction(tr("Last"), this);
    _action_last->setStatusTip(tr("Last image."));
    _action_last->setIcon(QIcon(":/images/left.png"));

    _action_next = new QAction(tr("Next"), this);
    _action_next->setStatusTip(tr("Next image"));
    _action_next->setIcon(QIcon(":/images/right.png"));

    _action_to_left = new QAction(tr("LeftSpin"), this);
    _action_to_left->setStatusTip(tr("To Left."));
    _action_to_left->setIcon(QIcon(":/images/toLeft.png"));

    _action_to_right = new QAction(tr("RightSpin"), this);
    _action_to_right->setStatusTip(tr("To Right."));
    _action_to_right->setIcon(QIcon(":/images/toRight.png"));

    _action_to_enlarge = new QAction(tr("Enlarge"), this);
    _action_to_enlarge->setStatusTip(tr("To Enlarge."));
    _action_to_enlarge->setIcon(QIcon(":/images/large.png"));

    _action_to_lessen = new QAction(tr("Lessen"), this);
    _action_to_lessen->setStatusTip(tr("To Lessen."));
    _action_to_lessen->setIcon(QIcon(":/images/small.png"));

    _action_delete = new QAction(tr("Delete"), this);
    _action_delete->setStatusTip(tr("Delete a image"));
    _action_delete->setIcon(QIcon(":/images/clear.png"));
    _action_delete->setShortcut(QKeySequence::Delete);

    QAction *exitAction = new QAction(tr("Exit"), this);
    exitAction->setStatusTip(tr("Exit"));
    exitAction->setIcon(QIcon(":/images/quit.png"));
    exitAction->setShortcut(QKeySequence::Quit);

    QAction *aboutQt = new QAction(tr("About Qt"), this);
    aboutQt->setStatusTip(tr("About Qt"));
    aboutQt->setIcon(QIcon(":/images/Qt.png"));

    QAction *about = new QAction(tr("About QImageViewer"), this);
    about->setStatusTip(tr("About QImageViewer"));
    about->setIcon(QIcon(":/images/help.png"));

    QMenu *fileMenu = _menu_bar->addMenu(tr("File"));
    fileMenu->addAction(_action_open);
    fileMenu->addAction(_action_close);
    fileMenu->addSeparator();
    fileMenu->addAction(_action_delete);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAction);

    QMenu *operationMenu = _menu_bar->addMenu(tr("Operate"));
    operationMenu->addAction(_action_last);
    operationMenu->addAction(_action_next);
    operationMenu->addSeparator();
    operationMenu->addAction(_action_to_left);
    operationMenu->addAction(_action_to_right);
    operationMenu->addSeparator();
    operationMenu->addAction(_action_to_enlarge);
    operationMenu->addAction(_action_to_lessen);

    QMenu *helpMenu = _menu_bar->addMenu(tr("Help"));
    helpMenu->addAction(aboutQt);
    helpMenu->addAction(about);

    _tool_bar->addAction(_action_open);
    _tool_bar->addAction(_action_close);
    _tool_bar->addAction(_action_last);
    _tool_bar->addAction(_action_next);
    _tool_bar->addAction(_action_to_left);
    _tool_bar->addAction(_action_to_right);
    _tool_bar->addAction(_action_to_enlarge);
    _tool_bar->addAction(_action_to_lessen);
    _tool_bar->addAction(_action_delete);
    _tool_bar->addAction(about);

    connect(_action_open, SIGNAL(triggered(bool)), this, SLOT(opened()));
    connect(_action_close, SIGNAL(triggered(bool)), this, SLOT(closed()));
    connect(_action_last, SIGNAL(triggered(bool)), this, SLOT(last()));
    connect(_action_next, SIGNAL(triggered(bool)), this, SLOT(next()));
    connect(_action_to_left, SIGNAL(triggered(bool)), this, SLOT(to_left()));
    connect(_action_to_right, SIGNAL(triggered(bool)), this, SLOT(to_right()));
    connect(_action_to_enlarge, SIGNAL(triggered(bool)), this, SLOT(to_large()));
    connect(_action_to_lessen, SIGNAL(triggered(bool)), this, SLOT(to_less()));
    connect(_action_delete, SIGNAL(triggered(bool)), this, SLOT(deleted()));

    connect(exitAction, SIGNAL(triggered(bool)), this, SLOT(closed()));
}
//=======================================================================================
