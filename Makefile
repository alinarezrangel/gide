CXX=g++

CFLAGS=-std=c++11 -g -Wall -Iinclude `pkg-config --cflags gtkmm-3.0 gtksourceviewmm-3.0`
CLIBS=`pkg-config --libs gtkmm-3.0 gtksourceviewmm-3.0`

TARGET=gide.out

SRC=src
INC=include

OBJS=Application.o ApplicationWindow.o FileSystemTreeModel.o

TAGSFILE=TAGS

$(TARGET): $(SRC)/main.cpp $(OBJS)
	$(CXX) $(CFLAGS) $< $(OBJS) $(CLIBS) -o $@

Application.o: $(SRC)/Application.cpp $(INC)/Application.hpp
	$(CXX) -c $(CFLAGS) $< $(CLIBS) -o $@

ApplicationWindow.o: $(SRC)/ApplicationWindow.cpp $(INC)/ApplicationWindow.hpp
	$(CXX) -c $(CFLAGS) $< $(CLIBS) -o $@

FileSystemTreeModel.o: $(SRC)/FileSystemTreeModel.cpp $(INC)/FileSystemTreeModel.hpp
	$(CXX) -c $(CFLAGS) $< $(CLIBS) -o $@

tags:
	etags src/*.cpp include/*.hpp

clean:
	rm $(OBJS) $(TARGET) $(TAGSFILE)
