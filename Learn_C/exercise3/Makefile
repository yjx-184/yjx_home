CFLAGS=-Wall -g

all: ex19

ex19:object.o

clean:
	rm -f ex19
	rm -f object.o

test:ex19 test_game.sh
	chmod +x ./test_game.sh
	./test_game.sh