#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include <QLabel>
#include <QDoubleSpinBox>
#include <QPushButton>
#include <QTextEdit>

#include <QTimer>

#include <qwt_plot.h>

#include "dynsystem.h"

class Form : public QWidget
{
    Q_OBJECT

public:
    Form(QWidget *parent = nullptr);
    ~Form();

public slots:
    void startCalculation();
    void stopCalculation();
    void makeStep();

private:
    QLabel *labelM;
    QLabel *labelGamma;
    QLabel *labelK;
    QLabel *labelInitX;
    QLabel *labelInitV;
    QLabel *labelDt;
    QDoubleSpinBox *doubleSpinBoxM;
    QDoubleSpinBox *doubleSpinBoxGamma;
    QDoubleSpinBox *doubleSpinBoxK;
    QDoubleSpinBox *doubleSpinBoxInitX;
    QDoubleSpinBox *doubleSpinBoxInitV;
    QDoubleSpinBox *doubleSpinBoxDt;
    QPushButton *pushButtonStart;
    QPushButton *pushButtonStop;
    QTextEdit *textEditLog;

    QwtPlot *plotTime;
    QwtPlot *plotPhase;

    QTimer * timer;

    DynSystem *system;
};
#endif // FORM_H
