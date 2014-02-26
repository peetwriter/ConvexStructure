#include <iostream>
#include <math.h>

using namespace std;

class Point {
private:
        double xval, yval, zval;
public:
        Point(double x = 0.0, double y = 0.0, double z = 0.0) {
                xval = x;
                yval = y;
                zval = z;
        }

        double x() { return xval; }
        double y() { return yval; }
        double z() { return zval; }

        double dist(Point other) {
                double xd = xval - other.xval;
                double yd = yval - other.yval;
                double zd = zval - other.zval;
                return sqrt(xd*xd + yd*yd + zd*zd);
        }

        Point add(Point b)
        {
                return Point(xval + b.xval, yval + b.yval , zval + b.zval);
        }

        Point sub(Point b)
        {
                return Point(xval - b.xval, yval - b.yval , zval - b.zval);
        }

        void move(double a, double b, double c)
        {
                xval += a;
                yval += b;
                zval += c;
        }

        void print(ostream &strm)
        {
                strm << "(" << xval << "," << yval << zval <<")";
        }
};
