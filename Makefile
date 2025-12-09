CXX=g++
SRCDIR=.
INCLUDE=-I$(SRCDIR)

SOURCES := $(shell find $(SRCDIR) -type f -name '*.cpp' 2>/dev/null)

OUT=main.out

.PHONY: run
run: 
	$(CXX) $(INCLUDE) $(SOURCES) -o $(OUT)

.PHONY: all
all: clean run


.PHONY: clean
clean:
	rm -f $(OUT)