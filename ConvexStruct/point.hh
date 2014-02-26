#include <iostream>
#include <math.h>

using namespace std;

class Point {
private:
        double xval, yval;
public:
        Point(double x = 0.0, double y = 0.0) {
                xval = x;
                yval = y;
        }

        double x() { return xval; }
        double y() { return yval; }

        double dist(Point other) {
                double xd = xval - other.xval;
                double yd = yval - other.yval;
                return sqrt(xd*xd + yd*yd);
        }

        Point add(Point b)
        {
                return Point(xval + b.xval, yval + b.yval);
        }

        Point sub(Point b)
        {
                return Point(xval - b.xval, yval - b.yval);
        }

        void move(double a, double b)
        {
                xval += a;
                yval += b;
        }

        void print(ostream &strm)
        {
                strm << "(" << xval << "," << yval << ")";
        }
};
