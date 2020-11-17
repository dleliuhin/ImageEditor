#include "region.h"

//=======================================================================================
Region::Region( const QImage& img, QWidget* parent )
    : QWidget ( parent             )
    , _label  ( new QLabel( this ) )
    , _image  ( img                )
{
    _label->setPixmap( QPixmap::fromImage( _image ) );

    resize( _image.width(), _image.height() );

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
