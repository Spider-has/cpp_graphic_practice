#ifndef DOT
#define DOT

#include <figures/IDraw.hpp>

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