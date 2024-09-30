# Makefile for Roster-Student Program

CXX = g++
CXXFLAGS = -Wall -g

TARGET = main

# Source files
SOURCES = main.cpp roster.cpp student.cpp
OBJECTS = $(SOURCES:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

clean:
	del /Q *.o $(EXEC) # For Windows, use 'del'
