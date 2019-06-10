OUT = App.out
CC = g++
SDIR = src
ODIR = out

$(OUT): Main.o
	$(CC) -g -o $(OUT) $(ODIR)/Main.o -lm

Main.o: $(SDIR)/Main.cpp main-dir
	$(CC) -g -c $(SDIR)/Main.cpp -o $(ODIR)/Main.o

main-dir:
	mkdir -p $(ODIR)

clean:
	rm -Rf src/*.dSYM
	rm -Rf $(ODIR)
	rm -f $(OUT)