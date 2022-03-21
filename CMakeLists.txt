cmake_minimum_required(VERSION 3.21)
project(Interval-Tree-Lab)

set(CMAKE_CXX_STANDARD 14)

add_executable(Interval-Tree-Lab IntervalTree.h my_tests.cpp AugmentedIntervalTree.h)
