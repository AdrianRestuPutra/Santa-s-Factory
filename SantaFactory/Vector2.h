#ifndef VECTOR2_H
#define VECTOR2_H

class Vector2 {
  public:
    int x, y;

    Vector2();
    Vector2(int x, int y);

  Vector2 &operator += (const Vector2 &rhs) {
    x += rhs.x;
    y += rhs.y;
    return *this;
  }
  
  Vector2 &operator -= (const Vector2 &rhs) {
    x -= rhs.x;
    y -= rhs.y;
    return *this;
  }

  Vector2 &operator = (const Vector2 &rhs) {
    x = rhs.x;
    y = rhs.y;
    return *this;
  }
};

#endif
