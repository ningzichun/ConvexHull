#ifndef CONVEXHULL_H
#define CONVEXHULL_H

#include <iostream>
#include <vector>
#include <queue>
#include<QString>
#include<QThread>
#include "point.h"
#include "dialogdrawboard.h"

using namespace std;


class ConvexHull:public QThread {
public:
    ConvexHull(int n, point* np,DialogDrawBoard*);
    void run();
    void addPoint(int x,int y);
    double calcArch(point a, point b);
    double calcDistance(point a,point b) ;
    double calcCross(point a, point b, point c);
    string printSelected();
    string printAll();
    point basePoint;
private:
    int n;
    vector<point> p;
    vector<point> q;
    DialogDrawBoard* db;
    void initial();
};

#endif // CONVEXHULL_H
