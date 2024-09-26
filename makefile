#tsofiatouito2@gmail.com

# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++2a -Wall -Wextra -g

# SFML include and library paths
SFML_INCLUDE = -I/Users/your_username/SFML/include
SFML_LIBS = -lsfml-graphics -lsfml-window -lsfml-system

# Source files
MAIN_SRCS = Demo.cpp Complex.cpp
TEST_SRCS = Test.cpp TestCounter.cpp
GUI_SRCS = Demo_GUI.cpp Complex.cpp
ALL_SRCS = $(MAIN_SRCS) $(TEST_SRCS)

# Object files
MAIN_OBJS = $(MAIN_SRCS:.cpp=.o)
TEST_OBJS = $(TEST_SRCS:.cpp=.o)
GUI_OBJS = $(GUI_SRCS:.cpp=.o)
ALL_OBJS = $(ALL_SRCS:.cpp=.o)

# Executable names
DEMO_TARGET = demo
TEST_TARGET = Test
GUI_TARGET = gui_demo

# Default target
all: $(DEMO_TARGET) $(TEST_TARGET)

# Build and run tests
test: $(TEST_TARGET)
	./$(TEST_TARGET)

# Tree build 
tree: $(MAIN_OBJS)
	$(CXX) $(CXXFLAGS) $(SFML_INCLUDE) $^ -o $@ $(SFML_LIBS)

# Link the main program (demo)
$(DEMO_TARGET): $(MAIN_OBJS)
	$(CXX) $(CXXFLAGS) $(SFML_INCLUDE) $^ -o $@ $(SFML_LIBS)

# Link the test program
$(TEST_TARGET): $(TEST_OBJS)
	$(CXX) $(CXXFLAGS) $(SFML_INCLUDE) $^ -o $@ $(SFML_LIBS)

# Link the GUI demo program
$(GUI_TARGET): $(GUI_OBJS)
	$(CXX) $(CXXFLAGS) $(SFML_INCLUDE) $^ -o $@ $(SFML_LIBS)

# Command to run the GUI demo
GUI: $(GUI_TARGET)
	./$(GUI_TARGET)

# Compile source files into object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(SFML_INCLUDE) -c $< -o $@

# Clean up generated files
clean:
	rm -f tree $(MAIN_OBJS) $(TEST_OBJS) $(GUI_OBJS) $(ALL_OBJS) $(DEMO_TARGET) $(TEST_TARGET) $(GUI_TARGET)
