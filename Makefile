OUT = App.out
CC = g++
SDIR = src
ODIR = out
INC = -std=c++11

# Adicionar novos arquivos a medida que for desenvolvendo
# Para adicionar quebra de linha, basta inserir uma barra invertida (\)
# Exemplo:
# _EXEMPLO = nome\
#							outroNome
_OBJS = Main.o \
				Dijkstra.o \
				Edge.o \
				SteinerGraph.o

# Cria os caminho completo de saídas para os arquivos objeto
OBJS = $(patsubst %, $(ODIR)/%, $(_OBJS))

# Compila os arquivos intermediários objeto
$(ODIR)/%.o: $(SDIR)/%.cpp
	$(CC) -g -c $(INC) -o $@ $< $(CFLAGS)

# Compila o arquivo de saída com nome $(OUT)
$(OUT): $(ODIR) $(OBJS) 
	$(CC) -g $(INC) $(ODIR)/*.o -lm -o $(ODIR)/$(OUT)

# Cria diretório de saída
$(ODIR):
	mkdir -p $(ODIR)

# Limpa o repositório dos arquivos de compilados
clean: 
	rm -Rf src/*.dSYM
	rm -Rf $(ODIR)