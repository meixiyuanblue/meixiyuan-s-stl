CXX = g++
CXXFLAGS = -O2
CPP = main.cpp
OBJ  = $(addprefix o/,$(notdir $(CPP:.cpp=.o)))
HPP = log/logV1.2.hpp
EXE = main.exe

all : $(EXE)

$(EXE) : $(OBJ) $(HPP)
	$(CXX) $(OBJ) -o $(EXE)
	
o/main.o : main.cpp $(HPP)
	$(CXX) -c main.cpp -o $@


$(OBJ): | o
o:
	mkdir o

clean : 
	del .\o\*.o,.\*.exe

run : 
	.\$(EXE)

.PHONY : all clean run