CXXFILES := main.cpp  Fun.cpp
OBJS :=
TARGET := LearnCpp

CC := g++
LIBS := -pthread -std=c++11
LDFLAGS := -L. 
DEFINES :=
INCLUDE := -I ./
CFLAGS :=
CXXFLAGS :=

all:
	$(CC) $(CXXFILES) $(INCLUDE) $(LDFLAGS)  $(LIBS) $(CXXFLAGS) -o $(TARGET)
clean:
	rm -rf *.o
	rm -rf $(TARGET)



