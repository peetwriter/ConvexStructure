#ifndef CONVECT_H
#define CONVECT_H
#include <point.hh>

class conVect
{
public:
  conVect() : x_(0),y_(0),z_(0) {}
  conVect(double x,double y, double z) : x_(x), y_(y), z_(z) {}
  double x() { return x_; }
  double y() { return y_; }
  double z() { return z_; }
  conVect& operator +=(const conVect& rhs)
  {
    x_ += rhs.x_;
    y_ += rhs.y_;
    z_ += rhs.z_;
    return *this;

  }
  conVect& operator -=(const conVect& rhs)
  {
      x_ -= rhs.x_;
      y_ -= rhs.y_;
      z_ -= rhs.z_;
      return *this;
  }

  conVect& operator -(conVect& rhs)
  {
      x_ -= rhs.x_;
      y_ -= rhs.y_;
      z_ -= rhs.z_;
      return *this;
  }

  conVect& operator -=(Point& rhs)
  {
      x_ -= rhs.x();
      y_ -= rhs.y();
      z_ -= rhs.z();
      return *this;
  }

  conVect& operator -(Point& rhs)
  {
      x_ -= rhs.x();
      y_ -= rhs.y();
      z_ -= rhs.z();
      return *this;
  }

  template <typename Scalar>
  conVect& operator *=(const Scalar& scalar)
  {
    x_ *+ scalar;
    y_ *+ scalar;
    z_ *+ scalar;
    return *this;
  }  
  conVect& crossPr(conVect* vec1, conVect* vec2){
      x_ = vec1->y_*vec2->z_ - vec1->z_*vec2->y_;
      y_ = vec1->z_*vec2->x_ - vec1->x_*vec2->z_;
      z_ = vec1->x_*vec2->y_ - vec1->y_*vec2->x_;
      return *this;
  }
  double vecLength(){
      return sqrt(x_*x_+ y_*y_+ z_*z_);
  }

 double x_, y_, z_;
};

#endif // CONVECT_H
