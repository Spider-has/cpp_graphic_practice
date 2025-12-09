#ifndef FILL_SQUARE
#define FILL_SQUARE

#include <figures/FillRectangle/FillRectangle.hpp>
#include <figures/IDraw.hpp>

namespace top
{
  struct FilledSquare : IDraw
  {
    FilledSquare(p_t left_bot, int width);
    p_t begin() const override;
    p_t next(p_t curr) const override;

  private:
    p_t left_bottom;
    size_t w;
  };
}

#endif