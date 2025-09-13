# Makefile for RawDoubletsViewer
# Requires MinGW/GCC with Windows support

CXX = g++
WINDRES = windres
CXXFLAGS = -mwindows -O2
LIBS = -lcomctl32
TARGET = winapi/RawLinks.exe
OBJDIR = winapi
SOURCES = $(OBJDIR)/main.cpp $(OBJDIR)/engine.cpp
RESOURCES = $(OBJDIR)/main.rc
RESOURCE_OBJ = $(OBJDIR)/main.o

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(SOURCES) $(RESOURCE_OBJ)
	@echo Building RawDoubletsViewer...
	$(CXX) $(CXXFLAGS) -o $@ $(SOURCES) $(RESOURCE_OBJ) $(LIBS)
	@echo Build successful! Run with: $(TARGET)

$(RESOURCE_OBJ): $(RESOURCES)
	@echo Compiling resources...
	$(WINDRES) $(RESOURCES) -o $@

clean:
	@echo Cleaning build files...
	rm -f $(TARGET) $(RESOURCE_OBJ)

help:
	@echo "Available targets:"
	@echo "  all     - Build the application (default)"
	@echo "  clean   - Remove build files"
	@echo "  help    - Show this help message"
	@echo ""
	@echo "Requirements:"
	@echo "  - MinGW/GCC compiler"
	@echo "  - Windows Resource Compiler (windres)"
	@echo "  - Windows Common Controls library"