#pragma once

#include "imageview.h"
#include "customlabel.h"
#include "region.h"

#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QToolBar>
#include <QStatusBar>
#include <QLabel>
#include <QFileInfoList>
#include <QMouseEvent>
#include <QRubberBand>

//=======================================================================================
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    explicit MainWindow( QWidget *parent = nullptr );
    virtual ~MainWindow();

    //-----------------------------------------------------------------------------------

public slots:

    void open();
    void close();
    void to_left();
    void to_right();
    void to_large();
    void to_less();

    //-----------------------------------------------------------------------------------

    void mouse_move( QMouseEvent* event );
    void mouse_press( QMouseEvent* event );
    void mouse_release( QMouseEvent* event );
    void mouse_wheel( QWheelEvent* event );
    void region( const QPoint& pos, const QRubberBand& region );

    //-----------------------------------------------------------------------------------

private:

    QMenuBar*    _menu_bar       { nullptr };
    QStatusBar*  _status_bar     { nullptr };
    QToolBar*    _tool_bar       { nullptr };
    QWidget*     _central_widget { nullptr };
    CustomLabel*  _label         { nullptr };
    ImageView*   _image_viewer   { nullptr };

    QList<Region*> _regions;

    //-----------------------------------------------------------------------------------

    QAction* _action_open       { nullptr };
    QAction* _action_close      { nullptr };
    QAction* _action_to_left    { nullptr };
    QAction* _action_to_right   { nullptr };
    QAction* _action_to_enlarge { nullptr };
    QAction* _action_to_lessen  { nullptr };
    QAction* _action_polygon    { nullptr };

    //-----------------------------------------------------------------------------------

    void _init_window_componet();
    void _init_img_viewer();
    void _init_img_resource();
    void _load_img_resource();
    void _init_connections();

};
//=======================================================================================
