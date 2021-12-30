
CC=gcc
CFLAGS=-Wall -Werror

SRC=src
OBJ=obj
SRCS=$(wildcard $(SRC)/*.c)
OBJS=$(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SRCS))

DEPS = $(patsubst $(OBJ)/%.o, $(OBJ)/%.d, $(OBJS))
DEPFLAGS= -MMD -MF $(@:.o=.d)

BINDIR=bin
BIN=$(BINDIR)/main
SUBMITNAME=sqlite_clone.zip

all: $(BIN)
release: CFLAGS=-Wall -O2 -DNDEBUG
release: clean
release: $(BIN)

-include $(DEPS)

$(BIN): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

$(OBJ)/%.o: $(SRC)/%.c
	$(CC) $(CFLAGS) -c $< -o $@ $(DEPFLAGS)

clean:
	$(RM) -r $(BINDIR)/* $(OBJ)/*

submit:
	$(RM) $(SUBMITNAME)
	zip $(SUBMITNAME) $(BIN)