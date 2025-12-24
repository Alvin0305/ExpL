LEX = lex
YACC = yacc
CC = gcc
CFLAGS = -Wall -g -std=gnu11
LIBS = -ll

OUT_DIR = io

COMPILER_EXE = $(OUT_DIR)/compiler
LINKER_EXE = $(OUT_DIR)/linker

C_SRCS = node/node.c code_gen/code_gen.c register/register.c evaluator/evaluator.c label/label.c label/label_stack.c util/util.c error_handler/error_handler.c g_symbol_table/g_symbol_table.c g_symbol_table/param_list.c local_symbol_table/local_symbol_table.c tuple_type_table/tuple_type_table.c code_gen/control_flow/control_flow.c code_gen/function/function.c code_gen/tuple/tuple.c code_gen/array/array.c code_gen/arithmetic/arithmetic.c
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
	rm -f $(OUT_DIR)/compiler $(OUT_DIR)/linker

# ==========================================
# AUTOMATED TESTING RULE
# ==========================================

ROOT_DIR = ../../..

test: all
	@echo "--- Starting Automated Testing ---"
	@if [ ! -d "io/expl" ]; then \
		echo "Error: 'io/expl' directory not found."; \
		exit 1; \
	fi
	@if [ ! -f "$(ROOT_DIR)/xsm" ]; then \
		echo "Error: 'xsm' not found at $(ROOT_DIR)/xsm"; \
		exit 1; \
	fi
	@# Initialize counters; use backslashes to run entire block in one shell session
	@total=0; pass=0; fail=0; \
	for src in $$(find io/expl -name "*.expl"); do \
		rel_path=$${src#io/expl/}; \
		base_name=$${rel_path%.expl}; \
		input_file="io/input/$$base_name.txt"; \
		output_file="io/output/$$base_name.txt"; \
		expect_file="io/expected_output/$$base_name.txt"; \
		\
		echo "Testing: $$base_name"; \
		total=$$((total + 1)); \
		\
		# 1. Run Compiler \
		./$(COMPILER_EXE) $$src > /dev/null; \
		if [ $$? -ne 0 ]; then \
			echo "  [ERROR] Compilation failed."; \
			fail=$$((fail + 1)); \
			continue; \
		fi; \
		\
		# 2. Run Linker \
		./$(LINKER_EXE) > /dev/null; \
		if [ $$? -ne 0 ]; then \
			echo "  [ERROR] Linking failed."; \
			fail=$$((fail + 1)); \
			continue; \
		fi; \
		\
		# 3. Prepare Output Directory \
		mkdir -p $$(dirname $$output_file); \
		\
		# Calculate paths relative to ROOT_DIR \
		xsm_rel=$$(realpath --relative-to=$(ROOT_DIR) io/translated.xsm); \
		input_rel=$$(realpath --relative-to=$(ROOT_DIR) $$input_file); \
		output_rel=$$(realpath --relative-to=$(ROOT_DIR) $$output_file); \
		\
		# 4. Run XSM \
		if [ -f $$input_file ]; then \
			(cd $(ROOT_DIR) && bash ./xsm -l library.lib -e $$xsm_rel < $$input_rel > $$output_rel); \
		else \
			(cd $(ROOT_DIR) && bash ./xsm -l library.lib -e $$xsm_rel > $$output_rel); \
		fi; \
		\
		# 5. Compare Results \
		if [ -f $$expect_file ]; then \
			if diff -w -B $$output_file $$expect_file > /dev/null; then \
				echo "  \033[0;32m[PASS]\033[0m"; \
				pass=$$((pass + 1)); \
			else \
				echo "  \033[0;31m[FAIL]\033[0m Output differs from expected."; \
				echo "         See: $$output_file"; \
				fail=$$((fail + 1)); \
			fi; \
		else \
			echo "  [WARN] No expected output file found."; \
			# Optional: Increment fail if you consider missing expected output a failure \
			# fail=$$((fail + 1)); \
		fi; \
	done; \
	\
	echo "\n========================================"; \
	echo "             TEST SUMMARY               "; \
	echo "========================================"; \
	echo "  TOTAL TESTS : $$total"; \
	echo "  PASSED      : \033[0;32m$$pass\033[0m"; \
	echo "  FAILED      : \033[0;31m$$fail\033[0m"; \
	echo "========================================"; \
	if [ $$fail -gt 0 ]; then exit 1; fi

.PHONY: all clean run translate generate test