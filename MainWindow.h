#include <QMainWindow>
#include <QLabel>
#include "FractalRenderer.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:

    explicit MainWindow(QWidget *parent = nullptr);
    
    ~MainWindow();

private slots:
    
    void onButtonIterate();
    
    void onButtonClear();
    
    void onComboBoxActivated(int index);
    
private:

    const int MAX_ITER_NUM = 16;

    QLabel *label;
    
    FractalRenderer *frRenderer;
    
    int iterNum;
};