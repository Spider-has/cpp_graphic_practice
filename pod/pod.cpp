#include <pod/pod.hpp>

top::p_t *top::extanded(const p_t *old, size_t old_s, size_t new_s)
{
  p_t *new_ps = new p_t[new_s];
  for (size_t i = 0; i < old_s; i++)
  {
    new_ps[i] = old[i];
  }
  return new_ps;
}

void top::extend(p_t **old, size_t &old_s, p_t new_pt)
{
  p_t *new_arr = extanded((*old), old_s, old_s + 1);
  delete[] (*old);
  (*old) = new_arr;
  (*old)[old_s] = new_pt;
  old_s++;
}

bool top::operator==(p_t a, p_t b)
{
  return a.x == b.x && a.y == b.y;
}

bool top::operator!=(p_t a, p_t b)
{
  return !(a == b);
}