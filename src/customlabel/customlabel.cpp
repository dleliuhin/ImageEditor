#include "customlabel.h"

//=======================================================================================
CustomLabel::CustomLabel( QWidget* parent )
    : QLabel       ( parent                                          )
    , _rubber_band ( new QRubberBand( QRubberBand::Rectangle, this ) )
{}
//=======================================================================================
CustomLabel::~CustomLabel()
{
    _rubber_band->close();
    delete _rubber_band;
}
//=======================================================================================


#include <QDebug>
//=======================================================================================
void CustomLabel::mouseMoveEvent( QMouseEvent* event )
{
    _rubber_band->setGeometry( { _last_pos, event->pos() } );
}
//=======================================================================================
void CustomLabel::mousePressEvent( QMouseEvent* event )
{
    _last_pos = event->pos();

    _rubber_band->setGeometry( { _last_pos, QSize() } );
    _rubber_band->show();

    _selected = true;
}
//=======================================================================================
void CustomLabel::mouseReleaseEvent( QMouseEvent* event )
{
    if ( _selected ) emit region( _last_pos, *_rubber_band );

    _selected = false;
}
//=======================================================================================
