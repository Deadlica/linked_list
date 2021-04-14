program : main.cpp linked_list.cpp
	g++ -o main main.cpp linked_list.cpp

run : main
	./main

rm : main
	rm main
