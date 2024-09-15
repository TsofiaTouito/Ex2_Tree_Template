# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++2a -Wall -Wextra

# SFML include and library paths
SFML_INCLUDE = -I/Users/your_username/SFML/include
SFML_LIBS = -lsfml-graphics -lsfml-window -lsfml-system

# Source files
MAIN_SRCS = Demo.cpp Complex.cpp

# Object files
MAIN_OBJS = $(MAIN_SRCS:.cpp=.o)

# Executable names
DEMO_TARGET = demo

# Default target (no longer building demo by default)
#all: $(DEMO_TARGET)

# Link the main program (tree)
tree: $(MAIN_OBJS)
	$(CXX) $(CXXFLAGS) $(SFML_INCLUDE) $^ -o $@ $(SFML_LIBS)

# Compile source files into object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(SFML_INCLUDE) -c $< -o $@

# Clean up generated files
clean:
	rm -f $(MAIN_OBJS) $(DEMO_TARGET) tree tree.o

#$(TEST_OBJS) $(TEST_TARGET) TestCounter.o 
