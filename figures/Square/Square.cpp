#include "figures/Square/Square.hpp"

top::Square::Square(p_t left_bot, size_t width):
    left_bottom(left_bot),
    w(width ? width - 1 : 0)
{
  if (!width)
  {
    throw std::invalid_argument(" square side must be more than zero");
  }
}

top::p_t top::Square::begin() const
{
  return left_bottom;
}

top::p_t top::Square::next(p_t curr) const
{
  return rectangleNext(curr, left_bottom, w, w);
}
