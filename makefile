
#tsofiatouito2@gmail.com

# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++2a -Wall -Wextra

# SFML include and library paths
SFML_INCLUDE = -I/Users/your_username/SFML/include
SFML_LIBS = -lsfml-graphics -lsfml-window -lsfml-system

# Source files
MAIN_SRCS = Demo.cpp Complex.cpp
TEST_SRCS = Test.cpp TestCounter.cpp
ALL_SRCS = $(MAIN_SRCS) $(TEST_SRCS)

# Object files
MAIN_OBJS = $(MAIN_SRCS:.cpp=.o)
TEST_OBJS = $(TEST_SRCS:.cpp=.o)
ALL_OBJS = $(ALL_SRCS:.cpp=.o)

# Executable names
DEMO_TARGET = demo
TEST_TARGET = Test

# Default target
all: $(DEMO_TARGET) $(TEST_TARGET)


# Build and run tests
test: $(TEST_TARGET)
	./$(TEST_TARGET)

# Tree build remains unchanged
tree: $(MAIN_OBJS)
	$(CXX) $(CXXFLAGS) $(SFML_INCLUDE) $^ -o $@ $(SFML_LIBS)


# Link the main program (demo)
$(DEMO_TARGET): $(MAIN_OBJS)
	$(CXX) $(CXXFLAGS) $(SFML_INCLUDE) $^ -o $@ $(SFML_LIBS)

# Link the test program
$(TEST_TARGET): $(TEST_OBJS)
	$(CXX) $(CXXFLAGS) $(SFML_INCLUDE) $^ -o $@ $(SFML_LIBS)

# Compile source files into object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(SFML_INCLUDE) -c $< -o $@

# Clean up generated files
clean:
	rm -f $(MAIN_OBJS) $(TEST_OBJS) $(ALL_OBJS) $(DEMO_TARGET) $(TEST_TARGET)
