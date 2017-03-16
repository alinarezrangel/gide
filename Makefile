CXX=g++

BOOST_CFLAGS=-I/usr/local/include/boost/
BOOST_LIBS=-lboost_filesystem -lboost_system

GTKMM_CFLAGS=`pkg-config --cflags gtkmm-3.0`
GTKMM_LIBS=`pkg-config --libs gtkmm-3.0`

GTKSOURCEVIEW_CFLAGS=`pkg-config --cflags gtksourceviewmm-3.0`
GTKSOURCEVIEW_LIBS=`pkg-config --libs gtksourceviewmm-3.0`

CFLAGS=-std=c++11 -g -Wall -Iinclude $(BOOST_CFLAGS) $(GTKMM_CFLAGS) $(GTKSOURCEVIEW_CFLAGS)
CLIBS=$(BOOST_LIBS) $(GTKMM_LIBS) $(GTKSOURCEVIEW_LIBS)

TARGET=gide.out

SRC=src
INC=include

OBJS=Application.o ApplicationWindow.o FileSystemTreeModel.o ProjectFolder.o ProjectTemplate.o Project.o

TAGSFILE=TAGS

$(TARGET): $(SRC)/main.cpp $(OBJS)
	$(CXX) $(CFLAGS) $< $(OBJS) $(CLIBS) -o $@

Application.o: $(SRC)/Application.cpp $(INC)/Application.hpp
	$(CXX) -c $(CFLAGS) $< $(CLIBS) -o $@

ApplicationWindow.o: $(SRC)/ApplicationWindow.cpp $(INC)/ApplicationWindow.hpp
	$(CXX) -c $(CFLAGS) $< $(CLIBS) -o $@

FileSystemTreeModel.o: $(SRC)/FileSystemTreeModel.cpp $(INC)/FileSystemTreeModel.hpp
	$(CXX) -c $(CFLAGS) $< $(CLIBS) -o $@

ProjectFolder.o: $(SRC)/ProjectFolder.cpp $(INC)/ProjectFolder.hpp
	$(CXX) -c $(CFLAGS) $< $(CLIBS) -o $@

ProjectTemplate.o: $(SRC)/ProjectTemplate.cpp $(INC)/ProjectTemplate.hpp
	$(CXX) -c $(CFLAGS) $< $(CLIBS) -o $@

Project.o: $(SRC)/Project.cpp $(INC)/Project.hpp
	$(CXX) -c $(CFLAGS) $< $(CLIBS) -o $@

tags:
	etags src/*.cpp include/*.hpp

clean:
	rm $(OBJS) $(TARGET) $(TAGSFILE)
