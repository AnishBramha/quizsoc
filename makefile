CXX = g++

ifeq ($(OS), Windows_NT)
	RM := del /Q
	EXEC_EXT := .exe

else
	RM := rm -f
	EXEC_EXT := 

endif


TARGET = app$(EXEC_EXT)

SRCS = main.cpp setup_ui.cpp quiz_ui.cpp files.cpp

OBJS = $(SRCS:.cpp=.o)

CXXFLAGS = -std=c++17 `wx-config --cxxflags`
LDFLAGS = `wx-config --libs`

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) -o $@ $^ $(LDFLAGS) $(LIBS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

main.o: main.hpp setup_ui.hpp
setup_ui.o: setup_ui.hpp files.hpp
quiz_ui.o: quiz_ui.hpp files.hpp
files.o: files.hpp

clean:
	$(RM) $(OBJS)

run:
	make all && make clean && ./app

.PHONY: all clean


