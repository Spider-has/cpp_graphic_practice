#ifndef RECTANGLE
#define RECTANGLE

#include <figures/IDraw.hpp>
#include <figures/utils/utils.hpp>
namespace top
{

  struct Rectangle : IDraw
  {
    Rectangle(p_t left_bot, size_t width, size_t height);
    p_t begin() const override;
    p_t next(p_t curr) const override;

  private:
    p_t left_bottom;
    size_t w, h;
  };
}

#endif