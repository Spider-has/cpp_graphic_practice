#include <figures/Rectangle/Rectangle.hpp>

top::Rectangle::Rectangle(p_t left_bot, int width, int height):
    left_bottom(left_bot),
    w(width - 1),
    h(height - 1)
{
}

top::p_t top::Rectangle::begin() const
{
  return left_bottom;
}

top::p_t top::Rectangle::next(p_t curr) const
{
  return RectangleNext(curr, left_bottom, w, h);
}
