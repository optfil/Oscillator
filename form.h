#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include <QLabel>
#include <QDoubleSpinBox>
#include <QPushButton>
#include <QTextEdit>

class Form : public QWidget
{
    Q_OBJECT

public:
    Form(QWidget *parent = nullptr);
    ~Form();

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
};
#endif // FORM_H
