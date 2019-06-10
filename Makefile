OUT = App.out
CC = g++
SDIR = src
ODIR = out
INC =

_OBJS = Main.o 

OBJS = $(patsubst %, $(ODIR)/%, $(_OBJS))

$(ODIR)/%.o: $(SDIR)/%.cpp
	$(CC) -g -c $(INC) -o $@ $< $(CFLAGS)

$(OUT): $(ODIR) $(OBJS) 
	$(CC) -g $(ODIR)/*.o -lm -o $(ODIR)/$(OUT)

$(ODIR):
	mkdir -p $(ODIR)

clean:
	rm -Rf src/*.dSYM
	rm -Rf $(ODIR)