#include <figures/FillRectangle/FillRectangle.hpp>

top::FilledRectangle::FilledRectangle(p_t left_bot, size_t width, size_t height):
    left_bottom(left_bot),
    w(width ? width - 1 : 0),
    h(height ? height - 1 : 0)
{
  if (!width || !height)
  {
    throw std::invalid_argument("filled rectangle sides must be more than zero");
  }
}

top::p_t top::FilledRectangle::begin() const
{
  return left_bottom;
};

top::p_t top::FilledRectangle::next(p_t curr) const
{
  return filledRectangleNext(curr, left_bottom, w, h);
}
