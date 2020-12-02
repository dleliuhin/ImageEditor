#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QToolBar>
#include <QStatusBar>
#include <QLabel>
#include <QFileInfoList>

#include "imageviewer.h"
#include "customlabel.h"

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
    void last();
    void next();
    void to_left();
    void to_right();
    void to_large();
    void to_less();
    void deleted();

    //-----------------------------------------------------------------------------------

    void mouse_move( QMouseEvent* event );
    void mouse_press( QMouseEvent* event );
    void mouse_release( QMouseEvent* event );
    void region( const QPoint& pos, const QRubberBand& region );

    //-----------------------------------------------------------------------------------

private:

    QMenuBar*     _menu_bar       { nullptr };
    QToolBar*     _tool_bar       { nullptr };
    QWidget*      _central_widget { nullptr };
    QStatusBar*   _status_bar     { nullptr };
    CustomLabel*  _label          { nullptr };
    ImageViewer* _image_viewer    { nullptr };

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

    void setQImageViewerWidget();
    void setWindowComponet();
    void initImageResource();
    void load_img_resource();

};
//=======================================================================================

#endif // MAINWINDOW_H
