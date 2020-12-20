#pragma once

#include "imageview.h"
#include "customlabel.h"

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
#include <QColorDialog>

//=======================================================================================
class Region : public QMainWindow
{
    Q_OBJECT

public:

    explicit Region( const QImage& img, QWidget* parent = nullptr );
    virtual ~Region() override;

    //-----------------------------------------------------------------------------------

signals:

    void close_tab();

    //-----------------------------------------------------------------------------------

public slots:

    void draw( const QPolygonF& data );

    //-----------------------------------------------------------------------------------

private:

    QMenuBar* _menu_bar      { nullptr };
    QToolBar* _tool_bar      { nullptr };
    QWidget* _central        { nullptr };
    QStatusBar* _status_bar  { nullptr };
    CustomLabel* _label      { nullptr };
    ImageView* _image_viewer { nullptr };

    //-----------------------------------------------------------------------------------

    QAction* _action_polygon { nullptr };
    QAction* _action_pallete { nullptr };

    //-----------------------------------------------------------------------------------

    QPixmap _pixmap;
    QImage  _image;
    QColor _color;
    QSize _size;

};
//=======================================================================================
