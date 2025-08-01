# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 `sdl2-config --cflags`
LDFLAGS = `sdl2-config --libs` -lSDL2_ttf -lSDL2_image


# Files and directories
SRC = main.cpp tools/Window.cpp tools/widgets/label/Label.cpp tools/widgets/button/Button.cpp tools/widgets/panel/Panel.cpp tools/widgets/textbox/Textbox.cpp tools/style/Style.cpp tools/widgets/checkbox/Checkbox.cpp
OBJ = $(SRC:.cpp=.o)
TARGET_DIR = builds
TARGET = $(TARGET_DIR)/app

# Build target
all: $(TARGET)

# Ensure build directory exists
$(TARGET): $(OBJ) | $(TARGET_DIR)
	$(CXX) $(OBJ) -o $@ $(LDFLAGS)

# Create build directory if it doesn't exist
$(TARGET_DIR):
	mkdir -p $(TARGET_DIR)

# Compile .cpp to .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up
clean:
	rm -f $(OBJ) $(TARGET)
	rm -rf $(TARGET_DIR)
