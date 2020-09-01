#include <QTextStream>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QComboBox>
#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), iterNum(0)
{
    QPushButton *buttonIterate = new QPushButton("Iterate");
    QPushButton *buttonClear = new QPushButton("Clear");
    
    buttonIterate->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    buttonClear->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    
    label = new QLabel("Iteration 0");
    QHBoxLayout *hlayout = new QHBoxLayout();
    QVBoxLayout *vlayout = new QVBoxLayout();
    frRenderer = new FractalRenderer(this);
    QComboBox *cbox = new QComboBox(this);
    
    cbox->insertItem(1, tr("Koch Curve"));
    cbox->insertItem(2, tr("Koch Snowflake"));
    cbox->insertItem(3, tr("Serpinsky Triangle"));
    
    hlayout->addWidget(buttonIterate);
    hlayout->addWidget(buttonClear);
    hlayout->addStretch();
    hlayout->addWidget(label);
    
    vlayout->addWidget(frRenderer, 1);
    vlayout->addWidget(cbox);
    vlayout->addLayout(hlayout);

    QWidget *centralWidget = new QWidget();
    centralWidget->setLayout(vlayout);
    this->setCentralWidget(centralWidget);
    
    connect(buttonIterate, SIGNAL(clicked()), this, SLOT(onButtonIterate()));
    connect(buttonClear, SIGNAL(clicked()), this, SLOT(onButtonClear()));
    connect(cbox, SIGNAL(activated(int)), this, SLOT(onComboBoxActivated(int)));
}

MainWindow::~MainWindow()
{
    delete frRenderer;
}

void MainWindow::onButtonIterate()
{
    if(iterNum < MAX_ITER_NUM)
    {
        ++iterNum;
        frRenderer->setDepth(iterNum);
        QString iterNumString;
        QTextStream(&iterNumString) << "Iteration " << iterNum;
        label->setText(iterNumString);
    }
}
    
void MainWindow::onButtonClear()
{
    label->setText("Iteration 0");
    iterNum = 0;
    frRenderer->setDepth(iterNum);
}

void MainWindow::onComboBoxActivated(int index)
{
    switch(index)
    {
        case 0: 
            frRenderer->setCurrentFractal(new KochCurve());
            break;
            
        case 1: 
            frRenderer->setCurrentFractal(new KochSnowflake());
            break;
            
        case 2: 
            frRenderer->setCurrentFractal(new SerpinskyTriangle());
            break;
    }
}
