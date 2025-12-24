LEX = lex
YACC = yacc
CC = gcc
CFLAGS = -Wall -g
LIBS = -ll

OUT_DIR = io

COMPILER_EXE = $(OUT_DIR)/compiler
LINKER_EXE = $(OUT_DIR)/linker

C_SRCS = node/node.c code_gen/code_gen.c register/register.c evaluator/evaluator.c label/label.c label/label_stack.c util/util.c error_handler/error_handler.c g_symbol_table/g_symbol_table.c g_symbol_table/param_list.c local_symbol_table/local_symbol_table.c
COMPILER_LEX = lexer.l
COMPILER_YACC = parser.y
LINKER_LEX = label/label_lexer.l
LINKER_SRC = label/label.c

all: $(COMPILER_EXE) $(LINKER_EXE)

$(COMPILER_EXE): y.tab.c lex.yy.c $(C_SRCS)
	$(CC) $(CFLAGS) y.tab.c lex.yy.c $(C_SRCS) -o $(COMPILER_EXE) $(LIBS)

$(LINKER_EXE): $(LINKER_LEX) $(LINKER_SRC)
	$(LEX) -o label_lex.c $(LINKER_LEX)
	$(CC) $(CFLAGS) label_lex.c $(LINKER_SRC) -o $(LINKER_EXE) $(LIBS)
	@rm -f label_lex.c

y.tab.c y.tab.h: $(COMPILER_YACC)
	$(YACC) -d $(COMPILER_YACC)

lex.yy.c: $(COMPILER_LEX) y.tab.h
	$(LEX) $(COMPILER_LEX)

run: $(COMPILER_EXE)
	./$(COMPILER_EXE)

translate: $(LINKER_EXE)
	./$(LINKER_EXE)

generate: clean all
	@echo "--- Running Compiler ---"
	./$(COMPILER_EXE)
	@echo "--- Running Label Translator"
	./$(LINKER_EXE)
	@echo "--- Done ---"

clean:
	rm -f lex.yy.c y.tab.c y.tab.h label_lex.c
	rm -f $(COMPILER_EXE) $(LINKER_EXE)

.PHONY: all clean run translate generate