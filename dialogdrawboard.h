#ifndef DIALOGDRAWBOARD_H
#define DIALOGDRAWBOARD_H

#include <QDialog>
#include <QPainter>
#include<QPen>
#include "convexhull.h"

namespace Ui {
class DialogDrawBoard;
}

class DialogDrawBoard : public QDialog
{
    Q_OBJECT

public:
    explicit DialogDrawBoard(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
    void reDraw(ConvexHull* ch,double);
    ~DialogDrawBoard();

private:
    Ui::DialogDrawBoard *ui;
    ConvexHull* ch;
    double base=400;
    double scaleRate=1;
};

#endif // DIALOGDRAWBOARD_H
