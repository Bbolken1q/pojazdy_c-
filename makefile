all:
	g++ -c main.cpp -o out/main.o
	g++ -c classes/*.cpp
	move *.o out/
	g++ -o main.exe out/*.o
