#include "canvas.hpp"
#include <iostream>

char *top::buildCanvas(frame_t f)
{
  size_t col_count = cols(f);
  size_t row_count = rows(f);
  char *canvas = new char[row_count * col_count];
  for (size_t i = 0; i < col_count * row_count; i++)
  {
    canvas[i] = ' ';
  }
  return canvas;
}

void top::paintCanvas(char *cnv, frame_t frame, const p_t *ps, size_t k, char f)
{
  size_t col_count = cols(frame);
  size_t row_count = rows(frame);

  for (size_t i = 0; i < k; i++)
  {
    size_t row_cnv = frame.right_top.y - ps[i].y;
    size_t col_cnv = ps[i].x - frame.left_bot.x;
    cnv[row_cnv * col_count + col_cnv] = f;
  }
}

void top::printCanvas(std::ostream &os, const char *cnv, frame_t f)
{
  size_t col_count = cols(f);
  size_t row_count = rows(f);

  for (size_t i = 0; i < row_count; i++)
  {
    for (size_t j = 0; j < col_count; j++)
    {
      os << cnv[i * col_count + j];
    }
    os << "\n";
  }
}
