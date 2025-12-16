#include <iostream>

#include "ascii_draw.hpp"

int main()
{
  using namespace top;
  IDraw *f[10] = {};
  p_t *p = nullptr;
  size_t s = 0;
  size_t figure_k = 3;

  char *cnv = nullptr;

  int err = 0;
  try
  {
    f[0] = new top::Dot(0, 0);
    f[1] = new top::Dot(10, 10);
    f[2] = new top::Dot(-10, -10);
    for (size_t i = 0; i < figure_k; i++)
    {
      getPoints(*f[i], &p, s);
    }
    frame_t frame = buildFrame(p, s);
    cnv = buildCanvas(frame);
    paintCanvas(cnv, frame, p, s, '#');
    printCanvas(std::cout, cnv, frame);
  }
  catch (...)
  {
    err = 1;
  }

  for (size_t i = 0; i < figure_k; i++)
  {
    delete f[i];
  }
  delete[] p;
  delete[] cnv;
  return err;
}
