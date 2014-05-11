cc = gcc
cxx = i586-mingw32msvc-gcc
libs = -lglut -lGL -lGLU -lstdc++
flags = 
file = main.cpp

debug:

linux:
	$(cc) -o a.out $(file) $(libs)
windows:
	$(cxx) -o spiningcube.exe $(file) -lglu32 -lopengl32 -lglut32
