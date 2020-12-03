#include "region.h"

#include <QDebug>
//=======================================================================================
Region::Region( const QImage& img, QWidget* parent )
    : QWidget   ( parent                                          )
    , _layout   ( new QBoxLayout( QBoxLayout::TopToBottom, this ) )
    , _tool_bar ( new QToolBar( this )                            )
    , _label    ( new QLabel( this )                              )
    , _image    ( img                                             )
{
    _layout->setContentsMargins( 0, 0, 0, 0 );
    _layout->setDirection( QBoxLayout::LeftToRight );
    _tool_bar->setOrientation( Qt::Vertical );

    _layout->addWidget( _tool_bar );

    size = img.size() * 2;

    _label->setPixmap( QPixmap::fromImage( _image.scaled( size, Qt::KeepAspectRatio ) ) );

    resize( size.width(), size.height() );

    static uint reg_count {1};

    setWindowTitle( "Subregion" + QString::number( reg_count++ ) );

    show();
    _label->show();
}
//=======================================================================================
Region::~Region()
{
    delete _label;
    close();
}
//=======================================================================================
QImage Region::get()
{
    return _pixmap.toImage().scaled( _image.width(),
                                     _image.height(),
                                     Qt::KeepAspectRatio );
}
//=======================================================================================
