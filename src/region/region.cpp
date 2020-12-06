#include "region.h"

#include <QScrollArea>
#include <QDebug>

//=======================================================================================
Region::Region( const QImage& img, QWidget* parent )
    : QWidget   ( parent                                          )
    , _tool_bar ( new QToolBar( this )                            )
    , _layout   ( new QBoxLayout( QBoxLayout::TopToBottom, this ) )
    , _label    ( new QLabel( this )                              )
    , _image    ( img                                             )
{
    auto* image_scroll_area = new QScrollArea( this );

    image_scroll_area->setAlignment( Qt::AlignCenter );
    image_scroll_area->setFrameShape( QFrame::NoFrame );
    image_scroll_area->setWidget( _label );

    auto* main_layout = new QGridLayout( this );

    main_layout->addWidget( image_scroll_area, 0, 0 );
    setLayout( main_layout );

//    _layout->setContentsMargins( 0, 0, 0, 0 );
//    _layout->setDirection( QBoxLayout::LeftToRight );
//    _tool_bar->setOrientation( Qt::Vertical );

//    _layout->addWidget( _tool_bar );

//    size = img.size() * 2;

//    _pixmap = QPixmap::fromImage( _image );

//    _label->setPixmap( QPixmap::fromImage( _image.scaled( size, Qt::KeepAspectRatio ) ) );

//    resize( size.width(), size.height() );

    static uint reg_count {1};

    setWindowTitle( "Subregion" + QString::number( reg_count++ ) );

    show();
//    _label->show();
}
//=======================================================================================
Region::~Region()
{
//    delete _label;
//    delete _tool_bar;
//    delete _layout;

    close();
}
//=======================================================================================
QImage Region::get()
{
//    return _pixmap.toImage().scaled( _image.width(),
//                                     _image.height(),
//                                     Qt::KeepAspectRatio );
}
//=======================================================================================
