#include "customlabel.h"

#include <QDebug>

//=======================================================================================
CustomLabel::CustomLabel( QWidget* parent )
    : QLabel ( parent )
{}
//=======================================================================================


//=======================================================================================
void CustomLabel::mousePressEvent( QMouseEvent* event )
{
    QLabel::mousePressEvent( event );
    qDebug() << event->pos();
    emit clicked();
}
//=======================================================================================
