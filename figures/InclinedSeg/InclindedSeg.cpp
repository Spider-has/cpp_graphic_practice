#include "InclindedSeg.hpp"
#include <figures/InclinedSeg/InclindedSeg.hpp>

top::InclinedSeg::InclinedSeg(p_t left_bot, size_t length):
    start(left_bot),
    length_(length ? length - 1 : 0)
{
  if (!length)
  {
    throw std::invalid_argument("inclined segment length must be more than zero");
  }
}

top::p_t top::InclinedSeg::begin() const
{
  return start;
}

top::p_t top::InclinedSeg::next(p_t curr) const
{
  if (curr.x - start.x < length_)
  {
    return {curr.x + 1, curr.y + 1};
  }
  return start;
}
