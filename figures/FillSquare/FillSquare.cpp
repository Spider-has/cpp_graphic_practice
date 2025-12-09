
#include <figures/FillSquare/FillSquare.hpp>

top::FilledSquare::FilledSquare(p_t left_bot, size_t width):
    left_bottom(left_bot),
    w(width ? width - 1 : 0)
{
  if (!width)
  {
    throw std::invalid_argument("filled square side must be more than zero");
  }
}

top::p_t top::FilledSquare::begin() const
{
  return left_bottom;
};

top::p_t top::FilledSquare::next(p_t curr) const
{
  return filledRectangleNext(curr, left_bottom, w, w);
};