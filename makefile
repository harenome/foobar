CC = g++

PATH_SRC = src
PATH_OBJ = obj
PATH_BIN = bin
PATH_LIB = lib
PATH_TESTS = tests
PATH_INCLUDE = include

FLAGS_GCOV = -fprofile-arcs -ftest-coverage
FLAGS_DBG = -g -Wall $(FLAGS_GCOV)
FLAGS_CC = -std=c++98 -pedantic $(FLAGS_DBG)
FLAGS_INCLUDE = -I$(PATH_INCLUDE)
FLAGS_LIB = -L$(PATH_LIB)

MISC_FILES = makefile Doxyfile AUTHORS COPYING LICENSE README README.md

vpath %.cpp $(PATH_SRC)
vpath %.hpp $(PATH_INCLUDE) $(PATH_TESTS)
vpath %.o $(PATH_OBJ)
vpath %.a $(PATH_LIB)

all: main tests

gcov: tests
		@bin/runner &> /dev/null
		@gcov -r runner

%.o: %.cpp | obj_dir
		$(CC) $(FLAGS_CC) $(FLAGS_INCLUDE) -o $(PATH_OBJ)/$@ -c $<

main: main.o libfoobar.a | bin_dir
		$(CC) $(FLAGS_LIB) -o $(PATH_BIN)/$@ $(PATH_OBJ)/main.o -lfoobar --coverage

foobar.o: foobar.cpp foobar.hpp
main.o: main.cpp foobar.hpp

libfoobar.a: foobar.o | lib_dir
		ar -crv $(PATH_LIB)/libfoobar.a $(PATH_OBJ)/foobar.o
		ranlib $(PATH_LIB)/libfoobar.a

tests: runner.cpp libfoobar.a | bin_dir
		$(CC) $(FLAGS_LIB) $(FLAGS_INCLUDE) -o $(PATH_BIN)/runner $(PATH_TESTS)/runner.cpp -lfoobar --coverage

runner.cpp: test_foobar.hpp
		cxxtestgen --error-printer -o $(PATH_TESTS)/runner.cpp $(PATH_TESTS)/test_foobar.hpp

obj_dir:
	 	@mkdir -p $(PATH_OBJ)

lib_dir:
		@mkdir -p $(PATH_LIB)

bin_dir:
		@mkdir -p $(PATH_BIN)

doc:
		@doxygen

clean:
		@rm -rf $(PATH_OBJ) $(PATH_LIB) $(PATH_BIN)

cleandoc: clean_doc
clean_doc:
		@rm -rf $(PATH_DOC)

cleantests: clean_tests
clean_tests:
		@rm -rf $(PATH_TESTS)/*.cpp
		@rm -rf $(PATH_BIN)/runner

cleanarchives: clean_archives
clean_archives:
		@rm -rf $(shell basename `pwd`)_*.tar.gz

cleangcov: clean_gcov
clean_gcov:
		@rm -rf *.gcno *.gcda *.gcov

cleanall: clean_all
clean_all: clean clean_doc clean_tests clean_archives clean_gcov
		@echo "Clean."

archive:
		@tar -cvzf $(shell basename `pwd`)_$(shell date "+%Y-%m-%d-%H-%M-%S").tar.gz $(PATH_SRC) $(PATH_INCLUDE) $(PATH_TESTS) $(MISC_FILES)
