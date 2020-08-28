#include <QTextStream>
#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), iterNum(0)
{
    ui->setupUi(this);
    
    connect(ui->buttonIterate, SIGNAL(clicked()), this, SLOT(onButtonIterate()));
    connect(ui->buttonClear, SIGNAL(clicked()), this, SLOT(onButtonClear()));
    
    ui->label->setText("Iteration 0");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onButtonIterate()
{
    if(iterNum < MAX_ITER_NUM)
    {
        ++iterNum;
        QString iterNumString;
        QTextStream(&iterNumString) << "Iteration " << iterNum;
        ui->label->setText(iterNumString);
    }
}
    
void MainWindow::onButtonClear()
{
    ui->label->setText("Iteration 0");
    iterNum = 0;
}