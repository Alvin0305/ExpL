LEX = lex
YACC = yacc
CC = gcc

TARGET = out

LEX_FILE = exprtree.l
YACC_FILE = exprtree.y

all: $(TARGET)

lex.yy.c: $(LEX_FILE)
	$(LEX) $(LEX_FILE)

y.tab.c y.tab.h: $(YACC_FILE)
	$(YACC) -d $(YACC_FILE)

$(TARGET): y.tab.c lex.yy.c
	$(CC) y.tab.c lex.yy.c -o $(TARGET) -ll

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f lex.yy.c y.tab.c y.tab.h $(TARGET)