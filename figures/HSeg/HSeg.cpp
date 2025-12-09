#include <figures/HSeg/HSeg.hpp>

top::Hseg::Hseg(p_t start, size_t length):
    start_(start),
    length_(length ? length - 1 : 0)
{
  if (!length)
  {
    throw std::invalid_argument("horizontal segment length must be more than zero");
  }
}

top::p_t top::Hseg::begin() const
{
  return start_;
}

top::p_t top::Hseg::next(p_t curr) const
{
  return hSegNext(curr, start_, length_);
}
