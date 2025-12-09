#include <canvas/canvas.hpp>

top::frame_t top::buildFrame(const p_t *ps, size_t s)
{
  if (ps && s)
  {
    int left = ps[0].x;
    int bottom = ps[0].y;
    int right = ps[0].x;
    int top = ps[0].y;
    for (size_t i = 0; i < s; i++)
    {
      if (ps[i].x < left)
      {
        left = ps[i].x;
      }
      else if (ps[i].x > right)
      {
        right = ps[i].x;
      }
      if (ps[i].y < bottom)
      {
        bottom = ps[i].y;
      }
      else if (ps[i].y > top)
      {
        top = ps[i].y;
      }
    }
    return frame_t{{left, bottom}, {right, top}};
  }
  throw std::runtime_error("points array is empty");
}

size_t top::cols(frame_t f)
{
  return f.right_top.x - f.left_bot.x + 1;
}
size_t top::rows(frame_t f)
{
  return f.right_top.y - f.left_bot.y + 1;
}

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

void top::printCanvas(const char *cnv, frame_t f)
{
  size_t col_count = cols(f);
  size_t row_count = rows(f);

  for (size_t i = 0; i < row_count; i++)
  {
    for (size_t j = 0; j < col_count; j++)
    {
      std::cout << cnv[i * col_count + j];
    }
    std::cout << "\n";
  }
}
