#include<sstream>
#include<QDebug>
#include<QDialog>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("凸包问题");
    ch=NULL;
    drawboard=new DialogDrawBoard(this);
    drawboard->setWindowTitle("画板");
}

MainWindow::~MainWindow()
{

    QDialog d1(this);
    d1.show();
    delete ui;
}



void MainWindow::on_initialButton_clicked()
{
    maxNum=1;
    int n=ui->initialN->text().toInt();
    if(n<1) {
        return;
    }
    stringstream inputData;
    inputData<<ui->initialData->toPlainText().toStdString();
    qDebug()<<QString::fromStdString( ui->initialData->toPlainText().toStdString());

    point* p = new point[n];
    for (int i = 0; i < n; i++) {
        inputData >> p[i].x >> p[i].y;
        checkmax(p[i].x,p[i].y);
        p[i].tag = i + 1;
    }
    drawboard->setMax(maxNum,ui->inputDelay->text().toInt());

    if(ch!=NULL){
        ch->terminate();
        delete ch;
    }
    ch=new ConvexHull(n,p,drawboard);
    ch->start();

    string tmp=ch->printAll();
    ui->allPoints->setText(QString::fromStdString(tmp));
    ui->selectedPoints->setText("");

    connect(ch,&QThread::finished,[=](){
        qDebug()<<"1";
        ui->selectedPoints->append(QString::fromStdString(ch->printSelected()));
//        //this->ui->selectedPoints->setText(QString::fromStdString(ch->printSelected()));
    });

    ui->initialButton->setText("已初始化");
    drawboard->show();
}

void MainWindow::on_addButton_clicked()
{
    if(ui->newX->text().size()<1 || ui->newY->text().size()<1){
        return;
    }
    if(ch!=NULL){
        if(ch->isRunning()){
            ch->terminate();
        }
    }
    int x=ui->newX->text().toInt();
    int y=ui->newY->text().toInt();
    ui->newX->clear();
    ui->newY->clear();
    ch->addPoint(x,y);
    checkmax(x,y);
    drawboard->setMax(maxNum,ui->inputDelay->text().toInt());

    //string tmp=ch->printSelected(); //输出点集
    //ui->selectedPoints->setText(QString::fromStdString(tmp));
    ui->selectedPoints->setText("");
    string tmp=ch->printAll();
    ui->allPoints->setText(QString::fromStdString(tmp));

    ui->initialN->setText(QString::number(ui->initialN->text().toInt()+1));
    ch->start();
    drawboard->show();
}

void MainWindow::on_openPaintBoard_clicked()
{
    //if(ch==NULL) return;
    drawboard->show();
}
void MainWindow::checkmax(int &a,int &b){
    if(a>maxNum) maxNum=a;
    if(0-a>maxNum) maxNum=0-a;
    if(b>maxNum) maxNum=b;
    if(0-b>maxNum) maxNum=0-b;
}
