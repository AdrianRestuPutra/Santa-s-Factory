#include "Vector2.h"

Vector2::Vector2() {
  x = 0;
  y = 0;
}

Vector2::Vector2(int _x, int _y) {
  x = _x;
  y = _y;
}

Vector2 &operator + (Vector2 &lhs, const Vector2 &rhs) {
  return (lhs += rhs);
}

Vector2 &operator - (Vector2 &lhs, const Vector2 &rhs) {
  return (lhs -= rhs);
}

