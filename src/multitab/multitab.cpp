#include "multitab.h"

#include <QVBoxLayout>

//=======================================================================================
Multitab::Multitab( QWidget* parent )
    : QMainWindow ( parent                 )
    , _tab        ( new QTabWidget( this ) )
{
    _tab->setTabShape( QTabWidget::TabShape::Triangular );

    setCentralWidget( _tab );

    show();
}
//=======================================================================================
Multitab::~Multitab()
{
    delete _tab;
}
//=======================================================================================

