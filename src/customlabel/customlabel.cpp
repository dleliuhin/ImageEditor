#include "customlabel.h"

#include <QApplication>
#include <QDebug>

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


//=======================================================================================
void CustomLabel::mouseMoveEvent( QMouseEvent* event )
{
    _rubber_band->setGeometry( { _last_pos, event->pos() } );

    emit mouse_move( event );
}
//=======================================================================================
void CustomLabel::mousePressEvent( QMouseEvent* event )
{
    _last_pos = event->pos();

    _rubber_band->setGeometry( { _last_pos, QSize() } );
    _rubber_band->show();

    _selected = true;

    emit mouse_press( event );
}
//=======================================================================================
void CustomLabel::mouseReleaseEvent( QMouseEvent* event )
{
    if ( _selected ) emit region( _last_pos, *_rubber_band );

    _selected = false;

    emit mouse_release( event );
}
//=======================================================================================
void CustomLabel::wheelEvent( QWheelEvent* event )
{
    if ( QApplication::keyboardModifiers() == Qt::ControlModifier )
        emit mouse_wheel( event );
}
//=======================================================================================
