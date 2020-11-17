#include "imageview.h"

#include <QFileDialog>
#include <QMessageBox>
#include <QDebug>
#include <QImageReader>

//=======================================================================================
ImageView::ImageView( QWidget* parent )
    : QWidget      ( parent                                          )    
{
    this->parent = parent;
    _init_img();
}
//=======================================================================================
ImageView::ImageView( QWidget* parent,
                        const QString& caption,
                        const QString& dir,
                        const QString& filer )
{
    this->parent = parent;
    _init_img();
    _load_img( caption, dir, filer );
}
//=======================================================================================
ImageView::~ImageView()
{
    this->parent = nullptr;
}
//=======================================================================================


//=======================================================================================
int ImageView::open_img( const QString& caption,
                          const QString& dir,
                          const QString& filer )
{
    _init_img();
    return _load_img( caption, dir, filer );
}
//=======================================================================================
int ImageView::close_img()
{
    _init_img();
    return EXIT_SUCCESS;
}
//=======================================================================================
int ImageView::del_img()
{
    if ( filename.isEmpty() ) return - 1;

    if ( QFile::remove( filename ) )
        qDebug() << "remove success: " << filename;

    else
    {
        qDebug() << "remove failed: " << filename;
        return - 1;
    }

    fileInfoList.removeAt( index );

    return EXIT_SUCCESS;
}
//=======================================================================================
int ImageView::zoom_in()
{
    return _upgrade_file_info( filename, angle, 12 );
}
//=======================================================================================
int ImageView::zoom_out()
{
    return _upgrade_file_info( filename, angle, 8 );
}
//=======================================================================================
int ImageView::rotato_to_right()
{
    angle += 1;
    angle = angle % 4;

    return _upgrade_file_info( filename, angle, 10 );
}
//=======================================================================================
int ImageView::spin_to_left()
{
    angle += 3;
    angle = angle % 4;

    return _upgrade_file_info( filename, angle, 10 );
}
//=======================================================================================


//=======================================================================================
void ImageView::_init_img()
{
    index = EXIT_FAILURE;
    angle = 0;
    size = QSize(0, 0);

    filename.clear();
    path.clear();
}
//=======================================================================================
int ImageView::_load_img()
{
    filename = QFileDialog::getOpenFileName( this, "Select image:",
                                             "D:\\Documents\\Pictures",
                                             "Images (*.jpg *.jpeg *.png *.bmp *.gif)" );
    if ( filename.isEmpty() ) return EXIT_FAILURE;

    _get_files_info();

    _upgrade_file_info( filename, angle, 10 );

    return EXIT_SUCCESS;
}
//=======================================================================================
int ImageView::_load_img( const QString& caption,
                           const QString& directory,
                           const QString& filer )
{
    filename = QFileDialog::getOpenFileName( this, caption, directory, filer );
    if ( filename.isEmpty() )
        return - 1;

    _get_files_info();

    _upgrade_file_info( filename, angle, 10 );

    return EXIT_SUCCESS;
}
//=======================================================================================
int ImageView::_upgrade_file_info( const QString& filename,
                                    const int angle,
                                    const int scale )
{
    QImage img_rotate;
    QMatrix matrix;
    QImage img_scaled;

    if ( filename.isEmpty() ) return EXIT_FAILURE;

    file_info = QFileInfo( filename );
    if ( !image.load( filename ) ) return EXIT_FAILURE;

    if ( size == QSize(0, 0) )
        size = image.size();

    emit loaded( image );

    img_scaled = image.scaled( size.width() * scale / 10,
                               size.height() * scale / 10,
                               Qt::KeepAspectRatio );
    if ( scale != 10 )
        size = img_scaled.size();

    matrix.rotate( angle * 90 );
    img_rotate = img_scaled.transformed( matrix );

    pixmap = QPixmap::fromImage( img_rotate );
    index = _get_file_idx();

    return EXIT_SUCCESS;
}
//=======================================================================================
int ImageView::_get_files_info()
{
    QFileInfo info;
    QFileInfoList infoList;

    path = QFileInfo(filename).absolutePath();
    dir = QFileInfo(filename).absoluteDir();

    /* clear list */
    fileInfoList.clear();

    infoList = dir.entryInfoList(QDir::Files);
    for (int i = 0; i < infoList.count(); i++) {
        info = infoList.at(i);
        QString suffix = info.suffix();

        if ( suffix == "jpg" || suffix == "bmp" || suffix == "png"
             || suffix == "gif" || suffix == "jpeg")
            fileInfoList.append( info );
    }

    return EXIT_SUCCESS;
}
//=======================================================================================
int ImageView::_get_file_idx()
{
    QFileInfo info;
    int j;

    if ( fileInfoList.count() <= 0 )
    {
        qDebug() << "fileInfoList is NULL!";
        return EXIT_FAILURE;
    }

    for (j = 0; j < fileInfoList.count(); j++)
    {
        info = fileInfoList.at(j);

        if ( info.fileName() == file_info.fileName() )
            break;
    }

    if (j >= fileInfoList.count())
    {
        qDebug() << "Not find current file!";

        return EXIT_FAILURE;
    }

    index = j;

    return index;
}
//=======================================================================================
