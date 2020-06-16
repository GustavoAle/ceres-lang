CC = gcc
CFLAGS = -ly -I.
LEX = flex
YACC = bison -d
OBJS = compiler.tab.o

OUTPUT = ceres

.SUFFIXES: .c .o

$(OUTPUT): $(OBJS)
	$(CC) $(CFLAGS) -o $(OUTPUT) $^

.c.o:
	$(CC) $(CFLAGS) -c $^

lex.yy.c:
	$(LEX) compiler.l

compiler.tab.c:
	$(YACC) compiler.y

compiler.tab.o: compiler.tab.c lex.yy.c

clean:
	$(RM) $(PROGRAM) $(OBJS) lex.yy.c compiler.tab.[ch] *.o