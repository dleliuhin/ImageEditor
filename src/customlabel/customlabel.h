#pragma once

#include <QLabel>
#include <QMouseEvent>
#include <QRubberBand>

//=======================================================================================
class CustomLabel : public QLabel
{
    Q_OBJECT

public:

    enum class Mode : int
    {
        UNDEF = 0,
        RUBBER,
        POLYGON,
    };

    explicit CustomLabel( const Mode mode = Mode::UNDEF, QWidget* parent = nullptr );
    virtual ~CustomLabel();

    void mouseMoveEvent( QMouseEvent* event ) override;
    void mousePressEvent( QMouseEvent* event ) override;
    void mouseReleaseEvent( QMouseEvent* event ) override;
    void wheelEvent( QWheelEvent* event ) override;

    //-----------------------------------------------------------------------------------

signals:

    void mouse_move( QMouseEvent* event );
    void mouse_press( QMouseEvent* event );
    void mouse_release( QMouseEvent* event );
    void mouse_wheel( QWheelEvent* event );
    void region( const QPoint& pos, const QRubberBand& region );
    void polygon( const QPolygonF& data );

    //-----------------------------------------------------------------------------------

public slots:

    void activate();

    //-----------------------------------------------------------------------------------

private:

    QRubberBand* _rubber_band { nullptr };
    QPolygonF _polygon;

    //-----------------------------------------------------------------------------------

    QPoint _last_pos { 0, 0 };
    bool _selected { false };

    //-----------------------------------------------------------------------------------

    bool _active { false };

    Mode _mode { Mode::UNDEF };

};
//=======================================================================================
