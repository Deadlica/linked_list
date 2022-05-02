program: main.cpp
	g++ -o main main.cpp -g

run: program
	./main

del: program
	rm main
