#ifndef FIGURE_UTILS
#define FIGURE_UTILS

#include "figures/Dot/Dot.hpp"
#include "figures/IDraw.hpp"
#include <figures/FillRectangle/FillRectangle.hpp>
#include <figures/FillSquare/FillSquare.hpp>
#include <figures/HSeg/HSeg.hpp>
#include <figures/Rectangle/Rectangle.hpp>
#include <figures/Square/Square.hpp>
#include <figures/VSeg/VSeg.hpp>
#include <iostream>

namespace top
{
  size_t count(IDraw &d);

  void makeFigures(IDraw **f, size_t size);

  size_t getPoints(const IDraw &figure, p_t **ps, size_t &size);
}

#endif