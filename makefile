
all: try.exe

mystr.o: mystr.h mystr.cpp
	g++.exe -o $@ -c mystr.cpp

try.exe: try.cpp mystr.o
	g++.exe -o $@ try.cpp mystr.o

