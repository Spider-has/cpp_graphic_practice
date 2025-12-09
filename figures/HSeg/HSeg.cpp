#include <figures/HSeg/HSeg.hpp>

top::Hseg::Hseg(p_t start, size_t length):
    start_(start),
    length_(length - 1)
{
  if (!length)
  {
    throw std::runtime_error("length of seg can't be zero");
  }
}

top::p_t top::Hseg::begin() const
{
  return start_;
}

top::p_t top::Hseg::next(p_t curr) const
{
  return HSegNext(curr, start_, length_);
}
