#include "customlabel.h"

#include <QApplication>
#include <QDebug>

//=======================================================================================
CustomLabel::CustomLabel( const Mode mode, QWidget* parent )
    : QLabel       ( parent                                          )
    , _rubber_band ( new QRubberBand( QRubberBand::Rectangle, this ) )
    , _mode        ( mode                                            )
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
    if ( !_active ) return;

    if ( _mode == Mode::RUBBER )
        _rubber_band->setGeometry( { _last_pos, event->pos() } );

    emit mouse_move( event );
}
//=======================================================================================
void CustomLabel::mousePressEvent( QMouseEvent* event )
{
    if ( !_active ) return;

    if ( _mode == Mode::RUBBER )
    {
        _last_pos = event->pos();

        _rubber_band->setGeometry( { _last_pos, QSize() } );
        _rubber_band->show();

        _selected = true;
    }

    else if ( _mode == Mode::POLYGON )
    {
        _polygon << event->pos();
        emit polygon( _polygon );
    }

    emit mouse_press( event );
}
//=======================================================================================
void CustomLabel::mouseReleaseEvent( QMouseEvent* event )
{
    if ( !_active ) return;

    if ( _mode == Mode::RUBBER )
    {
        if ( _selected ) emit region( _last_pos, *_rubber_band );

        _selected = false;
    }

    emit mouse_release( event );
}
//=======================================================================================
void CustomLabel::wheelEvent( QWheelEvent* event )
{
    if ( !_active ) return;

    if ( QApplication::keyboardModifiers() == Qt::ControlModifier )
        emit mouse_wheel( event );
}
//=======================================================================================


//=======================================================================================
void CustomLabel::activate()
{
    _active = !_active;
}
//=======================================================================================
