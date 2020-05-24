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
    double calcArch(const point &a, const point &b);
    double calcDistance(const point &a, const point &b);
    double calcCross(const point &a, const point &b, const point &c);
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
