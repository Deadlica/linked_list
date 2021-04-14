program: main.cpp linked_list.cpp
	g++ -o main main.cpp linked_list.cpp

run: program
	./main

del: program
	rm main
