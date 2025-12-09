#include <figures/FillRectangle/FillRectangle.hpp>

top::FilledRectangle::FilledRectangle(p_t left_bot, int width, int height):
    left_bottom(left_bot),
    w(width - 1),
    h(height - 1)
{
  if (height <= 0 || width <= 0)
  {
    throw std::runtime_error("height and width can't be zero or lower");
  }
}

top::p_t top::FilledRectangle::begin() const
{
  return left_bottom;
};

top::p_t top::FilledRectangle::next(p_t curr) const
{
  return FilledRectangleNext(curr, left_bottom, w, h);
}
