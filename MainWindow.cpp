#include <QTextStream>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include "MainWindow.h"
#include "FractalRenderer.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), iterNum(0)
{
    QPushButton *buttonIterate = new QPushButton("Iterate");
    QPushButton *buttonClear = new QPushButton("Clear");
    
    buttonIterate->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    buttonClear->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    
    connect(buttonIterate, SIGNAL(clicked()), this, SLOT(onButtonIterate()));
    connect(buttonClear, SIGNAL(clicked()), this, SLOT(onButtonClear()));
    
    label = new QLabel("Iteration 0");
    QHBoxLayout *hlayout = new QHBoxLayout();
    QVBoxLayout *vlayout = new QVBoxLayout();
    FractalRenderer *frRenderer = new FractalRenderer(this);
    
    hlayout->addWidget(buttonIterate);
    hlayout->addWidget(buttonClear);
    hlayout->addStretch();
    
    vlayout->addWidget(frRenderer, 1);
    vlayout->addLayout(hlayout);
    vlayout->addWidget(label);

    QWidget *centralWidget = new QWidget();
    centralWidget->setLayout(vlayout);
    this->setCentralWidget(centralWidget);
}

MainWindow::~MainWindow()
{
    
}

void MainWindow::onButtonIterate()
{
    if(iterNum < MAX_ITER_NUM)
    {
        ++iterNum;
        QString iterNumString;
        QTextStream(&iterNumString) << "Iteration " << iterNum;
        label->setText(iterNumString);
    }
}
    
void MainWindow::onButtonClear()
{
    label->setText("Iteration 0");
    iterNum = 0;
}