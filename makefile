all:
	g++ -c -std=gnu++17 main.cpp -o out/main.o
	g++ -c -std=gnu++17 classes/*.cpp
	move *.o out/
	g++ -std=gnu++17 -o main.exe out/*.o
