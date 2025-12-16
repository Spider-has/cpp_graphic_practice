#ifndef IDRAW_HPP
#define IDRAW_HPP

#include "geom.hpp"
#include <cstddef>

namespace top
{
  struct IDraw
  {
    virtual p_t begin() const = 0;
    virtual p_t next(p_t) const = 0;

    virtual ~IDraw() = default;
  };

  size_t getPoints(const IDraw &figure, p_t **ps, size_t &size);
}

#endif