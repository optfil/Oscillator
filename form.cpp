#include "form.h"

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
}

Form::~Form()
{
}

