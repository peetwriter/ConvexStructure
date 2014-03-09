#ifndef SEGMENT_H
#define SEGMENT_H

#include <point.hh>

class Segment
{
public:
    Segment() : p1(0,0,0), p2(0,0,0){} ;
    Segment(Point pst, Point pend)
    {
        p1 = pst;
        p2 = pend;
    };
    double length(){
        return p1.dist(p2);
    }
    Point p1;
    Point p2;
};

#endif // SEGMENT_H
