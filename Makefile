# Nome do arquivo executável
PROG = programa

# Lista de arquivos de código fonte
SRCS = $(wildcard *.c)

# Lista de arquivos de objeto
OBJS = $(SRCS:.c=.o)

# Compilador a ser usado
CC = gcc

# Flags do compilador
CFLAGS = -lintelfpgaup -std=c99 -lm

# Regra padrão (primeira regra)
all: $(PROG)

# Regras de compilação para cada arquivo
%.o: %.c $(wildcard *.h)
	$(CC) $(CFLAGS) -c $< -o $@

# Regra para o arquivo executável
$(PROG): $(OBJS)
	$(CC) $(OBJS) -o $(PROG)  $(CFLAGS) 

# Regra para executar o programa
run: $(PROG)
	sudo ./$(PROG)

# Regra para limpar os arquivos gerados
clean:
	rm -f $(PROG) $(OBJS)
