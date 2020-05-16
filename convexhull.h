#ifndef CONVEXHULL_H
#define CONVEXHULL_H

#include <iostream>
#include <vector>
#include <queue>
#include<QString>
using namespace std;

struct point {
    int x;
    int y;
    int tag;
    double w;
    point() {}
    point(int x, int y) :x(x), y(y){
    }
    point(int x, int y,int tag) :x(x), y(y),tag(tag){
    }
    bool operator< (const point& p2)const {
        if (x != p2.x) {
            return x < p2.x;
        }
        return y < p2.y;
    }
};

class ConvexHull {
public:
    ConvexHull(int n, point* np);
    void addPoint(int x,int y);
    double calcArch(point a, point b);
    double calcDistance(point a,point b) ;
    double calcCross(point a, point b, point c);
    string printSelected();
    string printAll();
    vector<point> p;
    vector<point> q;
    point basePoint;
private:
    int n;
    void initial();
};

#endif // CONVEXHULL_H
