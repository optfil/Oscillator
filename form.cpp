#include "form.h"

#include <QLayout>

Form::Form(QWidget *parent)
    : QWidget(parent)
{
    labelM = new QLabel("mass");
    labelGamma = new QLabel("gamma");
    labelK = new QLabel("rigidity");
    labelInitX = new QLabel("initial coordinate");
    labelInitV = new QLabel("initial velocity");
    labelDt = new QLabel("time step");

    doubleSpinBoxM = new QDoubleSpinBox;
    doubleSpinBoxGamma = new QDoubleSpinBox;
    doubleSpinBoxK = new QDoubleSpinBox;
    doubleSpinBoxInitX = new QDoubleSpinBox;
    doubleSpinBoxInitV = new QDoubleSpinBox;
    doubleSpinBoxDt = new QDoubleSpinBox;

    pushButtonStart = new QPushButton("Start");
    pushButtonStop = new QPushButton("Stop");

    textEditLog = new QTextEdit;

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
}

Form::~Form()
{
}

