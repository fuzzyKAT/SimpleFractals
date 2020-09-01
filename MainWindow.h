#include <QMainWindow>
#include <QLabel>

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:

    explicit MainWindow(QWidget *parent = nullptr);
    
    ~MainWindow();

private slots:
    
    void onButtonIterate();
    
    void onButtonClear();
    
private:

    QLabel *label;

    const int MAX_ITER_NUM = 16;
    
    int iterNum;
};