#include "convexhull.h"
#include "cmath"
#include <sstream>

ConvexHull::ConvexHull(int n, point* np,DialogDrawBoard* db):n(n),db(db) { //构造函数
    basePoint = np[0]; //获取初值
    for (int i = 0; i < n; i++) { //复制点
        p.push_back(np[i]);
        if (basePoint.y > np[i].y) {
            basePoint = np[i];
        }
    }
    db->setList(&p,&q);
}
void ConvexHull::run(){
    initial();
}
void ConvexHull::initial(){
    //计算每个点相对基准点的极角
    for (int i = 0; i < n; i++) { //复制点
        p[i].w = calcArch(basePoint, p[i]);
    }
    //对每个点按照极角降序排序，如果角度相同，按与基准点距离升序排列
    for (int i = 0; i < n; i++) {
        bool sorted=true;
        for (int j = i + 1; j < n; j++) {
            if (p[i].w < p[j].w){
                swap(p[i], p[j]);
                sorted=0;
            }
            else if (p[i].w == p[j].w) {
                if (calcDistance(basePoint, p[i]) > calcDistance(basePoint, p[j])) {
                    swap(p[i], p[j]);
                    sorted=0;
                }
            }
        }
        if(sorted) break;
    }
    //画线

    //新建队列
    while(q.size())q.pop_back();
    //入点 0点和1点
    q.push_back(p[0]);
    db->update();
    db->sleep();
    if(p.size()>1){
        q.push_back(p[1]);
        db->update();
        db->sleep();
    }
    for (int i = 2; i < n; i++) {
        //不符合条件
        //删去顶点
        //再判断
        while (calcCross(q[q.size() - 2], q[q.size() - 1], p[i]) <= 0 && q.size() >= 2) {
            q.pop_back();
        }
        q.push_back(p[i]);
        db->update();
        db->sleep();
        //这个点符合条件
        //加进去，continue
    }
    db->finished=1;
    db->update();
}
void ConvexHull::addPoint(int x, int y){ //加点
    p.push_back(point(x,y,p.size()+1));
    if (basePoint.y > y) {
        basePoint = point(x,y);
    }
    n++;
    //initial();
}
double ConvexHull::calcArch(const point &a, const point &b) {
    double distance = sqrt((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y));
    if (distance == 0) return 2.0; //为基准点
    return (b.x - a.x) * 1.0 / distance;
}
double ConvexHull::calcDistance(const point &a, const point &b) {
    return sqrt((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y));
}
double ConvexHull::calcCross(const point &a, const point &b, const point &c) {
    return (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
}

string ConvexHull::printSelected(){
    string rs;
    for(int i=0;i<q.size();i++){
        stringstream tmp;
        tmp<<"序号："<<q[i].tag<<"，坐标：("<<q[i].x<<","<<q[i].y<<")";
        rs=rs+tmp.str()+"\n";
    }
    return rs;
}
string ConvexHull::printAll(){
    string rs;
    for(int i=0;i<p.size();i++){
        stringstream tmp;
        tmp<<"序号："<<p[i].tag<<"，坐标：("<<p[i].x<<","<<p[i].y<<")";
        rs=rs+tmp.str()+"\n";
    }
    return rs;
}
