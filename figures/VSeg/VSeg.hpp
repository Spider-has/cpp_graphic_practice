#ifndef VSEG
#define VSEG

#include <figures/IDraw.hpp>
#include <figures/utils/utils.hpp>

namespace top
{
  struct Vseg : IDraw
  {

    Vseg(p_t start, size_t length);
    p_t begin() const override;
    p_t next(p_t) const override;

  private:
    p_t start_;
    size_t length_;
  };
}

#endif