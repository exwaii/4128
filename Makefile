#––– Compiler and flags
CXX      := g++-14
CPPFLAGS := -Wall -Wextra -Wshadow -Wformat=2 -Wfloat-equal \
            -Wconversion -Wlogical-op \
            -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC \
            -D_FORTIFY_SOURCE=2 -fstack-protector \
            -O2 -std=c++17 -g
LDFLAGS  := -L/opt/homebrew/opt/llvm/lib
# Gather all .cpp files
SRCS := $(shell find . -type f -name '*.cpp')

# The list of executables is just the same names without “.cpp”
EXES := $(SRCS:.cpp=)

# Default target: build every executable
all: $(EXES)

# Pattern rule: foo.cpp → foo
# $< is the source (foo.cpp), $@ is the target (foo)
%: %.cpp
	$(CXX) $(CPPFLAGS) $< -o $@

.PHONY: clean
clean:
	rm -f $(EXES)