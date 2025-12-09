#include <figures/FillRectangle/FillRectangle.hpp>

top::FilledRectangle::FilledRectangle(p_t left_bot, int width, int height):
    bottom(left_bot, width),
    w(width - 1),
    h(height - 1)
{
  if (height <= 0)
  {
    throw std::runtime_error("height can't be zero or lower");
  }
}
top::p_t top::FilledRectangle::begin() const
{
  return bottom.begin();
};
top::p_t top::FilledRectangle::next(p_t curr) const
{
  if (curr.x - bottom.begin().x < w)
  {
    return bottom.next(curr);
  }
  else if (curr.y - bottom.begin().y < h)
  {
    return {bottom.begin().x, curr.y + 1};
  }
  return bottom.begin();
}
