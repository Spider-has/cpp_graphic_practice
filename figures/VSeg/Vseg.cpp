
#include <figures/VSeg/VSeg.hpp>

top::Vseg::Vseg(p_t start, size_t length):
    start_(start),
    length_(length ? length - 1 : 0)
{
  if (!length)
  {
    throw std::invalid_argument("vertical segment length must be more than zero");
  }
}

top::p_t top::Vseg::begin() const
{
  return start_;
}

top::p_t top::Vseg::next(p_t curr) const
{
  return vSegNext(curr, start_, length_);
}