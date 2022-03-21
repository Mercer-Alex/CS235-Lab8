build:
	g++ -g -std=c++11 -o test AugmentedIntervalTree.h my_tests.cpp

test: build
	valgrind --leak-check=full ./test