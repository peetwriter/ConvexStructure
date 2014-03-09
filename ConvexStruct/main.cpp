#include <iostream>
#include <vector>
#include <segment.h>

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
        vector<Point> maxDistPoints();
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

}

using namespace convstr;
int main()
{
   vector<Point> points;
   Point* point1  = new Point(1.0, 1.0, 1.0);
   Point* point2  = new Point(2.0, 2.0, 2.0);
   Point* point3  = new Point(1.0, 2.0, 3.0);

   points.push_back(*point1);
   points.push_back(*point2);
   points.push_back(*point3);

   vector<Point> maxp = maxIterDist(points.begin(), points.end());
   //Segment* maxSegments = maxDist(points);
   cout<< maxp[0].dist(maxp[1]) << endl;

}

