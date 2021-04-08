program : main.cpp linkedlists.cpp
	g++ -o program main.cpp linkedlists.cpp

run : program
	./program

del :
	rm program
