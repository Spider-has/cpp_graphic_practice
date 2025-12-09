#ifndef INCLINED_LINE
#define INCLINED_LINE

#include "figures/IDraw.hpp"

namespace top
{
  struct InclinedSeg : IDraw
  {
    InclinedSeg(p_t left_bot, size_t length);
    p_t begin() const override;
    p_t next(p_t curr) const override;

  private:
    p_t start;
    size_t length_;
  };
}

#endif