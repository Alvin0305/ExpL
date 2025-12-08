LEX = lex
YACC = yacc
CC = gcc

TARGET = io/out

C_FILES = node/node.c code_gen/code_gen.c register/register.c

LEX_FILE = lexer.l
YACC_FILE = parser.y

all: $(TARGET)

lex.yy.c: $(LEX_FILE)
	$(LEX) $(LEX_FILE)

y.tab.c y.tab.h: $(YACC_FILE)
	$(YACC) -d $(YACC_FILE)

$(TARGET): y.tab.c lex.yy.c $(C_FILES)
	$(CC) y.tab.c lex.yy.c $(C_FILES) -o $(TARGET) -ll

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f lex.yy.c y.tab.c y.tab.h $(TARGET)