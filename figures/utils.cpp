#include <figures/utils.hpp>

size_t top::count(IDraw &d)
{
  {
    size_t k = 0;
    p_t p = d.begin();
    while (d.next(p) != d.begin())
    {
      k++;
      p = d.next(p);
    }
    return k;
  }
}

void top::makeFigures(IDraw **f, size_t size)
{
  f[0] = new FilledSquare({25, 5}, 7);
  f[1] = new Rectangle({-10, 10}, 10, 3);
  f[2] = new FilledRectangle({10, 0}, 3, 4);
}

size_t top::getPoints(const IDraw &figure, p_t **ps, size_t &size)
{
  size_t initial = size;
  p_t curr_point = figure.begin();
  extend(ps, size, curr_point);
  size_t count = size;
  while (figure.begin() != figure.next(curr_point))
  {

    curr_point = figure.next(curr_point);
    extend(ps, size, curr_point);
    count++;
  }
  return count - initial;
}
