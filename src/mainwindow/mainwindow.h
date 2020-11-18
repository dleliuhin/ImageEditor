#pragma once

#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QToolBar>
#include <QStatusBar>
#include <QLabel>
#include <QFileInfoList>
#include <QMouseEvent>
#include <QRubberBand>

#include "imageview.h"
#include "region.h"

//=======================================================================================
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    explicit MainWindow( QWidget *parent = nullptr );
    virtual ~MainWindow();

    //-----------------------------------------------------------------------------------

    void mouseMoveEvent( QMouseEvent* event ) override;
    void mousePressEvent( QMouseEvent* event ) override;
    void mouseReleaseEvent( QMouseEvent* event ) override;

    //-----------------------------------------------------------------------------------

public slots:

    void opened();
    void closed();
    void to_left();
    void to_right();
    void to_large();
    void to_less();

    //-----------------------------------------------------------------------------------

private:

    QMenuBar*    _menu_bar       { nullptr };
    QToolBar*    _tool_bar       { nullptr };
    QWidget*     _central_widget { nullptr };
    QStatusBar*  _status_bar     { nullptr };
    QLabel*      _image_label    { nullptr };
    ImageView*  _image_viewer    { nullptr };

    QRubberBand* _rubber_band { nullptr };

    QList<Region*> _regions;

    QPoint _last_pos { 0, 0 };
    bool _selected { false };

    //-----------------------------------------------------------------------------------

    QAction* _action_open       { nullptr };
    QAction* _action_close      { nullptr };
    QAction* _action_to_left    { nullptr };
    QAction* _action_to_right   { nullptr };
    QAction* _action_to_enlarge { nullptr };
    QAction* _action_to_lessen  { nullptr };

    //-----------------------------------------------------------------------------------

    void _init_img_viewer();
    void _init_window_componet();
    void _load_img_resource();
    void _init_img_resource();

};
//=======================================================================================
