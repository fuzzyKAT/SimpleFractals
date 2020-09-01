#include <QOpenGLWidget>
#include <QOpenGLFunctions>

class FractalRenderer : public QOpenGLWidget
{
public:
    
    FractalRenderer(QWidget *parent)
        : QOpenGLWidget(parent)
    {
        this->setMinimumSize(400, 300);
        //QSizePolicy sizeplc(QSizePolicy::Expanding, QSizePolicy::Expanding);
        //this->setSizePolicy(sizeplc);
    }
    
protected:
    
    void initializeGL() override
    {
        QOpenGLFunctions *glf = QOpenGLContext::currentContext()->functions();
        glf->glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    }
    
    void paintGL() override
    {
        QOpenGLFunctions *glf = QOpenGLContext::currentContext()->functions();
        glf->glClear(GL_COLOR_BUFFER_BIT);
    }
    
    void resizeGL(int w, int h) override
    {
        QOpenGLFunctions *glf = QOpenGLContext::currentContext()->functions();
        glf->glViewport(0, 0, w, h);
    }
};