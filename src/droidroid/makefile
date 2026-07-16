CXX = clang++
CXXFLAGS = -std=c++17
BIN = ../../dist/droiddroid.exe

all: $(BIN)

$(BIN): droiddroid.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -f $(BIN)

