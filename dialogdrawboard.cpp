#include "dialogdrawboard.h"
#include "ui_dialogdrawboard.h"


DialogDrawBoard::DialogDrawBoard(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogDrawBoard)
{
    ui->setupUi(this);
    this->resize(900,900);
}

DialogDrawBoard::~DialogDrawBoard()
{
    delete ui;
}

void DialogDrawBoard::paintEvent(QPaintEvent *event){
    if(p==NULL) return;
    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
    QPen pen(QColor(100,100,100));
    pen.setWidth(2);
    painter.setPen(pen);
    double base2=base/2;
    painter.drawLine(0,base2,base,base2);
    painter.drawLine(base2,0,base2,base);
    painter.drawLine(base2,0,base2-20,20);
    painter.drawLine(base2,0,base2+20,20);
    painter.drawLine(base,base2,base-20,base2-20);
    painter.drawLine(base,base2,base-20,base2+20);
    painter.drawText(base-10,base2+1,"x");
    painter.drawText(base2+1,10,"y");

    painter.translate(base2,base2);
    painter.scale(scaleRate,scaleRate);
    //pen.setWidth(10);
    pen.setColor(QColor(50,50,50));
    painter.setPen(pen);
    for(int i=0;i<p->size();i++){
        painter.drawText((*p)[i].x,0-(*p)[i].y,QString::number((*p)[i].tag));
    }

    pen.setColor(QColor(20,20,20));
    pen.setWidth(2);
    if(scaleRate*2<1){
        pen.setWidth(1+1.5/scaleRate);
    }
    pen.setColor(QColor(0,0,0));
    painter.setPen(pen);
    painter.setPen(pen);

    for(int i=1;i<q->size();i++){
        painter.drawLine((*q)[i-1].x,0-(*q)[i-1].y,(*q)[i].x,0-(*q)[i].y);
    }
    if(finished){
        painter.drawLine((*q)[0].x,0-(*q)[0].y,(*q)[q->size()-1].x,0-(*q)[q->size()-1].y);
    }

    pen.setWidth(3);
    if(scaleRate*3<1){
        pen.setWidth(1+2/scaleRate);
    }
    pen.setColor(QColor(0,0,0));
    painter.setPen(pen);
    for(int i=0;i<p->size();i++){
        painter.drawPoint((*p)[i].x,0-(*p)[i].y);
    }
}
void DialogDrawBoard::setMax(double theMax,int delay){
    this->delay=delay;
    base=this->size().width();
    if(this->size().height()<base)base=this->size().height(); //获取窗口大小
    scaleRate=base/2/(theMax+16);
    finished=0;
}

void DialogDrawBoard::setList(vector<point> *pp,vector<point>*qq){
    p=pp;
    q=qq;
    finished=0;
    update();
}

void DialogDrawBoard::sleep(){
    if(delay){
        Sleep(delay);
    }
}
