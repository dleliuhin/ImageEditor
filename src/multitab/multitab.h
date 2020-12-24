#pragma once

#include "region.h"

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

signals:

    void tabs_empty();

    //-----------------------------------------------------------------------------------

public slots:

    void add_tab( Region* region );
    void close_tab();

    //-----------------------------------------------------------------------------------

private:

    QTabWidget* _tabs { nullptr };

    int _current {-1};

};
//=======================================================================================
