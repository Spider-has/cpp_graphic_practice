#include <iostream>

#include "canvas/canvas.hpp"
#include "figures/index.hpp"
#include "pod/pod.hpp"

int main()
{
  using namespace top;
  IDraw *f[10] = {};
  p_t *p = nullptr;
  size_t s = 0;
  size_t figure_k = 0;

  char *cnv = nullptr;

  int err = 0;
  try
  {
    makeFigures(f, figure_k);
    for (size_t i = 0; i < figure_k; i++)
    {
      getPoints(*f[i], &p, s);
    }
    frame_t frame = buildFrame(p, s);
    cnv = buildCanvas(frame);
    paintCanvas(cnv, frame, p, s, '#');
    printCanvas(cnv, frame);
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
