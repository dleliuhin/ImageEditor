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
    virtual ~ImageView();

    //-----------------------------------------------------------------------------------

    QImage image;
    QPixmap pixmap;

    //-----------------------------------------------------------------------------------

    int open_img( const QString& caption, const QString& dir, const QString& filer );
    int zoom_in();
    int zoom_out();
    int to_right();
    int to_left();
    int close_img();

};

//=======================================================================================
