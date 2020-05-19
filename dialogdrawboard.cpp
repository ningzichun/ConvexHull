#include "dialogdrawboard.h"
#include "ui_dialogdrawboard.h"


DialogDrawBoard::DialogDrawBoard(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogDrawBoard)
{
    ui->setupUi(this);
    this->resize(800,800);
}

DialogDrawBoard::~DialogDrawBoard()
{
    delete ui;
}

void DialogDrawBoard::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
    QPen pen(QColor(100,100,100));
    pen.setWidth(1);
    painter.setPen(pen);
    painter.drawLine(0,400,800,400);
    painter.drawLine(400,0,400,800);
    painter.drawLine(400,0,380,20);
    painter.drawLine(400,0,420,20);
    painter.drawLine(800,400,780,380);
    painter.drawLine(800,400,780,420);
    painter.drawText(790,401,"x");
    painter.drawText(401,10,"y");

    painter.translate(base,base);
    painter.scale(scaleRate,scaleRate);

    pen.setWidth(1);
    pen.setColor(QColor(50,50,50));
    painter.setPen(pen);
    for(int i=0;i<p->size();i++){
        painter.drawText((*p)[i].x,(*p)[i].y,QString::number((*p)[i].tag));
    }

    pen.setColor(QColor(20,20,20));
    pen.setWidth(1);
    painter.setPen(pen);

    for(int i=1;i<q->size();i++){
        painter.drawLine((*q)[i-1].x,(*q)[i-1].y,(*q)[i].x,(*q)[i].y);
    }
    painter.drawLine((*q)[0].x,(*q)[0].y,(*q)[q->size()-1].x,(*q)[q->size()-1].y);


    pen.setWidth(3);
    pen.setColor(QColor(0,0,0));
    painter.setPen(pen);
    for(int i=0;i<p->size();i++){
        painter.drawPoint((*p)[i].x,(*p)[i].y);
    }
}
void DialogDrawBoard::setMax(double theMax,int delay){
    this->delay=delay;
    base=400;
    scaleRate=380/theMax;
}

void DialogDrawBoard::setList(vector<point> *pp,vector<point>*qq){
    p=pp;
    q=qq;
    update();
}

void DialogDrawBoard::sleep(){
    if(delay){
        Sleep(delay);
    }
}
