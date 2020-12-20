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

public slots:

    void add_tab( Region* region );

    //-----------------------------------------------------------------------------------

private:

    QTabWidget* _tabs { nullptr };

};
//=======================================================================================
