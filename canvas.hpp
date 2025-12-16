#ifndef CANVAS_HPP
#define CANVAS_HPP

#include "geom.hpp"
#include <iosfwd>

namespace top
{
  char *buildCanvas(frame_t f);

  void paintCanvas(char *cnv, frame_t frame, const p_t *ps, size_t k, char f);

  void printCanvas(std::ostream &os, const char *cnv, frame_t fr);
}

#endif