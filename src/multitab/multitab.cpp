#include "multitab.h"

static const QSize wsize( 720, 480 );

//=======================================================================================
Multitab::Multitab( QWidget* parent )
    : QMainWindow ( parent                 )
    , _tabs       ( new QTabWidget( this ) )
{
    _tabs->setTabShape( QTabWidget::TabShape::Triangular );

    setCentralWidget( _tabs );

    show();
}
//=======================================================================================
Multitab::~Multitab()
{
    delete _tabs;
}
//=======================================================================================


//=======================================================================================
void Multitab::add_tab( Region* region )
{
    auto index = _tabs->count() + 1;

    _tabs->addTab( region, QString( "Tab %0" ).arg( index ) );

    _tabs->setCurrentWidget( region );

    resize( wsize );
}
//=======================================================================================
