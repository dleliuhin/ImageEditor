#pragma once

#include <QWidget>
#include <QImage>
#include <QPixmap>
#include <QDir>
#include <QSize>
#include <QFileInfo>
#include <QFileInfoList>

//=======================================================================================

class ImageView : public QWidget
{
    Q_OBJECT

public:

    explicit ImageView( QWidget* parent = nullptr );
    explicit ImageView( QWidget* parent,
                           const QString& caption,
                           const QString& dir,
                           const QString& filer );
    virtual ~ImageView();

    //-----------------------------------------------------------------------------------

    QWidget* parent { nullptr };

    int angle {0};

    QSize size;
    QString filename;
    QString path;
    QDir dir;
    QFileInfo file_info;

    QImage image;
    QPixmap pixmap;

    //-----------------------------------------------------------------------------------

    int open_img( const QString& caption, const QString& dir, const QString& filer );
    int close_img();
    int zoom_in();
    int zoom_out();
    int rotate_to_right();
    int spin_to_left();

    //-----------------------------------------------------------------------------------

private:

    void _init_img();
    int _load_img();
    int _load_img( const QString& caption, const QString& dir, const QString& filer );
    int _upgrade_file_info( const QString& filename, const int angle, const int scale );
    int _get_files_info();
    int _get_file_idx();

};

//=======================================================================================
