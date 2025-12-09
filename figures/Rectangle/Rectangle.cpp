#include <figures/Rectangle/Rectangle.hpp>

top::Rectangle::Rectangle(p_t left_bot, int width, int height):
    left(p_t{left_bot.x, left_bot.y}, height),
    top(p_t{left_bot.x, left_bot.y + height - 1}, width),
    w(width - 1),
    h(height - 1)
{
}

top::p_t top::Rectangle::begin() const
{
  return left.begin();
}

top::p_t top::Rectangle::next(p_t curr) const
{
  if (curr.x == left.begin().x && curr.y < top.begin().y)
  {
    return left.next(curr);
  }
  else if (curr.y == top.begin().y && curr.x < top.begin().x + w)
  {
    return top.next(curr);
  }
  else if (curr.x == top.begin().x + w && curr.y > left.begin().y)
  {
    return {curr.x, curr.y - 1};
  }
  else if (curr.y == left.begin().y && curr.x > left.begin().x)
  {
    return {curr.x - 1, curr.y};
  }
  return left.begin();
}
