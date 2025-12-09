#include <figures/Rectangle/Rectangle.hpp>

top::Rectangle::Rectangle(p_t left_bot, size_t width, size_t height):
    left_bottom(left_bot),
    w(width ? width - 1 : 0),
    h(height ? height - 1 : 0)
{
  if (!width || !height)
  {
    throw std::invalid_argument("rectangle sides must be more than zero");
  }
}

top::p_t top::Rectangle::begin() const
{
  return left_bottom;
}

top::p_t top::Rectangle::next(p_t curr) const
{
  return rectangleNext(curr, left_bottom, w, h);
}
