# Project-Computer-Graphics
Computer Graphics Projects Implemented by using graphics.h library in c++
##Graphics configure for code::blocks
1. First download WinBGIm GCC47 file from here.
2. unzip the WinBGIm_GCC47.zip
3. open "graphics.h" file. and replace 302 line with "int left=0, int top=0, int
right=INT_MAX, int bottom=INT_MAX," line.
4. copy & paste "graphics.h" and "winbgim.h" into compiler include folder.
5. copy & paste libbgi.a file into compiler lib folder.
6. Now open code::blocks.
7. Go to settings -> Compiler -> Linker settings
8. Left side Linker libraries click add, and browse the file "libbgi.a" and add. In my pc this
is "C:\Program Files (x86)\CodeBlocks\MinGW\lib\libbgi.a"
9. In Right side Other linker options text field copy paste this, "-lbgi -lgdi32 -lcomdlg32 -
luuid -loleaut32 -lole32" (without quotes)
10. Press ok
