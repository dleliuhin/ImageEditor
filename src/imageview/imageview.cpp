#include "imageview.h"

#include <QFileDialog>
#include <QMessageBox>
#include <QDebug>
#include <QImageReader>

//=======================================================================================
ImageView::ImageView( QWidget* parent )
    : QWidget ( parent )
{
    clear();
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

    _changed();

    return true;
}
//=======================================================================================
int ImageView::zoom( const int scale )
{
    image = image.scaled( size.width() * scale / 10,
                          size.height() * scale / 10,
                          Qt::KeepAspectRatio );

    _changed();
}
//=======================================================================================
int ImageView::to_right()
{
    _rotate(1);
}
//=======================================================================================
int ImageView::to_left()
{
    _rotate(3);
}
//=======================================================================================


//=======================================================================================
void ImageView::_rotate( const int scale )
{
    angle = angle % 4;

    QMatrix matrix;
    matrix.rotate( angle * 90 );
    image = image.transformed( matrix );

    _changed();
}
//=======================================================================================


//=======================================================================================
void ImageView::_changed()
{
    pixmap = QPixmap::fromImage( image );
    resize( size );
    setWindowTitle( QFileInfo( fname ).fileName() );
    show();
}
//=======================================================================================
