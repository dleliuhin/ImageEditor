#include "region.h"

#include <QPainterPath>
#include <QScrollArea>
#include <QPainter>
#include <QDebug>

//=======================================================================================

static uint reg_count {1};

//=======================================================================================
Region::Region( const QImage& img, QWidget* parent )
    : QMainWindow   ( parent               )
    , _menu_bar     ( new QMenuBar( this ) )
    , _tool_bar     ( new QToolBar( this ) )
    , _central      ( new QWidget( this )  )
    , _status_bar   ( new QStatusBar( this ) )
    , _label        ( new CustomLabel( CustomLabel::Mode::POLYGON, this ) )
    , _image_viewer ( new ImageView()      )
    , _image        ( img                  )
{
    setWindowIcon( QIcon( ":/images/logo.png" ) );
    setMenuBar( _menu_bar );
    addToolBar( _tool_bar );
    setCentralWidget( _central );
    setStatusBar( _status_bar );

    _image.convertTo( QImage::Format_RGB888 );

    _size = _image.size() * 2;

    _image_viewer->set( _image.scaled( _size, Qt::KeepAspectRatio ) );

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

    auto* image_scroll_area = new QScrollArea( this );

    image_scroll_area->setAlignment( Qt::AlignCenter );
    image_scroll_area->setFrameShape( QFrame::NoFrame );
    image_scroll_area->setWidget( _label );

    auto* main_layout = new QGridLayout( this );

    main_layout->addWidget( image_scroll_area, 0, 0 );
    _central->setLayout( main_layout );

    //-----------------------------------------------------------------------------------

    _label->clear();
    _label->setPixmap( _image_viewer->pixmap );
    _label->resize( _image_viewer->size );

    //-----------------------------------------------------------------------------------

    connect( _action_pallete, &QAction::triggered, [ this ]
    {
        _color = QColorDialog::getColor( Qt::yellow, this );
    } );

    connect( _action_polygon, &QAction::triggered, [ this ]
    {
        _label->activate();
    } );

    connect( _label, &CustomLabel::polygon, this, &Region::draw );

    //-----------------------------------------------------------------------------------

    setWindowTitle( "Subregion" + QString::number( reg_count++ ) );

    show();
}
//=======================================================================================
Region::~Region()
{
    reg_count--;

    delete _tool_bar;
    delete _central;
    delete _label;

    close();
}
//=======================================================================================
QImage Region::get()
{}
//=======================================================================================


//=======================================================================================
void Region::draw( const QPolygonF& data )
{
    _pixmap = _image_viewer->pixmap;
    QPainter painter ( &_pixmap );
    painter.setCompositionMode( QPainter::CompositionMode_SourceIn );

    QPen pen( Qt::red, 3, Qt::DashDotLine, Qt::RoundCap, Qt::RoundJoin );
    painter.setPen( pen );

    QBrush brush;
    brush.setColor( _color );
    brush.setStyle( Qt::SolidPattern );

    QPainterPath path;
    path.addPolygon( data );

    painter.drawPolygon( data, Qt::OddEvenFill );
    painter.fillPath( path, brush );
//    painter.end();

    _label->setPixmap( _pixmap );
}
//=======================================================================================
