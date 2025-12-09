#ifndef FIGURE_INDEX
#define FIGURE_INDEX

#include "figures/Dot/Dot.hpp"
#include "figures/IDraw.hpp"
#include <figures/FillRectangle/FillRectangle.hpp>
#include <figures/FillSquare/FillSquare.hpp>
#include <figures/HSeg/HSeg.hpp>
#include <figures/Rectangle/Rectangle.hpp>
#include <figures/Square/Square.hpp>
#include <figures/VSeg/VSeg.hpp>
#include <figures/utils/utils.hpp>
#include <iostream>

namespace top
{
  void makeFigures(IDraw **f, size_t &size);
}

#endif