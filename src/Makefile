CC = gcc
CFLAGS = -ly -I.
LEX = flex
YACC = bison -d
OBJS = parser.tab.o

OUTPUT = ceres

.SUFFIXES: .c .o

$(OUTPUT): $(OBJS)
	$(CC) $(CFLAGS) -o $(OUTPUT) $^

.c.o:
	$(CC) $(CFLAGS) -c $^

lex.yy.c:
	$(LEX) compiler/compiler.l

parser.tab.c:
	$(YACC) compiler/compiler.y

parser.tab.o: parser.tab.c lex.yy.c

clean:
	$(RM) $(PROGRAM) $(OBJS) lex.yy.c parser.tab.[ch] *.o