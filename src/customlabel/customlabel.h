#pragma once

#include <QLabel>
#include <QMouseEvent>
#include <QRubberBand>

//=======================================================================================
class CustomLabel : public QLabel
{
    Q_OBJECT

public:

    explicit CustomLabel( QWidget* parent = nullptr );
    virtual ~CustomLabel();

    void mouseMoveEvent( QMouseEvent* event ) override;
    void mousePressEvent( QMouseEvent* event ) override;
    void mouseReleaseEvent( QMouseEvent* event ) override;

    //-----------------------------------------------------------------------------------

signals:

    void mouse_move( QMouseEvent* event );
    void mouse_press( QMouseEvent* event );
    void mouse_release( QMouseEvent* event );
    void region( const QPoint& pos, const QRubberBand& region );

    //-----------------------------------------------------------------------------------

private:

    QRubberBand* _rubber_band { nullptr };

    //-----------------------------------------------------------------------------------

    QPoint _last_pos { 0, 0 };
    bool _selected { false };

};
//=======================================================================================
