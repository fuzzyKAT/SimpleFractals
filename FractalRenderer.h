#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include "Fractals.h"

class FractalRenderer : public QOpenGLWidget, private QOpenGLFunctions
{
public:
    
    FractalRenderer(QWidget *parent)
        : QOpenGLWidget(parent), depth(0), fractal(0x0)
    {
        this->setMinimumSize(300, 300);
        
        fractal = new KochCurve();
    }
    
    void setDepth(int d)
    {
        depth = d;
        this->update();
    }
    
    void setCurrentFractal(Fractal *cfrac)
    {
        if(fractal)
        {
            delete fractal;
        }
        
        fractal = cfrac;
        this->update();
    }
    
protected:
    
    void initializeGL() override
    {
        initializeOpenGLFunctions();
        glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    }
    
    void paintGL() override
    {
        glClear(GL_COLOR_BUFFER_BIT);
        fractal->draw(depth);
    }
    
    void resizeGL(int w, int h) override
    {
        glViewport(0, 0, w, h);
    }
    
private:
    
    int depth;
    
    Fractal *fractal;
};