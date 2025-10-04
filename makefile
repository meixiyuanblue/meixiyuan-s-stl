CXX = g++
CXXFLAGS = -O2
CPP = main.cpp
OBJ  = $(addprefix o/,$(notdir $(CPP:.cpp=.o)))
EXE = main.exe

all : $(EXE)

$(EXE) : $(OBJ)
	$(CXX) $^ -o $@
	
o/main.o : main.cpp
	$(CXX) -c $^ -o $@


$(OBJ): | o
o:
	mkdir o

clean : 
	del .\o\*.o,.\*.exe

run : 
	.\$(EXE)

.PHONY : all clean run