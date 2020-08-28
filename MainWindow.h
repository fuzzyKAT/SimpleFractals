#include <QMainWindow>

namespace Ui
{
    class MainWindow;
}

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

    const int MAX_ITER_NUM = 16;

    Ui::MainWindow *ui;
    
    int iterNum;
};