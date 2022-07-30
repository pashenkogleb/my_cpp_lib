CXXFLAGS = -std=c++11
CC = g++


run: test
	./test


test : test.o