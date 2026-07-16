CXX = clang++
CXXFLAGS = -std=c++17 -I src/include
LDFLAGS = -lshlwapi
SRCDIR = src
DISTDIR = dist

BINS = arts ct chrome-dev pyr jr justutil sqlt3 wif lc fp cat dt cppi jvi csi cci snip jpb ctp cf ls wr xr fstr rm mv
TARGETS = $(addprefix $(DISTDIR)/, $(addsuffix .exe, $(BINS)))

.PHONY: all clean

all: $(TARGETS)

$(DISTDIR)/%.exe: $(SRCDIR)/%.cpp $(SRCDIR)/runner.cpp | $(DISTDIR)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

$(DISTDIR):
	mkdir -p $(DISTDIR)

clean:
	rm -f $(TARGETS)
