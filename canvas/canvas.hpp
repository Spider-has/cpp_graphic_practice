#ifndef CANVAS
#define CANVAS

#include <iostream>
#include <pod/pod.hpp>

namespace top
{
  frame_t buildFrame(const p_t *ps, size_t s);

  char *buildCanvas(frame_t f);

  void paintCanvas(char *cnv, frame_t frame, const p_t *ps, size_t k, char f);

  void printCanvas(const char *cnv, frame_t fr);

  p_t *extanded(const p_t *old, size_t old_s, size_t new_s);

  void extend(p_t **old, size_t &old_s, p_t new_pt);

  size_t cols(frame_t f);
  size_t rows(frame_t f);
}

#endif