#pragma once

#include <QMainWindow>
#include <QTabWidget>
#include <QObject>

//=======================================================================================
class Multitab : public QMainWindow
{
    Q_OBJECT

public:

    explicit Multitab( QWidget* parent = nullptr );
    virtual ~Multitab() override;

    //-----------------------------------------------------------------------------------

private:

    QTabWidget* _tab { nullptr };

};
//=======================================================================================
