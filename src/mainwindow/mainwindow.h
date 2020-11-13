#pragma once

#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QToolBar>
#include <QStatusBar>
#include <QLabel>
#include <QFileInfoList>
#include <QRubberBand>
#include <QMouseEvent>

#include "qimageviewer.h"

//=======================================================================================
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    explicit MainWindow( QWidget *parent = nullptr );
    virtual ~MainWindow();

    //-----------------------------------------------------------------------------------

public slots:

    void opened();
    void closed();
    void to_left();
    void to_right();
    void to_large();
    void to_less();
    void deleted();

    //-----------------------------------------------------------------------------------

private:

    QMenuBar*   _menu_bar       { nullptr };
    QToolBar*   _tool_bar       { nullptr };
    QWidget*    _central_widget { nullptr };
    QStatusBar* _status_bar     { nullptr };
    QLabel*     _image_label    { nullptr };
    QImageView* _image_viewer   { nullptr };

    //-----------------------------------------------------------------------------------

    QAction* _action_open       { nullptr };
    QAction* _action_close      { nullptr };
    QAction* _action_last       { nullptr };
    QAction* _action_next       { nullptr };
    QAction* _action_to_left    { nullptr };
    QAction* _action_to_right   { nullptr };
    QAction* _action_to_enlarge { nullptr };
    QAction* _action_to_lessen  { nullptr };
    QAction* _action_delete     { nullptr };

    //-----------------------------------------------------------------------------------

    void _init_img_viewer();
    void _init_window_componet();
    void _load_img_resource();
    void _init_img_resource();

    //-----------------------------------------------------------------------------------

    QRubberBand* _rubber_band { nullptr };

    //-----------------------------------------------------------------------------------

    void mouseMoveEvent( QMouseEvent* event );
    void mousePressEvent( QMouseEvent* event );

private slots:

    void _im_show( const QImage& src );

};
//=======================================================================================
