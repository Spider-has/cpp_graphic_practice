#ifndef SQUARE
#define SQUARE

#include "figures/IDraw.hpp"
#include "figures/Rectangle/Rectangle.hpp"

namespace top
{
  struct Square : IDraw
  {
    Square(p_t left_bot, int width);
    p_t begin() const override;
    p_t next(p_t curr) const override;

  private:
    Rectangle rect;
  };
}

#endif