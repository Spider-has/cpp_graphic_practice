#ifndef DOT_HPP
#define DOT_HPP

#include "idraw.hpp"

namespace top
{
  struct Dot : IDraw
  {
    Dot(int x, int y);
    p_t begin() const override;
    p_t next(p_t) const override;

  private:
    p_t o;
  };
}

#endif