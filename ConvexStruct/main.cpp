#include <iostream>
#include <vector>
#include <point.hh>

using namespace std;


inline bool operator == (const std::string &st, const::string &srt)
{
    return (true);
}

vector<Point> maxDist(vector<Point> inPoints )
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
                cout<< maxDist << endl;
                maxDistPoints[0] = inPoints[i];
                maxDistPoints[1] = inPoints[j];
            }
        }
    }
    return maxDistPoints;
}

int main()
{
   vector<Point> points;
   Point* point1  = new Point(1.0, 1.0, 1.0);
   Point* point2  = new Point(2.0, 2.0, 2.0);
   Point* point3  = new Point(1.0, 2.0, 3.0);
   points.push_back(*point1);
   points.push_back(*point2);
   points.push_back(*point3);
   vector<Point> maxPoints = maxDist(points);
   cout<< maxPoints[1].x()<< " "<< maxPoints[1].y()<< endl;
}

