#include "geom.hpp"
#include <stdexcept>
bool top::operator==(p_t a, p_t b)
{
  return a.x == b.x && a.y == b.y;
}

bool top::operator!=(p_t a, p_t b)
{
  return !(a == b);
}

size_t top::cols(frame_t f)
{
  return f.right_top.x - f.left_bot.x + 1;
}
size_t top::rows(frame_t f)
{
  return f.right_top.y - f.left_bot.y + 1;
}

top::frame_t top::buildFrame(const p_t *ps, size_t s)
{
  if (ps && s)
  {
    int left = ps[0].x;
    int bottom = ps[0].y;
    int right = ps[0].x;
    int top = ps[0].y;
    for (size_t i = 0; i < s; i++)
    {
      if (ps[i].x < left)
      {
        left = ps[i].x;
      }
      else if (ps[i].x > right)
      {
        right = ps[i].x;
      }
      if (ps[i].y < bottom)
      {
        bottom = ps[i].y;
      }
      else if (ps[i].y > top)
      {
        top = ps[i].y;
      }
    }
    return frame_t{{left, bottom}, {right, top}};
  }
  throw std::runtime_error("points array is empty");
}