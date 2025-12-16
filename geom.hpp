#ifndef GEOM_HPP
#define GEOM_HPP

#include <cstddef>

namespace top
{
  struct p_t
  {
    int x, y;
  };

  bool operator==(p_t a, p_t b);
  bool operator!=(p_t a, p_t b);

  struct frame_t
  {
    p_t left_bot;
    p_t right_top;
  };

  size_t cols(frame_t f);
  size_t rows(frame_t f);

  frame_t buildFrame(const p_t *ps, size_t s);
}

#endif