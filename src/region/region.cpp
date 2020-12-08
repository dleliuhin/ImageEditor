#include "region.h"

#include <QScrollArea>
#include <QDebug>

//=======================================================================================
Region::Region( const QImage& img, QWidget* parent )
    : QWidget   ( parent                                          )
    , _scroll_area ( new QScrollArea( this )                      )
    , _grid_layout ( new QGridLayout( this )                      )
    , _tool_bar ( new QToolBar( this )                            )
    , _label    ( new QLabel( this )                              )
    , _image    ( img                                             )
{
    _scroll_area->setAlignment( Qt::AlignCenter );
    _scroll_area->setFrameShape( QFrame::NoFrame );
    _scroll_area->setWidget( _label );

    _grid_layout->addWidget( _scroll_area );
    setLayout( _grid_layout );

    _size = img.size() * 2;

    _pixmap = QPixmap::fromImage( _image );

    _label->setPixmap( QPixmap::fromImage( _image.scaled( _size, Qt::KeepAspectRatio ) ) );

    resize( _size );

    static uint reg_count {1};

    setWindowTitle( "Subregion" + QString::number( reg_count++ ) );

    show();
    _label->show();
}
//=======================================================================================
Region::~Region()
{
    delete _scroll_area;
    delete _grid_layout;
    delete _tool_bar;
    delete _label;

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
