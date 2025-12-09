#include <iostream>

namespace top
{
  namespace pod
  {
    struct p_t
    {
      int x, y;
    };

    bool operator==(p_t a, p_t b);
    bool operator!=(p_t a, p_t b);

    struct frame_t
    {
      p_t left_bot;
      p_t right_top;
    };
  }
  using namespace pod;

  namespace figures
  {
    struct IDraw
    {
      virtual p_t begin() const = 0;
      virtual p_t next(p_t) const = 0;

      virtual ~IDraw() = default;
    };

    struct Dot : IDraw
    {
      Dot(int x, int y);
      Dot(p_t pt);

      p_t begin() const override;
      p_t next(p_t) const override;

    private:
      p_t o;
    };

    struct Vseg : IDraw
    {

      Vseg(p_t start, size_t length);
      p_t begin() const override;
      p_t next(p_t) const override;

    private:
      p_t start_;
      size_t length_;
    };

    struct Hseg : IDraw
    {

      Hseg(p_t start, size_t length);
      p_t begin() const override;
      p_t next(p_t) const override;

    private:
      p_t start_;
      size_t length_;
    };

    struct Rectangle : IDraw
    {
      Rectangle(p_t left_bot, int width, int height);
      p_t begin() const override;
      p_t next(p_t curr) const override;

    private:
      Hseg top;
      Vseg left;
      int w, h;
    };

    struct Square : IDraw
    {

      Square(p_t left_bot, int width);
      p_t begin() const override;
      p_t next(p_t curr) const override;

    private:
      Rectangle rect;
    };

    struct FilledRectangle : IDraw
    {
      FilledRectangle(p_t left_bot, int width, int height);
      p_t begin() const override;
      p_t next(p_t curr) const override;

    private:
      Hseg bottom;
      int w, h;
    };

    struct FilledSquare : IDraw
    {
      FilledSquare(p_t left_bot, int width);
      p_t begin() const override;
      p_t next(p_t curr) const override;

    private:
      FilledRectangle fRect;
    };

    size_t count(IDraw &d);

    // TODO:: Круг
  }
  using namespace figures;

  void makeFigures(IDraw **f, size_t size);
  size_t getPoints(const IDraw &figure, p_t **ps, size_t &size);

  frame_t buildFrame(const p_t *ps, size_t s);

  char *buildCanvas(frame_t f);

  void paintCanvas(char *cnv, frame_t frame, const p_t *ps, size_t k, char f);

  void printCanvas(const char *cnv, frame_t fr);

  p_t *extanded(const p_t *old, size_t old_s, size_t new_s);

  void extend(p_t **old, size_t &old_s, p_t new_pt);

  size_t cols(frame_t f);
  size_t rows(frame_t f);
}

int main()
{
  using namespace top;
  IDraw *f[3] = {};
  p_t *p = nullptr;
  size_t s = 0;

  char *cnv = nullptr;

  int err = 0;
  try
  {
    makeFigures(f, 3);
    for (size_t i = 0; i < 3; i++)
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

  for (size_t i = 0; i < 3; i++)
  {
    delete f[i];
  }
  delete[] p;
  delete[] cnv;
  return err;
}

bool top::pod::operator==(p_t a, p_t b)
{
  return a.x == b.x && a.y == b.y;
}

bool top::pod::operator!=(p_t a, p_t b)
{
  return !(a == b);
}

size_t top::figures::count(IDraw &d)
{
  {
    size_t k = 0;
    p_t p = d.begin();
    while (d.next(p) != d.begin())
    {
      k++;
      p = d.next(p);
    }
    return k;
  }
}

top::Dot::Dot(int x, int y):
    IDraw(),
    o{x, y}
{
}

top::p_t top::Dot::begin() const
{
  return o;
}

top::p_t top::Dot::next(p_t prev) const
{
  return o;
}

void top::makeFigures(IDraw **f, size_t size)
{
  f[0] = new FilledSquare({25, 5}, 7);
  f[1] = new Rectangle({-10, 10}, 10, 3);
  f[2] = new FilledRectangle({10, 0}, 3, 4);
}

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

top::p_t *top::extanded(const p_t *old, size_t old_s, size_t new_s)
{
  p_t *new_ps = new p_t[new_s];
  for (size_t i = 0; i < old_s; i++)
  {
    new_ps[i] = old[i];
  }
  return new_ps;
}

void top::extend(p_t **old, size_t &old_s, p_t new_pt)
{
  p_t *new_arr = extanded((*old), old_s, old_s + 1);
  delete[] (*old);
  (*old) = new_arr;
  (*old)[old_s] = new_pt;
  old_s++;
}

size_t top::getPoints(const IDraw &figure, p_t **ps, size_t &size)
{
  size_t initial = size;
  p_t curr_point = figure.begin();
  extend(ps, size, curr_point);
  size_t count = size;
  while (figure.begin() != figure.next(curr_point))
  {

    curr_point = figure.next(curr_point);
    extend(ps, size, curr_point);
    count++;
  }
  return count - initial;
}

top::Vseg::Vseg(p_t start, size_t length):
    start_(start),
    length_(length - 1)
{
  if (!length)
  {
    throw std::runtime_error("length of seg can't be zero");
  }
}

top::p_t top::Vseg::begin() const
{
  return start_;
}

top::p_t top::Vseg::next(p_t curr) const
{
  if (curr.y - start_.y < length_)
    return {curr.x, curr.y + 1};
  return start_;
}

top::Hseg::Hseg(p_t start, size_t length):
    start_(start),
    length_(length - 1)
{
  if (!length)
  {
    throw std::runtime_error("length of seg can't be zero");
  }
}

top::p_t top::Hseg::begin() const
{
  return start_;
}

top::p_t top::Hseg::next(p_t curr) const
{
  if (curr.x - start_.x < length_)
  {
    return {curr.x + 1, curr.y};
  }
  return start_;
}

top::Rectangle::Rectangle(p_t left_bot, int width, int height):
    left(p_t{left_bot.x, left_bot.y}, height),
    top(p_t{left_bot.x, left_bot.y + height - 1}, width),
    w(width - 1),
    h(height - 1)
{
}

top::p_t top::Rectangle::begin() const
{
  return left.begin();
}

top::p_t top::Rectangle::next(p_t curr) const
{
  if (curr.x == left.begin().x && curr.y < top.begin().y)
  {
    return left.next(curr);
  }
  else if (curr.y == top.begin().y && curr.x < top.begin().x + w)
  {
    return top.next(curr);
  }
  else if (curr.x == top.begin().x + w && curr.y > left.begin().y)
  {
    return {curr.x, curr.y - 1};
  }
  else if (curr.y == left.begin().y && curr.x > left.begin().x)
  {
    return {curr.x - 1, curr.y};
  }
  return left.begin();
}

top::Square::Square(p_t left_bot, int width):
    rect(left_bot, width, width)
{
}
top::p_t top::Square::begin() const
{
  return rect.begin();
};
top::p_t top::Square::next(p_t curr) const
{
  return rect.next(curr);
};

top::FilledRectangle::FilledRectangle(p_t left_bot, int width, int height):
    bottom(left_bot, width),
    w(width - 1),
    h(height - 1)
{
  if (height <= 0)
  {
    throw std::runtime_error("height can't be zero or lower");
  }
}
top::p_t top::FilledRectangle::begin() const
{
  return bottom.begin();
};
top::p_t top::FilledRectangle::next(p_t curr) const
{
  if (curr.x - bottom.begin().x < w)
  {
    return bottom.next(curr);
  }
  else if (curr.y - bottom.begin().y < h)
  {
    return {bottom.begin().x, curr.y + 1};
  }
  return bottom.begin();
}

top::FilledSquare::FilledSquare(p_t left_bot, int width):
    fRect(left_bot, width, width)
{
}
top::p_t top::FilledSquare::begin() const
{
  return fRect.begin();
};
top::p_t top::FilledSquare::next(p_t curr) const
{
  return fRect.next(curr);
};