#include "figures/Square/Square.hpp"

top::Square::Square(p_t left_bot, int width):
    left_bottom(left_bot),
    w(width - 1)
{
}

top::p_t top::Square::begin() const
{
  return left_bottom;
}

top::p_t top::Square::next(p_t curr) const
{
  return RectangleNext(curr, left_bottom, w, w);
}
