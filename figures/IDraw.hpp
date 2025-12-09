#ifndef IDRAW
#define IDRAW

#include "canvas/canvas.hpp"
#include "pod/pod.hpp"

namespace top
{
  struct IDraw
  {
    virtual p_t begin() const = 0;
    virtual p_t next(p_t) const = 0;

    virtual ~IDraw() = default;
  };

  // TODO:: Круг
  // TODO:: косая линия

}

#endif