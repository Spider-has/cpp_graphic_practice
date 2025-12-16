#include "idraw.hpp"

namespace
{
  top::p_t *extanded(const top::p_t *old, size_t old_s, size_t new_s)
  {
    using namespace top;
    p_t *new_ps = new p_t[new_s];
    for (size_t i = 0; i < old_s; i++)
    {
      new_ps[i] = old[i];
    }
    return new_ps;
  }

  void extend(top::p_t **old, size_t &old_s, top::p_t new_pt)
  {
    using namespace top;
    p_t *new_arr = extanded((*old), old_s, old_s + 1);
    delete[] (*old);
    (*old) = new_arr;
    (*old)[old_s] = new_pt;
    old_s++;
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