#include "region.h"

#include <QScrollArea>
#include <QDebug>

//=======================================================================================
Region::Region( const QImage& img, QWidget* parent )
    : QMainWindow   ( parent               )
    , _menu_bar     ( new QMenuBar( this ) )
    , _tool_bar     ( new QToolBar( this ) )
    , _status_bar   ( new QStatusBar( this ) )
    , _label        ( new QLabel( this )   )
    , _image_viewer ( new ImageView()      )
    , _image        ( img                  )
{
    setWindowIcon( QIcon( ":/images/logo.png" ) );
    setMenuBar( _menu_bar );
    addToolBar( _tool_bar );
    setCentralWidget( _central );
    setStatusBar( _status_bar );

    _image_viewer->set( img );

    _size = img.size() * 2;

    resize( _size );

    //-----------------------------------------------------------------------------------

    _action_polygon = new QAction( "Polygon", this );
    _action_polygon->setStatusTip( "Polygon." );
    _action_polygon->setIcon( QIcon( ":/images/polygon.png" ) );

    //-----------------------------------------------------------------------------------

    _action_pallete = new QAction( "Pallete", this );
    _action_pallete->setStatusTip( "Pallete." );
    _action_pallete->setIcon( QIcon( ":/images/rgb.png" ) );

    //-----------------------------------------------------------------------------------

    _tool_bar->addAction( _action_polygon );
    _tool_bar->addAction( _action_pallete );

    //-----------------------------------------------------------------------------------

//    auto* image_scroll_area = new QScrollArea( this );

//    image_scroll_area->setAlignment( Qt::AlignCenter );
//    image_scroll_area->setFrameShape( QFrame::NoFrame );
//    image_scroll_area->setWidget( _label );

//    auto* main_layout = new QGridLayout( this );

//    main_layout->addWidget( image_scroll_area, 0, 0 );
//    _central->setLayout( main_layout );

    //-----------------------------------------------------------------------------------

//    _label->setPixmap( _image_viewer->pixmap );
//    _label->resize( _size );

    static uint reg_count {1};
    setWindowTitle( "Subregion" + QString::number( reg_count++ ) );

    show();
}
//=======================================================================================
Region::~Region()
{
    delete _tool_bar;
    delete _central;
    delete _label;

    close();
}
//=======================================================================================
QImage Region::get()
{}
//=======================================================================================
