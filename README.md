# RawDoubletsViewer

A Windows application for viewing and exploring LinksPlatform database files (*.links). This tool provides a graphical interface to browse the internal structure of doublets stored in LinksPlatform databases.

## What is RawDoubletsViewer?

RawDoubletsViewer is a Windows GUI application that allows you to:
- Open and inspect LinksPlatform database files (*.links format)
- View doublets data in a structured table format
- Explore the relationships between links including Source, Target, and various tree structure fields
- Navigate through large datasets with an intuitive ListView interface

## System Requirements

- **Operating System**: Windows (x86/64)
- **Compiler**: Dev-C++ IDE or any C++ compiler with Windows API support
- **Libraries**: Windows Common Controls (comctl32.dll)

## Building the Application

### Option 1: Using Dev-C++ IDE (Recommended)

1. **Install Dev-C++**
   - Download and install Dev-C++ from [sourceforge.net](https://sourceforge.net/projects/orwelldevcpp/)

2. **Open the project**
   - Launch Dev-C++
   - Open the project file: `winapi/RawLinks.dev`

3. **Build the project**
   - Press `F9` or go to `Execute > Compile & Run`
   - The executable `RawLinks.exe` will be created

### Option 2: Using MinGW/GCC

1. **Install MinGW**
   - Download MinGW from [mingw.org](http://www.mingw.org/)
   - Make sure `gcc`, `g++`, and `windres` are in your PATH

2. **Compile from command line**
   ```bash
   cd winapi
   windres main.rc -o main.o
   g++ -o RawLinks.exe main.cpp engine.cpp main.o -lcomctl32 -mwindows
   ```

### Option 3: Using Visual Studio

1. **Create a new project**
   - Open Visual Studio
   - Create a new "Windows Desktop Application" project
   - Add all `.cpp` and `.h` files from the `winapi` folder
   - Add the resource file `main.rc`

2. **Configure project settings**
   - Link against `comctl32.lib`
   - Set subsystem to Windows

3. **Build the solution**

## Running the Application

1. **Launch the executable**
   - Double-click `RawLinks.exe` or run from command line

2. **Open a LinksPlatform database**
   - Click "File > Open" (or use Ctrl+O)
   - Browse for a `.links` file
   - Select the file to load its contents

3. **Explore the data**
   - The main window displays a table with columns:
     - **Index**: Sequential item number
     - **Source**: Source link ID
     - **Target**: Target link ID
     - **LeftAsSource**: Left child when this link is used as source
     - **LeftAsTarget**: Left child when this link is used as target
     - **RightAsSource**: Right child when this link is used as source
     - **RightAsTarget**: Right child when this link is used as target
     - **SizeAsSource**: Size of subtree when used as source
     - **SizeAsTarget**: Size of subtree when used as target

## Understanding the Data Structure

The application visualizes the internal structure of LinksPlatform doublets databases. Each row represents a "doublet" - a fundamental unit in the LinksPlatform that connects two other links or values through Source and Target relationships.

### Key Concepts:
- **Doublet**: A connection between Source and Target
- **Tree Structure**: Links are organized in binary trees for efficient navigation
- **Source/Target**: The two endpoints of each doublet relationship

## File Format

The application reads binary `.links` files that contain:
- File header with metadata (allocated links, free links, etc.)
- Array of link structures with their relationships

## Troubleshooting

### Common Issues:

1. **Application won't start**
   - Ensure you have Windows Common Controls available
   - Try running as administrator

2. **Can't open .links files**
   - Verify the file is a valid LinksPlatform database
   - Check file permissions

3. **Build errors**
   - Make sure all header files are in the same directory
   - Verify comctl32 library is linked properly

### Performance Notes:
- Large databases (>1M links) may take time to load
- The ListView uses virtual mode for better performance with large datasets

## Contributing

This is part of the [LinksPlatform](https://github.com/linksplatform) ecosystem. Feel free to contribute improvements or report issues.

## Related Projects

- [Data.Doublets](https://github.com/linksplatform/Data.Doublets) - Core doublets implementation
- [LinksPlatform](https://github.com/linksplatform) - Main platform repository