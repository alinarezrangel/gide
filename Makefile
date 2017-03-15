CXX=g++

CFLAGS=-std=c++11 -g -Wall -Iinclude `pkg-config --cflags gtkmm-3.0 gtksourceviewmm-3.0`
CLIBS=`pkg-config --libs gtkmm-3.0 gtksourceviewmm-3.0`

TARGET=gide.out

SRC=src
INC=include

OBJS=GIDEApplication.o GIDEApplicationWindow.o GIDEFileSystemTreeModel.o

TAGSFILE=TAGS

$(TARGET): $(SRC)/main.cpp $(OBJS)
	$(CXX) $(CFLAGS) $< $(OBJS) $(CLIBS) -o $@

GIDEApplication.o: $(SRC)/GIDEApplication.cpp $(INC)/GIDEApplication.hpp
	$(CXX) -c $(CFLAGS) $< $(CLIBS) -o $@

GIDEApplicationWindow.o: $(SRC)/GIDEApplicationWindow.cpp $(INC)/GIDEApplicationWindow.hpp
	$(CXX) -c $(CFLAGS) $< $(CLIBS) -o $@

GIDEFileSystemTreeModel.o: $(SRC)/GIDEFileSystemTreeModel.cpp $(INC)/GIDEFileSystemTreeModel.hpp
	$(CXX) -c $(CFLAGS) $< $(CLIBS) -o $@

tags:
	etags src/*.cpp include/*.hpp

clean:
	rm $(OBJS) $(TARGET) $(TAGSFILE)
