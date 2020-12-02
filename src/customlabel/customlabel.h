#ifndef CUSTOMLABEL_H
#define CUSTOMLABEL_H

#include <QLabel>
#include <QMouseEvent>

//=======================================================================================
class CustomLabel : public QLabel
{
    Q_OBJECT

public:

    explicit CustomLabel( QWidget* parent = nullptr );

    void mousePressEvent( QMouseEvent* event ) override;

    //-----------------------------------------------------------------------------------

signals:

    void clicked();

};
//=======================================================================================

#endif // CUSTOMLABEL_H
