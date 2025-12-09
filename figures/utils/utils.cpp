#include "figures/utils/utils.hpp"
#include "utils.hpp"

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

top::p_t top::hSegNext(p_t curr, p_t start, size_t len)
{
  if (curr.x - start.x < len)
  {
    return {curr.x + 1, curr.y};
  }
  return start;
}

top::p_t top::vSegNext(p_t curr, p_t start, size_t len)
{
  if (curr.y - start.y < len)
    return {curr.x, curr.y + 1};
  return start;
}

top::p_t top::rectangleNext(p_t curr, p_t left_bottom, size_t w, size_t h)
{
  if (curr.x == left_bottom.x && curr.y < left_bottom.y + h)
  {
    return vSegNext(curr, left_bottom, h);
  }
  else if (curr.y == left_bottom.y + h && curr.x < left_bottom.x + w)
  {
    return hSegNext(curr, left_bottom, w);
  }
  else if (curr.x == left_bottom.x + w && curr.y > left_bottom.y)
  {
    return {curr.x, curr.y - 1};
  }
  else if (curr.y == left_bottom.y && curr.x > left_bottom.x)
  {
    return {curr.x - 1, curr.y};
  }
  return left_bottom;
}

top::p_t top::filledRectangleNext(p_t curr, p_t left_bottom, size_t w, size_t h)
{
  if (curr.x - left_bottom.x < w)
  {
    return hSegNext(curr, left_bottom, w);
  }
  else if (curr.y - left_bottom.y < h)
  {
    return {left_bottom.x, curr.y + 1};
  }
  return left_bottom;
}
