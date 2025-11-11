CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra
TARGET = system_prank
SOURCE = tesk2.cpp
$(TARGET): $(SOURCE)
 $(CXX) $(CXXFLAGS) -o $(TARGET) $(SOURCE)
clean:
 rm -f $(TARGET)

install:
 install -m 755 $(TARGET) /usr/local/bin/
.PHONY:clean install