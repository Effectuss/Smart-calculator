CC = g++
CFLAGS =-Wall -Wextra -Werror -std=c++17
OS=$(shell uname)

TARGET = calc_test
DIRS = $(addprefix model/, credit math)

SOURCES = $(wildcard $(addsuffix /*.cc, $(DIRS)))
SOURCES_TEST = $(wildcard tests/*.cc)
OBJECTS_TEST = $(SOURCES_TEST:.cc=.o)
OBJECTS = $(SOURCES:.cc=.o)
GOBJECTS = $(addsuffix  _gcov.o, $(basename $(OBJECTS)))
HEADERS = $(wildcard $(addsuffix /*.h, $(DIRS))) controller/controller.h

LDFLAGS := -lgtest -lgtest_main
VFLAG := --leak-check=full --show-leak-kinds=all -s
CFLAGS_GCOV := --coverage
CPPCHECKFLAG := --enable=all --suppress=missingIncludeSystem --language=c++ --std=c++17

ifeq ($(OS), Linux)
LEAKS := leaks --atExit -- ./$(TARGET)
endif
ifeq ($(OS), Darwin)
LEAKS := valgrind $(VFLAG) ./$(TARGET)
LDFLAGS += -lpthread -L/usr/lib
endif

all: install

%.o: %.cc
	$(CC) $(CFLAGS) -c $< -o $@

%_gcov.o: %.cc
	$(CC) $(CFLAGS) -c $< -o $@ $(CFLAGS_GCOV)

install: uninstall
	mkdir -p build
	cd build; cmake ..; make
	mkdir -p app
	cp -r ./build/SmartCalculator.app app/

uninstall:
	rm -rf app

clean:
	@rm -rf */*.o */*/*.o *.o
	@rm -rf */*.gcno */*/*.gcno *.gcno
	@rm -rf build

tests: $(OBJECTS) $(OBJECTS_TEST)
	$(CC) $(CFLAGS) $^ -o tests.out $(LDFLAGS)
	./tests.out

dvi:
	@echo $(GOBJECTS)

dist:

gcov_report: $(GOBJECTS) $(OBJECTS_TEST)
	./tests.out
	lcov --capture --directory . --output-file main_coverage.info
	genhtml  main_coverage.info --output-directory lcov_report

check:

leaks:
