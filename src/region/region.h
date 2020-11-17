#pragma once

#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QImage>
#include <QPixmap>

//=======================================================================================
class Region : public QWidget
{
    Q_OBJECT

public:

    explicit Region( const QImage& img,  QWidget* parent = nullptr );
    virtual ~Region();

    //-----------------------------------------------------------------------------------

private:

    QLabel* _label  { nullptr };
    QPixmap _pixmap;
    QImage  _image;

};
//=======================================================================================
