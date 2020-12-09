#include "imageview.h"

#include <QFileDialog>
#include <QMessageBox>
#include <QDebug>
#include <QImageReader>

//=======================================================================================
ImageView::ImageView( QWidget* parent )
    : QWidget ( parent )
{
    resize( QSize( 1280, 800 ) );
    setWindowTitle( "QImageViewer" );
}
//=======================================================================================
ImageView::~ImageView()
{}
//=======================================================================================


//=======================================================================================
bool ImageView::open( const QString& caption,
                      const QString& dir,
                      const QString& filter )
{
    fname = QFileDialog::getOpenFileName( this, caption, dir, filter );

    if ( fname.isEmpty() ) return false;

    static auto info = QFileInfo( fname );

    if ( !image.load( fname ) ) return false;

    size = image.size();

    return _changed( angle, 10 );
}
//=======================================================================================
bool ImageView::set( const QImage& src )
{
    image = src;

    size = image.size();

    return _changed( angle, 10 );
}
//=======================================================================================
bool ImageView::zoom( const int scale )
{
    return _changed( angle, scale );
}
//=======================================================================================
bool ImageView::to_right()
{
    return _rotate(1);
}
//=======================================================================================
bool ImageView::to_left()
{
    return _rotate(3);
}
//=======================================================================================
bool ImageView::clear()
{
    angle = 0;
    size = QSize(0, 0);
    fname.clear();
    image = {};

    return true;
}
//=======================================================================================


//=======================================================================================
bool ImageView::_rotate( const int scale )
{
    angle += scale;
    angle = angle % 4;

    return _changed( angle, 10 );
}
//=======================================================================================


//=======================================================================================
bool ImageView::_changed( const int& angle, const int& scale )
{
    QImage img_rotate;
    QMatrix matrix;
    QImage img_scaled;

    if ( size == QSize(0, 0) ) size = image.size();

    img_scaled = image.scaled( size.width() * scale / 10,
                               size.height() * scale / 10,
                               Qt::KeepAspectRatio );

    if ( scale != 10 ) size = img_scaled.size();

    matrix.rotate( angle * 90 );

    img_rotate = img_scaled.transformed( matrix );

    pixmap = QPixmap::fromImage( img_rotate );

    return true;
}
//=======================================================================================
