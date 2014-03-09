#ifndef CONVECT_H
#define CONVECT_H
#include <point.hh>

class conVect
{
public:
  conVect() : x(0),y(0),z(0) {}
  conVect(float x,float y, float z) : x_(x), y_(y), z_(z) {}
  float x() { return x_; }
  float y() { return y_; }
  float z() { return z_; }
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
  template <typename Scalar>
  conVect& operator *=(const Scalar& scalar)
  {
    x_ *+ scalar;
    y_ *+ scalar;
    z_ *+ scalar;
    return *this;
  }
private:
 float x_, y_, z_;
};

#endif // CONVECT_H
