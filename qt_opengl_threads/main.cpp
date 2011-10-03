


#include <QApplication>
#include <Qt>



#include "appwindow.hpp"

#include <X11/Xlib.h>

int main(int argc, char *argv[])
{
    // this would maybe work in qt4.8: QApplication::setAttribute(  Qt::AA_X11InitThreads );
    XInitThreads();
    
    QApplication app(argc, argv); //Qt::AA_X11InitThreads  Qt::ApplicationAttribute
    AppWindow aw;
    //app.setCentralWidget(&aw);
    aw.show();
    return app.exec();
}