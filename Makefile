CXX=g++

CFLAGS=-std=c++11 -g -Wall -Iinclude `pkg-config --cflags gtkmm-3.0`
CLIBS=`pkg-config --libs gtkmm-3.0`

TARGET=gide.out

SRC=src
INC=include

OBJS=GIDEApplication.o

TAGSFILE=TAGS

$(TARGET): $(SRC)/main.cpp $(OBJS)
	$(CXX) $(CFLAGS) $< $(OBJS) $(CLIBS) -o $@

GIDEApplication.o: $(SRC)/GIDEApplication.cpp $(INC)/GIDEApplication.hpp
	$(CXX) -c $(CFLAGS) $< $(CLIBS) -o $@

tags:
	etags src/*.cpp include/*.hpp

clean:
	rm $(OBJS) $(TARGET) $(TAGSFILE)
