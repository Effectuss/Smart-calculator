CC = g++
CFLAGS = -Wall -Wextra -Werror -std=c++17
OS=$(shell uname)

TARGET = tests.out
DIRS = $(addprefix model/, credit math)

SOURCES = $(wildcard $(addsuffix /*.cc, $(DIRS)))
SOURCES_TEST = $(wildcard tests/*.cc)
OBJECTS_TEST = $(SOURCES_TEST:.cc=.o)
OBJECTS = $(SOURCES:.cc=.o)
GOBJECTS = $(addsuffix  _gcov.o, $(basename $(OBJECTS)))
HEADERS = $(wildcard $(addsuffix /*.h, $(DIRS))) controller/controller.h

LDFLAGS = -lgtest -lgtest_main
VFLAG = --leak-check=full --show-leak-kinds=all -s
CFLAGS_GCOV = --coverage
CPPCHECKFLAG = --enable=all --suppress=unusedFunction --suppress=missingInclude --suppress=unknownMacro --suppress=unusedStructMember --language=c++ --std=c++17

ifeq ($(OS), Linux)
LEAKS = valgrind $(VFLAG) ./$(TARGET)
LDFLAGS += -lpthread -L/usr/lib
endif
ifeq ($(OS), Darwin)
LEAKS = leaks --atExit -- ./$(TARGET)
endif

all: install

%.o: %.cc
	$(CC) $(CFLAGS) -c $< -o $@

%_gcov.o: %.cc
	$(CC) $(CFLAGS) -c $< -o $@ $(CFLAGS_GCOV)

install: uninstall
	@mkdir -p build
	cd build; cmake ..; make
	@mkdir -p app
	@cp -r ./build/SmartCalculator.app app/

uninstall:
	@rm -rf app

tests: $(OBJECTS) $(OBJECTS_TEST)
	$(CC) $(CFLAGS) $^ -o tests.out $(LDFLAGS)
	./tests.out

dvi:

dist:

lcov_report: $(GOBJECTS) $(OBJECTS_TEST)
	$(CC) $(CFLAGS) $^ -o tests.out $(LDFLAGS) $(CFLAGS_GCOV)
	./tests.out
	lcov --no-external --capture --directory . --output-file main_coverage.info
	genhtml  main_coverage.info --output-directory lcov_report

check: tests
	@cppcheck $(CPPCHECKFLAG) */*.cc */*/*.cc *.cc  */*.h */*/*.h *.h
	@-cp ../materials/linters/.clang-format .
	@clang-format -n */*.cc */*/*.cc *.cc  $(HEADERS) */*/*.ui
	@make clean

leaks: tests
	$(LEAKS)
	@make clean

clean:
	@rm -rf */*.o */*/*.o *.o
	@rm -rf */*.gcno */*/*.gcno *.gcno
	@rm -rf */*.gcda */*/*.gcda *.gcda
	@rm -rf main_coverage.info
	@rm -rf build
	@rm -rf .clang-format
	@rm -rf tests.out
	@rm -rf lcov_report
