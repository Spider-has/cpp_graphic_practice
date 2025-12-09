
#include <figures/VSeg/VSeg.hpp>

top::Vseg::Vseg(p_t start, size_t length):
    start_(start),
    length_(length - 1)
{
  if (!length)
  {
    throw std::runtime_error("length of seg can't be zero");
  }
}

top::p_t top::Vseg::begin() const
{
  return start_;
}

top::p_t top::Vseg::next(p_t curr) const
{
  return VSegNext(curr, start_, length_);
}