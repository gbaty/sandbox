
#ifndef GLWIDGET
#define GLWIDGET

#include <QObject>
#include <QThread>
#include <QGLWidget>
#include <QResizeEvent>

#include "glthread.hpp"

class GLWidget : public QGLWidget {
    Q_OBJECT
public:
    GLWidget(QWidget *parent): QGLWidget(parent), glt(this)
    { 
        setAutoBufferSwap(false);
        resize(320, 240);
    }
    void startRendering(){
         glt.start();
    }
    void stopRendering(){
        glt.stop();
        glt.wait();
    }
protected:
    void resizeEvent(QResizeEvent *evt){
        glt.resizeViewport(evt->size());
    }
    void paintEvent(QPaintEvent *){
        // Handled by the GLThread.
    }
    void closeEvent(QCloseEvent *evt){
        stopRendering();
        QGLWidget::closeEvent(evt);
    }
    GLThread glt;
};

#endif
