CC = gcc
СFLAGS = -Wall -Werror -Wextra
GCOVFLAGS = -fprofile-arcs -ftest-coverage
LIBS = -lcheck

OC = $(shell uname -s)
LINUX = -lsubunit -lrt -lpthread -lm

all: s21_string.a test gcov_report

s21_string.a: s21_string.o
	ar rcs s21_string.a *.o
	cp s21_string.a libs21_string.a
	cp s21_string.a ls21_string.a
	ranlib libs21_string.a
	ranlib ls21_string.a

s21_string.o: function/s21_*.c
	$(CC) $(СFLAGS) -c function/s21_*.c

test: s21_string.a
ifeq ($(OC), Darwin)
	$(CC) $(СFLAGS) tests/s21_tests.c s21_string.a -o test.out $(LIBS)
	./test.out
else
	$(CC) $(СFLAGS) tests/s21_tests.c s21_string.a -o test.out $(LIBS) $(LINUX)
	./test.out
endif

gcov_report: gcov_test.info
ifeq ($(OC), Darwin)
	$(CC) $(CFLAGS) $(GCOVFLAGS) tests/s21_tests.c function/s21_*.c -o test.out $(LIBS)
else
	$(CC) $(CFLAGS) $(GCOVFLAGS) tests/s21_tests.c function/s21_*.c -o test.out $(LIBS) $(LINUX)
endif
	./test.out
	lcov -t "test" -o test.info -c -d .
	genhtml -o report/ gcov_test.info
	open report/index.html

gcov_test.info: gcov_test gcov_test.gcda
	lcov -t "gcov_test" -o gcov_test.info --no-external -c -d .

gcov_test: tests/s21_tests.c s21_string.a
ifeq ($(OC), Darwin)
	$(CC) $(СFLAGS) $(GCOVFLAGS) tests/s21_tests.c function/s21_*.c -o gcov_test $(LIBS)
else
	$(CC) $(СFLAGS) $(GCOVFLAGS) tests/s21_tests.c function/s21_*.c -o gcov_test $(LIBS) $(LINUX)
endif

gcov_test.gcda: gcov_test
	chmod +x *
	./gcov_test

open: gcov_report
	open report/index.html

format:
	cp ../materials/linters/.clang-format ../src
	clang-format -i function/*.c
	clang-format -i tests/*.c
	clang-format -i *.h
	clang-format -n function/*.c
	clang-format -n tests/*.c
	clang-format -n *.h
	rm .clang-format

clang-format:
	cp ../materials/linters/.clang-format ../src
	clang-format -n function/*.c
	clang-format -n tests/*.c
	clang-format -n *.h
	rm .clang-format

clean: 
	rm -rf *.o *.a *.info test.out gcov_test
	rm -rf report
	rm *.gcno
	rm *.gcda

rebuild: clean all
