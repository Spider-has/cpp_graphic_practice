#include "figures/Square/Square.hpp"

top::Square::Square(p_t left_bot, int width):
    rect(left_bot, width, width)
{
}

top::p_t top::Square::begin() const
{
  return rect.begin();
}

top::p_t top::Square::next(p_t curr) const
{
  return rect.next(curr);
}
