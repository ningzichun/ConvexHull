#ifndef DIALOGDRAWBOARD_H
#define DIALOGDRAWBOARD_H

#include<vector>
#include <iostream>
#include <QDialog>
#include <QPainter>
#include<QPen>
#include "point.h"
#include <windows.h>
#include <sys/stat.h>
using namespace std;

namespace Ui {
class DialogDrawBoard;
}

class DialogDrawBoard : public QDialog
{
    Q_OBJECT

public:
    explicit DialogDrawBoard(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
    void setMax(double,int);
    void setList(vector<point>*,vector<point>*);
    void sleep();
    ~DialogDrawBoard();

private:
    Ui::DialogDrawBoard *ui;
    int delay;
    vector<point>*p;
    vector<point>*q;
    double base=400;
    double scaleRate=1;
};

#endif // DIALOGDRAWBOARD_H
