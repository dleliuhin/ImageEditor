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
#include <QRect>

//=======================================================================================
MainWindow::MainWindow( QWidget* parent )
    : QMainWindow     ( parent                                          )
    , _menu_bar       ( new QMenuBar( this )                            )
    , _tool_bar       ( new QToolBar( this )                            )
    , _central_widget ( new QWidget( this )                             )
    , _status_bar     ( new QStatusBar( this )                          )
    , _image_viewer   ( new ImageView( this )                           )
    //    , _image_label    ( new QLabel( this )                              )
    //    , _rubber_band    ( new QRubberBand( QRubberBand::Rectangle, this ) )
{
    setMenuBar( _menu_bar );
    addToolBar( _tool_bar );
    setCentralWidget( _central_widget );
    setStatusBar( _status_bar );
    resize( 1280, 800 );

    /* set menu and toolbar */
    _init_window_componet();

    /* image show widget */
    _init_img_viewer();
}
//=======================================================================================
MainWindow::~MainWindow()
{
    delete _menu_bar;
    delete _tool_bar;
    delete _central_widget;
    delete _status_bar;
    delete _image_viewer;

    delete _action_open;
    delete _action_close;
    delete _action_to_left;
    delete _action_to_right;
    delete _action_to_enlarge;
    delete _action_to_lessen;
}
//=======================================================================================

//=======================================================================================
void MainWindow::opened()
{
    auto ok = _image_viewer->open( "Select image:",
                                   "$$PWD",
                                   "Images (*.jpg *.jpeg *.png *.bmp *.gif)" );
    if ( !ok )
    {
        QMessageBox::information( this, "Error", "Open a file failed!" );
        return;
    }
}
//=======================================================================================
void MainWindow::closed()
{
    //    _init_img_resource();
    //    _image_viewer->close_img();
}
//=======================================================================================
void MainWindow::to_left()
{
    //    if ( _image_viewer->spin_to_left() )
    //    {
    //        QMessageBox::information(this, "Error", "Open a image, please!");
    //        return ;
    //    }

    //    _load_img_resource();
}
//=======================================================================================
void MainWindow::to_right()
{
    //    if ( _image_viewer->rotate_to_right() )
    //    {
    //        QMessageBox::information(this, "Error", "Open a image, please!");
    //        return ;
    //    }

    //    _load_img_resource();
}
//=======================================================================================
void MainWindow::to_large()
{
    //    if ( _image_viewer->zoom_in() )
    //    {
    //        QMessageBox::information(this, "Error", "Open a image, please!");
    //        return;
    //    }

    //    _load_img_resource();
}
//=======================================================================================
void MainWindow::to_less()
{
    //    if ( _image_viewer->zoom_out() )
    //    {
    //        QMessageBox::information(this, "Error", "Open a image, please!");
    //        return;
    //    }

    //    _load_img_resource();
}
//=======================================================================================


//=======================================================================================
void MainWindow::_init_window_componet()
{
    _action_open = new QAction( "Open", this );
    _action_open->setShortcut( QKeySequence::Open );
    _action_open->setStatusTip( "Open a image." );
    _action_open->setIcon( QIcon( ":/images/open.png" ) );

    _action_close = new QAction( "Close", this );
    _action_close->setShortcut( QKeySequence::Close );
    _action_close->setStatusTip( "Close a image." );
    _action_close->setIcon( QIcon( ":/images/close.png" ) );

    _action_to_left = new QAction( "To Left", this );
    _action_to_left->setStatusTip( "To Left." );
    _action_to_left->setIcon( QIcon( ":/images/toLeft.png" ) );

    _action_to_right = new QAction( "To Right", this );
    _action_to_right->setStatusTip( "To Right." );
    _action_to_right->setIcon( QIcon( ":/images/toRight.png" ) );

    _action_to_enlarge = new QAction( "Enlarge", this );
    _action_to_enlarge->setStatusTip( "To Enlarge." );
    _action_to_enlarge->setIcon( QIcon( ":/images/large.png" ) );

    _action_to_lessen = new QAction( "Lessen", this );
    _action_to_lessen->setStatusTip( "To Lessen." );
    _action_to_lessen->setIcon( QIcon( ":/images/small.png" ) );

    auto* exit_action = new QAction( "Exit", this );
    exit_action->setStatusTip( "Exit" );
    exit_action->setIcon( QIcon( ":/images/quit.png" ) );
    exit_action->setShortcut( QKeySequence::Quit );

    auto* file_menu = _menu_bar->addMenu( "File" );
    file_menu->addAction( _action_open );
    file_menu->addAction( _action_close );
    file_menu->addSeparator();
    file_menu->addAction( exit_action );

    auto* operation_menu = _menu_bar->addMenu( "Operate" );

    operation_menu->addSeparator();
    operation_menu->addAction( _action_to_left );
    operation_menu->addAction( _action_to_right );
    operation_menu->addSeparator();
    operation_menu->addAction( _action_to_enlarge );
    operation_menu->addAction( _action_to_lessen  );

    _tool_bar->addAction( _action_open       );
    _tool_bar->addAction( _action_close      );
    _tool_bar->addAction( _action_to_left    );
    _tool_bar->addAction( _action_to_right   );
    _tool_bar->addAction( _action_to_enlarge );
    _tool_bar->addAction( _action_to_lessen  );

    connect( _action_open,       &QAction::triggered, this, &MainWindow::opened   );
    connect( _action_close,      &QAction::triggered, this, &MainWindow::closed   );
    connect( _action_to_left,    &QAction::triggered, this, &MainWindow::to_left  );
    connect( _action_to_right,   &QAction::triggered, this, &MainWindow::to_right );
    connect( _action_to_enlarge, &QAction::triggered, this, &MainWindow::to_large );
    connect( _action_to_lessen,  &QAction::triggered, this, &MainWindow::to_less  );
    connect( exit_action,        &QAction::triggered, this, &MainWindow::closed   );
}
//=======================================================================================
void MainWindow::_init_img_viewer()
{
    auto* image_scroll_area = new QScrollArea( this );
    image_scroll_area->setAlignment( Qt::AlignCenter );
    image_scroll_area->setFrameShape( QFrame::NoFrame );
    image_scroll_area->setWidget( _image_viewer );

    auto* main_layout = new QGridLayout( this );
    main_layout->addWidget( image_scroll_area, 0, 0 );
    _central_widget->setLayout( main_layout );
}
//=======================================================================================
