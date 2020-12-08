#include <QApplication>

#include "mainwindow.h"

//=======================================================================================
int main(int argc, char **argv)
{
    QApplication app( argc, argv );

    MainWindow mainWindow;
    mainWindow.setWindowIcon( QIcon( ":/images/logo.png" ) );
    mainWindow.show();

    return app.exec();

    QApplication::closeAllWindows();
}
//=======================================================================================
