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
    for(int i=0;i<ch->p.size();i++){
        painter.drawText(ch->p[i].x,ch->p[i].y,QString::number(ch->p[i].tag));
    }

    pen.setColor(QColor(20,20,20));
    pen.setWidth(1);
    painter.setPen(pen);

    for(int i=1;i<ch->q.size();i++){
        painter.drawLine(ch->q[i-1].x,ch->q[i-1].y,ch->q[i].x,ch->q[i].y);
    }
    painter.drawLine(ch->q[0].x,ch->q[0].y,ch->q[ch->q.size()-1].x,ch->q[ch->q.size()-1].y);


    pen.setWidth(3);
    pen.setColor(QColor(0,0,0));
    painter.setPen(pen);
    for(int i=0;i<ch->p.size();i++){
        painter.drawPoint(ch->p[i].x,ch->p[i].y);
    }
}
void DialogDrawBoard::reDraw(ConvexHull* ch,double theMax){
    this->ch=ch;
    base=400;
    scaleRate=380/theMax;
    update();
}
