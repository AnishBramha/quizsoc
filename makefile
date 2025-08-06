CXX = g++

ifeq ($(OS), Windows_NT)
	RM := del /Q
	EXEC_EXT := .exe

else
	RM := rm -f
	EXEC_EXT := 

endif


TARGET = app$(EXEC_EXT)

SRCS = main.cpp ui.cpp 

OBJS = $(SRCS:.cpp=.o)

CXXFLAGS = -std=c++17 `wx-config --cxxflags`
LDFLAGS = `wx-config --libs`

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) -o $@ $^ $(LDFLAGS) $(LIBS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

main.o: main.hpp ui.hpp
ui.o: ui.hpp

clean:
	$(RM) $(OBJS)

run:
	make all && make clean && ./app

.PHONY: all clean


