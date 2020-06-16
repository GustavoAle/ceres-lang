CC = gcc
CFLAGS = -ly -I.
LEX = flex
YACC = bison -d
OBJS = parser.tab.o

OUTPUT = cerespre

.SUFFIXES: .c .o

$(OUTPUT): $(OBJS)
	$(CC) $(CFLAGS) -o $(OUTPUT) $^

.c.o:
	$(CC) $(CFLAGS) -c $^

lex.yy.c:
	$(LEX) lexer.l

parser.tab.c:
	$(YACC) parser.y

parser.tab.o: parser.tab.c lex.yy.c

clean:
	$(RM) $(PROGRAM) $(OBJS) lex.yy.c parser.tab.[ch] *.o