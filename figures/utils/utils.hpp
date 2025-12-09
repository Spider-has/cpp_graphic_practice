#ifndef FIGURE_UTILS
#define FIGURE_UTILS

#include "figures/IDraw.hpp"
#include "pod/pod.hpp"
#include <iostream>

namespace top
{
  size_t count(IDraw &d);
  size_t getPoints(const IDraw &figure, p_t **ps, size_t &size);

  p_t hSegNext(p_t curr, p_t start, size_t len);
  p_t vSegNext(p_t curr, p_t start, size_t len);

  p_t rectangleNext(p_t curr, p_t left_bottom, size_t w, size_t h);
  p_t filledRectangleNext(p_t curr, p_t left_bottom, size_t w, size_t h);
}

#endif