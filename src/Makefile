CC = gcc
CFLAGS = -Wall -Werror -Wextra -g -std=c11
OS = $(shell uname)

ifeq ($(OS),Linux)
    det_OS = -lcheck -lm -lrt -lpthread -lsubunit
else
    det_OS = -lcheck -lm -lpthread
endif

all: clean style s21_string.a test gcov_report

test: clean
	$(CC) $(CFLAGS) --coverage tests/*.c sprintf/*.c sscanf/*.c *.c -o test $(det_OS)
	./test

s21_string.a:
	$(CC) $(CFLAGS) sscanf/*.c sprintf/*.c *.c -c
	ar rc s21_string.a *.o
	ranlib s21_string.a

gcov_report:
	lcov -t "s21_string_tests" -o string.info -c -d .
	genhtml -o tests/report/ string.info
	open ./tests/report/index.html

clean:
	rm -rf test *.gcda *.gcno *.o *.info *.a tests/*.gcno tests/report test.dSYM

style:
	clang-format -style=Google -n *.c *.h
	clang-format -style=Google -n tests/*.c tests/*.h
	clang-format -style=Google -n sprintf/*.c sprintf/*.h
	clang-format -style=Google -n sscanf/*.c sscanf/*.h

clang:
	clang-format -style=Google -i *.c *.h
	clang-format -style=Google -i tests/*.c tests/*.h
	clang-format -style=Google -i sprintf/*.c sprintf/*.h
	clang-format -style=Google -i sscanf/*.c sscanf/*.h

install_brew:
	cd ~
	curl -fsSL https://rawgit.com/kube/42homebrew/master/install.sh | zsh
	brew install lcov

rebuild: clean test