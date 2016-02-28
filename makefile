all: goblins

goblins: main.o game.o
	g++ main.o game.o -o goblins

main.o: main.cpp
	g++ -c main.cpp

game.o: game.cpp
	g++ -c game.cpp

clean:
	rm *.o goblins