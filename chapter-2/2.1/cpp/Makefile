# ******************************************
CXX = g++
CXXFLAGS = -Wall -g
objects = main.o Node.o
# ******************************************

main: $(objects)
	$(CXX) -o main $(objects)

main.o: Node.h
Node.o: Node.h

.PHONY   : clean
clean:
	rm main $(objects)
