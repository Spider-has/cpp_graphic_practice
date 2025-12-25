#include <cassert>
#include <cstring>
#include <iostream>
#include <limits>

void skip_line_chars()
{
  std::cin >> std::noskipws;
  char ch;
  std::cin.clear();
  while (std::cin >> ch && ch != '\n')
  {
  }
  std::cin >> std::skipws;
}

void skip_line(std::istream &is)
{
  is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void hi(std::istream &is, std::ostream &os, size_t &context)
{
  unsigned int i = 0;
  if (!(is >> i))
  {
    throw std::runtime_error("hi expects unsigned int");
  }
  skip_line(is);

  os << "< HI: " << i << "! >" << '\n';
}

void hello(std::istream &is, std::ostream &os, size_t &context)
{
  os << "< HELLO! >\n";
}

void next(std::istream &is, std::ostream &os, size_t &context)
{
  unsigned int i = 0;
  if (!(is >> i))
  {
    throw std::runtime_error("hi expects unsigned int");
  }
  context = i;
  skip_line(is);

  os << "< next: " << i << "! >" << '\n';
}

void last(std::istream &is, std::ostream &os, size_t &context)
{
  os << "< context: " << context << " >" << '\n';
}

std::istream &getword(std::istream &is, char *buffer, size_t k, size_t &size, bool (*c)(char))
{
  assert(k > 0 && " k must be greater than zero");
  if (!k || !buffer)
  {
    throw std::logic_error("bad buffer");
  }
  std::ios_base::fmtflags f(is.flags());

  is >> std::noskipws;
  size_t i = 0;
  for (char next = 0; (is) && !c(next) && i < k - 1; ++i)
  {
    is >> next;
    buffer[i] = next;
  }
  buffer[i] = 0;
  size = i;
  is.flags(f);
  return is;
}

bool is_space(char c)
{
  return std::isspace(c);
}

size_t match(const char *word, const char *const *words, size_t k)
{
  size_t w_len = std::strlen(word);
  for (size_t i = 0; i < k; i++)
  {
    bool matching = (w_len == std::strlen(words[i]));

    matching = matching && !std::strcmp(word, words[i]);
    if (matching)
    {
      assert(i < k && "i must be less than k");
      return i;
    }
  }
  return k;
}

struct ICmd
{
  virtual const char *name() const = 0;
  virtual const char *help() const = 0;
  virtual const char *desc() const = 0;
  virtual void invoke() const = 0;
};

struct Cmd
{
  const char *name;
  void (*cmd)();
};

int main()
{
  constexpr size_t cmd_count = 4;
  std::cout << "CLI\n";
  using cmd_t = void (*)(std::istream &, std::ostream &, size_t &);

  size_t context = 0;

  cmd_t cmds[cmd_count] = {hi, hello, next, last};
  const char *const cmds_text[] = {"hi", "hello", "next", "last"};

  constexpr size_t buff_capacity = 255;
  char word[buff_capacity + 1] = {};
  size_t size = 0;

  while (!(getword(std::cin, word, buff_capacity, size, is_space)).eof())
  {
    if (std::cin.fail())
    {
      std::cerr << " < UNKNOWN COMMAND >\n";
      std::cin.clear(std::cin.rdstate() ^ std::ios::failbit);
      skip_line(std::cin);
    }
    else
    {
      word[size - 1] = 0;
      if (size_t i = match(word, cmds_text, cmd_count); i < cmd_count)
      {
        try
        {
          cmds[i](std::cin, std::cout, context);
        }
        catch (const std::exception &e)
        {
          std::cerr << "< INVALID COMMAND: " << e.what() << " >\n";
          if (std::cin.fail())
          {
            std::cin.clear(std::cin.rdstate() ^ std::ios::failbit);
          }
          skip_line(std::cin);
        }
      }
      else
      {
        std::cerr << "< INVALID COMMAND >\n";
      }
    }
  }
}