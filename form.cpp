#include "form.h"

#include <QLayout>

Form::Form(QWidget *parent)
    : QWidget(parent), system(nullptr)
{
    timer = new QTimer(this);
    timer->setInterval(0);

    labelM = new QLabel("mass");
    labelGamma = new QLabel("gamma");
    labelK = new QLabel("rigidity");
    labelInitX = new QLabel("initial coordinate");
    labelInitV = new QLabel("initial velocity");
    labelDt = new QLabel("time step");

    doubleSpinBoxM = new QDoubleSpinBox;
    doubleSpinBoxM->setMinimum(1.0);
    doubleSpinBoxM->setMaximum(100.0);
    doubleSpinBoxM->setSingleStep(1.0);
    doubleSpinBoxM->setDecimals(2);
    doubleSpinBoxGamma = new QDoubleSpinBox;
    doubleSpinBoxGamma->setMinimum(-100.0);
    doubleSpinBoxGamma->setMaximum(100.0);
    doubleSpinBoxGamma->setSingleStep(1.0);
    doubleSpinBoxGamma->setDecimals(2);
    doubleSpinBoxK = new QDoubleSpinBox;
    doubleSpinBoxK->setMinimum(1.0);
    doubleSpinBoxK->setMaximum(100.0);
    doubleSpinBoxK->setSingleStep(1.0);
    doubleSpinBoxK->setDecimals(2);
    doubleSpinBoxInitX = new QDoubleSpinBox;
    doubleSpinBoxInitX->setMinimum(-100.0);
    doubleSpinBoxInitX->setMaximum(100.0);
    doubleSpinBoxInitX->setSingleStep(1.0);
    doubleSpinBoxInitX->setDecimals(2);
    doubleSpinBoxInitV = new QDoubleSpinBox;
    doubleSpinBoxInitV->setMinimum(-100.0);
    doubleSpinBoxInitV->setMaximum(100.0);
    doubleSpinBoxInitV->setSingleStep(1.0);
    doubleSpinBoxInitV->setDecimals(2);
    doubleSpinBoxDt = new QDoubleSpinBox;
    doubleSpinBoxDt->setMinimum(1e-6);
    doubleSpinBoxDt->setMaximum(1.0);
    doubleSpinBoxDt->setSingleStep(0.001);
    doubleSpinBoxDt->setDecimals(6);
    doubleSpinBoxDt->setValue(0.001);

    doubleSpinBoxInitX->setValue(1.0);

    pushButtonStart = new QPushButton("Start");
    pushButtonStop = new QPushButton("Stop");

    textEditLog = new QTextEdit;
    textEditLog->setReadOnly(true);

    QGridLayout *layoutParameters = new QGridLayout;
    layoutParameters->addWidget(labelM, 0, 0);
    layoutParameters->addWidget(labelGamma, 1, 0);
    layoutParameters->addWidget(labelK, 2, 0);
    layoutParameters->addWidget(doubleSpinBoxM, 0, 1);
    layoutParameters->addWidget(doubleSpinBoxGamma, 1, 1);
    layoutParameters->addWidget(doubleSpinBoxK, 2, 1);
    layoutParameters->addWidget(labelInitX, 0, 2);
    layoutParameters->addWidget(labelInitV, 1, 2);
    layoutParameters->addWidget(labelDt, 2, 2);
    layoutParameters->addWidget(doubleSpinBoxInitX, 0, 3);
    layoutParameters->addWidget(doubleSpinBoxInitV, 1, 3);
    layoutParameters->addWidget(doubleSpinBoxDt, 2, 3);

    QHBoxLayout *layoutButtons = new QHBoxLayout;
    layoutButtons->addWidget(pushButtonStart);
    layoutButtons->addWidget(pushButtonStop);

    QVBoxLayout *layoutMain = new QVBoxLayout;
    layoutMain->addLayout(layoutParameters);
    layoutMain->addLayout(layoutButtons);
    layoutMain->addWidget(textEditLog);

    this->setLayout(layoutMain);

    //Qt4: connect(pushButtonStart, SIGNAL(clicked()), this, SLOT(startCalculation()));
    connect(pushButtonStart, &QPushButton::clicked, this, &Form::startCalculation);
    connect(pushButtonStop, &QPushButton::clicked, this, &Form::stopCalculation);
    connect(timer, &QTimer::timeout, this, &Form::makeStep);
}

Form::~Form()
{
    delete system;
}

void Form::startCalculation()
{
    textEditLog->clear();
    delete system;
    system = new DynSystem(doubleSpinBoxM->value(),
                           doubleSpinBoxGamma->value(),
                           doubleSpinBoxK->value(),
                           doubleSpinBoxInitX->value(),
                           doubleSpinBoxInitV->value(),
                           0.0,
                           doubleSpinBoxDt->value());
    textEditLog->append("system created");
    textEditLog->append("parameters:");
    textEditLog->append("mass = " + QString::number(system->m()));
    textEditLog->append(QString("%1\t%2\t%3")
                        .arg(system->t())
                        .arg(system->x())
                        .arg(system->v()));
    timer->start();
}

void Form::stopCalculation()
{
    timer->stop();
}

void Form::makeStep()
{
    for (int i = 0; i < 10; ++i)
    {
        system->step();
        textEditLog->append(QString("%1\t%2\t%3")
                            .arg(system->t())
                            .arg(system->x())
                           .arg(system->v()));
    }
}

