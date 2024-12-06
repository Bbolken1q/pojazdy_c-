all:
	g++ -I src/include -L src/lib -c -std=gnu++17 main.cpp -o out/main.o -lmingw32 -lSDL2main -lSDL2 -lSDL2_image
	g++ -I src/include -L src/lib -c -std=gnu++17 classes/*.cpp -lmingw32 -lSDL2main -lSDL2 -lSDL2_image
	move *.o out/
	g++ -I src/include -L src/lib -std=gnu++17 -o main.exe out/*.o -lmingw32 -lSDL2main -lSDL2 -lSDL2_image 
