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

    QString fname;
    QImage image;
    QPixmap pixmap;
    QSize size;
    int angle {0};

    //-----------------------------------------------------------------------------------

    bool open( const QString& caption, const QString& dir, const QString& filter );
    int zoom( const int scale );
    int to_right();
    int to_left();
    int close();

    //-----------------------------------------------------------------------------------

    void _rotate( const int scale );

    //-----------------------------------------------------------------------------------

private slots:

    void _changed();

};
//=======================================================================================
