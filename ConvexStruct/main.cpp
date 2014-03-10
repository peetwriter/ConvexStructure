#include <iostream>
#include <vector>
#include <segment.h>
#include <convect.h>

using namespace std;

namespace  convstr{
   Segment* maxDist(vector<Point> inPoints )
    {
        double maxDist = 0;
        vector<Point> maxDistPoints(2);
        for(int i=0; i< inPoints.size(); i++)
        {
            for(int j=0; j< inPoints.size(); j++)
            {
                if (inPoints[i].dist(inPoints[j]) > maxDist)
                {
                    maxDist = inPoints[i].dist(inPoints[j]);
                    maxDistPoints[0] = inPoints[i];
                    maxDistPoints[1] = inPoints[j];
                }
            }
        }
        return new Segment(maxDistPoints[0], maxDistPoints[1]);
    }

   vector<Point> maxIterDist(vector<Point>::iterator stp, vector<Point>::iterator endp){
        double maxDist = 0;
        vector<Point> maxDistPoints(2);
        for(vector<Point>::iterator i = stp; i!= endp; i++)
        {
            for(vector<Point>::iterator j = stp; j!= endp; j++)
            {
                if (i->dist(*j) > maxDist){
                    maxDist = i->dist(*j);
                    maxDistPoints[0] = *i;
                    maxDistPoints[1] = *j;
                }
            }
        }
        return maxDistPoints;
    }

    bool checkPoints(vector<Point> points){
       //check if there are more than 3 points
        cout<< points.size()<<endl;
       if (points.size() < 4) {
            cout<<"there is not enough points to build a convex"<<endl;
            return false;
       }

       //check if points is on one line:
       double result = 0;
       conVect* vect1 = new conVect();
       conVect* vect2 = new conVect();
       conVect* vect3 = new conVect();
       vector<Point> maxDist = maxIterDist(points.begin(), points.end());
       for (vector<Point>::iterator i = points.begin(); i != points.end(); i++ ){
           vect1->x_ = maxDist[0].x() - i->x();
           vect1->z_ = maxDist[0].z() - i->z();
           vect1->y_ = maxDist[0].y() - i->y();

           vect2->x_ = maxDist[1].x() - i->x();
           vect2->z_ = maxDist[1].z() - i->z();
           vect2->y_ = maxDist[1].y() - i->y();
           vect3->crossPr(vect1, vect2);
           result += vect3->x()*vect3->x() + vect3->y()*vect3->y() + vect3->z()*vect3->z();
       }
       if(result == 0){
           cout<<"all points is on one line"<<endl;
           return false;
        }

       //check if points not on one plane
       for (vector<Point>::iterator i = points.begin(); i != points.end(); i++ ){

       }
    }

    double distPointToSegment(Point point, vector<Point> segment){
        conVect* vect1 = new conVect(point.x(), point.y(), point.z());
        conVect* vect2 = new conVect(segment[0].x(), segment[0].y(), segment[0].z());
        conVect* vect3 = new conVect(segment[0].x(), segment[0].y(), segment[0].z());
        conVect resv = vect3 - vect2;
        //double d = ((vect3 - vect2).crossPr(vect2 - vect1)).vecLength();
        //return resv.x_;
        return 5;
    }
}

using namespace convstr;
int main()
{
   vector<Point> points;
   Point* point1  = new Point(1.0, 1.0, 0.0);
   Point* point2  = new Point(4.0, 1.0, 0.0);
   Point* point3  = new Point(2.0, 2.0, 0.0);
   Point* point4  = new Point(4.0, 4.0, 0.0);

   points.push_back(*point1);
   points.push_back(*point2);
   points.push_back(*point3);
   points.push_back(*point4);

   vector<Point> newPoints;
   newPoints.push_back(*point1);
   newPoints.push_back(*point2);
   cout<<"distance: "<< distPointToSegment(*point3, newPoints);

   vector<Point> maxp = maxIterDist(points.begin(), points.end());
   bool res  = checkPoints(points);
   //Segment* maxSegments = maxDist(points);
   cout<< maxp[0].dist(maxp[1]) << endl;


}

