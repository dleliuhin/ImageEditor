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

static const QSize wsize( 1200, 800 );

//=======================================================================================
MainWindow::MainWindow( QWidget* parent )
    : QMainWindow     ( parent                                              )
    , _menu_bar       ( new QMenuBar    ( this )                            )
    , _status_bar     ( new QStatusBar  ( this )                            )
    , _tool_bar       ( new QToolBar    ( this )                            )
    , _label          ( new CustomLabel ( CustomLabel::Mode::RUBBER, this ) )
    , _image_viewer   ( new ImageView                                       )
    , _scene          ( new QGraphicsScene( this )                          )
    , _view           ( new QGraphicsView( this )                           )
{
    setMenuBar( _menu_bar );
    addToolBar( _tool_bar );
    setCentralWidget( _view );
    setStatusBar( _status_bar );
    resize( wsize );

    _init_window_componet();
    _init_connections();

    _view->setScene( _scene );

    _view->show();
}
//=======================================================================================
MainWindow::~MainWindow()
{
    close();

    delete _menu_bar;
    delete _tool_bar;
    delete _status_bar;
    delete _label;
    delete _image_viewer;
    delete _regions;
    delete _scene;
    delete _view;

    delete _action_open;
    delete _action_close;
    delete _action_to_left;
    delete _action_to_right;
    delete _action_to_enlarge;
    delete _action_to_lessen;
    delete _action_polygon;

    QApplication::closeAllWindows();
}
//=======================================================================================


//=======================================================================================
void MainWindow::open()
{
    auto ok = _image_viewer->open( "Select image:",
                                   "$$PWD",
                                   "Images (*.jpg *.jpeg *.png *.bmp *.gif)" );
    if ( !ok )
    {
        QMessageBox::information( this, "Error", "Open a file failed!" );
        return;
    }

    _label->setPixmap( _image_viewer->pixmap );
}
//=======================================================================================
void MainWindow::close()
{
    _image_viewer->close();
}
//=======================================================================================
void MainWindow::to_left()
{
    if ( !_image_viewer->to_left() )
    {
        QMessageBox::information( this, "Error", "Open a image, please!" );
        return;
    }

    _label->setPixmap( _image_viewer->pixmap );
}
//=======================================================================================
void MainWindow::to_right()
{
    if ( !_image_viewer->to_right() )
    {
        QMessageBox::information( this, "Error", "Open a image, please!" );
        return;
    }

    _label->setPixmap( _image_viewer->pixmap );
}
//=======================================================================================
void MainWindow::to_large()
{
    if ( !_image_viewer->zoom( 12 ) )
    {
        QMessageBox::information(this, "Error", "Open a image, please!");
        return;
    }

    _label->setPixmap( _image_viewer->pixmap );
}
//=======================================================================================
void MainWindow::to_less()
{
    if ( !_image_viewer->zoom(8) )
    {
        QMessageBox::information(this, "Error", "Open a image, please!");
        return;
    }

    _label->setPixmap( _image_viewer->pixmap );
}
//=======================================================================================


//=======================================================================================
void MainWindow::mouse_wheel( QWheelEvent* event )
{
    bool ok { false };

    if ( event->angleDelta().y() > 0 )
        ok = _image_viewer->zoom(12);

    else
        ok = _image_viewer->zoom(8);

    if ( !ok )
    {
        QMessageBox::information( this, "Error", "Open a image, please!" );
        return;
    }
}
//=======================================================================================


//=======================================================================================
void MainWindow::_init_window_componet()
{
    _action_open = new QAction( "Open", this );
    _action_open->setShortcut( QKeySequence::Open );
    _action_open->setStatusTip( "Open a image." );
    _action_open->setIcon( QIcon( ":/images/open.png" ) );

    //-----------------------------------------------------------------------------------

    _action_close = new QAction( "Close", this );
    _action_close->setShortcut( QKeySequence::Close );
    _action_close->setStatusTip( "Close a image." );
    _action_close->setIcon( QIcon( ":/images/close.png" ) );

    //-----------------------------------------------------------------------------------

    _action_to_left = new QAction( "To Left", this );
    _action_to_left->setStatusTip( "To Left." );
    _action_to_left->setIcon( QIcon( ":/images/toLeft.png" ) );

    //-----------------------------------------------------------------------------------

    _action_to_right = new QAction( "To Right", this );
    _action_to_right->setStatusTip( "To Right." );
    _action_to_right->setIcon( QIcon( ":/images/toRight.png" ) );

    //-----------------------------------------------------------------------------------

    _action_to_enlarge = new QAction( "Enlarge", this );
    _action_to_enlarge->setStatusTip( "To Enlarge." );
    _action_to_enlarge->setIcon( QIcon( ":/images/large.png" ) );

    //-----------------------------------------------------------------------------------

    _action_to_lessen = new QAction( "Lessen", this );
    _action_to_lessen->setStatusTip( "To Lessen." );
    _action_to_lessen->setIcon( QIcon( ":/images/small.png" ) );

    //-----------------------------------------------------------------------------------

    _action_polygon = new QAction( "Polygon", this );
    _action_polygon->setStatusTip( "Polygon." );
    _action_polygon->setIcon( QIcon( ":/images/polygon.png" ) );
    _action_polygon->setCheckable( true );

    //-----------------------------------------------------------------------------------

    auto* exit_action = new QAction( "Exit", this );

    exit_action->setStatusTip( "Exit" );
    exit_action->setIcon( QIcon( ":/images/quit.png" ) );
    exit_action->setShortcut( QKeySequence::Quit );

    //-----------------------------------------------------------------------------------

    auto* file_menu = _menu_bar->addMenu( "File" );

    file_menu->addAction( _action_open );
    file_menu->addAction( _action_close );
    file_menu->addSeparator();
    file_menu->addAction( exit_action );

    //-----------------------------------------------------------------------------------

    auto* operation_menu = _menu_bar->addMenu( "Operate" );

    operation_menu->addSeparator();
    operation_menu->addAction( _action_to_left );
    operation_menu->addAction( _action_to_right );
    operation_menu->addSeparator();
    operation_menu->addAction( _action_to_enlarge );
    operation_menu->addAction( _action_to_lessen  );
    operation_menu->addAction( _action_polygon );

    //-----------------------------------------------------------------------------------

    _tool_bar->addAction( _action_open       );
    _tool_bar->addAction( _action_close      );
    _tool_bar->addAction( _action_to_left    );
    _tool_bar->addAction( _action_to_right   );
    _tool_bar->addAction( _action_to_enlarge );
    _tool_bar->addAction( _action_to_lessen  );
    _tool_bar->addAction( _action_polygon     );

    //-----------------------------------------------------------------------------------

    connect( _action_open,       &QAction::triggered, this, &MainWindow::open     );
    connect( _action_close,      &QAction::triggered, this, &MainWindow::close    );
    connect( _action_to_left,    &QAction::triggered, this, &MainWindow::to_left  );
    connect( _action_to_right,   &QAction::triggered, this, &MainWindow::to_right );
    connect( _action_to_enlarge, &QAction::triggered, this, &MainWindow::to_large );
    connect( _action_to_lessen,  &QAction::triggered, this, &MainWindow::to_less  );

    connect( _action_polygon,    &QAction::triggered, [ this ]
    {
        if ( !_image_viewer->fname.isEmpty() )
            _label->activate();
    } );

    connect( exit_action,        &QAction::triggered, this, &MainWindow::close    );

    //-----------------------------------------------------------------------------------

    _scene->addWidget( _label );
}
//=======================================================================================
void MainWindow::_init_connections()
{
//    connect( _label, &CustomLabel::mouse_wheel, this, &MainWindow::mouse_wheel );
//    connect( _label, &CustomLabel::region,
//             [ this ]( const QPoint& pos, const QRubberBand& region )
//    {
//        if ( !_regions )
//        {
//            _regions = new Multitab( this );

//            connect( _regions, &Multitab::tabs_empty, [ this ]
//            {
//                _regions->hide();
//            } );
//        }

//        if ( _regions->isHidden() ) _regions->setHidden( false );

//        _regions->add_tab( new Region( _image_viewer->image.copy( pos.x(),
//                                                                  pos.y(),
//                                                                  region.width(),
//                                                                  region.height() ) ) );
//    } );
}
//=======================================================================================
