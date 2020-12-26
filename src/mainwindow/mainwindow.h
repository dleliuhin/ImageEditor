#pragma once

#include "customlabel.h"
#include "multitab.h"
#include "imageview.h"
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
#include <QGraphicsView>

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

    void mouse_wheel( QWheelEvent* event );

    //-----------------------------------------------------------------------------------

private:

    QMenuBar*    _menu_bar       { nullptr };
    QStatusBar*  _status_bar     { nullptr };
    QToolBar*    _tool_bar       { nullptr };
    CustomLabel*  _label         { nullptr };
    ImageView*   _image_viewer   { nullptr };
    Multitab*    _regions        { nullptr };
    QGraphicsView* _view         { nullptr };

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
    void _init_connections();

};
//=======================================================================================
