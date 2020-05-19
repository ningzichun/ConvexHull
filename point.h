#ifndef POINT_H
#define POINT_H
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

#endif // POINT_H
