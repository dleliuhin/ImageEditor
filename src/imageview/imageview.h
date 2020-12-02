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
    bool zoom( const int scale );
    bool to_right();
    bool to_left();
    bool clear();

    //-----------------------------------------------------------------------------------

    bool _rotate( const int scale );

    //-----------------------------------------------------------------------------------

private slots:

    bool _changed( const int& angle, const int& scale );

};
//=======================================================================================
