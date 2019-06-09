
App.out: Main.o
	cc -g -o App.out Main.o -lm

Main.o: src/Main.cpp
	cc -g -c src/Main.cpp

clean:
	rm -f *.out *.o