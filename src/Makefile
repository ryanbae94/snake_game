CC=g++
TARGET=snake
OBJECTS=main.o Map.o SnakeGame.o Snake.o Item.o

all: $(TARGET)

clean:
	rm -f *.o
	rm -f $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -lncurses -o $(TARGET) -std=c++11

Map.o: Map.cpp SnakeGame.h map.h
	$(CC) -g -c Map.cpp -lncurses -std=c++11

SnakeGame.o: SnakeGame.cpp SnakeGame.h
	$(CC) -g SnakeGame.cpp -c -lncurses -std=c++11

main.o: main.cpp SnakeGame.h
	$(CC) -g main.cpp -c -lncurses -std=c++11
