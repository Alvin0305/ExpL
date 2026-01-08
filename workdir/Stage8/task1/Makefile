LEX   = lex
YACC  = yacc
CC    = gcc
CFLAGS = -Wall -g -std=gnu11
LIBS  = -ll

OUT_DIR = io
ROOT_DIR = ../../..

COMPILER_EXE = $(OUT_DIR)/compiler
LINKER_EXE   = $(OUT_DIR)/linker

COMPILER_LEX  = lexer.l
COMPILER_YACC = parser.y
LINKER_LEX    = label/label_lexer.l
LINKER_SRC    = label/label.c

C_SRCS = \
	g_symbol_table/g_symbol_table.c \
	g_symbol_table/param_list.c \
	local_symbol_table/local_symbol_table.c \
	\
	type_table/type_table.c \
	tuple_type_table/tuple_type_table.c \
	\
	type_info/type_info.c \
	type_info/dimension.c \
	\
	label/label.c \
	label/label_stack.c \
	\
	code_gen/code_gen.c \
	code_gen/control_flow/control_flow.c \
	code_gen/function/function.c \
	code_gen/tuple/tuple.c \
	code_gen/array/array.c \
	code_gen/arithmetic/arithmetic.c \
	code_gen/library/library.c \
	code_gen/user_type/user_type.c \
	code_gen/pointer/pointer.c \
	\
	node/node.c \
	node/array/node_array.c \
	node/control_flow/node_control_flow.c \
	node/function/node_function.c \
	node/tuple/node_tuple.c \
	node/library/node_library.c \
	node/user_type/node_user_type.c \
	node/pointer/node_pointer.c \
	\
	register/register.c \
	evaluator/evaluator.c \
	\
	class_table/class_table.c\
	\
	util/util.c \
	util/var_list.c \
	error_handler/error_handler.c 

# ==========================================
# DEFAULT TARGET
# ==========================================

all: $(COMPILER_EXE) $(LINKER_EXE)

# ==========================================
# DIRECTORY SETUP
# ==========================================

$(OUT_DIR):
	mkdir -p $(OUT_DIR)

# ==========================================
# COMPILER BUILD
# ==========================================

$(COMPILER_EXE): $(OUT_DIR) y.tab.c lex.yy.c $(C_SRCS)
	$(CC) $(CFLAGS) y.tab.c lex.yy.c $(C_SRCS) -o $@ $(LIBS)

y.tab.c y.tab.h: $(COMPILER_YACC)
	$(YACC) -d $<

lex.yy.c: $(COMPILER_LEX) y.tab.h
	$(LEX) $<

# ==========================================
# LINKER BUILD
# ==========================================

$(LINKER_EXE): $(OUT_DIR) $(LINKER_LEX) $(LINKER_SRC)
	$(LEX) -o label_lex.c $(LINKER_LEX)
	$(CC) $(CFLAGS) label_lex.c $(LINKER_SRC) -o $@ $(LIBS)
	rm -f label_lex.c

# ==========================================
# RUN TARGETS
# ==========================================

run: $(COMPILER_EXE)
	./$(COMPILER_EXE)

translate: $(LINKER_EXE)
	./$(LINKER_EXE)

generate: clean all
	@echo "--- Running Compiler ---"
	./$(COMPILER_EXE)
	@echo "--- Running Label Translator ---"
	./$(LINKER_EXE)
	@echo "--- Done ---"

# ==========================================
# CLEAN
# ==========================================

clean:
	rm -f lex.yy.c y.tab.c y.tab.h label_lex.c
	rm -f $(COMPILER_EXE) $(LINKER_EXE)

# ==========================================
# AUTOMATED TESTING
# ==========================================

test: all
	@echo "--- Starting Automated Testing ---"
	@total=0; pass=0; fail=0; \
	for src in $$(find io/expl -name "*.expl"); do \
		rel=$${src#io/expl/}; \
		base=$${rel%.expl}; \
		inp="io/input/$$base.txt"; \
		out="io/output/$$base.txt"; \
		exp="io/expected_output/$$base.txt"; \
		exp_err="io/expected_output/$$base.err"; \
		printf "Testing: $$base"; \
		total=$$((total+1)); \
		comp_out=$$(mktemp); \
		./$(COMPILER_EXE) $$src > $$comp_out 2>&1; \
		comp_status=$$?; \
		if [ -f $$exp_err ]; then \
			grep "^\[ERROR" $$comp_out > $$comp_out.err; \
			if [ $$comp_status -ne 0 ] && diff -w -B $$comp_out.err $$exp_err > /dev/null; then \
				printf " \033[0;32m[PASS - EXPECTED ERROR]\033[0m\n"; \
				pass=$$((pass+1)); \
			else \
				printf " \033[0;31m[FAIL - ERROR]\033[0m\n"; \
				fail=$$((fail+1)); \
			fi; \
			rm -f $$comp_out $$comp_out.err; \
			continue; \
		fi; \
		if [ $$comp_status -ne 0 ]; then \
			printf " \033[0;31m[FAIL - COMPILER ERROR]\033[0m\n"; \
			fail=$$((fail+1)); \
			rm -f $$comp_out; \
			continue; \
		fi; \
		rm -f $$comp_out; \
		./$(LINKER_EXE) > /dev/null || { printf " \033[0;31m[LINKER ERROR]\033[0m\n"; fail=$$((fail+1)); continue; }; \
		mkdir -p $$(dirname $$out); \
		xsm_rel=$$(realpath --relative-to=$(ROOT_DIR) io/translated.xsm); \
		inp_rel=$$(realpath --relative-to=$(ROOT_DIR) $$inp 2>/dev/null); \
		out_rel=$$(realpath --relative-to=$(ROOT_DIR) $$out); \
		if [ -f $$inp ]; then \
			(cd $(ROOT_DIR) && bash ./xsm -l library.lib -e $$xsm_rel < $$inp_rel > $$out_rel); \
		else \
			(cd $(ROOT_DIR) && bash ./xsm -l library.lib -e $$xsm_rel > $$out_rel); \
		fi; \
		if diff -w -B $$out $$exp > /dev/null; then \
			printf " \033[0;32m[PASS]\033[0m\n"; \
			pass=$$((pass+1)); \
		else \
			printf " \033[0;31m[FAIL]\033[0m\n"; \
			fail=$$((fail+1)); \
		fi; \
	done; \
	echo "==========================================="; \
	printf " TOTAL: $$total  PASS: \033[0;32m$$pass\033[0m  FAIL: \033[0;31m$$fail\033[0m\n"; \
	echo "==========================================="; \
	[ $$fail -eq 0 ]


.PHONY: all clean run translate generate test
