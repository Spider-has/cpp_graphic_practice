#include <figures/index.hpp>

void top::makeFigures(IDraw **f, size_t &size)
{
  f[0] = new Square({25, 5}, 7);
  f[1] = new Vseg({5, 5}, 10);
  f[2] = new Rectangle({10, 0}, 10, 5);
  f[3] = new FilledRectangle({40, -5}, 5, 7);
  f[4] = new FilledSquare({40, 15}, 5);
  f[5] = new Hseg({40, 4}, 10);
  f[6] = new Dot(3, 3);
  f[7] = new InclinedSeg({60, 20}, 5);
  size = 8;
}