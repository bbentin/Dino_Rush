target: jogo_simao

all: compile link clean

compile:
	g++ -c *cpp Fontes -I "SFML/include"

link:
	g++ *.o -Wall -o main - L"SFML/lib" -lsfml-graphics -lsfml-window -lsfml-system

clean:
	del *.o