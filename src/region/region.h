#pragma once

#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QImage>
#include <QPixmap>
#include <QToolBar>
#include <QBoxLayout>

//=======================================================================================
class Region : public QWidget
{
    Q_OBJECT

public:

    explicit Region( const QImage& img,  QWidget* parent = nullptr );
    virtual ~Region();

    //-----------------------------------------------------------------------------------

    QImage get();

    //-----------------------------------------------------------------------------------

private:

    QToolBar* _tool_bar { nullptr };
    QBoxLayout* _layout { nullptr };
    QLabel*   _label    { nullptr };

    QPixmap _pixmap;
    QImage  _image;

    QSize size;
};
//=======================================================================================
