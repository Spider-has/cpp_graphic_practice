#ifndef FILL_RECTANGLE
#define FILL_RECTANGLE

#include <figures/HSeg/HSeg.hpp>
#include <figures/IDraw.hpp>

namespace top
{

  struct FilledRectangle : IDraw
  {
    FilledRectangle(p_t left_bot, int width, int height);
    p_t begin() const override;
    p_t next(p_t curr) const override;

  private:
    Hseg bottom;
    int w, h;
  };
}

#endif