#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "convexhull.h"
#include "dialogdrawboard.h"
#include "point.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    ConvexHull *ch;

private slots:

    void on_initialButton_clicked();

    void on_addButton_clicked();

    void on_openPaintBoard_clicked();

private:
    Ui::MainWindow *ui;
    DialogDrawBoard* drawboard;
    void checkmax(int&,int&);
    double maxNum=0;

};
#endif // MAINWINDOW_H
