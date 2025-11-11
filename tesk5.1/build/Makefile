CXX g++
CXXFLAGS = -std=c++17 -Wall -Wextra -I.
TARGET = main
BUILD_DIR = build
SOURCS mian.cpp person.cpp
OBJECTS = $(SOURCES:%.cpp=$(BUILD_DIR)/%.o)
$(BUILD_DIR)/$(TARGET):$(OBJECTS)
@mkdir -p $(BUILD_DIR)
$(CXX)$(OBJECTS) -O $@
$(BUILD_DIR)/%.O: %.cpp
@mkdir -p $(BUILD_DIR)
$(CXX)$(CXXFLAGS) -C $< -O $@
.PHONY:  clean run 
run: $(BUILD_DIR)/$(TARGET)
@echo "Running program..."
@echo "========================"
@./$(BUILD_DIR)/$(TARGET)
clean:
	rm -rf $(BUILD_DIR)
all:$(BUILD_DIR)/$(TARGET)