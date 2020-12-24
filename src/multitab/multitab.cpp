#include "multitab.h"

//=======================================================================================

static const QSize wsize( 720, 480 );

//=======================================================================================
Multitab::Multitab( QWidget* parent )
    : QMainWindow ( parent                 )
    , _tabs       ( new QTabWidget( this ) )
{
    _tabs->setTabShape( QTabWidget::TabShape::Triangular );

    setCentralWidget( _tabs );

    show();

    connect( _tabs, &QTabWidget::currentChanged, [&]( const int& id ){ _current = id; } );
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

    connect( region, &Region::close_tab, this, &Multitab::close_tab );
}
//=======================================================================================
void Multitab::close_tab()
{
    _tabs->removeTab( _current );

    if( _tabs->count() == 0 )
        emit tabs_empty();
}
//=======================================================================================


//=======================================================================================
void Multitab::closeEvent( QCloseEvent* event )
{
    _tabs->clear();
}
//=======================================================================================
