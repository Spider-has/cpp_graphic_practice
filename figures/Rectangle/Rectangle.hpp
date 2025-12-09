#ifndef RECTANGLE
#define RECTANGLE

#include <figures/HSeg/HSeg.hpp>
#include <figures/IDraw.hpp>
#include <figures/VSeg/VSeg.hpp>
#include <figures/utils/utils.hpp>
namespace top
{

  struct Rectangle : IDraw
  {
    Rectangle(p_t left_bot, int width, int height);
    p_t begin() const override;
    p_t next(p_t curr) const override;

  private:
    p_t left_bottom;
    size_t w, h;
  };
}

#endif