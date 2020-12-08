#pragma once

#include "imageview.h"

#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QImage>
#include <QPixmap>
#include <QToolBar>
#include <QBoxLayout>
#include <QScrollArea>
#include <QMainWindow>
#include <QMenuBar>
#include <QStatusBar>

//=======================================================================================
class Region : public QMainWindow
{
    Q_OBJECT

public:

    explicit Region( const QImage& img,  QWidget* parent = nullptr );
    virtual ~Region() override;

    //-----------------------------------------------------------------------------------

    QImage get();

    //-----------------------------------------------------------------------------------

private:

    QMenuBar* _menu_bar     { nullptr };
    QToolBar* _tool_bar     { nullptr };
    QWidget*  _central      { nullptr };
    QStatusBar* _status_bar { nullptr };
    QLabel*   _label        { nullptr };
    ImageView*_image_viewer { nullptr };

    //-----------------------------------------------------------------------------------

    QAction* _action_polygon { nullptr };
    QAction* _action_pallete { nullptr };

    //-----------------------------------------------------------------------------------

    QPixmap _pixmap;
    QImage  _image;

    QSize _size;

};
//=======================================================================================
