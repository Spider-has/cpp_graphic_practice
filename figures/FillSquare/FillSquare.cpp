
#include <figures/FillSquare/FillSquare.hpp>

top::FilledSquare::FilledSquare(p_t left_bot, int width):
    left_bottom(left_bot),
    w(width)
{
}

top::p_t top::FilledSquare::begin() const
{
  return left_bottom;
};

top::p_t top::FilledSquare::next(p_t curr) const
{
  return FilledRectangleNext(curr, left_bottom, w, w);
};