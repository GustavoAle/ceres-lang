CC = gcc
CFLAGS = -ll
LEX = flex
YACC = bison -d
OBJS = parser.tab.o

OUTPUT = ceres

.SUFFIXES: .c .o

$(OUTPUT): $(OBJS)
	$(CC) $(CFLAGS) -o $(OUTPUT) $^

.c.o:
	$(CC) $(CFLAGS) -c $< 


lexer: lexer.l
	$(LEX) lexer.l

parser: parser.y
	$(YACC) parser.y

parser.tab.o: parser lexer

clean:
	$(RM) $(PROGRAM) $(OBJS) lex.yy.c parser.tab.[ch] *.o