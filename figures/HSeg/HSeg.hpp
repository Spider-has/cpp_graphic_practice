#ifndef HSEG
#define HSEG

#include <figures/IDraw.hpp>

namespace top
{
  struct Hseg : IDraw
  {

    Hseg(p_t start, size_t length);
    p_t begin() const override;
    p_t next(p_t) const override;

  private:
    p_t start_;
    size_t length_;
  };
}

#endif