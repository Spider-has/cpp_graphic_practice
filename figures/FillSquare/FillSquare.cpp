
#include <figures/FillSquare/FillSquare.hpp>

top::FilledSquare::FilledSquare(p_t left_bot, int width):
    fRect(left_bot, width, width)
{
}
top::p_t top::FilledSquare::begin() const
{
  return fRect.begin();
};
top::p_t top::FilledSquare::next(p_t curr) const
{
  return fRect.next(curr);
};