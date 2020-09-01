#ifndef FRACTALS_H
#define FRACTALS_H
#include <QOpenGLFunctions>
#include <cmath>

class Fractal : private QOpenGLFunctions
{
public:
    
    virtual ~Fractal() {}
    
    // Отрисовывает фрактал
    virtual void draw(int level) = 0;
};

struct Point
{
    Point()
        : x(0.0), y(0.0) {}
    
    Point(float _x, float _y)
        : x(_x), y(_y) {}
    
    Point &operator+=(const Point &p)
    {
        x += p.x;
        y += p.y;
        return *this;
    }
    
    float x;
    float y;
};

class KochCurve : public Fractal
{
public:
    
    KochCurve()
    {
        pt1 = Point(-0.95f, 0.0f);
        pt2 = Point( 0.95f, 0.0f);
    }
    
    KochCurve(Point p1, Point p2)
        : pt1(p1), pt2(p2) {}

    void draw(int level)
    {
        glColor3f(0.0f, 0.0f, 1.0f);
        
        if(!level)
        {
            glBegin(GL_LINES);
            glVertex2f(pt1.x, pt1.y);
            glVertex2f(pt2.x, pt2.y);
            glEnd();
            return;
        }
        
        drawCurve(level-1, pt1, pt2);
    }

private:
    
    void drawCurve(int level, Point &px, Point &py)
    {
        const double cf = sqrt(3.0)/6;
        Point p1((py.x + 2*px.x)/3, (py.y + 2*px.y)/3);
        Point p2((2*py.x + px.x)/3, (px.y + 2*py.y)/3);
        Point ps((px.x + py.x)/2, (px.y + py.y)/2);
        Point pd(-(py.y - px.y)*cf, (py.x - px.x)*cf);
        ps += pd;
        
        if(!level)
        {
            
            glBegin(GL_LINE_STRIP);
            glVertex2f(px.x, px.y);
            glVertex2f(p1.x, p1.y);
            glVertex2f(ps.x, ps.y);
            glVertex2f(p2.x, p2.y);
            glVertex2f(py.x, py.y);
            glEnd();
            
            return;
        }
    
        drawCurve(level-1, px, p1);
        drawCurve(level-1, p2, py);
        drawCurve(level-1, p1, ps);
        drawCurve(level-1, ps, p2);
    }
    
    Point pt1;
    Point pt2;
};

class KochSnowflake : public Fractal
{
public:
    
    KochSnowflake()
    {
        Point p1( 0.000f,  0.9f);
        Point p2( 0.808f, -0.5f);
        Point p3(-0.808f, -0.5f);
        
        c1 = new KochCurve(p1, p2);
        c2 = new KochCurve(p2, p3);
        c3 = new KochCurve(p3, p1);
    }
    
    ~KochSnowflake()
    {
        delete c1;
        delete c2;
        delete c3;
    }
    
    void draw(int level)
    {
        c1->draw(level);
        c2->draw(level);
        c3->draw(level);
    }
    
private:
    
    KochCurve *c1;
    KochCurve *c2;
    KochCurve *c3;
};

class SerpinskyTriangle : public Fractal
{
public:
    
    void draw(int level)
    {
        Point p1( 0.0f,  0.9f);
        Point p2( 0.9f, -0.9f);
        Point p3(-0.9f, -0.9f);
        
        glColor3f(0.0f, 0.0f, 1.0f);
        drawTriangle(level, p1, p2, p3);
    }
    
private:

    void drawTriangle(int level, Point &p1, Point &p2, Point &p3)
    {
        if(!level)
        {
            glBegin(GL_TRIANGLES);
            glVertex2f(p1.x, p1.y);
            glVertex2f(p2.x, p2.y);
            glVertex2f(p3.x, p3.y);
            glEnd();
            
            return;
        }
        
        Point px((p1.x + p2.x)/2, (p1.y + p2.y)/2);
        Point py((p2.x + p3.x)/2, (p2.y + p3.y)/2);
        Point pz((p3.x + p1.x)/2, (p3.y + p1.y)/2);
        
        drawTriangle(level-1, p1, px, pz);
        drawTriangle(level-1, p2, px, py);
        drawTriangle(level-1, p3, py, pz);
    }
};

#endif