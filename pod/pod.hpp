#ifndef COMMON
#define COMMON

#include <iostream>

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

  p_t *extanded(const p_t *old, size_t old_s, size_t new_s);

  void extend(p_t **old, size_t &old_s, p_t new_pt);
}

#endif