CXX=clang++
CXXFLAGS=-std=c++17 -Werror -Wsign-conversion
VALGRIND_FLAGS=-v --leak-check=full --show-leak-kinds=all --error-exitcode=99

# List of source files
SOURCES=Demo.cpp Complex.cpp
HEADERS=node.hpp tree.hpp Complex.hpp Iterator.hpp
OBJECTS=$(SOURCES:.cpp=.o)

# Default target: runs the demo
run: demo
	./demo

# Build the demo executable
demo: $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o demo

# Run clang-tidy with specified checks and warnings
tidy:
	clang-tidy $(SOURCES) $(HEADERS) -checks=bugprone-*,clang-analyzer-*,cppcoreguidelines-*,performance-*,portability-*,readability-*,-cppcoreguidelines-pro-bounds-pointer-arithmetic,-cppcoreguidelines-owning-memory --warnings-as-errors=-* --

# Run valgrind memory check on demo
valgrind: demo
	valgrind --tool=memcheck $(VALGRIND_FLAGS) ./demo 2>&1 | { egrep "lost| at " || true; }

# Compile .cpp files to .o object files
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) --compile $< -o $@

# Clean up generated files
clean:
	rm -f *.o demo
