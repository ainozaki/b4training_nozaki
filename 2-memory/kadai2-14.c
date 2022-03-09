#include <stdio.h>

struct Point {
  int x;
  int y;
};

struct ColoredPoint {
  struct Point point;
  int color;
};

void show(struct Point *p) { printf("(%d, %d)\n", p->x, p->y); }

int main() {
  struct ColoredPoint cp;
  cp.point.x = 1;
  cp.point.y = 2;
  show(&cp.point);
  return 0;
}
